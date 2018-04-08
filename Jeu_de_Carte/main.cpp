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
	// Begin
	cout << "Bienvenue à Jeu De Carte TIENLEN Vietnam !" << endl;
	cout << "Hey, tu t'appelles comment? " << endl;
	string nom_de_joeur("");
	cin >> nom_de_joeur ;
	int nombre_de_joeurs_virtuels(0);
	cout << "Ok, " << nom_de_joeur << ", Tu veux combien de joueur avec toi, souviens-toi que tu auras maximum 3 jolies joueurs !" << endl;
	cin >> nombre_de_joeurs_virtuels;
	while (!cin || nombre_de_joeurs_virtuels < 1 ||  nombre_de_joeurs_virtuels >3 ){
		// user didn't input a number
		cin.clear(); // reset failbit
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
		cout << "T'es sur que tu as remplis un chiffre de 1 à 3, :D, essayes encore une fois " << endl;
		cin >> nombre_de_joeurs_virtuels;
	}
	cout << "Ok, " << nom_de_joeur << ", Tu as bien "<< nombre_de_joeurs_virtuels << " jolie joueurs avec toi! " << endl;
	Match match = Match(nombre_de_joeurs_virtuels);
	cout << "Ok, " << nom_de_joeur << ", T'es prêt pour recevoir les carte, vois-ci tes carte, 13 cartes ! " << endl;
	Match
//
//    Match* match = new Match();
//    int number_joueur = (*match).determine_joueur();
//    Match match;
//    int number_joueur = match.determine_joueur();
//    cout << "number: " << number_joueur<< endl;
//    int number_joueur = 4;
//    Jeu_de_Carte jeu;
//    jeu.set_carte();
//    jeu.distribuer_carte(number_joueur);
	
    return 0;
}


