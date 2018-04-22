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
    //O day anh chi them cai Constructeur cua Carte, ma ko can lam gi them
	Carte();
    Carte(Value_of_Carte value_carte, Type_of_Carte type_cart);
    Carte(Carte const& r_carte_source);
    Value_of_Carte get_value_carte();
    void set_value_carte(Value_of_Carte value_carte);
    Type_of_Carte get_type_carte();
    void set_type_carte(Type_of_Carte type_carte);
    void set_valide(bool valide);
    bool get_valide();
    void copy_from_carte(Carte const& carte_source);
private:
    Value_of_Carte m_value_carte;
    Type_of_Carte m_type_carte;
    bool m_valide;
};


#endif /* Carte_hpp */
