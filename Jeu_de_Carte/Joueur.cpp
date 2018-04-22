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
void Joueur::ignore(){
    if (m_tour==true) {
        m_tour=false;
    }
};
Main_Joueur* Joueur::get_main_jouer(){
    return m_main_joueur;
};
bool Joueur::verify_is_finish(){
    int number_verified(0);
    for (int i(0); i < 13; i++) {
        if (m_main_joueur->get_carte_en_main()[i].get_valide() == 0) {
            number_verified++;
        }
    }
    if (number_verified == 13) {
        m_is_finish = true;
    }
    return m_is_finish;
};
void Joueur::set_classement(int classement){
    m_classement = classement;
};
int Joueur::get_classement(){
    return m_classement;
};
