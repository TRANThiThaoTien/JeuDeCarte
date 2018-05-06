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
    
    (&match.get_joueur_tab()[0])->affichage();
    (&match.get_joueur_tab()[1])->affichage();
    /*
    cout << "Min joueur "  << match.get_tour() << endl;
    cout << "Min Carte " << min_carte->get_value_carte() << " - " << min_carte->get_type_carte() << endl;
    while (!match.verify_is_over()) {
        if (match.verify_first_attack()) {
            // min_joueur have to play the first attack with his smallest card
            if (match.get_tour() == 0) {
                // Joueur physique
                int choix(0);
                choix = match.get_joueur_tab()[0].demand_attack_type_with_min_card(min_carte);
                // Vefify choix input
                match.set_carte_cible(new Carte_cible());
                match.get_carte_cible()->set_type_attack(choix);
                match.get_carte_cible()->set_carte_cible(match.get_joueur_tab()[0].attack_with_min_card_and_type_attack(choix));
                
            }else{
                // Joueur virtuel
                // Choisir par  défaut attack plus simple -> attack single
                match.set_carte_cible(new Carte_cible());
                match.get_carte_cible()->set_type_attack(1);
                match.get_carte_cible()->set_carte_cible(match.get_joueur_tab()[match.get_tour()].attack_with_min_card_and_type_attack(1));
            }
            match.set_first_attack(false);
        }else{
            
        }
        match.set_tour(match.get_tour() + 1);
        break;
    }
    match.get_carte_cible()->print();
    */
    
    return 0;
}


