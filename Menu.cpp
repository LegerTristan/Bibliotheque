#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include"Outils.h"
using namespace std;

//////////////////////////////////////////////
//
//		Dernier délai : 16 janvier 2019		//
//
//////////////////////////////////////////////

int main() {

	Biblio maBib;
	int choix;

	FILE* fichier = NULL;

	maBib.nbrli = 0;
	maBib.nbrgenre = 4;
	maBib.nbrcensure = 8;

		do {
			system("cls");
			cout << "\t\t\t=== Bienvenue dans la bibliotheque ===\n\n \t\t\t1- Gestion des livres \n\n \t\t\t2- Gestion des auteurs\n\n \t\t\t3- Gestion des genres\n\n \t\t\t4- Gestion des censures\n\n \t\t\t5- Gestion de la sauvegarde \n\n \t\t\t6- Quitter\n\n";
			cout << "\t\t\t Choix : ";
			cin >> choix;

			switch (choix) {

			case 1: Menuli(maBib);
				break;

			case 2: Menuau(maBib);
				break;

			case 3: Menuge(maBib);
				break;

			case 4: Menuce(maBib);
				break;

			case 5: Menusa(maBib, fichier);
				break;

			case 6: cout << "Au revoir !" << endl;
				system("Pause");
				break;

			default: cout << "Erreur" << endl;
				system("Pause");
				break;
			}
		} while ((choix != 6));

	return 0;
}
