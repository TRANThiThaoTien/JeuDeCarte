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

using namespace std;

Main_Joueur::Main_Joueur(){
    m_p_carte_en_main = (Carte *)malloc(13*sizeof(Carte));
    m_p_carte_to_fight =(Carte *)malloc(13*sizeof(Carte));
    m_p_is_valid_carte_tab = (int *)malloc(13*sizeof(int));
}
Main_Joueur::~Main_Joueur(){
    free(m_p_carte_en_main);
    m_p_carte_en_main = NULL;
    free(m_p_carte_to_fight);
    m_p_carte_to_fight = NULL;
}

// TODO
void Main_Joueur:: attack_double(Carte* p_carte_en_main){
    
};
void Main_Joueur:: attack_plural(Carte* p_carte_en_main){
    
};
Carte Main_Joueur:: get_carte_en_main(){
    // TODO
    Carte carte_to_return(Coeur, A);
    return carte_to_return;
};
void Main_Joueur:: set_carte_to_fight(){
    
};
Carte Main_Joueur:: get_carte_to_fight(){
    // TODO
    Carte carte_to_return(Coeur, A);
    return carte_to_return;
};
bool Main_Joueur:: test_position_carte(Carte* p_carte_en_main){
    return true;
};
void Main_Joueur:: set_carte_en_main(Carte* p_carte_en_main){
    for (int i(0); i<13; i++) {
        m_p_carte_en_main[i]=p_carte_en_main[i];
    }
};
void Main_Joueur:: print_carte_en_main(Carte* p_carte_en_main) const{
    for (int i(0); i<13; i++) {
        if (m_p_is_valid_carte_tab[i]!=0) {
            cout<< "position " << i << ":"<< endl;
        }
    }
};
bool Main_Joueur::test_position_int(string position){
    bool is_int(true);
    for (int i(0); i<position.length(); i++) {
        if (!isdigit(position[i])) {
            is_int= false;
        }
    }
    return is_int;
};

int Main_Joueur::test_postion_existed(Carte* p_carte_en_main,string position){
    int position_int(0);
    position_int=atoi(position.c_str());
    while (test_position_int(position) || (position_int<0) || (position_int > 12) || (m_p_is_valid_carte_tab[position_int])==0 ) {
        cout << "Please choose the position in the list : " << endl;
        getline(cin, position);
        int position_int(0);
        position_int=atoi(position.c_str());
    }
    return position_int;
};

void Main_Joueur::attack_single(Carte* p_carte_en_main){
    print_carte_en_main(p_carte_en_main);
    cout << "Please choose one position corresponding to the carte to fight : " << endl;
    string position("14");
    getline(cin, position);
    int position_int=test_postion_existed(p_carte_en_main, position);
    m_p_is_valid_carte_tab[position_int]=0;
};



