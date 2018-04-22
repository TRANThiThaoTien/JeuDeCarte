//
//  Carte.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Carte.hpp"

using namespace std;
Carte::Carte(){
	
};
Carte::Carte(Value_of_Carte value_carte, Type_of_Carte type_carte): m_value_carte(value_carte), m_type_carte(type_carte),m_valide(true){
};
Carte::Carte(Carte const& r_carte_source): m_value_carte(r_carte_source.m_value_carte), m_type_carte(r_carte_source.m_type_carte), m_valide(r_carte_source.m_valide){
};
void Carte::set_type_carte(Type_of_Carte type_carte){
    
    m_type_carte = type_carte;
    
};
void Carte::set_value_carte(Value_of_Carte value_carte){
    m_value_carte= value_carte;
};
Type_of_Carte Carte:: get_type_carte(){
    return m_type_carte;
};

Value_of_Carte Carte::get_value_carte(){
    return m_value_carte;
};
void Carte::copy_from_carte(Carte const& carte_source){
    this->m_type_carte = carte_source.m_type_carte;
    this->m_value_carte = carte_source.m_value_carte;
    this->m_valide = carte_source.m_valide;
};
void Carte::set_valide(bool valide){
    m_valide = valide;
};
bool Carte::get_valide(){
    return m_valide;
};



