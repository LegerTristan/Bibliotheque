#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include"Outils.h"
using namespace std;

//////////////////////////////////////
//Procédure qui permet de saisir les dimensions d'une matrice carrée.
//
//Entrée : Une constante n (nb)
//
//Sortie : L'entier nb qui possède la valeur de la constante n
//
/////////////////////////////////////

void Saisie(int &nb) {

	do {
		cout << "Veuillez saisir une dimension superieur a 0 pour votre matrice carree : ";
		cin >> nb;
	} while (nb <= 0);

}

//////////////////////////////////////
//Procédure qui permet de saisir les valeurs d'une matrice carrée pour un n donné.
//
//Entrée : La dimension de la matrice carrée nb1.
//
//Sortie : La matrice avec ses valeurs
//
/////////////////////////////////////

void Saisiemat(int nb1, int matrice[100][100]) {

	int i, j;

	for (i = 0; i < nb1; i = i + 1) {

		for (j = 0; j < nb1; j = j + 1) {

			cout << "\nEntrer la valeur de la case (" << i << ";" << j << "): ";
			cin >> matrice[i][j];
		}
	}

	cout << "Matrice saisie.";
	system("Pause");
}

//////////////////////////////////////
//Procédure qui permet d'afficher une matrice carrée de dimension n et de valeurs i, j prédéfini.
//
//Entrée : la dimension de la matrice carrée nb2 et la matrice
//
//Sortie : Affichage de la matrice
//
/////////////////////////////////////

void Affichemat(int nb2, int matrice[100][100]) {

	int avance;
	avance = 0;

	cout << "La matrice A que vous avez saisie est : \n";

	for (int i = 0; i < nb2; i++) {
		for (int j = 0; j < nb2; j++) {			// Tu fais afficher la matrice ligne par ligne. Donc pour  i = 1, tu affiches pour j = 1, j= 2 etc.
												// Le "avance" sert à placer la limite, c'est-à-dire de définir le retour à la ligne lorsque t'as fini i = 1 afin que cela ressemble à une matrice, quelque soit n.
			cout << matrice[i][j] << "\t";
			avance = avance + 1;

			if (avance == nb2) {
				cout << "\n";
				avance = 0;
			}
		}
	}
}

//////////////////////////////////////
//Procédure qui permet de transposer une matrice et d'afficher cette matrice carrée de dimension n et de valeurs i, j prédéfini.
//
//Entrée : la dimension de la matrice carrée nb2 et la matrice non-transposée
//
//Sortie : Affichage de la matrice transposée
//
/////////////////////////////////////

void Transmat(int nb3, int matrice[100][100]) {

	int avance;
	avance = 0;

	cout << "La matrice B (transposee de A) est : \n";

	for (int i = 0; i < nb3; i++) {
		for (int j = 0; j < nb3; j++) {

			cout << matrice[j][i] << "\t";
			avance = avance + 1;

			if (avance == nb3) {
				cout << "\n";
				avance = 0;
			}
		}
	}
}

//////////////////////////////////////
//Fonction qui permet de mettre les lettres d'un moment en majuscule
//
//Entrée : Le mot
//
//Sortie : Le mot en majuscule
//
/////////////////////////////////////

string maj(string mot) {

	int i;
	for (i = 0; i < int(mot.length()); i = i - 1) {
		if (mot[i] >= 'a' && mot[i] <= 'z')
		{
			mot[i] = mot[i] - 'a' + 'A';
		}
	}
	return mot;
}

//////////////////////////////////////
//Fonction qui permet de compter le nombre de voyelles dans un mot
//
//Entrée : Le mot
//
//Sortie : Le nombre de voyelles
//
/////////////////////////////////////

int nbrVoy(string mot) {

	int i, nbrvoy;
	nbrvoy = 0;

	for (i = 0; i < int(mot.length()); i = i + 1) {
		if ((mot[i] == 'a') || (mot[i] == 'e') || (mot[i] == 'i') || (mot[i] == 'o') || (mot[i] == 'u') || (mot[i] == 'A') || (mot[i] == 'E') || (mot[i] == 'I') || (mot[i] == 'O') || (mot[i] == 'U') || (mot[i] == 'Y')) {

			nbrvoy = nbrvoy + 1;
		}
	}
	return nbrvoy;
}

