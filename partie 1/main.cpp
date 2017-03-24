//MAIN PARTIE 1

#include <iostream>
#include <string>
#include "Pile.h"

using namespace std;

int main()
{
    string taches[7] = {"MENAGE", "ETUDE", "EPICERIE", "SPORT", "BENEVOLAT", "LECTURE", "AUTRE"};
    double durees[7] = {1.2, 3.5, 0.8, 2.5, 1.8, 0.75, 10};
    
    // Creer une pile de type "paires STL de (string, double)"
	Pile<pair<string, double> > pile(6);

    cout << "Empilage des taches..." << endl;
    // Ajouter les 7 paires correspondant aux t�ches et dur�es ci-haut sur la pile.
    // Vous pouvez ici utiliser une boucle for standard de i = 0 � 7
    // Le programme doit afficher: "Tache ajoutee sur la pile: [nom de la t�che] d'une duree de [dur�e]"
    //                         ou: "La pile est pleine!"
    //                         selon le succ�s ou non de l'ajout.	
	for (int i = 0; i < 7; i++) {
		if (pile.empiler(make_pair(taches[i], durees[i])))
		{
			cout << "Tache ajoutee sur la pile: " << taches[i] << " d'une duree de " << durees[i] << endl;
		}
		else 
		{
			cout << "La pile est pleine!" << endl;
		}
	}

    cout << "Depilage des taches..." << endl;
    // Retirer les 7 paires de (t�che,dur�e) de la pile, ***en assumant que vous ne connaissez pas le nombre d'�l�ments dans la pile***
    // (utilisez le bool�en retourn� par la fonction depiler())
    // Le programme doit afficher: "Depilage de la tache: [nom de la t�che] d'une duree de [dur�e]"
    //                         ou: "La pile est vide!"
    //                         selon le cas.
	for (int i = pile.obtenirTaille(); i >= 0; i--) {
		if (!pile.estVide()) {
			 pair<string,double> jacques = *pile.obtenirSommet();
			 string paul = jacques.first;
			//cout << "Depilage de la tache " << pile.obtenirSommet().first;//<< "d'une duree de " << pile.obtenirSommet()->second << endl;
			pile.depiler();
		}
		else
			cout << "La pile est vide" << endl;
	}
    


    system("pause");

	return 0;
}