//
//  Jeu_de_Carte.hpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Jeu_de_Carte_hpp
#define Jeu_de_Carte_hpp

#include <stdio.h>
#include "Carte.hpp"
#include <iostream>
#include "Joueur.hpp"
#include "Main_Joueur.hpp"

class Jeu_de_Carte {
public:
    Jeu_de_Carte();
    ~Jeu_de_Carte();
    void distribuer_carte(int number_joueur);
    void set_carte();
    Carte* get_carte();
private:
    Carte* m_carte_tab;
};

#endif /* Jeu_de_Carte_hpp */
