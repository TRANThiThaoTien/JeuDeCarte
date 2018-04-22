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
    m_carte_cible = NULL;
    cout << "Ok to initialize the match !" << endl;
};
Match::~Match(){
    if (m_joueur_tab != NULL) {
			delete[] m_joueur_tab;
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
    //getline(cin, number_joueur_string);
	cin >> number_joueur_string;
    while (!test_int(number_joueur_string) || atoi(number_joueur_string.c_str()) <= 0|| atoi(number_joueur_string.c_str()) > 4) {
        cout << "Please choose the number of player, lower than 4 and greater than 0 : " << endl;
        //getline(cin, number_joueur_string);
			cin >> number_joueur_string;
    }
    m_nombre_joueur = atoi(number_joueur_string.c_str());
    //m_joueur_tab = (Joueur *)malloc(m_nombre_joueur * sizeof(Joueur));
	m_joueur_tab = new Joueur[m_nombre_joueur];
	cout << "number of joueur " << m_nombre_joueur << endl;
    for (int i(0); i < m_nombre_joueur; i++) {
        if (i==0) {
            m_joueur_tab[0] = Joueur_physic();
            cout << "Enter your name" << endl;
            string name_joueur_physic("");
            //getline(cin, name_joueur_physic);
					cin >> name_joueur_physic;
            m_joueur_tab[0].set_name(name_joueur_physic);
        }
        else{
            m_joueur_tab[i] = Joueur_virtuel();
        }
    }
};
bool Match::verify_is_over(){
    int number_finish(0);
    for (int i(0); i<m_nombre_joueur; i++) {
        if (m_joueur_tab[i].verify_is_finish() == true) {
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
                m_joueur_tab[m_tour].set_tour(true);
                break;
            }
        }
        if (b_is_found) {
            break;
        }
    }
};
void Match::set_first_attack(bool is_first_attack){
    m_is_first_attack = is_first_attack;
};
bool Match::verify_first_attack(){
    return m_is_first_attack;
};
void Match::set_obligation_to_fight(bool is_obligated_to_fight){
    m_is_obligated_to_fight = is_obligated_to_fight;
};
bool Match::verify_obligation_to_fight(){
    return m_is_obligated_to_fight;
};
