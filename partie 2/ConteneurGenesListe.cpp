
#include "ConteneurGenesListe.h"

ConteneurGenesListe::ConteneurGenesListe()
{
	//rien?
}

ConteneurGenesListe::~ConteneurGenesListe()
{
	//rien pour l'instant
}

void ConteneurGenesListe::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu)
{
	liseGene_.push_back(Gene(id, nom, desc, espece, contenu));
}

Gene* ConteneurGenesListe::trouver(unsigned int id) const
{
	return nullptr;
}

bool ConteneurGenesListe::retirer(unsigned int id)
{
	return true;
}

unsigned int ConteneurGenesListe::retirerEspece(const string &esoece)
{
	return 0;
}

void ConteneurGenesListe::vider()
{
	liseGene_.clear()
}

void ConteneurGenesListe::afficherParEspeceEtNom(ostream& out) const
{

}

void ConteneurGenesListe::afficherParLongueur(ostream& out) const
{
	copy(liseGene_.begin(), liseGene_.end(), ostream_iterator<Gene>(cout, "\n"));
}

void ConteneurGenesListe::afficherEspece(const string &espece, ostream& out) const
{

}

unsigned int ConteneurGenesListe::modifierNoms(const string &espece, const map<string, string> &noms)
{
	return 0;
}