//////////////////////////////////////
//Procédure qui permet d'afficher les livres présents dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : La liste de livres présents dans la bibliothèque
//
/////////////////////////////////////

void Affili(Biblio uneBib)
{
	if (uneBib.nbrli == 0)
	{
		cout << "Il n'y a pas de livre dans la bibliotheque, veuillez d'abord saisir des livres avant d'affficher la bibliotheque" << endl << endl;
	}
	else
	{
		cout << "Voici les livres contenu dans notre bibliotheque :" << endl;
		for (int i(0); i < uneBib.nbrli; i++)
		{
			cout << "Le livre " << i + 1 << " est " << uneBib.tab[i].titre << " paru en " << uneBib.tab[i].année << " dont le genre est " << uneBib.tab[i].genre << endl;
		}
		cout << endl;
	}
}

//////////////////////////////////////
//Procédure qui permet d'ajouter des livres dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : La bibliothèque avec les livres ajoutés
//
/////////////////////////////////////

void Addli(Biblio &uneBib)
{
	string titre;
	int i(0);
	bool existe(true);
	bool valide(false);

	std::cout << "Saisir le titre du livre a ajouter : ";
	cin.ignore();
	getline(cin, titre);

	while (existe && (i <= uneBib.nbrli))
	{
		if (titre == uneBib.tab[i].titre)
		{
			existe = false;
		}
		i += 1;
	}
	if (!existe)
	{
		cout << "Le livre est deja present dans la bibliotheque " << endl;
	}
	else
	{
		uneBib.tab[uneBib.nbrli].titre = titre;   
		cout << "Saisir le nom de l'auteur : ";
		getline(cin, uneBib.tab[uneBib.nbrli].nom);
		cout << "Saisir l'annee de parution : ";
		cin >> uneBib.tab[uneBib.nbrli].année;
		cout << "Saisir le nombre de pages : ";
		cin >> uneBib.tab[uneBib.nbrli].nbrpage;

		do
		{
			cout << "Saisir le genre du livre : ";
			cin >> uneBib.tab[uneBib.nbrli].genre;


			unsigned int i = 0;
			while (!valide && i < uneBib.nbrgenre)
			{
				if (uneBib.tab[uneBib.nbrli].genre == uneBib.genres[i]) valide = true;
				++i;
			}

			if (!valide)
			{
				std::cout << "Le genre n'est pas valide" << std::endl;
			}

		} while (!valide);
		uneBib.nbrli = uneBib.nbrli + 1;
	}
	cout << endl;
}


//////////////////////////////////////
//Fonction qui permet de rechercher un livre dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : Le livre recherché et sa position
//
/////////////////////////////////////

int Searchli(Biblio uneBib)
{
	string titre;
	int i(0);
	bool existe(false);

	cout << "Saisir le titre du livre a chercher : ";
	cin.ignore();
	getline(cin, titre);

	while ((existe == false) && (i < uneBib.nbrli))
	{
		if (titre == uneBib.tab[i].titre)
		{
			existe = true;
		}
		i++;
	}
	if (existe == false)
	{
		cout << "Ce livre n'existe pas dans la bibliotheque\n\n";
	}
	else
	{
		cout << "Le livre se trouve a la position " << i << endl;
	}
	cout << endl;
	return i - 1;
}

//////////////////////////////////////
//Procédure qui permet de supprimer un livre dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : La biliothèque avec les livres supprimés
//
/////////////////////////////////////

void Suppli(Biblio &uneBib)
{
	string titre;
	int j;

	for (j = Searchli(uneBib); j < uneBib.nbrli; j++) {

		uneBib.tab[j] = uneBib.tab[j + 1];
		uneBib.nbrli = uneBib.nbrli - 1;

		cout << "Le livre a bien ete supprime." << endl;
	}
}

