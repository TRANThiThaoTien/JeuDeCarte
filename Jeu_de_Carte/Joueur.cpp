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

Main_Joueur Joueur::set_main_joueur(Main_Joueur main){
    main_joueur=main;
    return main_joueur;
};
bool Joueur::ignore(){
    if (m_tour==true) {
        m_tour=false;
    }
    return m_tour;
};

//Déclarer action :  call function attack() in class Main
void Joueur::attack(Main_Joueur main, Carte* carte_en_main){
        string number_of_carte(0);
        cout << "Choose the strategy to attack : " << endl;
        cout << "Enter the number of carte you want to fight" << endl;
        getline(cin, number_of_carte);
        if (number_of_carte=="1") {
            main.attack_single(carte_en_main);
        }
        else if (number_of_carte=="2"){
            main.attack_double(carte_en_main);
        }
        else {
            main.attack_plural(carte_en_main);
        }
};


