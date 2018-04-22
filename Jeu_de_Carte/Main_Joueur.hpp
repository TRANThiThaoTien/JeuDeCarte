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
//#include "Match.hpp"
#include "Carte_cible.hpp"

class Main_Joueur{

public:
    Main_Joueur();
    ~Main_Joueur();
    void set_carte_en_main(Carte* carte_en_main);
    Carte* get_carte_en_main();
    void print_carte_en_main();
 private:
    Carte* m_carte_en_main;
};


#endif /* Main_Joueur_hpp */