//////////////////////////////////////
//Procédure qui permet d'ajouter un genre de livre à la liste
//
//Entrée : La bibliothèque
//
//Sortie : La biliothèque avec les genres de livres ajoutés
//
/////////////////////////////////////

void Addg(Biblio &uneBib)
{
	string titre;
	string choix("p");

	cout << "La liste des genres existant deja est :\n" << endl;
	for (int j = 0; j < uneBib.nbrgenre; j++)
	{

		cout << uneBib.genres[j] << " ";
	}
	do {
		cout << "\nSouhaitez-vous ajouter un nouveau genre ? (o/n)";
		cin >> choix;
		if (choix == "o")
		{
			cout << "Ajoutez un nouveau genre : ";
			cin.ignore();
			getline(cin, uneBib.genres[uneBib.nbrgenre]);
			++uneBib.nbrgenre;
			cout << "\nGenre saisi.";
		}
	} while (choix != "n");

}

//////////////////////////////////////
//Procédure qui permet d'afficher la liste des censures présentes dans la bibliothèque
//
//Entrée : La biliothèque
//
//Sortie : La liste des censures présentes dans la bibliothèque
//
/////////////////////////////////////

void Affic(Biblio &uneBib) {


	if (uneBib.nbrcensure == 0)
	{
		cout << "Il n'y a pas de censure dans la bibliotheque, veuillez d'abord saisir des censures avant de les afficher " << endl << endl;
	}
	else
	{
		cout << "Voici les différentes censures enregistrées dans la  bibliotheque :" << endl;
		for (int i(0); i < uneBib.nbrcensure; i++)
		{
			cout << "La censure n" << i + 1 << " est " << uneBib.censures[i] << endl;
		}
		cout << endl;
	}
}

//////////////////////////////////////
//Procédure qui permet d'ajouter des censures
//
//Entrée : Les censures existantes
//
//Sortie : Les nouvelles censures ajoutées
//
/////////////////////////////////////

void Addc(Biblio &uneBib)
	{
		string censure;
		string choix("p");

		cout << "La liste des censures existant deja est :\n" << endl;
		for (int j = 0; j < uneBib.nbrcensure; j++)
		{

			cout << uneBib.censures[j] << " ";
		}
		do {
			cout << "\nSouhaitez-vous ajouter une nouvelle censure ? (o/n)";
			cin >> choix;
			if (choix == "o")
			{
				cout << "Ajoutez une nouvelle censure : ";
				cin.ignore();
				getline(cin, uneBib.censures[uneBib.nbrcensure]);
				++uneBib.nbrcensure;
				cout << "\nCensure saisi.";
			}
		} while (choix != "n");
}

//////////////////////////////////////
//Procédure qui permet d'afficher le menu de gestion des livres
//
//Entrée : Rien
//
//Sortie : Le menu de gestion des livres et ses différents choix
//
/////////////////////////////////////

void Menuli(Biblio &uneBib){

	int choix;

	do {
		system("cls");
		cout << "\t\tBienvenue dans le gestionnaire des livres \n\n \t\t\t1- Afficher la liste des livres dans la bibliotheque\n\n \t\t\t2- Ajouter un livre\n\n \t\t\t3- Rechercher un livre\n\n \t\t\t4- Supprimer un livre\n\n   \t\t\t5- Noter un livre\n\n \t\t\t6- Revenir au menu precedent\n\n";
		cout << "\t\t\t Choix : ";
		cin >> choix;

		switch (choix) {

		case 1: Affili(uneBib);
			system("Pause");
			system("cls");
			break;

		case 2: Addli(uneBib);
			system("Pause");
			system("cls");
			break;

		case 3: Searchli(uneBib);
			system("Pause");
			system("cls");
			break;

		case 4: Suppli(uneBib);
			system("Pause");
			system("cls");
			break;

		case 5: //cout << "Au revoir" << endl;
			system("Pause");
			system("cls");
			break;

		case 6:
			break;

		default: cout << "Erreur" << endl;
			system("Pause");
			system("cls");
			break;
		}
	} while ((choix != 6));
}

