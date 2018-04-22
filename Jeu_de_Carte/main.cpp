//
//  main.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include <iostream>
#include "Jeu_de_Carte.hpp"
#include "Match.hpp"
#include "Carte_cible.hpp"

using namespace std;
//
ostream& operator<<(ostream& out, const Type_of_Carte value){
    static map<Type_of_Carte, string> strings;
    if (strings.size() == 0){
#define INSERT_ELEMENT(p) strings[p] = #p
        INSERT_ELEMENT(Coeur);
        INSERT_ELEMENT(Carreau);
        INSERT_ELEMENT(Trefle);
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
    
    Match match;
    match.initialize();
    Jeu_de_Carte carte_block;
    carte_block.set_carte();
    carte_block.distribute(&match);
    Carte* min_carte = match.find_smallest_carte();
    cout << "Min joueur "  << match.get_tour() << endl;
    cout << "Min Carte " << min_carte->get_value_carte() << " - " << min_carte->get_type_carte() << endl;
    //while (!match.verify_is_over()) {
          //match.set_tour(match.get_tour() + 1);
    
    
    //}

    
    
    return 0;
}


