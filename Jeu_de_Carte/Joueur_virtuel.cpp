//
//  Joueur_virtuel.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 31/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Joueur_virtuel.hpp"
#include <iostream>
#include <string>


using namespace std;

void Joueur_virtuel::determine_to_fight_or_not(Carte_cible* cible){
    bool is_possible_to_fight(false);
    if (cible->get_type_attack() == attack_single) {
        for (int i(0); i < 13; i++) {
            if (m_main_joueur->get_carte_en_main()[i].get_value_carte() > cible->get_carte_cible()[0].get_value_carte()) {
                m_main_joueur->get_carte_en_main()[i].set_empty(0);
                is_possible_to_fight = true;
                cible->set_carte_cible(&m_main_joueur->get_carte_en_main()[i]);
                break;
            }
        }
        if (is_possible_to_fight == false) {
            ignore();
        }
    }
};
