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
    
    Carte(Type_of_Carte carte_type, Value_of_Carte carte_value);
    ~Carte();
    Value_of_Carte get_value_carte();
    void set_value_carte(Value_of_Carte value_carte);
    Type_of_Carte get_type_carte();
    void set_type_carte(Type_of_Carte type_carte);
    static Carte NullObject;
    
private:
    
    Value_of_Carte m_value_carte;
    Type_of_Carte m_type_carte;
};


#endif /* Carte_hpp */
