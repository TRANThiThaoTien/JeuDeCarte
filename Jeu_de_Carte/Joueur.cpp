//
//  Joueur.cpp
//  Jeu_de_Carte
//
//  Created by Cao Bui on 27/03/2018.
//  Copyright © 2018 Thi Thao Tien. All rights reserved.
//

#include "Joueur.hpp"
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

Joueur::Joueur(){
    m_main_joueur = new Main_Joueur();
    m_name = "";
    m_tour = false;
    m_is_finish = false;
    m_classement = 0;
};

Joueur::~Joueur(){
	if (!m_main_joueur) {
		delete m_main_joueur;
	}
};
string Joueur::get_name(){
    return m_name;
};
void Joueur::set_name(string name){
    m_name=name;
};
bool Joueur::get_tour(){
    return m_tour;
};
void Joueur::set_tour(bool tour){
    m_tour=tour;
};
void Joueur::ignore(){
    if (m_tour==true) {
        m_tour=false;
    }
};
Main_Joueur* Joueur::get_main_jouer(){
    return m_main_joueur;
};
bool Joueur::verify_is_finish(){
    int number_verified(0);
    for (int i(0); i < 13; i++) {
        if (m_main_joueur->get_carte_en_main()[i].get_valide() == 0) {
            number_verified++;
        }
    }
    if (number_verified == 13) {
        m_is_finish = true;
    }
    return m_is_finish;
};
void Joueur::set_classement(int classement){
    m_classement = classement;
};
int Joueur::get_classement(){
    return m_classement;
};
bool Joueur::test_int(string number_string){
    bool is_int(true);
    for (int i(0); i<number_string.length(); i++) {
        if (!isdigit(number_string[i])) {
            is_int= false;
        }
    }
    return is_int;
};
int Joueur::find_card_on_main (Carte carte_source){
    int position_carte_in_main(0);
    for (int i(0); i < 13; i++) {
        if (m_main_joueur->get_carte_en_main()[i].get_value_carte() == carte_source.get_value_carte()
            && m_main_joueur->get_carte_en_main()[i].get_type_carte() == carte_source.get_type_carte()
            && m_main_joueur->get_carte_en_main()[i].get_valide() == true) {
            position_carte_in_main = i;
        }
    }
    return position_carte_in_main;
};
int Joueur::demand_attack_type_with_min_card(Carte* min_carte){
    // Set -> push all cards whose the same value with the min cards -> Possibility of attackal types likes: 1, 2, 3, 4
    m_main_joueur->set_carte_same_value(*min_carte);
    int number_of_same_value_cartes(1);
    for (int i(0); i < 13; i++) {
        if (m_main_joueur->get_carte_en_main()[i].get_value_carte() == min_carte->get_value_carte() && m_main_joueur->get_carte_en_main()[i].get_type_carte() != min_carte->get_type_carte()) {
            m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
            number_of_same_value_cartes++;
        }
    }
    // Set -> push all cards in the chains beginning from the min card
    m_main_joueur->set_carte_chaine(*min_carte);
    int number_of_carte_in_chain(1);
    int b_is_continue(true);
    bool b_is_found(false);
    while (b_is_continue) {
        b_is_found = false;
        for (int i(0); i < 13; i++) {
            if (m_main_joueur->get_carte_en_main()[i].get_value_carte() == min_carte->get_value_carte() + number_of_carte_in_chain) {
                m_main_joueur->set_carte_chaine(m_main_joueur->get_carte_en_main()[i]);
                number_of_carte_in_chain++;
                b_is_found = true;
                break;
            }
        }
        if (b_is_found) {
            b_is_continue = true;
        }else{
            b_is_continue = false;
        }
    }
    //
    if (number_of_same_value_cartes == 1) {
        cout << "Single card is valable, you can attack by taping 1 !" << endl;
    }else if (number_of_same_value_cartes == 2){
        cout << "Single card is valable, you can attack by taping 1 !"<< endl;
        cout << "Double card is valable, you can attack by taping 2 !"<< endl;
    }else if (number_of_same_value_cartes == 3){
        cout << "Single card is valable, you can attack by taping 1 !"<< endl;
        cout << "Double card is valable, you can attack by taping 2 !"<< endl;
        cout << "Triple card is valable, you can attack by taping 3 !"<< endl;
    }else if (number_of_same_value_cartes == 4){
        cout << "Single card is valable, you can attack by taping 1 !"<< endl;
        cout << "Double card is valable, you can attack by taping 2 !"<< endl;
        cout << "Triple card is valable, you can attack by taping 3 !"<< endl;
        cout << "Quad card is valable, you can attack by taping 4 !"<< endl;
    }
    if (number_of_carte_in_chain >= 3) {
        cout << "Chain card is valable, you can attack by taping 5! " << endl;
    }
    string player_choix("");
    cin >> player_choix;
    // Verify play's choice ok
    while (!test_int(player_choix) ||
           atoi(player_choix.c_str()) < 1 ||
           (atoi(player_choix.c_str()) < 5 && atoi(player_choix.c_str()) > number_of_same_value_cartes) ||
           (atoi(player_choix.c_str()) == 5 && number_of_carte_in_chain < 3) ||
           atoi(player_choix.c_str()) > 5){
        cout << "Please choose the valable attack: " << endl;
        cin >> player_choix;
    }
    return atoi(player_choix.c_str());
};
vector<Carte> Joueur::attack_with_min_card_and_type_attack(int type_attack){
    vector<Carte> attack_cards;
    switch (type_attack) {
        case 1:{
            // Attack single card - min card
            // Only one posibility
            // Set invalide min card on carte in main
            int position_min_carte_in_main = find_card_on_main(m_main_joueur->get_carte_same_value()[0]);
            m_main_joueur->get_carte_en_main()[position_min_carte_in_main].set_valide(false);
            //return attack card -> update carte cible
            attack_cards.push_back(m_main_joueur->get_carte_en_main()[position_min_carte_in_main]);
        }
            break;
        case 2:
        {
            cout << "You have these choices to attack double with the card min :" << endl;
            cout << "Press the number corresponding to the couple of cards you want to fight :" << endl;
            for (int i(1); i < m_main_joueur->get_carte_same_value().size(); i++) {
                cout << i << ". " << m_main_joueur->get_carte_same_value()[0].get_value_carte() << " - " << m_main_joueur->get_carte_same_value()[0].get_type_carte() << " and " << m_main_joueur->get_carte_same_value()[i].get_value_carte() << " - " << m_main_joueur->get_carte_same_value()[i].get_type_carte() << endl;
            }
            string choice("");
            cin >> choice;
            while (!test_int(choice) || atoi(choice.c_str()) < 1 || atoi(choice.c_str()) > m_main_joueur->get_carte_same_value().size()) {
                cout << "Please repress the number : " << endl;
                cin >> choice;
            }
            int choice_int = atoi(choice.c_str());
            int position_first_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[0]);
            m_main_joueur->get_carte_en_main()[position_first_carte].set_valide(false);
            attack_cards.push_back(m_main_joueur->get_carte_en_main()[position_first_carte]);
            int position_second_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[choice_int]);
            m_main_joueur->get_carte_en_main()[position_second_carte].set_valide(false);
            attack_cards.push_back(m_main_joueur->get_carte_en_main()[position_second_carte]);
        }
            break;
        case 3:
        {
            if (m_main_joueur->get_carte_same_value().size() == 3) {
                for (int i(0); i < 13; i++) {
                    if (m_main_joueur->get_carte_en_main()[i].get_value_carte() == m_main_joueur->get_carte_same_value()[0].get_value_carte()) {
                        m_main_joueur->get_carte_en_main()[i].set_valide(false);
                    }
                }
            }
            else {
                for (int i(1); i < 4; i++) {
                    cout << i << " . "<< m_main_joueur->get_carte_same_value()[i].get_value_carte() << " - "
                    << m_main_joueur->get_carte_same_value()[i].get_type_carte() << endl;
                }
                cout << "Please choose the two other card to fight triple card with the min card: " << endl;
                cout << "Please choose the first card :" << endl;
                string first_card("");
                while (!test_int(first_card) || atoi(first_card.c_str()) < 1 || atoi(first_card.c_str()) > 3) {
                    cout << "Please repress the number, lower than 3 and greater than 0 : " << endl;
                    cin >> first_card;
                }
                int first_card_int = atoi(first_card.c_str());
                cout << "Please choose the second card :" << endl;
                string seconde_card("");
                while (!test_int(seconde_card) || atoi(seconde_card.c_str()) < 1 || atoi(seconde_card.c_str()) > 3 || atoi(seconde_card.c_str()) == first_card_int) {
                    cout << "Please repress the number, lower than 3, greater than 0 and different from the first card : " << endl;
                    cin >> seconde_card;
                }
                int second_card_int = atoi(seconde_card.c_str());
                int position_min_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[0]);
                int position_first_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[first_card_int]);
                int position_second_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[second_card_int]);
                m_main_joueur->get_carte_en_main()[position_min_carte].set_valide(false);
                m_main_joueur->get_carte_en_main()[position_first_carte].set_valide(false);
                m_main_joueur->get_carte_en_main()[position_second_carte].set_valide(false);
                attack_cards.push_back(m_main_joueur->get_carte_en_main()[position_min_carte]);
                attack_cards.push_back(m_main_joueur->get_carte_en_main()[position_first_carte]);
                attack_cards.push_back(m_main_joueur->get_carte_en_main()[position_second_carte]);
            }
        }
            break;
        case 4:
        {
            for (int i(0); i < 13; i++) {
                if (m_main_joueur->get_carte_en_main()[i].get_value_carte() == m_main_joueur->get_carte_same_value()[0].get_value_carte()) {
                    m_main_joueur->get_carte_en_main()[i].set_valide(false);
                    attack_cards.push_back(m_main_joueur->get_carte_en_main()[i]);
                }
            }
        }
            break;
        case 5:
        {
            cout << "Please choose the number of cards you want to play : " << endl;
            string number_card;
            cin >> number_card;
            while (!test_int(number_card) || atoi(number_card.c_str()) < 3 || atoi(number_card.c_str()) > m_main_joueur->get_carte_chaine().size()) {
                cout << "Please choose the number of cards you want to play, greater than 2 and lower than " << m_main_joueur->get_carte_chaine().size() << endl;
                cin >> number_card;
            }
            int number_card_int = atoi(number_card.c_str());
            for (int i(0); i < number_card_int; i++) {
                int position_card_in_hand = find_card_on_main(m_main_joueur->get_carte_chaine()[i]);
                m_main_joueur->get_carte_en_main()[position_card_in_hand].set_valide(false);
                attack_cards.push_back(m_main_joueur->get_carte_en_main()[position_card_in_hand]);
            }
        }
            break;
    }
    return attack_cards;
};
bool Joueur::verify_possibility_contre_cible(Carte_cible* card_cible){
    bool is_capable_attack(false);
    Type_Attack type_attack = card_cible->get_type_attack();
    if (type_attack == attack_single) {
        for (int i(0); i < 13; i++) {
            if (m_main_joueur->get_carte_en_main()[i].get_value_carte() > card_cible->get_carte_cible()[0].get_value_carte()) {
                m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                is_capable_attack = true;
            }
            else if (m_main_joueur->get_carte_en_main()[i].get_value_carte() == card_cible->get_carte_cible()[0].get_value_carte()){
                if (m_main_joueur->get_carte_en_main()[i].get_type_carte() > card_cible->get_carte_cible()[0].get_type_carte()) {
                    m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                    is_capable_attack = true;
                }
            }
        }
    }
    else if (type_attack == attack_double){
        int position_to_compare(0);
        Type_of_Carte type_plus(Pique);
        (card_cible->get_carte_cible()[0].get_type_carte() > card_cible->get_carte_cible()[1].get_type_carte()) ? type_plus =
        card_cible->get_carte_cible()[0].get_type_carte() : type_plus = card_cible->get_carte_cible()[1].get_type_carte();
        while (position_to_compare < 12) {
            for (int i(12); i > (i - position_to_compare); i--) {
                if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() < card_cible->get_carte_cible()[0].get_value_carte()) {
                    break;
                }
                else if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() == m_main_joueur->get_carte_en_main()[i].get_value_carte() && m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() > card_cible->get_carte_cible()[0].get_value_carte()) {
                    m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[position_to_compare]);
                    m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                    is_capable_attack = true;
                }
                else if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() == card_cible->get_carte_cible()[0].get_value_carte() && m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() == m_main_joueur->get_carte_en_main()[i].get_value_carte()){
                    Type_of_Carte type_plus_in_hand(Pique);
                    (m_main_joueur->get_carte_en_main()[position_to_compare].get_type_carte() > m_main_joueur->get_carte_en_main()[i].get_type_carte()) ? type_plus_in_hand =
                    m_main_joueur->get_carte_en_main()[position_to_compare].get_type_carte() : type_plus_in_hand = m_main_joueur->get_carte_en_main()[i].get_type_carte();
                    if (type_plus < type_plus_in_hand) {
                        m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[position_to_compare]);
                        m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                        is_capable_attack = true;
                    }
                }
            }
            position_to_compare++;
        }
    }
    else if (type_attack == attack_trois) {
        int position_to_compare(0);
        while (position_to_compare < 9) {
            int counter_card_same_value(0);
            for (int i(12); i > (i - position_to_compare); i--) {
                if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() < card_cible->get_carte_cible()[0].get_value_carte()) {
                    break;
                }
                else {
                    m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                    counter_card_same_value++;
                    if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() == m_main_joueur->get_carte_en_main()[i].get_value_carte()) {
                        counter_card_same_value++;
                        m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                    }
                }
            }
            if (counter_card_same_value >= 3) {
                is_capable_attack = true;
            }
            else if (counter_card_same_value < 3){
                for (int i(0); i < counter_card_same_value; i++) {
                    m_main_joueur->get_carte_same_value().pop_back();
                }            }
            position_to_compare++;
        }
    }
    else if (type_attack == attack_quarte) {
        int position_to_compare(0);
        while (position_to_compare < 9) {
            int counter_card_same_value(0);
            for (int i(12); i > (i - position_to_compare); i--) {
                if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() < card_cible->get_carte_cible()[0].get_value_carte()) {
                    break;
                }
                else {
                    m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                    counter_card_same_value++;
                    if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() == m_main_joueur->get_carte_en_main()[i].get_value_carte()) {
                        counter_card_same_value++;
                        m_main_joueur->set_carte_same_value(m_main_joueur->get_carte_en_main()[i]);
                    }
                }
            }
            if (counter_card_same_value == 4) {
                is_capable_attack = true;
            }
            else if (counter_card_same_value != 4){
                for (int i(0); i < counter_card_same_value; i++) {
                    m_main_joueur->get_carte_same_value().pop_back();
                }
            }
            position_to_compare++;
        }
    }
    else if (type_attack == attack_plural){
        int number_card_in_serie = sizeof(card_cible->get_carte_cible())/sizeof(card_cible->get_carte_cible()[0]);
        Carte card_max_in_serie = card_cible->get_carte_cible()[number_card_in_serie-1];
        int position_to_compare(0);
        while (position_to_compare < 13) {
            int number_of_carte_in_chain(0);
            bool b_is_found(false);
            if (m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() <= card_max_in_serie.get_value_carte()) {
                position_to_compare++;
                break;
            }
            else {
                while (number_of_carte_in_chain <= number_card_in_serie) {
                    for (int i(0); i < 13; i++) {
                        if (m_main_joueur->get_carte_en_main()[i].get_value_carte() == m_main_joueur->get_carte_en_main()[position_to_compare].get_value_carte() - number_of_carte_in_chain) {
                            m_main_joueur->set_carte_chaine(m_main_joueur->get_carte_en_main()[i]);
                            b_is_found = true;
                            m_main_joueur->set_carte_chaine(m_main_joueur->get_carte_en_main()[i]);
                            break;
                        }
                    }
                    if (b_is_found == true) {
                        number_of_carte_in_chain++;
                    }
                    else {
                        for (int i(0); i < number_of_carte_in_chain; i++ ) {
                            m_main_joueur->get_carte_chaine().pop_back();
                        }
                        break;
                    }
                }
                if (number_of_carte_in_chain == number_card_in_serie) {
                    is_capable_attack = true;
                }

            }
        }
        
    }
    return is_capable_attack;
};
void Joueur::propose_demand_attack_contre_cible(Carte_cible* card_cible){
    Type_Attack type_attack_of_cible = card_cible->get_type_attack();
    string choice_string("");
    int choice_int(0);
    cout << "Do you want to attack ou ignore? Press 1 for ignore and 2 for attack :" << endl;
    cin >> choice_string;
    while (!test_int(choice_string) || atoi(choice_string.c_str()) < 1 || atoi(choice_string.c_str()) > 2) {
        cout << "Do you want to attack ou ignore? Press 1 for ignore and 2 for attack :" << endl;
        cin >> choice_string;
    }
    choice_int = atoi(choice_string.c_str());
    if (choice_int == 1) {
        ignore();
    }
    else {
        if (type_attack_of_cible == attack_single) {
            cout << "You have these options to attack the cible to choose, press the correspond number:" << endl;
            for (int i(0); i < m_main_joueur->get_carte_same_value().size(); i++) {
                cout << i << " . " << m_main_joueur->get_carte_same_value()[i].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i].get_type_carte() << endl;
            }
            string choice_card_string("");
            int choice_card_int(0);
            cin >> choice_card_string;
            while (!test_int(choice_card_string) || atoi(choice_card_string.c_str()) < 0 || atoi(choice_card_string.c_str()) > m_main_joueur->get_carte_same_value().size()-1) {
                cout << "You have to choose the number greater than 0 and lower than " << m_main_joueur->get_carte_same_value().size()-1 << endl;
                cin >> choice_card_string;
            }
            choice_card_int = atoi(choice_card_string.c_str());
            int position_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[choice_card_int]);
            m_main_joueur->get_carte_en_main()[position_carte].set_valide(false);
        }
        else if (type_attack_of_cible == attack_double) {
            cout << "You have these options to attack the cible to choose, press the correspond number:" << endl;
            for (int i(0); i < m_main_joueur->get_carte_same_value().size()-1; i=i+2) {
                cout << i/2 << " . " << m_main_joueur->get_carte_same_value()[i].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i].get_type_carte() << "and" << "  " << m_main_joueur->get_carte_same_value()[i+1].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i+1].get_type_carte() << endl;
            }
            string choice_card_string("");
            int choice_card_int(0);
            cin >> choice_card_string;
            while (!test_int(choice_card_string) || atoi(choice_card_string.c_str()) < 0 || atoi(choice_card_string.c_str()) > m_main_joueur->get_carte_same_value().size()/2) {
                cout << "You have to choose the number greater than 0 and lower than " << m_main_joueur->get_carte_same_value().size()-2 << endl;
                cin >> choice_card_string;
            }
            choice_card_int = atoi(choice_card_string.c_str());
            int position_first_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[choice_card_int*2]);
            m_main_joueur->get_carte_en_main()[position_first_carte].set_valide(false);
            int position_second_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[choice_card_int*2+1]);
            m_main_joueur->get_carte_en_main()[position_second_carte].set_valide(false);
        }
        else if (type_attack_of_cible == attack_trois) {
            cout << "You have these options to attack the cible to choose, press the correspond number:" << endl;
            for (int i(0); i < m_main_joueur->get_carte_same_value().size()-2; i=i+3) {
                cout << i/3 << " . " << m_main_joueur->get_carte_same_value()[i].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i].get_type_carte() << " and "  << m_main_joueur->get_carte_same_value()[i+1].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i+1].get_type_carte() << " and "<< m_main_joueur->get_carte_same_value()[i+2].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i+2].get_type_carte() << endl;
            }
            string choice_card_string("");
            int choice_card_int(0);
            cin >> choice_card_string;
            while (!test_int(choice_card_string) || atoi(choice_card_string.c_str()) < 0 || atoi(choice_card_string.c_str()) > m_main_joueur->get_carte_same_value().size()/3) {
                cout << "You have to choose the number greater than 0 and lower than " << m_main_joueur->get_carte_same_value().size()/3 << endl;
                cin >> choice_card_string;
            }
            choice_card_int = atoi(choice_card_string.c_str());
            for (int i(0); i < 3; i++) {
                int position_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[choice_card_int*3+i]);
                m_main_joueur->get_carte_en_main()[position_carte].set_valide(false);
            }
        }
        else if (type_attack_of_cible == attack_quarte) {
            cout << "You have these options to attack the cible to choose, press the correspond number:" << endl;
            for (int i(0); i < m_main_joueur->get_carte_same_value().size()-3; i=i+4) {
                cout << i/3 << " . " << m_main_joueur->get_carte_same_value()[i].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i].get_type_carte() << " and "  << m_main_joueur->get_carte_same_value()[i+1].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i+1].get_type_carte() << " and "<< m_main_joueur->get_carte_same_value()[i+2].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i+2].get_type_carte() << " and "<< m_main_joueur->get_carte_same_value()[i+3].get_value_carte() << "-" << m_main_joueur->get_carte_same_value()[i+3].get_type_carte() << endl;
            }
            string choice_card_string("");
            int choice_card_int(0);
            cin >> choice_card_string;
            while (!test_int(choice_card_string) || atoi(choice_card_string.c_str()) < 0 || atoi(choice_card_string.c_str()) > m_main_joueur->get_carte_same_value().size()/4) {
                cout << "You have to choose the number greater than 0 and lower than " << m_main_joueur->get_carte_same_value().size()/3 << endl;
                cin >> choice_card_string;
            }
            choice_card_int = atoi(choice_card_string.c_str());
            for (int i(0); i < 4; i++) {
                int position_carte = find_card_on_main(m_main_joueur->get_carte_same_value()[choice_card_int*4+i]);
                m_main_joueur->get_carte_en_main()[position_carte].set_valide(false);
            }
        }
        else if (type_attack_of_cible == attack_plural)
        {
            int number_card_in_serie = sizeof(card_cible->get_carte_cible())/sizeof(card_cible->get_carte_cible()[0]);
            
        }
    }
};

void Joueur::affichage(){
    cout << "It's a joueur !" << endl;
}























