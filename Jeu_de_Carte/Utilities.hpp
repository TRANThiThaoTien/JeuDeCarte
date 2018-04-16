//
//  Utilities.h
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Utilities_h
#define Utilities_h

#include <iostream>
#include <string>
#include <map>

using namespace std;

enum Type_of_Carte {
    Coeur=3,
    Carreau=2,
    Trefle=1,
    Pique=0
};
enum Value_of_Carte {
    A =11 ,
    Deux =12,
    Trois=0 ,
    Quatre=1,
    Cinque=2,
    Six=3,
    Sept=4,
    Huit=5,
    Neuf=6,
    Dix=7,
    J=8,
    D=9,
    R=10
};

enum Type_Attack {
    attack_single,
    attack_double,
    attack_trois,
    attack_quarte,
    attack_plural
};

#endif /* Utilities_h */







