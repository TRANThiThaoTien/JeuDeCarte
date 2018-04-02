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

int main(int argc, const char * argv[]) {
    Jeu_de_Carte jeu;
    jeu.set_carte();
    for (int i(0); i<52; i++) {
        cout << jeu.m_carte_tab[i].get_value_carte() << " "<< jeu.m_carte_tab[i].get_type_carte()<< endl;
    }
    
    return 0;
}


