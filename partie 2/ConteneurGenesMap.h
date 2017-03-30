/*!
* \file		Foncteur.h
* \author	Jean-Frederic Fontaine
*			Samuel Ferron
* \date		2017-03-23
* \brief	Implementation des foncteurs
*/
#pragma once
#include "conteneurGenes.h"
#include <iostream>
#include <map>
#include <utility>
#include <iterator>
#include <algorithm>
#include "Gene.h"

class ConteneurGenesMap : public ConteneurGenes
{
	ConteneurGenesMap();
	virtual ~ConteneurGenesMap();

	virtual void inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu);
	virtual Gene* trouver(unsigned int id) const;
	virtual bool retirer(unsigned int id);
	virtual unsigned int retirerEspece(const string &espece);
	virtual void vider();

	virtual void afficherParEspeceEtNom(ostream& out) const;
	virtual void afficherParLongueur(ostream& out) const;
	virtual void afficherEspece(const string &espece, ostream& out) const;

private:
	multimap<string, Gene* > multiMapGene_;
};