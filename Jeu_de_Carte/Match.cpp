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

void Match::determine_joueur(){
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
            m_joueur_tab[0] = Joueur_physic();
            cout << "Enter your name" << endl;
            string name_joueur_physic("");
            getline(cin, name_joueur_physic);
            m_joueur_tab[0].set_name(name_joueur_physic);
        }
        else{
            m_joueur_tab[i] = Joueur_virtuel();
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

            
            