//////////////////////////////////////
//Procédure qui permet d'afficher le menu de gestion des auteurs
//
//Entrée : Rien
//
//Sortie : Le menu de gestion des auteurs et ses différents choix
//
/////////////////////////////////////

void Menuau(Biblio &uneBib) {

	int choix;

	do {
		system("cls");
		cout << "\t\tBienvenue dans le gestionnaire des auteurs \n\n \t\t\t1- Afficher la liste des livres dans la bibliotheque\n\n \t\t\t2- Ajouter un livre\n\n \t\t\t3- Rechercher un livre\n\n \t\t\t4- Supprimer un livre\n\n   \t\t\t5- Noter un livre\n\n \t\t\t6- Revenir au menu precedent\n\n";
		cout << "\t\t\t Choix : ";
		cin >> choix;

		switch (choix) {

		case 1: Affili(uneBib);
			system("Pause");
			system("cls");
			break;

		case 2: Addli(uneBib);
			system("Pause");
			system("cls");
			break;

		case 3: Searchli(uneBib);
			system("Pause");
			system("cls");
			break;

		case 4: Suppli(uneBib);
			system("Pause");
			system("cls");
			break;

		case 5: //cout << "Au revoir" << endl;
			system("Pause");
			system("cls");
			break;

		case 6: 
			break;

		default: cout << "Erreur" << endl;
			system("Pause");
			system("cls");
			break;
		}
	} while ((choix != 6));
}

//////////////////////////////////////
//Procédure qui permet d'afficher le menu de gestion des censures
//
//Entrée : Rien
//
//Sortie : Le menu de gestion des censures et ses différents choix
//
/////////////////////////////////////

void Menuce(Biblio &uneBib) {

	int choix;

	do {
		system("cls");
		cout << "\t\tBienvenue dans le gestionnaire des censures \n\n \t\t\t1- Afficher la liste des censures\n\n \t\t\t2- Ajouter une censure\n\n \t\t\t3- Supprimer une censure\n\n \t\t\t4- Verifier la censure de tout les livres\n\n \t\t\t5- Revenir au menu precedent\n\n";
		cout << "\t\t\t Choix : ";
		cin >> choix;

		switch (choix) {

		case 1: Affic(uneBib);
			system("Pause");
			system("cls");
			break;

		case 2: Addc(uneBib);
			system("Pause");
			system("cls");
			break;

		case 3: Suppc(uneBib);
			system("Pause");
			system("cls");
			break;

		case 4: //Suppli(uneBib);
			system("Pause");
			system("cls");
			break;

		case 5: 
			break;

		default: cout << "Erreur" << endl;
			system("cls");
			system("Pause");
			break;
		}
	} while ((choix != 5));
}

//////////////////////////////////////
//Procédure qui permet d'afficher le menu de gestion des genres
//
//Entrée : Rien
//
//Sortie : Le menu de gestion des genres et ses différents choix
//
/////////////////////////////////////

void Menuge(Biblio &uneBib) {

	int choix;

	do {
		system("cls");
		cout << "\t\tBienvenue dans le gestionnaire des genres\n\n \t\t\t1- Afficher tout les genres\n\n \t\t\t2- Ajouter un genre\n\n \t\t\t3- Supprimer un genre\n\n \t\t\t4- Trier selon votre genre de livre\n\n \t\t\t5- Revenir au menu precedent\n\n";
		cout << "\t\t\t Choix : ";
		cin >> choix;

		switch (choix) {


		case 1: Affig(uneBib);
			system("Pause");
			system("cls");
			break;

		case 2: Addg(uneBib);
			system("Pause");
			system("cls");
			break;

		case 3: Suppg(uneBib);
			system("Pause");
			system("cls");
			break;

		case 4: Sortg(uneBib);
			system("Pause");
			system("cls");
			break;

		case 5: 
			break;

		default: cout << "Erreur" << endl;
			system("Pause");
			system("cls");
			break;
		}
	} while ((choix != 5));
}

