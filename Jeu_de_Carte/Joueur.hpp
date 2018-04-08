//
//  Joueur.hpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Joueur_hpp
#define Joueur_hpp

#include <stdio.h>
#include <iostream>
#include "Main_Joueur.hpp"
#include "Carte.hpp"
#include "Utilities.hpp"

using namespace std;

class Joueur {
    
public:
    
    Joueur();
    ~Joueur();
    string get_name();
    void set_name(string name);
    bool get_tour();
    void set_tour(bool tour);
    bool ignore();
    Type_Attack attack(Main_Joueur main, Carte* carte_cible_to_fight, Type_Attack type_cible_attack);
    Main_Joueur* get_main_jouer();
    void set_main_joueur(Main_Joueur* main);
    void set_winner(bool is_winner);
    bool get_winner();
    
protected:
    
    string m_name;
    bool m_tour;
    Main_Joueur* main_joueur;
    bool m_is_winner;
};
#endif /* Joueur_hpp */
