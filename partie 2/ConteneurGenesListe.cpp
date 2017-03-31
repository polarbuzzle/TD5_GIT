
#include "ConteneurGenesListe.h"
#include <functional>

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
	listeGene_.push_back(new Gene(id, nom, desc, espece, contenu));
}

Gene* ConteneurGenesListe::trouver(unsigned int id) const
{
//	auto it = find_if(listeGene_.begin(), listeGene_.end(), MemeId(id));

//	if(it != listeGene_.end())
//		return *it;
	return nullptr;
}

bool ConteneurGenesListe::retirer(unsigned int id)
{
	Gene* aRetirer = trouver(id);
	if (aRetirer != nullptr)
	{
		//listeGene_.remove(aRetirer);
		//delete aRetirer;
		return true;
	}
	return false;
}

unsigned int ConteneurGenesListe::retirerEspece(const string &espece)
{
	//TEMPORAIRE
	unsigned int init = listeGene_.size();
	listeGene_.remove_if(MemeEspece(espece));
	unsigned int fin = listeGene_.size();

	return init - fin;
}

void ConteneurGenesListe::vider()
{

}

void ConteneurGenesListe::afficherParEspeceEtNom(ostream& out) const
{

}

void ConteneurGenesListe::afficherParLongueur(ostream& out) const
{
	copy(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene*>(out, "\n"));
}

void ConteneurGenesListe::afficherEspece(const string &espece, ostream& out) const
{

}

unsigned int ConteneurGenesListe::modifierNoms(const string &espece, const map<string, string> &noms)
{
	return 0;
}