//////////////////////////////////////
//Procédure qui permet de supprimer un genre dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : La biliothèque avec les genres supprimés
//
/////////////////////////////////////

void Suppg(Biblio &uneBib)
{
	string gnr;
	int j;

	for (j = Searchg(uneBib); j < uneBib.nbrgenre; j++) {

		uneBib.genres[j] = uneBib.genres[j + 1];
	}
	if (j == uneBib.nbrgenre) {
		uneBib.nbrgenre = uneBib.nbrgenre - 1;
		cout << "Le genre a bien ete supprime." << endl;
	}
}

//////////////////////////////////////
//Fonction qui recherche un genre dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : Le genre en question
//
/////////////////////////////////////

int Searchg(Biblio &uneBib)
{
	char rep;
	string gnr;
	bool existe;
	int i;

	do {
		existe = false;
		i = 0;
		rep = 'n';
		cout << "Saisir le genre a chercher (saisir \"sortir\" pour sortir): ";
		cin.ignore();
		getline(cin, gnr);

		if (gnr != "sortir") {
			while ((existe == false) && (i < uneBib.nbrgenre))
			{
				if (gnr == uneBib.genres[i])
				{
					existe = true;
				}
				i++;
			}
			if (existe == false)
			{
				cout << "Ce genre n'existe pas dans la bibliotheque\n\n";
			}
			else
			{
				cout << "Le genre se trouve a la position " << i << endl;
				cout << "Etes-vous sur de vouloir supprimer ce genre ? (o/n)\n";
				cin >> rep;
			}
			cout << endl;
		}
		else {

			cout << "Sortie de la procedure." << endl;
			rep = 'o';
			i = 1000;
		}
	} while (rep == 'n');
	return i - 1;
}

//////////////////////////////////////
//Procédure qui permet d'afficher les genres présents dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : La liste des genres présentes dans la bibliothèque
//
/////////////////////////////////////
void Affig(Biblio &uneBib) {


	if (uneBib.nbrgenre == 0)
	{
		cout << "Il n'y a pas de genre dans la bibliotheque, veuillez d'abord saisir des genres avant de les afficher" << endl << endl;
	}
	else
	{
		cout << "Voici les differents genres enregistres dans la  bibliotheque :" << endl;
		for (int i(0); i < uneBib.nbrgenre; i++)
		{
			cout << "Le genre n" << i + 1 << " est " << uneBib.genres[i] << endl;
		}
		cout << endl;
	}
}

//////////////////////////////////////
//Procédure qui permet de supprimer une censure dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : La biliothèque avec les censures supprimées
//
/////////////////////////////////////

void Suppc(Biblio &uneBib)
{
	string cns;
	int j;

	for (j = Searchc(uneBib); j < uneBib.nbrcensure; j++) {

		uneBib.censures[j] = uneBib.censures[j + 1];
	}
	if (j == uneBib.nbrcensure) {
		uneBib.nbrcensure = uneBib.nbrcensure - 1;
		cout << "La censure a bien ete supprime." << endl;
	}
}

//////////////////////////////////////
//Fonction qui recherche une censure dans la bibliothèque
//
//Entrée : La bibliothèque
//
//Sortie : La censure en question
//
/////////////////////////////////////

int Searchc(Biblio &uneBib)
{
	char rep;
	string cns;
	bool existe;
	int i;

	do {
		existe = false;
		i = 0;
		rep = 'n';
		cout << "Saisir la censure a chercher (saisir \"sortir\" pour sortir): ";
		cin.ignore();
		getline(cin, cns);

		if (cns != "sortir") {
			while ((existe == false) && (i < uneBib.nbrcensure))
			{
				if (cns == uneBib.censures[i])
				{
					existe = true;
				}
				i++;
			}
			if (existe == false)
			{
				cout << "Cette censure n'existe pas dans la bibliotheque\n\n";
			}
			else
			{
				cout << "La censure se trouve a la position " << i << endl;
				cout << "Etes-vous sur de vouloir supprimer cette censure ? (o/n)\n";
				cin >> rep;
			}
			cout << endl;
		}
		else {

			cout << "Sortie de la procedure." << endl;
			rep = 'o';
			i = 1000;
		}
	} while (rep == 'n');
	return i - 1;
}

