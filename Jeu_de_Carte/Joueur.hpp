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
#include "Carte_cible.hpp"

using namespace std;

class Joueur {
    
public:
    
    Joueur();
    ~Joueur();
    string get_name();
    void set_name(string name);
    bool get_tour();
    void set_tour(bool tour);
    void ignore();
    Type_Attack attack(Carte_cible* cible);
    Main_Joueur* get_main_jouer();
    void set_main_joueur(Main_Joueur* main);
    void set_winner(bool is_winner);
    bool get_winner();
    bool verify_is_finish();
    void determine_to_fight_or_not(Carte_cible* carte);
    void set_classement(int classement);
    int get_classement();
    
protected:
    Main_Joueur* m_main_joueur;
    string m_name;
    bool m_is_finish;
    bool m_tour;
    int m_classement;
};
#endif /* Joueur_hpp */
