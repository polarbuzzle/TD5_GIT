#pragma once

#include "conteneurGenes.h"
#include <list>
#include <iterator>
#include <algorithm>

class ConteneurGenesListe : public ConteneurGenes
{
public:
	ConteneurGenesListe();
	virtual ~ConteneurGenesListe();

	virtual void inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu);
	virtual Gene* trouver(unsigned int id) const;
	virtual bool retirer(unsigned int id);
	virtual unsigned int retirerEspece(const string &espece);
	virtual void vider();

	virtual void afficherParEspeceEtNom(ostream& out) const;
	virtual void afficherParLongueur(ostream& out) const;
	virtual void afficherEspece(const string &espece, ostream& out) const;

	virtual unsigned int modifierNoms(const string &espece, const map<string, string> &noms);
private:
	list<Gene> listeGene_;
};