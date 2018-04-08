//
//  Joueur.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Joueur.hpp"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

Joueur::Joueur(){
    main_joueur = (Main_Joueur *)malloc(sizeof(Main_Joueur));
    // O day Vang de y ha,
    // Cai malloc chi la de allocate, thue mot loc bo nho mémoire, chu khong co keu ham constructeur cho moi cai Carte, nen ban chat no khong co gi het
    // Minh phai khoi tao manuellement, tuc la phai keu cai constructeur cua Carte manuellement
    *main_joueur = Main_Joueur();
    m_name = "Default";
    m_tour = false;
    // Huong tiep can bang malloc la huong tiep can theo C,
    // Anh de Vang dung vi Vang hieu hieu dung malloc, roi free trong Destructeur, TODO, vang viet destructeur cho moi classe ma trong constructeur co dung malloc ha, roi dung free trong do!
    // Sau khi Vang hieu roi thi se chuyen sang dung new() va delete(), huong tiep can C++
};

Joueur::~Joueur(){
    free(main_joueur);
    main_joueur=NULL;
};
string Joueur::get_name(){
    return m_name;
};
void Joueur::set_name(string name){
    m_name=name;
};
bool Joueur::get_tour(){
    return m_tour;
};
void Joueur::set_tour(bool tour){
    m_tour=tour;
};

void Joueur::set_main_joueur(Main_Joueur* main){
    main_joueur = main;
};
bool Joueur::ignore(){
    if (m_tour==true) {
        m_tour=false;
    }
    return m_tour;
};
Main_Joueur* Joueur::get_main_jouer(){
    return main_joueur;
};
void Joueur::set_winner(bool is_winner){
    m_is_winner=is_winner;
};
bool Joueur::get_winner(){
    return m_is_winner;
};


//Déclarer action :  call function attack() in class Main
Type_Attack Joueur::attack(Main_Joueur main, Carte* carte_cible_to_fight, Type_Attack type_cible_attack){
        Type_Attack type_attack(attack_single);
        if (type_cible_attack==attack_single) {
            main.attack_single(main.get_carte_en_main(), carte_cible_to_fight, main.get_carte_to_fight());
            type_attack=attack_single;
        }
        else if (type_cible_attack==attack_double){
            main.attack_double(main.get_carte_en_main(), carte_cible_to_fight, main.get_carte_to_fight());
            type_attack=attack_double;
        }
        else if (type_cible_attack==attack_plural){
            //number_of_carte is the number of carte the cible poses
            main.attack_plural(main.get_carte_en_main(), carte_cible_to_fight, main.get_carte_to_fight());
            type_attack=attack_plural;
        }
        else if (type_cible_attack==attack_trois){
            //number_of_carte is the number of carte the cible poses
            main.attack_trois(main.get_carte_en_main(), carte_cible_to_fight, main.get_carte_to_fight());
            type_attack=attack_trois;
        }
        else if (type_cible_attack==attack_quarte){
            //number_of_carte is the number of carte the cible poses
            main.attack_quarte(main.get_carte_en_main(), carte_cible_to_fight, main.get_carte_to_fight());
            type_attack=attack_quarte;
        }
    
    return type_attack;
};

