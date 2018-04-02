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

using namespace std;

class Joueur {
    
public:
    
    string get_name();
    void set_name(string name);
    bool get_tour();
    void set_tour(bool tour);
    bool ignore();
    void attack(Main_Joueur main, Carte carte_en_main[]);
    Main_Joueur get_main_jouer();
    Main_Joueur set_main_joueur(Main_Joueur main);
    
protected:
    
    string m_name;
    bool m_tour;
    Main_Joueur main_joueur;
    
};
#endif /* Joueur_hpp */
