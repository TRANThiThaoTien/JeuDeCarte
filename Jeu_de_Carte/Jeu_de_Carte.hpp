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
#include "Match.hpp"

class Jeu_de_Carte {
public:
    Jeu_de_Carte();
    ~Jeu_de_Carte();
    void distribute(Match* match);
    void set_carte();
    Carte* get_carte();
private:
    Carte* m_carte_tab;

};

#endif /* Jeu_de_Carte_hpp */
