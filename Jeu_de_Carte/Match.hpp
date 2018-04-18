//
//  Match.hpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#ifndef Match_hpp
#define Match_hpp

#include <stdio.h>
#include "Joueur.hpp"
#include "Joueur_physic.hpp"
#include "Joueur_virtuel.hpp"

class Match {
public:
    Match();
    ~Match();
    void set_match(bool match);
    bool get_match();
    void set_tour(int tour);
    int get_tour();
    Joueur* get_joueur_tab();
    void initialize();
    int get_nombre_joueur();
    bool test_int(string number_string);
    bool verify_is_over();
    void find_smallest_carte();
    void determine_tour();

    
private:
    
    bool m_is_over;
    int m_tour;
    Joueur* m_joueur_tab;
    Carte_cible* m_carte_cible;
    int m_nombre_joueur;
};



#endif /* Match_hpp */
