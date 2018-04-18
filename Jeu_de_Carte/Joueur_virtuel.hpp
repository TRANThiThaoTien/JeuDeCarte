//
//  Joueur_virtuel.hpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 31/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Joueur_virtuel_hpp
#define Joueur_virtuel_hpp

#include <stdio.h>
#include <iostream>
#include "Joueur.hpp"

class Joueur_virtuel : public Joueur{
public:
    Type_Attack attack(Carte_cible cible);
    void determine_to_fight_or_not(Carte_cible* cible);
};

#endif /* Joueur_virtuel_hpp */
