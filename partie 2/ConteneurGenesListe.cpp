/*!
* \file		ConteneurGenesListe.cpp
* \author	Jean-Frederic Fontaine
*			Samuel Ferron
* \date		2017-03-23
* \brief	Implementation de la classe ConteneurGenesListe
*/

#include "ConteneurGenesListe.h"
#include <functional>

using namespace std::placeholders;

/*!
* \brief Constructeur par default
*
*/
ConteneurGenesListe::ConteneurGenesListe()
{
	//aucune instruction a faire
}

/*!
* \brief Destructeur
*
* Le destructeur appelle la methode membre vider() qui s'occupe de detruire les pointeurs dans la liste
*/
ConteneurGenesListe::~ConteneurGenesListe()
{
	vider();
}

/*!
* \brief Fonction permettant d'ajouter un gene dans une liste.
*
* Cette fonction ajoute un element dans la liste avec la methode
* membre push_back de liste.
*
* \param[in]	id		Le numero d'identification du gene
* \param[in]	espece	L'espece du gene
* \param[in]	nom		Le nom du gene
* \param[in]	dsc		La description du gene
* \param[in]	contenu	Le contenu du genome
* \return		none
*/
void ConteneurGenesListe::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu)
{
	listeGene_.push_back(new Gene(id, nom, desc, espece, contenu));
}

/*!
* \brief Fonction permettant de trouver un gene si il appartient a la liste
*
* Cette fonction retourne un element de type Gene* si l'id en parametre correspond a
* un element de la liste.
*
* \param[in]	id		Le numero d'identification du gene
* \return		Gene* le pointeur du gene si trouve, sinon nullptr
*/
Gene* ConteneurGenesListe::trouver(unsigned int id) const
{
	auto it = find_if(listeGene_.begin(), listeGene_.end(), MemeId(id));

	if(it != listeGene_.end())
		return *it;
	return nullptr;
}

/*!
* \brief Fonction qui retire un element de la liste
*
* Cette fonction retourne trouve si le pointeur que nous voulon retirer existe
* et le retire le la liste pour ensuite le delete pour liberer son espace memoire.
*
* \param[in]	id		Le numero d'identification du gene
* \return		bool	booleen vrai si un element est bien retire
*/
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

/*!
* \brief Fonction qui retire un element de la liste si son espece correspond a l'espece en parametre
*
* Cette fonction retourne trouve si le pointeur que nous voulon retirer existe
* et le retire le la liste pour ensuite le delete pour liberer son espace memoire
* Cette methode nous permet de retirer un espece en son entierete dans le meme algorithme et
* retourne le nombre d'elements retires.
*
* \param[in]	espece			L'espece que nous voulons retirer
* \return		unsigned int	Le nombre d'elements retires
*/
unsigned int ConteneurGenesListe::retirerEspece(const string &espece)
{
	unsigned int nbrRetire = listeGene_.size();
	listeGene_.remove_if(DetruireEspece(espece));
	return nbrRetire - listeGene_.size();
}

/*!
* \brief Fonction qui vide la liste
*
* Cette fonction s'occupe de detruire tous les pointeurs de la liste et
* retire chaque elements de la liste.
*
* \return		none
*/
void ConteneurGenesListe::vider()
{
	for_each(listeGene_.begin(), listeGene_.end(), DetruireGenes());
	listeGene_.clear();

}

/*!
* \brief Fonction affiche la liste
*
* Cette fonction affiche la liste classee en ordre d'espece et de nom
*
* \return	none
*/
void ConteneurGenesListe::afficherParEspeceEtNom(ostream& out) const
{
	copy(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene*>(out, "\n"));
}

/*!
* \brief Fonction affiche la liste
*
* Cette fonction affiche la liste classee en ordre croissant de longueur
*
* \return	none
*/
void ConteneurGenesListe::afficherParLongueur(ostream& out) const
{
	copy(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene*>(out, "\n"));
}

/*!
* \brief Fonction affiche la un espece
*
* Cette fonction affiche tous le elements de la liste d'un certain espece
*
* \return	none
*/
void ConteneurGenesListe::afficherEspece(const string &espece, ostream& out) const
{
	copy_if(listeGene_.begin(), listeGene_.end(), ostream_iterator<Gene*>(out, "\n"), MemeEspece(espece));
}

/*!
* \brief Fonction qui modifi les noms
*
* Cette fonction change les noms d'un gene si il appartient a un espece. 
*
* \param	espece L'espece dans l'aquelle nous voulons 
* \return	unsigned int nombre d'elements modifies
*/
unsigned int ConteneurGenesListe::modifierNoms(const string &espece, const map<string, string> &noms)
{
	Gene* gene;
	list<Gene*>::iterator itGene = listeGene_.begin();
	unsigned int nombreModifies = 0;
	for (auto it = noms.begin(); it != noms.end();)
	{
		itGene = find_if(listeGene_.begin(), listeGene_.end(), 
			bind(logical_and<bool>(),
				bind(MemeNom(it->first), _1),
				bind(MemeEspece(espece), _1)
				)
			);
		if (itGene != listeGene_.end())
		{
			gene = *itGene;
			gene->setNom(it->second);
			nombreModifies++;
		}
		else
		{
			++it;
		}
	}
	return nombreModifies;
}

/*!
* \brief Fonction pour trier la liste
*
* Cette fonction classe la liste en ordre croissant de longueur
*
* \return	none
*/
void ConteneurGenesListe::trierParLongueur(ostream& out)
{
	listeGene_.sort(TriParLongueur());
	
}

/*!
* \brief Fonction pour trier la liste
*
* Cette fonction classe la liste en ordre croissant d'espece et de nom
*
* \return	none
*/
void ConteneurGenesListe::trierParEspeceEtNom(ostream& out)
{
	listeGene_.sort(TriParEspeceNom());
	
}