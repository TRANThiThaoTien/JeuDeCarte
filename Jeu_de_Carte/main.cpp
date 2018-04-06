//
//  main.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include <iostream>
#include "Jeu_de_Carte.hpp"

using namespace std;
//
ostream& operator<<(ostream& out, const Type_of_Carte value){
    static map<Type_of_Carte, string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Coeur);
        INSERT_ELEMENT(Carreau);
        INSERT_ELEMENT(Trèfle);
        INSERT_ELEMENT(Pique);
#undef INSERT_ELEMENT
    }

    return out << strings[value];
}
ostream& operator<<(ostream& out, const Value_of_Carte value){
    static map<Value_of_Carte, string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(A);
        INSERT_ELEMENT(Deux);
        INSERT_ELEMENT(Trois);
        INSERT_ELEMENT(Quatre);
        INSERT_ELEMENT(Cinque);
        INSERT_ELEMENT(Six);
        INSERT_ELEMENT(Sept);
        INSERT_ELEMENT(Huit);
        INSERT_ELEMENT(Neuf);
        INSERT_ELEMENT(Dix);
        INSERT_ELEMENT(J);
        INSERT_ELEMENT(D);
        INSERT_ELEMENT(R);
#undef INSERT_ELEMENT
    }
    
    return out << strings[value];
}


int main(int argc, const char * argv[]) {
    Jeu_de_Carte jeu;
//    for (int i(0); i<52; i++) {
//        cout << jeu.get_carte()[i].get_value_carte() << "-"<< jeu.get_carte()[i].get_type_carte()<< endl;
//    }
    jeu.distribuer_carte(2, jeu.get_carte());
    
    return 0;
}


