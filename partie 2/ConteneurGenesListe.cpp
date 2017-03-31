
#include "ConteneurGenesListe.h"
#include <functional>

ConteneurGenesListe::ConteneurGenesListe()
{
	//rien?
}

ConteneurGenesListe::~ConteneurGenesListe()
{
	vider();
}

void ConteneurGenesListe::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu)
{
	listeGene_.push_back(new Gene(id, nom, desc, espece, contenu));
}

Gene* ConteneurGenesListe::trouver(unsigned int id) const
{
	auto it = find_if(listeGene_.begin(), listeGene_.end(), MemeId(id));

	if(it != listeGene_.end())
		return *it;
	return nullptr;
}

bool ConteneurGenesListe::retirer(unsigned int id)
{
	Gene* aRetirer = trouver(id);
	if (aRetirer != nullptr)
	{
		listeGene_.remove(aRetirer);
		delete aRetirer;
		return true;
	}
	return false;
}

unsigned int ConteneurGenesListe::retirerEspece(const string &espece)
{
	unsigned int nbrRetire = listeGene_.size();
	listeGene_.remove_if(DetruireEspece(espece));
	return nbrRetire - listeGene_.size();
}

void ConteneurGenesListe::vider()
{
	for_each(listeGene_.begin(), listeGene_.end(), DetruireGenes());
	listeGene_.clear();

}

void ConteneurGenesListe::afficherParEspeceEtNom(ostream& out) const
{
	copy(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene*>(out, "\n"));
}

void ConteneurGenesListe::afficherParLongueur(ostream& out) const
{
	copy(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene*>(out, "\n"));
}

void ConteneurGenesListe::afficherEspece(const string &espece, ostream& out) const
{
	copy_if(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene*>(out, "\n"), MemeEspece(espece));
}

unsigned int ConteneurGenesListe::modifierNoms(const string &espece, const map<string, string> &noms)
{
	Gene* gene;
	unsigned int nombreModifies = 0;
	for (auto it = noms.begin(); it != noms.end(); ++it)
	{
		auto itGene = find_if(listeGene_.begin(), listeGene_.end(), MemeNom(it->first));
		
		if (itGene != listeGene_.end())
		{
			gene = *itGene;
			gene->setNom(it->second);
			nombreModifies++;
		}
	}
	return nombreModifies;
}

void ConteneurGenesListe::trierParLongueur(ostream& out)
{
	listeGene_.sort(TriParLongueur());
	afficherParLongueur(out);
}

void ConteneurGenesListe::trierParEspeceEtNom(ostream& out)
{
	listeGene_.sort(TriParEspeceNom());
	afficherParEspeceEtNom(out);
}