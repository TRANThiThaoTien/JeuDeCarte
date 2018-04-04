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
    
    void attack_single(Carte* carte_en_main);
    void attack_double(Carte* carte_en_main);
    void attack_plural(Carte* carte_en_main);
    void set_carte_en_main(Carte carte_en_main[]);
    Carte get_carte_en_main();
    void set_carte_to_fight();
    Carte get_carte_to_fight();
    void print_carte_en_main(Carte* carte_en_main);
    bool test_position_carte(Carte* carte_en_main);
    bool test_position_int(std::string position);
    int test_postion_existed(Carte* carte_en_main,std::string position);
    
private:
    
    Carte m_carte_en_main[13];
    Carte m_carte_to_fight[13];
};


#endif /* Main_Joueur_hpp */
