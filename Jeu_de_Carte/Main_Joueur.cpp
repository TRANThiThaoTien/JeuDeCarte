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
    m_carte_en_main = NULL;
    m_carte_same_value.clear();
    m_carte_chaine.clear();
}
Main_Joueur::~Main_Joueur(){
	if (!m_carte_en_main) {
		delete [] m_carte_en_main;
		m_carte_en_main = NULL;
	}
}
void Main_Joueur:: set_carte_en_main(Carte* carte_en_main){
    m_carte_en_main = carte_en_main;
}
Carte* Main_Joueur::get_carte_en_main(){
    return m_carte_en_main;
}; 
void Main_Joueur:: print_carte_en_main(){
    for (int i(0); i<13; i++) {
        if (m_carte_en_main[i].get_valide() != 0) {
            cout<< "position " << i << ":" << m_carte_en_main[i].get_value_carte() << "-"<<m_carte_en_main[i].get_type_carte() << endl;
        }
    }
};
void Main_Joueur::set_carte_same_value(Carte carte){
    m_carte_same_value.push_back(carte);
};
vector<Carte> Main_Joueur::get_carte_same_value(){
    return m_carte_same_value;
};
void Main_Joueur::set_carte_chaine(Carte carte){
    m_carte_chaine.push_back(carte);
};
vector<Carte> Main_Joueur::get_carte_chaine(){
    return m_carte_chaine;
};