//////////////////////////////////////
//Procédure qui permet de trier la bibliothèque selon le genre d'un livre et par ordre alphabtéique ensuite
//
//Entrée : La bibliothèque
//
//Sortie : La bibliothèque triée selon le genre du livre.
//
/////////////////////////////////////

void Sortg(Biblio &uneBib) {

	Livre  temp, tempo;
	string  gnr;
	int k, nbrfav, c, reste;
	int car, compa, i;
	bool find, trouver;

	cout << "Par quelle genre voulez-vous classez ? ";
	cin >> gnr;

	k = 0;
	nbrfav = 0;
	find = false;
	trouver = false;

	for (i = 0; i < uneBib.nbrli; ++i) {

		if (uneBib.tab[i].genre == gnr) {

			temp = uneBib.tab[k];
			uneBib.tab[k] = uneBib.tab[i];
			uneBib.tab[i] = temp;
			++k;
			++nbrfav;
		}
	}

	reste = uneBib.nbrli - nbrfav;
	nbrfav--;

	do {

		for (int j = 1; j <= nbrfav; ++j) {

			do {

				int p = int(uneBib.tab[j].titre.length());

				for (c = 0; c < p; ++c) {

					car = uneBib.tab[j].titre[c];
					compa = uneBib.tab[j - 1].titre[c];

					if (car < compa) {

						tempo = uneBib.tab[j];
						uneBib.tab[j] = uneBib.tab[j - 1];
						uneBib.tab[j - 1] = tempo;
						find = true;
					}

					if ((!find) && (c <= int(uneBib.tab[j].titre.length())) && (c <= int(uneBib.tab[j - 1].titre.length()))) {

						find = true;

					}
				}
			} while ((!find) && (c <= int(uneBib.tab[j].titre.length())) && (c <= int(uneBib.tab[j - 1].titre.length())));
		}
		nbrfav--;
	} while (nbrfav != 0);

	nbrfav = uneBib.nbrli - reste;

	do {

		for (int l = nbrfav + 1; l <= uneBib.nbrli; ++l) {

			do {

				cout << "test2";

				int p = int(uneBib.tab[l].titre.length());

				for (c = 0; c < p; ++c) {
					cout << "test3";

					car = uneBib.tab[l].titre[c];
					compa = uneBib.tab[l - 1].titre[c];

					cout << car;
					cout << compa;

					cout << "test4";

					if (car < compa) {

						tempo = uneBib.tab[l];
						uneBib.tab[l] = uneBib.tab[l - 1];
						uneBib.tab[l - 1] = tempo;
						trouver = true;

					}

					if ((!trouver) && (c <= int(uneBib.tab[l].titre.length())) && (c <= int(uneBib.tab[l - 1].titre.length()))) {

						trouver = true;

					}
				}
			} while ((!trouver) && (c <= int(uneBib.tab[l].titre.length())) && (c <= int(uneBib.tab[l - 1].titre.length())));
		}
		reste--;
	} while (reste != 0);
	system("Pause");
	cout << "Rangement fini" << endl;
}


//////////////////////////////////////
//Procédure qui permet d'afficher le menu de gestion de la sauvegarde
//
//Entrée : Rien
//
//Sortie : Le menu de gestion de la sauvegarde et ses différentes choix
//
/////////////////////////////////////

void Menusa(Biblio &uneBib, FILE* fic) {

	int choix;

	do {
		system("cls");
		cout << "\t\t=== Bienvenue dans le gestionnaire de la sauvegarde ===\n\n \t\t\t1- Sauvegarder\n\n \t\t\t2- Charger la sauvegarde\n\n \t\t\t3- Supprimer la sauvegarde\n\n  \t\t\t4- Revenir au menu precedent\n\n";
		cout << "\t\t\t Choix : ";
		cin >> choix;

		switch (choix) {


		case 1: Save(uneBib, fic);
			system("Pause");
			system("cls");
			break;

		case 2: Load(uneBib, fic);
			system("Pause");
			system("cls");
			break;

		case 3: Erase(uneBib, fic);
			system("Pause");
			system("cls");
			break;

		case 4:
			break;

		default: cout << "Erreur" << endl;
			system("Pause");
			system("cls");
			break;
		}
	} while ((choix != 4));
}

