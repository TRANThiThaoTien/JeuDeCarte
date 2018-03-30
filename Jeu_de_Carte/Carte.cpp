//
//  Carte.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Carte.hpp"

using namespace std;

void Carte::set_type_carte(Type_of_Carte type_carte){
    
    m_type_carte = type_carte;
    
};

Type_of_Carte Carte:: get_type_carte(){
    return m_type_carte;
};

int Carte::get_value_carte(){
    return m_value_carte;
};

void Carte::set_value_carte(int value_carte){
    m_value_carte= value_carte;
};

