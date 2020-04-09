#ifndef OUTILS_H
#define OUTILS_H
#include<iostream>
#include<string>
using namespace std;

int const MAX = 100;

struct Livre {
	string titre;
	string nom;
	string genre;
	int année;
	int nbrpage;
};


struct Biblio {
	Livre tab[MAX];
	int nbrli;
	int nbrgenre;
	int nbrcensure;
	string censures[101] = { "con", "merde", "salope", "pute", "connard", "connasse", "putain", "conne"};
	string genres[101] = { "roman", "science-fiction", "policier", "horreur" };
	string censure;
};


void Saisie(int &nb);
void Saisiemat(int nb1, int matrice[100][100]);
void Affichemat(int nb2, int matrice[100][100]);
void Transmat(int nb3, int matrice[100][100]);
int nbrVoy(string mot);
string maj(string mot);
void Affili(Biblio uneBib);
void Addli(Biblio &uneBib);
int Searchli(Biblio uneBib);
void Suppli(Biblio &uneBib);
void Affig(Biblio &uneBib);
void Addg(Biblio &uneBib);
void Suppg(Biblio &uneBib);
void Sortg(Biblio &uneBib);
void Suppc(Biblio &uneBib);
void Affic(Biblio &uneBib);
void Addc(Biblio &uneBib);
void Menuli(Biblio &uneBib);
void Menuau(Biblio &uneBib);
void Menuce(Biblio &uneBib);
void Menuge(Biblio &uneBib);
void Menusa(Biblio &uneBib, FILE* fic);
int Searchg(Biblio &uneBib);
int Searchc(Biblio &uneBib);
void Save(Biblio &uneBib, FILE* fic);
void Load(Biblio &uneBib, FILE* fic);
void Erase(Biblio &uneBib, FILE* fic);
//void Verifc(Biblio &uneBib);
#endif