//////////////////////////////////////
//Procédure qui permet de sauvegarder les données du programme
//
//Entrée : Le programme non sauvegardée
//
//Sortie : Le programme sauvegardée
//
/////////////////////////////////////

void Save(Biblio &uneBib, FILE* fic) {

	char choix;

	choix = 'p';

		cout << "Souhaitez-vous sauvegarder vos donnees (o/n) ?\n";
		cin >> choix;

		if (choix == 'o') {
			cout << "Sauvegarde en cours...\n";

			fic = fopen("dossier/save.txt", "w+");

			if (fic != NULL) {

				fprintf(fic, "liste des livres : %d ", uneBib.nbrli);

				for (int i = 0; i < uneBib.nbrli; ++i) {

					for (int j = 0; j < uneBib.tab[i].titre.length(); ++j) {

						fprintf(fic, "%c ", uneBib.tab[i].titre[j]);

					}
					for (int j = 0; j < uneBib.tab[i].nom.length(); ++j) {

						fprintf(fic, "%c ", uneBib.tab[i].nom[j]);

					}
					fprintf(fic, " %d ", uneBib.tab[i].année);
					fprintf(fic, " %d ", uneBib.tab[i].nbrpage);
					for (int j = 0; j < uneBib.tab[i].genre.length(); ++j) {

						fprintf(fic, "%c", uneBib.tab[i].genre[j]);

					}
					fprintf(fic, "\n");

				}

				fprintf(fic, " liste des genres : %d ", uneBib.nbrgenre);

				for (int i = 0; i < uneBib.nbrgenre; ++i) {

					for (int j = 0; j < uneBib.genres[i].length(); ++j) {

						fprintf(fic, "%c", uneBib.genres[i][j]);
						fprintf(fic, " ");

					}

				}

				fprintf(fic,  " liste des censures : %d ", uneBib.nbrcensure);

				for (int i = 0; i < uneBib.nbrcensure; ++i) {

					for (int j = 0; j < uneBib.censures[i].length(); ++j) {

						fprintf(fic, "%c", uneBib.censures[i][j]);
						fprintf(fic, " ");

					}

				}

				cout << "Sauvegarde terminee !" << endl;
				fclose(fic);
			}
		else {

			cout << "Impossible d'ouvrir le fichier de sauvegarde des données.";

		}
	}
}


//////////////////////////////////////
//Procédure qui permet de charger la sauvegarde
//
//Entrée : Le programme avec des données quelconques
//
//Sortie : Le programme avec la sauvegarde chargée
//
/////////////////////////////////////

void Load(Biblio &uneBib, FILE* fic) {

	char choix;
	int i, j;
	char txtlu[100];

	choix = 'p';
	i = 0;
	j = 0;

	cout << "Souhaitez-vous charger vos donnees sauvegardees (o/n) ?\n";
	cin >> choix;

	if (choix == 'o') {
		cout << "Chargement...\n";

		fic = fopen("dossier/save.txt", "r");

		if (fic != NULL) {

			fseek(fic, 19, SEEK_SET);
			fscanf(fic, "%d", &uneBib.nbrli);
			fseek(fic, 1, SEEK_CUR);
			while ( i < uneBib.nbrli){

				fscanf(fic, "%s", txtlu);
				uneBib.tab[i].titre = txtlu;
				cout << txtlu << endl;;

				fscanf(fic, "%s", txtlu);
				uneBib.tab[i].nom = txtlu;
				cout << txtlu << endl;

				cout << ftell(fic) << endl;
				fscanf(fic, "%d", &uneBib.tab[i].année);
				cout << ftell(fic) << endl;
				fscanf(fic, "%d", &uneBib.tab[i].nbrpage);
				cout << ftell(fic) << endl;

				fscanf(fic, "%s", txtlu);
				uneBib.tab[i].genre = txtlu;
				cout << txtlu << endl;

				cout << uneBib.tab[i].titre << endl;
				cout << uneBib.tab[i].nom << endl;
				cout << uneBib.tab[i].année << endl;
				cout << uneBib.tab[i].nbrpage << endl;
				cout << uneBib.tab[i].genre << endl;

				i++;
			}

				
			
			cout << "\n" << uneBib.nbrli << endl;


			cout << "Chargement terminee !" << endl;
			fclose(fic);
		}
		else {

			cout << "Impossible d'ouvrir le fichier de sauvegarde des données.";

		}
	}
}

