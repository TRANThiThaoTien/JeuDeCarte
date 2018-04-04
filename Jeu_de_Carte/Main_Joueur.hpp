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
    void attack_single(Carte* p_carte_en_main);
    void attack_double(Carte* p_carte_en_main);
    void attack_plural(Carte* p_carte_en_main);
    void set_carte_en_main(Carte* p_carte_en_main);
    Carte get_carte_en_main();
    void set_carte_to_fight();
    Carte get_carte_to_fight();
    void print_carte_en_main(Carte* p_carte_en_main) const;
    bool test_position_carte(Carte* p_carte_en_main);
    bool test_position_int(std::string position);
    int test_postion_existed(Carte* p_carte_en_main,std::string position);
    
private:
    
    Carte* m_p_carte_en_main;
    Carte* m_p_carte_to_fight;
    int * m_p_is_valid_carte_tab;
};


#endif /* Main_Joueur_hpp */
