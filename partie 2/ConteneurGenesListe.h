/*!
* \file		ConteneurGenesListe.h
* \author	Jean-Frederic Fontaine
*			Samuel Ferron
* \date		2017-03-23
* \brief	Definition de la classe ConteneurGeneListe
*/

#ifndef _CONENEUR_GENES_LISTE_
#define _CONENEUR_GENES_LISTE_

#include "conteneurGenes.h"
#include "Foncteur.h"
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

	virtual void trierParLongueur();
	virtual void trierParEspeceEtNom();

	virtual void afficherParEspeceEtNom(ostream& out) const;
	virtual void afficherParLongueur(ostream& out) const;
	virtual void afficherEspece(const string &espece, ostream& out) const;

	virtual unsigned int modifierNoms(const string &espece, const map<string, string> &noms);
private:
	list<Gene*> listeGene_;
};

#endif // !_CONENEUR_GENES_LISTE_