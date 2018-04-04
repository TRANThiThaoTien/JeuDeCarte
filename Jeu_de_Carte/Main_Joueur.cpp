//
//  Main_Joueur.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Main_Joueur.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;
void Main_Joueur:: set_carte_en_main(Carte carte_en_main[13]){
    for (int i(0); i<13; i++) {
        m_carte_en_main[i]=carte_en_main[i];
    }
};
void Main_Joueur:: print_carte_en_main(Carte* carte_en_main){
    for (int i(0); i<13; i++) {
        if (carte_en_main[i].get_empty()!=0) {
            cout<< "position " << i << ":" << carte_en_main[i].get_type_carte() << carte_en_main[i].get_value_carte() << endl;
        }
    }
};

bool Main_Joueur:: test_position_int(string position){
    bool is_int(true);
    for (int i(0); i<position.length(); i++) {
        if (!isdigit(position[i])) {
            is_int= false;
        }
    }
    return is_int;
};

int Main_Joueur::test_postion_existed(Carte* carte_en_main,string position){
    int position_int(0);
    position_int=atoi(position.c_str());
    while (test_position_int(position) || (position_int<0) || (position_int > 12) || (carte_en_main[position_int].get_empty())==0 ) {
        cout << "Please choose the position in the list : " << endl;
        getline(cin, position);
        int position_int(0);
        position_int=atoi(position.c_str());
    }
    return position_int;
};

void Main_Joueur::attack_single(Carte* carte_en_main){
    print_carte_en_main(carte_en_main);
    cout << "Please choose one position corresponding to the carte to fight : " << endl;
    string position("13");
    getline(cin, position);
    int position_int=test_postion_existed(carte_en_main, position);
    carte_en_main[position_int].set_empty(0);
};



