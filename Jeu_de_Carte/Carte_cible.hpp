//
//  Carte_cible.hpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 13/04/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Carte_cible_hpp
#define Carte_cible_hpp
#include "Carte.hpp"
#include <stdio.h>
#include "Utilities.hpp"

class Carte_cible : public Carte{
public:
    Carte_cible();
    ~Carte_cible();
    Carte* get_carte_cible();
    void set_carte_cible(Carte* carte_cible);
    Type_Attack get_type_attack();
private:
    Carte* m_cible_to_figth;
    Type_Attack m_type_attack;
};

#endif /* Carte_cible_hpp */