//////////////////////////////////////
//Procédure qui permet d'effacer les données de sauvegardes
//
//Entrée : La sauvegarde
//
//Sortie : Rien
//
/////////////////////////////////////

void Erase(Biblio &uneBib, FILE* fic) {

	char choix;

	choix = 'p';

	cout << "Etes-vous sur de vouloir supprimer votre sauvegarde ? (o/n) ?\n";
	cin >> choix;

	if (choix == 'o') {
		cout << "Effacement en cours...\n";

		fic = fopen("dossier/save.txt", "w+");

		if (fic != NULL) {

			cout << "Effacement terminee !" << endl;
			fclose(fic);

		}
		else {

			cout << "Impossible d'ouvrir le fichier de sauvegarde des données.";

		}
	}
}

//////////////////////////////////////
//Procédure qui permet de vérifier que le nom d'un titre, d'un auteur, d'un genre n'est pas une censure.
//
//Entrée : Le mot saisi
//
//Sortie : La vérification du mot
//
/////////////////////////////////////

 /*void Verifc(Biblio &uneBib) {

	 string mot;
	 bool verif;
	 int i;

	 cin.ignore();
	 getline(cin, uneBib.censure);
	 verif = false;

	 do {
		 for (i = 0; i < uneBib.nbrcensure - 1; ++i) {

			 if (mot == uneBib.censures[i]) {

				 verif = true;
				 cout << "Ce mot est censure ! ";

			 }
		 }
	 } while (!verif && i < uneBib.nbrcensure - 1);

	 return &uneBib.censure;
	 return verif;
}*/

/* void Addli(Biblio &uneBib)
 {
	 string mot;
	 int i(0);
	 bool existe(true);
	 bool valide(false);

	 cout << "Saisir le titre du livre a ajouter : ";
	 Verifc(uneBib);


	 while (existe && (i <= uneBib.nbrli))
	 {
		 if (mot == uneBib.tab[i].titre)
		 {
			 existe = false;
		 }
		 i += 1;
	 }
	 if (!existe)
	 {
		 cout << "Le livre est deja present dans la bibliotheque " << endl;
	 }
	 else
	 {
		 uneBib.tab[uneBib.nbrli].titre = mot;
		 cout << "Saisir le nom de l'auteur : ";
		 Verifc(uneBib);
		 uneBib.tab[uneBib.nbrli].nom = mot;
		 cout << "Saisir l'annee de parution : ";
		 cin >> uneBib.tab[uneBib.nbrli].année;
		 cout << "Saisir le nombre de pages : ";
		 cin >> uneBib.tab[uneBib.nbrli].nbrpage;

		 do
		 {
			 string userGenre;
			 cout << "Saisir le genre du livre : ";
			 Verifc(uneBib);
			 uneBib.tab[uneBib.nbrli].genre = mot;


			 unsigned int i = 0;
			 while (!valide && i < uneBib.nbrgenre)
			 {
				 if (userGenre == uneBib.genres[i]) valide = true;
				 uneBib.tab[uneBib.nbrli].genre = userGenre;
				 ++i;
			 }

			 if (!valide)
			 {
				 std::cout << "Le genre n'est pas valide" << std::endl;
			 }

		 } while (!valide);
		 uneBib.nbrli = uneBib.nbrli + 1;
	 }
	 cout << endl;
 }*/