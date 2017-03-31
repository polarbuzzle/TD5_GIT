/*!
* \file		Foncteur.h
* \author	Jean-Frederic Fontaine
*			Samuel Ferron
* \date		2017-03-23
* \brief	Fichier header de la classe conteneur gene
*/
#pragma once
#include "conteneurGenes.h"
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>
#include "Gene.h"
#include "Foncteur.h"
#include <vector>
using namespace std;




class ConteneurGenesMap : public ConteneurGenes
{	
public:
	//Constructeur par defaut 
	ConteneurGenesMap();
	//Destructeur
	virtual ~ConteneurGenesMap();

	//Fonctions d'acces et de mofifications
	virtual void inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu);
	
	virtual Gene* trouver(unsigned int id) const;
	virtual bool retirer(unsigned int id);
	virtual unsigned int retirerEspece(const string &espece);
	virtual void vider();

	virtual void afficherParEspeceEtNom(ostream& out) const;
	virtual void afficherParLongueur(ostream& out) const;
	virtual void afficherEspece(const string &espece, ostream& out) const;
	virtual unsigned int modifierNoms(const string &espece, const map<string, string> &noms);
	virtual void trierParLongueur(ostream& out) {};
	virtual void trierParEspeceEtNom(ostream& out) {};
private:
	multimap<string, Gene* > multiMapGene_;

};