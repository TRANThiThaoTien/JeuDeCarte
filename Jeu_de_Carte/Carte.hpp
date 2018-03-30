//
//  Carte.hpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Carte_hpp
#define Carte_hpp

#include <stdio.h>
#include <iostream>
#include "Utilities.hpp"

class Carte {
    
public:

    int get_value_carte();
    void set_value_carte(int value_carte);
    Type_of_Carte get_type_carte();
    void set_type_carte(Type_of_Carte type_carte);
    //void set_value_jeu_de_carte();
    
private:
    
    //int jeu_de_carte[52];
    int m_value_carte;
    Type_of_Carte m_type_carte;
};


#endif /* Carte_hpp */
