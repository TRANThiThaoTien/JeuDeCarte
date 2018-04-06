//
//  Main_Joueur.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Main_Joueur.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include "Carte.hpp"
#include <algorithm>

using namespace std;

Main_Joueur::Main_Joueur(){
    m_carte_en_main = (Carte *)malloc(13*sizeof(Carte));
    m_carte_to_fight =(Carte *)malloc(13*sizeof(Carte));
    for (int i(0); i< 13; i++) {
        m_carte_en_main[i] = Carte();
        m_carte_to_fight[i] = Carte();
    }
}
Main_Joueur::~Main_Joueur(){
    free(m_carte_en_main);
    m_carte_en_main = NULL;
    free(m_carte_to_fight);
    m_carte_to_fight = NULL;
}
void Main_Joueur::set_carte_empty(Carte* carte_en_main, int* position_tab ){
    for (int i(0); i<sizeof(*position_tab/sizeof(position_tab[0])); i++) {
        carte_en_main[position_tab[i]].set_empty(0);
    }
};
void Main_Joueur:: set_carte_en_main(Carte* carte_en_main){
    for (int i(0); i<13; i++) {
        m_carte_en_main[i].set_type_carte(carte_en_main[i].get_type_carte());
        m_carte_en_main[i].set_value_carte(carte_en_main[i].get_value_carte());
        m_carte_en_main[i].set_empty(1);
    }
}
Carte* Main_Joueur::get_carte_en_main(){
    return m_carte_en_main;
};

void Main_Joueur::set_carte_to_fight(Carte* carte_to_fight){
    m_carte_to_fight=carte_to_fight;
};
Carte* Main_Joueur::get_carte_to_fight(){
    return m_carte_to_fight;
};
void Main_Joueur:: print_carte_en_main(Carte* carte_en_main){
    for (int i(0); i<13; i++) {
        if (carte_en_main[i].get_empty()!=0) {
            cout<< "position " << i << ":" << carte_en_main[i].get_type_carte() << "-"<<carte_en_main[i].get_value_carte() << endl;
        }
    }
};

bool Main_Joueur:: test_position_int(string position){
    bool is_int(true);
    for (int i(0); i<position.length(); i++) {
        if (!isdigit(position[i])) {
            is_int= false;
        }
    }
    return is_int;
};

int Main_Joueur::test_postion_existed(Carte* carte_en_main,string position){
    int position_int(0);
    position_int=atoi(position.c_str());
    while (test_position_int(position) || (position_int<0) || (position_int > 12) || (carte_en_main[position_int].get_empty())==0 ) {
        cout << "The position you choose is wrong, please choose the position in the list : " << endl;
        getline(cin, position);
        int position_int(0);
        position_int=atoi(position.c_str());
    }
    return position_int;
};
int* Main_Joueur::attack_number_carte(int number_of_carte, Carte* carte_en_main){
    print_carte_en_main(carte_en_main);
    int* position_tab = (int*)malloc(number_of_carte*sizeof(int));
    for (int i(0); i<number_of_carte;i++) {
        cout << "Please choose the position "<< i<< " "<< "corresponding to the carte to fight : " << endl;
        string position("13");
        getline(cin, position);
        position_tab[i]=test_postion_existed(carte_en_main, position);
    }
    return position_tab;
};
void Main_Joueur::attack_single(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight){
      int* position_tab = attack_number_carte(1, carte_en_main);
    //TODO
    //Compare type
    while (carte_en_main[position_tab[0]].get_value_carte()<=carte_cible_fight[0].get_value_carte()) {
        if (carte_en_main[position_tab[0]].get_value_carte()==carte_cible_fight[0].get_value_carte() && carte_en_main[position_tab[0]].get_type_carte() > carte_cible_fight[0].get_type_carte()) {
            break;
        }
        else
        position_tab = attack_number_carte(1, carte_en_main);
    }
    set_carte_empty(carte_en_main,position_tab);
};
//TODO
//Compare two double
bool Main_Joueur::test_coueur(Carte carte_first, Carte carte_second){
    bool is_existed(false);
    if (carte_first.get_type_carte()==Coeur) {
        is_existed=true;
    }
    if (carte_second.get_type_carte()==Coeur) {
        is_existed=true;
    }
    return is_existed;
};
void Main_Joueur::attack_double(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight){
    int* position_tab = attack_number_carte(2, carte_en_main);
    while (carte_en_main[position_tab[0]].get_value_carte()!=carte_en_main[position_tab[1]].get_value_carte()) {
        position_tab = attack_number_carte(1, carte_en_main);
    }
    while (carte_en_main[position_tab[0]].get_value_carte() <= carte_cible_fight[0].get_value_carte()) {
        if (carte_en_main[position_tab[0]].get_value_carte() == carte_cible_fight[0].get_value_carte() && test_coueur(carte_en_main[position_tab[0]], carte_en_main[position_tab[1]])) {
            break;
        }
        else 
        position_tab = attack_number_carte(1, carte_en_main);
    }
    set_carte_empty(carte_en_main,position_tab);
};
void Main_Joueur::attack_trois(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight){
    print_carte_en_main(carte_en_main);
    int* position_tab = attack_number_carte(3, carte_en_main);
    while (carte_en_main[position_tab[0]].get_value_carte()!=carte_en_main[position_tab[1]].get_value_carte()&&carte_en_main[position_tab[0]].get_value_carte()!=carte_en_main[position_tab[2]].get_value_carte()) {
        position_tab = attack_number_carte(1, carte_en_main);
    }
    while (carte_en_main[position_tab[0]].get_value_carte()<=carte_cible_fight[0].get_value_carte()) {
        if (carte_en_main[position_tab[0]].get_value_carte()==carte_cible_fight[0].get_value_carte() && carte_en_main[position_tab[0]].get_type_carte() > carte_cible_fight[0].get_type_carte()) {
            break;
        }
        else
            position_tab = attack_number_carte(1, carte_en_main);
    }
    set_carte_empty(carte_en_main,position_tab);
};

