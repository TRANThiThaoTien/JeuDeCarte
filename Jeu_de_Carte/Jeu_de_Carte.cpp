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
    for (int i(0); i<52; i++) {
        m_carte_tab[i].set_empty(1);
    }
    // O day Vang de y ha,
    // Cai malloc chi la de allocate, thue mot loc bo nho mémoire, chu khong co keu ham constructeur cho moi cai Carte, nen ban chat no khong co gi het
    // Minh phai khoi tao manuellement, tuc la phai keu cai constructeur cua Carte manuellement
    for (int i(0); i<52; i++) {
        m_carte_tab[i] = Carte();
    }
    
    // Huong tiep can bang malloc la huong tiep can theo C,
    // Anh de Vang dung vi Vang hieu hieu dung malloc, roi free trong Destructeur, TODO, vang viet destructeur cho moi classe ma trong constructeur co dung malloc ha, roi dung free trong do!
    // Sau khi Vang hieu roi thi se chuyen sang dung new() va delete(), huong tiep can C++
}
// Pareillement de déstructeur
Jeu_de_Carte::~Jeu_de_Carte(){
    
}
void Jeu_de_Carte::set_carte(){
    for (int i(0); i<52; i++) {
        if (i%4==0) {
            m_carte_tab[i].set_type_carte(Coeur);
        }
        else if (i%4==1){
            m_carte_tab[i].set_type_carte(Carreau);

        }
        else if (i%4==2){
            m_carte_tab[i].set_type_carte(Trèfle);
            
        }
        else {
            m_carte_tab[i].set_type_carte(Pique);
            
        }
    }
    for (int i(0); i<52; i++) {
        if (i%13==0) {
            m_carte_tab[i].set_value_carte(A);
        }
        else if (i%13==1){
            m_carte_tab[i].set_value_carte(Deux);
        }
        else if (i%13==2){
            m_carte_tab[i].set_value_carte(Trois);
        }
        else if (i%13==3){
            m_carte_tab[i].set_value_carte(Quatre);
        }
        else if (i%13==4){
            m_carte_tab[i].set_value_carte(Cinque);
        }
        else if (i%13==5){
            m_carte_tab[i].set_value_carte(Six);
        }
        else if (i%13==6){
            m_carte_tab[i].set_value_carte(Sept);
        }
        else if (i%13==7){
            m_carte_tab[i].set_value_carte(Huit);
        }
        else if (i%13==8){
            m_carte_tab[i].set_value_carte(Neuf);
        }
        else if (i%13==9){
            m_carte_tab[i].set_value_carte(Dix);
        }
        else if (i%13==10){
            m_carte_tab[i].set_value_carte(J);
        }
        else if (i%13==11){
            m_carte_tab[i].set_value_carte(D);
        }
        else if (i%13==12){
            m_carte_tab[i].set_value_carte(R);
        }
        
    }
    
};

void Jeu_de_Carte:: distribuer_carte(int number_joueur, Carte* carte_to_distribuer){
    Joueur joueur_tab[number_joueur];
    for (int i(0); i<number_joueur; i++) {
        Carte* carte_en_main = (Carte *)malloc(13*sizeof(Carte));
        int number_carte_en_main(0);
        while (number_carte_en_main<13) {
            int position_carte(0);
            srand((int)time(0));
            position_carte = rand()%52+1;
            while (carte_to_distribuer[position_carte].get_empty() == 0) {
                srand((int)time(0));
                position_carte = rand()%52+1;
            }
            carte_en_main[number_carte_en_main]= carte_to_distribuer[position_carte];
            carte_to_distribuer[position_carte].set_empty(0);
            number_carte_en_main++;
        }
        joueur_tab[i].get_main_jouer()->set_carte_en_main(carte_en_main);
        joueur_tab[i].get_main_jouer()->print_carte_en_main(carte_en_main);
    }
};


//How to book function get_carte
Carte* Jeu_de_Carte::get_carte(){
    return m_carte_tab;
};


