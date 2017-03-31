//MAIN PARTIE 2

#include <iostream>
#include <fstream>

#include "conteneurGenesListe.h"
#include "conteneurGenesMap.h"
#include "conteneurGenes.h"

using namespace std;

int main()
{
	char c;
	ConteneurGenes* genes;
	
	// Le conteneur a deux implementations parmi lesquelles on choisit
	cout << "---  Voulez-vous utiliser la version liste (1) ou la version map (2) ? " << endl;
	do {
		cin.get(c);
	} while (c != '1' && c != '2');

	if (c == '1') {
		cout << "Utilisation de la version LISTE" << endl;
		genes = new ConteneurGenesListe();
	}
	//} else {
	//	cout << "Utilisation de la version MAP" << endl;
	//	genes = new ConteneurGenesMap();
	//}
	
	//	ouverture du fichier de donnees
	ifstream fichier;
	fichier.open("genes.txt");
	if (fichier.fail()) {
		cout << "Fichier non trouve !\n" << endl;
		return 1;
	}
	// Lecture des entrees de chaque gene
	string nom, description, espece, contenu, id;
	getline(fichier, id);
	while (!fichier.eof()) {
		getline(fichier,nom);
		getline(fichier,description);
		getline(fichier,espece);
		getline(fichier,contenu);
		genes->inserer(atoi(id.c_str()), nom, description, espece, contenu);
		getline(fichier,id);
	}
	fichier.close();

	

	cout << "----------------------------------------------------------" << endl;
	cout << "AFFICHAGE PAR ESPECE ET NOM\n" << endl;
	// !!!!  A FAIRE: afficher les g�nes par esp�ce et nom dans la sortie standard
	cout << "----------------------------------------------------------" << endl;
	cout << "RECHERCHE DU GENE 25107" << endl;
	// !!!! A FAIRE: rechercher et afficher le g�ne ayant l'ID 25107
	// Le programme doit afficher "Le g�ne 25107 n'a pas �t� trouv�" si le g�ne n'est pas trouv�
	

	cout << "----------------------------------------------------------" << endl;
	cout << "RETRAIT DU GENE 2290" << endl;
	// !!!! A FAIRE: retirer le g�ne 2290
	// Le programme doit afficher "Le g�ne a �t� retir�" si le retrait r�ussit, 
	// ou bien "Le g�ne 2290 n'a pas �t� trouv�" si le retrait �choue

	
	cout << "----------------------------------------------------------" << endl;
	cout << "RETRAIT DE L'ESPECE HOMO SAPIENS" << endl;
	// !!!! A FAIRE: retirer tous les g�nes de l'esp�ce Homo sapiens
	// Le programme doit afficher le nombre de g�nes retir�s ("Nombre de genes retires = XX")
	

	cout << "----------------------------------------------------------" << endl;
	cout << "RETRAIT DU GENE 552" << endl;

	// !!!! A FAIRE: retirer le g�ne 552
	// Le programme doit afficher "Le g�ne a �t� retir�" si le retrait r�ussit, 
	// ou bien "Le g�ne 552 n'a pas �t� trouv�" si le retrait �choue
	

	cout << "----------------------------------------------------------" << endl;
	cout << "MODIFICATION DU NOM DES GENES DE Mus musculus: Avpr1a-->XXXXX, Fmr1-->YYYYY et UwtA1-->ZZZZZ" << endl;
	// !!!! A FAIRE: modifier le nom des g�nes suivants pour l'esp�ce Mus musculus
	// G�ne Avpr1a --> nouveau nom = "XXXXX"
	// G�ne Fmr1 --> nouveau nom = "YYYYY"
	// G�ne UwtA1 --> nouveau nom = "ZZZZZ"
	// Le programme doit afficher le nombre de g�nes modifi�s ("Modification de XX nom(s) effectu�e")


	cout << "----------------------------------------------------------" << endl;
	cout << "AFFICHAGE PAR LONGEUR\n" << endl;
	map<string, string> m;
	m.insert(make_pair("Avpr1a", "XXXXX"));
	m.insert(make_pair("Fmr1", "YYYYY"));
	m.insert(make_pair("Uwta1", "ZZZZZ"));
	//{ "Avpr1a", "XXXXX", "Fmr1", "YYYYY", "Uwta1", "ZZZZZ" };
	cout << genes->modifierNoms("Mus musculus", m);
	// !!!! A FAIRE: afficher les g�nes par longueur

	// !!!! A FAIRE: N'OUBLIEZ PAS DE R�PONDRE AUX QUESTIONS DANS UN FICHIER TEXTE !!!!


	delete genes;

	return 0;
}
