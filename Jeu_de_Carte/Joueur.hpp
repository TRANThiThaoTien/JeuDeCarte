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
    void set_classement(int classement);
    int get_classement();
    bool test_int(string number_string);
    int find_card_on_main (Carte carte_source);
    int demand_attack_type_with_min_card(Carte* min_carte);
    vector<Carte> attack_with_min_card_and_type_attack(int type_attack);
    bool verify_possibility_contre_cible(Carte_cible* card_cible);
    void propose_demand_attack_contre_cible(Carte_cible* card_cible);
    
    virtual void affichage();

protected:
    Main_Joueur* m_main_joueur;
    string m_name;
    bool m_is_finish;
    bool m_tour;
    int m_classement;
};
#endif /* Joueur_hpp */
