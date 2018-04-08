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
};
Match::~Match(){
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

int Match::determine_joueur(){
    string number_joueur_string(0);
    cout << "Please choose the number of player : " << endl;
    getline(cin, number_joueur_string);
    int number_joueur = atoi(number_joueur_string.c_str());
    return number_joueur;
};
void Match::determine_tour(int number_joueur){
    Joueur* joueur_tab = (Joueur*)malloc(number_joueur*sizeof(Joueur));
    for (int i(0); i<number_joueur; i++) {
        if (m_tour%number_joueur==i) {
            joueur_tab[i].set_tour(true);
        }
        if (joueur_tab[i].ignore() || joueur_tab[i].attack(joueur_tab[i].get_main_jouer(), joueur_tab[i].get_main_jouer()->get_carte_to_fight(), joueur_tab[i].get_main_jouer()->get) {
            <#statements#>
        }
    }
};

