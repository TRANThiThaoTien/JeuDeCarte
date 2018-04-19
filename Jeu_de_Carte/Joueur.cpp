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
    m_main_joueur = new Main_Joueur();
    m_name = "";
    m_tour = false;
    m_is_winner = false;
    m_is_finish = false;
    m_classement = 0;
};

Joueur::~Joueur(){
	if (!m_main_joueur) {
		delete m_main_joueur;
	}
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
    m_main_joueur = main;
};
bool Joueur::ignore(){
    if (m_tour==true) {
        m_tour=false;
    }
    return m_tour;
};
Main_Joueur* Joueur::get_main_jouer(){
    return m_main_joueur;
};
void Joueur::set_winner(bool is_winner){
    m_is_winner=is_winner;
};
bool Joueur::get_winner(){
    return m_is_winner;
};
bool Joueur::is_finish(){
    int number_verified(0);
    for (int i(0); i < 13; i++) {
        if (m_main_joueur->get_carte_en_main()[i].get_empty() == 0) {
            number_verified++;
        }
    }
    if (number_verified == 13) {
        m_is_finish = true;
    }
    return m_is_finish;
};

//Déclarer action :  call function attack() in class Main
Type_Attack Joueur::attack(Carte_cible* cible){
        Type_Attack type_attack(attack_single);
        if (cible->get_type_attack()==attack_single) {
            m_main_joueur->attack_single(cible);
            cible->set_type_attack(attack_single);
        }
        else if (cible->get_type_attack()==attack_double){
            m_main_joueur->attack_double(cible);
            cible->set_type_attack(attack_double);
        }
        else if (cible->get_type_attack()==attack_plural){
            m_main_joueur->attack_plural(cible);
            cible->set_type_attack(attack_plural);
        }
        else if (cible->get_type_attack()==attack_trois){
            m_main_joueur->attack_trois(cible);
            cible->set_type_attack(attack_trois);
        }
        else if (cible->get_type_attack()==attack_quarte){
            m_main_joueur->attack_quarte(cible);
            cible->set_type_attack(attack_quarte);
        }
    
    return type_attack;
};
void Joueur::determine_to_fight_or_not(Carte_cible* carte){};
void Joueur::set_classement(int classement){
    m_classement = classement;
};
int Joueur::get_classement(){
    return m_classement;
};
