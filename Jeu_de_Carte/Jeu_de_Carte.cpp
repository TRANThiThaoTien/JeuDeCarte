//
//  Jeu_de_Carte.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 30/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Jeu_de_Carte.hpp"
#include <ctime>
Jeu_de_Carte::Jeu_de_Carte(){
    m_carte_tab = (Carte *)malloc(52*sizeof(Carte));
}
// Pareillement de déstructeur
Jeu_de_Carte::~Jeu_de_Carte(){
    //free(m_carte_tab);
    //m_carte_tab=NULL;
}
void Jeu_de_Carte::set_carte(){
    Type_of_Carte type_carte(Coeur);
    Value_of_Carte value_carte(A);
    int empty(1);
    int carte_position(0);
    for (int i(0); i < 4; i++) {
        int j(0);
        if (i%4==0) {
            type_carte = Coeur;
            for (j = 0; j < 13; j++){
                if (j%13==0) {
                    value_carte = A;
                }
                else if (j%13==1){
                    value_carte = Deux;
                }
                else if (j%13==2){
                    value_carte = Trois;
                }
                else if (j%13==3){
                    value_carte = Quatre;
                }
                else if (j%13==4){
                    value_carte = Cinque;
                }
                else if (j%13==5){
                    value_carte = Six;
                }
                else if (j%13==6){
                    value_carte = Sept;
                }
                else if (j%13==7){
                    value_carte = Huit;
                }
                else if (j%13==8){
                    value_carte = Neuf;
                }
                else if (j%13==9){
                    value_carte = Dix;
                }
                else if (j%13==10){
                    value_carte = J;
                }
                else if (j%13==11){
                    value_carte = D;
                }
                else if (j%13==12){
                    value_carte = R;
                }
                carte_position = 13*i + j;
                m_carte_tab[carte_position] = Carte(value_carte, type_carte, empty);
            }
        }
        else if (i%4==1){
            type_carte = Carreau;
            for (j = 0; j < 13; j++){
                if (j%13==0) {
                    value_carte = A;
                }
                else if (j%13==1){
                    value_carte = Deux;
                }
                else if (j%13==2){
                    value_carte = Trois;
                }
                else if (j%13==3){
                    value_carte = Quatre;
                }
                else if (j%13==4){
                    value_carte = Cinque;
                }
                else if (j%13==5){
                    value_carte = Six;
                }
                else if (j%13==6){
                    value_carte = Sept;
                }
                else if (j%13==7){
                    value_carte = Huit;
                }
                else if (j%13==8){
                    value_carte = Neuf;
                }
                else if (j%13==9){
                    value_carte = Dix;
                }
                else if (j%13==10){
                    value_carte = J;
                }
                else if (j%13==11){
                    value_carte = D;
                }
                else if (j%13==12){
                    value_carte = R;
                }
                carte_position = 13*i + j;
                m_carte_tab[carte_position] = Carte(value_carte, type_carte, empty);
            }
        }
        else if (i%4==2){
            type_carte = Trefle;
            for (j = 0; j < 13; j++){
                if (j%13==0) {
                    value_carte = A;
                }
                else if (j%13==1){
                    value_carte = Deux;
                }
                else if (j%13==2){
                    value_carte = Trois;
                }
                else if (j%13==3){
                    value_carte = Quatre;
                }
                else if (j%13==4){
                    value_carte = Cinque;
                }
                else if (j%13==5){
                    value_carte = Six;
                }
                else if (j%13==6){
                    value_carte = Sept;
                }
                else if (j%13==7){
                    value_carte = Huit;
                }
                else if (j%13==8){
                    value_carte = Neuf;
                }
                else if (j%13==9){
                    value_carte = Dix;
                }
                else if (j%13==10){
                    value_carte = J;
                }
                else if (j%13==11){
                    value_carte = D;
                }
                else if (j%13==12){
                    value_carte = R;
                }
                carte_position = 13*i + j;
                m_carte_tab[carte_position] = Carte(value_carte, type_carte, empty);
            }
        }
        else {
            type_carte = Pique;
            for (j = 0; j < 13; j++){
                if (j%13==0) {
                    value_carte = A;
                }
                else if (j%13==1){
                    value_carte = Deux;
                }
                else if (j%13==2){
                    value_carte = Trois;
                }
                else if (j%13==3){
                    value_carte = Quatre;
                }
                else if (j%13==4){
                    value_carte = Cinque;
                }
                else if (j%13==5){
                    value_carte = Six;
                }
                else if (j%13==6){
                    value_carte = Sept;
                }
                else if (j%13==7){
                    value_carte = Huit;
                }
                else if (j%13==8){
                    value_carte = Neuf;
                }
                else if (j%13==9){
                    value_carte = Dix;
                }
                else if (j%13==10){
                    value_carte = J;
                }
                else if (j%13==11){
                    value_carte = D;
                }
                else if (j%13==12){
                    value_carte = R;
                }
                carte_position = 13*i + j;
                m_carte_tab[carte_position] = Carte(value_carte, type_carte, empty);
            }
        }
    }

};
//void Jeu_de_Carte:: distribuer_carte(int number_joueur){
//    Joueur joueur_tab[number_joueur]; 
//     for (int i(0); i<number_joueur; i++) {
//        Carte* carte_en_main = (Carte *)malloc(13*sizeof(Carte));
//        int number_carte_en_main(0);
//        while (number_carte_en_main<13) {
//            int position_carte(0);
//            srand((int)time(0));
//            position_carte = rand()%52;
//            while (m_carte_tab[position_carte].get_empty() == 0) {
//                srand((int)time(0));
//                position_carte = rand()%52;
//            }
//            //carte_en_main[number_carte_en_main]= carte_to_distribuer[position_carte];
//            carte_en_main[number_carte_en_main] = Carte(m_carte_tab[position_carte]);
//            m_carte_tab[position_carte].set_empty(0);
//            number_carte_en_main++;
//        }
//        joueur_tab[i].get_main_jouer()->set_carte_en_main(carte_en_main);
//        cout << "---------------" << endl;
//        joueur_tab[i].get_main_jouer()->print_carte_en_main();
//    }
//};
void Jeu_de_Carte:: distribute(Match* match){
    int position_max(51);
    int number_carte_rest(52);
    for (int i(0); i<match->get_nombre_joueur(); i++) {
        Carte* carte_en_main = (Carte *)malloc(13*sizeof(Carte));
        int number_carte_en_main(0);
        while (number_carte_en_main<13) {
            int position_carte(0);
            srand((int)time(0));
            position_carte = rand()%number_carte_rest;
            carte_en_main[number_carte_en_main] = Carte(m_carte_tab[position_carte]);
            m_carte_tab[position_carte] = m_carte_tab[position_max];
            position_max--;
            number_carte_en_main++;
            number_carte_rest--;
        }
        (match->get_joueur_tab())[i].get_main_jouer()->set_carte_en_main(carte_en_main);
        cout << "---------------" << endl;
        match->get_joueur_tab()[i].get_main_jouer()->print_carte_en_main();
    }
};

//How to book function get_carte
Carte* Jeu_de_Carte::get_carte(){
    return m_carte_tab;
};


