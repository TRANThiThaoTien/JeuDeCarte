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

class Match {
public:
    Match();
    ~Match();
    void set_match(bool match);
    bool get_match();
    void set_tour(int tour);
    int get_tour();
    int determine_joueur();
    void determine_tour(int number_joueur);
private:
    
    bool m_is_over;
    int m_tour;
};



#endif /* Match_hpp */
