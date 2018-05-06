//
//  Carte_cible.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 13/04/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Carte_cible.hpp"
#include <iostream>
#include "Utilities.hpp"



using namespace std;

Carte_cible::Carte_cible(){
    m_cible_to_figth.clear();
    m_type_attack = attack_single;
};
Carte_cible::~Carte_cible(){};
vector<Carte> Carte_cible::get_carte_cible(){
    return m_cible_to_figth;
};
void Carte_cible::set_carte_cible(vector<Carte> carte_cible){
    //m_cible_to_figth = carte_cible;
    m_cible_to_figth.clear();
    for (int i(0); i < carte_cible.size(); i++) {
        m_cible_to_figth.push_back(carte_cible[i]);
    }
};
Type_Attack Carte_cible::get_type_attack(){
    return m_type_attack;
};
void Carte_cible::set_type_attack(int choix){
    switch (choix) {
        case 1:
            m_type_attack = Type_Attack::attack_single;
            break;
        case 2:
            m_type_attack = Type_Attack::attack_double;
            break;
        case 3:
            m_type_attack = Type_Attack::attack_trois;
            break;
        case 4:
            m_type_attack = Type_Attack::attack_quarte;
            break;
        case 5:
            m_type_attack = Type_Attack::attack_plural;
            break;
        default:
            break;
    }
};
void Carte_cible::print(){
    cout << "Carte_cible actuell:" << endl;
    cout << "Type attack: " << m_type_attack << endl;
    for (int i(0); i < m_cible_to_figth.size(); i++) {
        cout << m_cible_to_figth[i].get_value_carte() << "-" << m_cible_to_figth[i].get_type_carte() << endl;
    }
    cout << "---------" << endl;
}
