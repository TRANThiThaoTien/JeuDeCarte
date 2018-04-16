//
//  Match.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Match.hpp"
#include <iostream>

using namespace std;

Match::Match(){
    m_is_over = false;
    m_tour = 0;
    m_nombre_joueur = 0;
    m_joueur_tab = NULL;
    cout << "Ok to initialize the match !" << endl;
};
Match::~Match(){
    if (m_joueur_tab != NULL) {
        free(m_joueur_tab);
        m_joueur_tab = NULL;
    }
};
void Match::set_tour(int tour){
    m_tour=tour;
};
int Match::get_tour(){
    return m_tour;
};
void Match::set_match(bool match){
    m_is_over=match;
};
bool Match::get_match(){
    return m_is_over;
};
int Match::get_nombre_joueur(){
    return m_nombre_joueur;
};
bool Match::test_int(string number_string){
    bool is_int(true);
    for (int i(0); i<number_string.length(); i++) {
        if (!isdigit(number_string[i])) {
            is_int= false;
        }
    }
    return is_int;
};
Joueur* Match::get_joueur_tab(){
    return m_joueur_tab;
};

void Match::initialize(){
    string number_joueur_string("");
    cout << "Please choose the number of player : " << endl;
    getline(cin, number_joueur_string);
    while (!test_int(number_joueur_string) || atoi(number_joueur_string.c_str()) <= 0|| atoi(number_joueur_string.c_str()) > 4) {
        cout << "Please choose the number of player, lower than 4 and greater than 0 : " << endl;
        getline(cin, number_joueur_string);
    }
    m_nombre_joueur = atoi(number_joueur_string.c_str());
    m_joueur_tab = (Joueur *)malloc(m_nombre_joueur * sizeof(Joueur));
    for (int i(0); i < m_nombre_joueur; i++) {
        if (i==0) {
            m_joueur_tab[0] = Joueur();
            cout << "Enter your name" << endl;
            string name_joueur_physic("");
            getline(cin, name_joueur_physic);
            m_joueur_tab[0].set_name(name_joueur_physic);
        }
        else{
            m_joueur_tab[i] = Joueur();
        }
    }
};
bool Match::verify_is_over(){
    int number_finish(0);
    for (int i(0); i<m_nombre_joueur; i++) {
        if (m_joueur_tab[i].is_finish() == true) {
            number_finish++;
        }
    }
    if (number_finish >= (m_nombre_joueur-1)) {
        m_is_over = true;
    }
    return m_is_over;
};
void Match::find_smallest_carte(){
    bool b_is_found(0);
    for (int i(0); i < m_nombre_joueur; i++) {
        cout << i << endl;
        for (int j(0); j < 13; j++) {
            cout << j << endl;
            if (m_joueur_tab[i].get_main_jouer()->get_carte_en_main()[j].get_value_carte() == Trois && m_joueur_tab[i].get_main_jouer()->get_carte_en_main()[j].get_type_carte() == Pique) {
                b_is_found = true;
                m_tour = i;
                cout << "tour :" <<m_tour << endl;
                break;
            }
        }
        if (b_is_found) {
            break;
        }
    }
};
void Match::determine_tour(int number_joueur, Carte_cible carte_cible){
//    int joueur_tour(0);
//    while (!m_is_over) {
//        // tim bai nho nhat de set m_tour
//        
//        joueur_tour = m_tour%number_joueur;
//                m_joueur_tab[joueur_tour].set_tour(true);
//        if (m_joueur_tab[joueur_tour].ignore() || m_joueur_tab[joueur_tour].attack(m_joueur_tab[joueur_tour].get_main_jouer(), carte_cible.get_type_attack())) {
//                m_tour++;
//        }
//        
//    }
};

            
            
