//
//  Main_Joueur.hpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Main_Joueur_hpp
#define Main_Joueur_hpp

#include <stdio.h>
#include "Carte.hpp"

class Main_Joueur{

public:
    Main_Joueur();
    ~Main_Joueur();
    int* attack_number_carte(int number_of_carte, Carte* carte_en_main);
    void attack_single(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight);
    void attack_double(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight);
    void attack_plural(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight);
    void attack_trois(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight);
    void attack_quarte(Carte* carte_en_main, Carte* carte_cible_fight, Carte* carte_to_fight);
    void set_carte_en_main(Carte* carte_en_main);
    Carte* get_carte_en_main();
    void set_carte_to_fight(Carte* carte_to_fight);
    Carte* get_carte_to_fight();
    void print_carte_en_main(Carte* carte_en_main);
    bool test_position_carte(Carte* carte_en_main);
    bool test_position_int(std::string position);
    int test_postion_existed(Carte* carte_en_main,std::string position);
    bool test_chain_carte(int number_of_carte,int* position_tab);
    bool test_carte_cible(Carte carte_cible, Carte carte_joueur);
    void set_carte_empty(Carte* carte_en_main, int* position_tab);
    bool test_coueur(Carte carte_first, Carte carte_second);
    void set_carte_to_carte_to_fight(Carte* carte_en_main, int position_tab[], Carte* carte_to_fight, int number_carte);

private:
    
    Carte* m_carte_en_main;
    Carte* m_carte_to_fight;
};


#endif /* Main_Joueur_hpp */
