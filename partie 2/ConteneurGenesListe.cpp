
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
	listeGene_.push_back(Gene(id, nom, desc, espece, contenu));
}

Gene* ConteneurGenesListe::trouver(unsigned int id) const
{
	/*list<Gene*>::iterator it = find_if(listeGene_.begin(), listeGene_.end(), MemeId(id));
	return *it;*/
}

bool ConteneurGenesListe::retirer(unsigned int id)
{
	return true;
}

unsigned int ConteneurGenesListe::retirerEspece(const string &espece)
{
	return 0;
}

void ConteneurGenesListe::vider()
{
	listeGene_.clear();
}

void ConteneurGenesListe::afficherParEspeceEtNom(ostream& out) const
{

}

void ConteneurGenesListe::afficherParLongueur(ostream& out) const
{
	copy(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene>(cout, "\n"));
}

void ConteneurGenesListe::afficherEspece(const string &espece, ostream& out) const
{

}

unsigned int ConteneurGenesListe::modifierNoms(const string &espece, const map<string, string> &noms)
{
	return 0;
}