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

Carte_cible::Carte_cible() : Carte(Deux, Pique, 1){
    m_cible_to_figth = NULL;
    m_type_attack = attack_single;
};
Carte_cible::~Carte_cible(){};
Carte* Carte_cible::get_carte_cible(){
    return m_cible_to_figth;
};
void Carte_cible::set_carte_cible(Carte* carte_cible){
    m_cible_to_figth = carte_cible;
};
Type_Attack Carte_cible::get_type_attack(){
    return m_type_attack;
};