void Main_Joueur::attack_quarte(Carte *carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight){
    int* position_tab = attack_number_carte(4, carte_en_main);
    while ((carte_en_main[position_tab[0]].get_value_carte()!=carte_en_main[position_tab[1]].get_value_carte())&& (carte_en_main[position_tab[0]].get_value_carte()!=carte_en_main[position_tab[2]].get_value_carte())&& (carte_en_main[position_tab[0]].get_value_carte()!=carte_en_main[position_tab[3]].get_value_carte())) {
        position_tab = attack_number_carte(4, carte_en_main);
        
    }
    while (carte_en_main[position_tab[0]].get_value_carte()<=carte_cible_fight[0].get_value_carte()) {
        if (carte_en_main[position_tab[0]].get_value_carte()==carte_cible_fight[0].get_value_carte() && carte_en_main[position_tab[0]].get_type_carte() > carte_cible_fight[0].get_type_carte()) {
            break;
        }
        else
            position_tab = attack_number_carte(1, carte_en_main);
    }
    set_carte_empty(carte_en_main,position_tab);

};
bool Main_Joueur::test_chain_carte(int number_of_carte, int* position_tab){
    bool is_rise_by_1(true);
    sort(position_tab, position_tab + number_of_carte);
    for (int i(0); i<number_of_carte-1; i++) {
        if (position_tab[i]!=(position_tab[i+1]-1)) {
            is_rise_by_1=false;
        }
    }
    return is_rise_by_1;
};
Value_of_Carte myfn(Carte carte)
{
    return carte.get_value_carte();
}
void Main_Joueur::attack_plural(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight){
//    print_carte_en_main(carte_en_main);
//    //TODO
//    //Find the number of carte of the cible
//    int number_of_carte(0);
//    for (int i(0); i< 13; i++) {
//        if (carte_cible_fight[i].get_empty()==0) {
//            number_of_carte++;
//        }
//    }
//    int* position_tab = attack_number_carte(number_of_carte, carte_en_main);
//    while (!test_chain_carte(number_of_carte, position_tab)) {
//        position_tab = attack_number_carte(number_of_carte, carte_en_main);
//    }
//    Carte max_element_carte_fighted = *max_element(carte_cible_fight, carte_cible_fight+number_of_carte,myfn);
//    Carte* carte_max_main= (Carte*)malloc(number_of_carte*sizeof(Carte));
//    int j(0);
//    for (int i(0); i<number_of_carte; i++) {
//        carte_max_main[j]=carte_en_main[position_tab[i]];
//        j++;
//    }
//    
//    Carte max_element_carte_en_main = *max_element(carte_max_main, carte_max_main+number_of_carte, myfn);
//    while (max_element_carte_en_main.get_value_carte() <= max_element_carte_fighted.get_value_carte()) {
//        if (max_element_carte_en_main.get_type_carte()>max_element_carte_fighted.get_type_carte()) {
//            break;
//        }
//        else
//            position_tab = attack_number_carte(number_of_carte, carte_en_main);
//    }
//    set_carte_empty(carte_en_main,position_tab);
};


