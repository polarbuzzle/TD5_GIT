/*! \file */
/*!
* \file		ConteneurGenesMap.cpp
* \author	Jean-Frederic Fontaine
*			Samuel Ferron
* \date		2017-03-23
* \brief	Implementation de la classe ConteneurGenesMap.cpp 
*/
#include "ConteneurGenesMap.h"
using namespace std; 

/*!
* \brief Constructeur par defaut d'un objet ConteneurGenesMap
*
*/
ConteneurGenesMap::ConteneurGenesMap()
{

}
/*!
* \brief Destructeur d'un objet ConteneurGenesMap
*
*/
ConteneurGenesMap::~ConteneurGenesMap()
{
	vider(); 
}
/*!
* \brief  ConteneurGenesMap::inserer()
*
* Cette fonction place dans un multimap de gene les differentes information 
* concernant un gene. Plus speficiquement, on place dans l'element first 
* l'espece du gene. Pour le second, on creer un nouveau gene avec l'id, le gene, 
* le nom, et le contenu. On place le pointeur de ce gene dans le "second" du 
* multimap. 
*
* \param[in]	id		Le numero d'identification du gene 
* \param[in]	espece	L'espece du gene 
* \param[in]	nom		Le nom du gene 
* \param[in]	dsc		La description du gene 
* \param[in]	contenu	Le contenu du genome 
* \return		none
*/
void ConteneurGenesMap::inserer(unsigned int id, const string &nom, const string &desc, const string &espece, const string &contenu)
{
	multiMapGene_.insert(pair<string, Gene*>(espece, new Gene(id, nom, desc, espece, contenu)));
}

/*!
* \brief ConteneurGenesMap::trouver() 
*
* Permet de trouver un un gene selon le id qui est passer en 
* parametre. 
*
* \param[in]	id(int)		L'id du gene a trouver
* \return		Gene*		Retourne un pointeur de gene 
*/
Gene* ConteneurGenesMap::trouver(unsigned int id) const
{
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; ++it) {
		Gene bob = *(it->second);
		if (bob.getId() == id) 
		{
			return it->second;
		}
	}
	return nullptr;
}
/*!
* \brief ConteneurGenesMap::retirer() 
*
* Permet de retirer un gene de la map selon 
* l'id qui est fourni en parametre.
*
* \param[in]	id(unsigned int)	Id du gene a retirer 
* \return		bool				Booleen vrai ou faut selon si le gene a 
*									ete supprimer ou non. 
*/
bool ConteneurGenesMap::retirer(unsigned int id) 
{
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; it++) {
		if (it->second->getId() == id)
		{
			delete it->second;
			multiMapGene_.erase(it);
			return true;
		}
	}
	return false; 
};
/*!
* \brief ConteneurGenesMap::retirerEspece()
*
* Permet de retirer tous les genes qui font 
* parti d'une espece donne en parametre. 
* La fonction s'assure de "delete" les pointeurs 
* de gene qui correspondent a cette espece. 
*
* \param[in]	espece(const string)	L'espece a trouver et supprimer
* \return		int						Retourne le nombre de gene supprimer	 
*/
unsigned int ConteneurGenesMap::retirerEspece(const string &espece)
{
	int compteur = 0; 
	vector<Gene*> vectorGeneTrouver; 
	auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; it++) {
		if (it->first == espece) {
			vectorGeneTrouver.push_back(it->second);
			compteur++;
		}
	}
	for_each(vectorGeneTrouver.begin(), vectorGeneTrouver.end(), DetruireGenes());
	multiMapGene_.erase(espece);
	return compteur; 
}
/*!
* \brief ConteneurGenesMap::vider()
*
* Permet de vider la multimap. La fonction s'assure 
* de delete les pointeurs de genes. 
*
* \return AUCUN
*/
void ConteneurGenesMap::vider()
{
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; ++it)
		delete it->second;
	multiMapGene_.clear(); 
}
/*!
* \brief ConteneurGenesMap::afficherParEspeceEtNom()
*
* Fonction qui permet d'afficher en ordre Alphabetique de
* l'espece et du nom. 
*
* \param[in] out(ostream&)	Le flux dans lequel placer les gene trier. 
* \return AUCUN
*/

void ConteneurGenesMap::afficherParEspeceEtNom(ostream& out) const
{
	vector<Gene*> tempo; 
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; ++it) {
		tempo.push_back(it->second);
	}
	sort(tempo.begin(), tempo.end(), TriParEspeceNom());
	copy(tempo.begin(), tempo.end(), ostream_iterator<Gene*>(out, "\n"));
}
/*!
* \brief afficherParLongueur()
*
* Fonction qui pemret d'afficher les differents genes 
* contenu dans la multimap en ordre de longeur (definit 
* par le foncteur)
*
* \param[in] out(ostream&)	Flux dans lequel placer les genes ordonner
* \return AUCUN
*/
void ConteneurGenesMap::afficherParLongueur(ostream& out) const
{
	vector<Gene*> tempo;
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; ++it) {
		tempo.push_back(it->second);
	}
	sort(tempo.begin(), tempo.end(), TriParLongueur());
	copy(tempo.begin(), tempo.end(), ostream_iterator<Gene*>(out, "\n"));
}
/*!
* \brief ConteneurGenesMap::afficherEspece()
*
* Permet d'afficher des genes selon l'espece recu en 
* parametre. 
*
* \param[in] espece(string)		L'espece de gene a afficher 
* \param[in] out(ostream&)		Le flux dans lequel placer l'espece
* \return AUCUN
*/
void ConteneurGenesMap::afficherEspece(const string &espece, ostream& out) const
{
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; ++it) {
		if(it->first == espece)
		{
			out << it->second; 
		}
	}
}
/*!
* \brief  ConteneurGenesMap::modifierNoms()
*
* Permet de modifier le nom de plusieurs genes. Cette 
* fonctiion recoit en parametre une map dans lequel on 
* retrouve une paire: nom a changer et nouveau nom . Ainsi, on parcour l'objet
* puis on compare l'espece recu en parametre et l'espce de l'objet 
* si ceux-ci sont pareil on compare les noms du map recu en parametre 
* et le nom de l'objet. Si ceux-ci son pareil on change le nom de l'objet 
* par le nouveau nom contenu dans le map. 
*
* \param[in]	espece(string)				L'espece a investiguer		
* \param[in]	nom(map<string, string>)	Le map servant a chercher un nom afin de le remplacer
* \return		unsigned int				Le nombre de nom modifier selon les criteres. 				
*/
unsigned int ConteneurGenesMap::modifierNoms(const string &espece, const map<string, string> &noms)
{
	int compteur = 0; 
	auto endAModifier	= multiMapGene_.end(); 
	auto endQuiModifie = noms.end(); 
	for (auto debut1 = noms.begin(); debut1 != endQuiModifie; debut1++)
	{
		for (auto it = multiMapGene_.begin(); it != endAModifier; it++)
		{
			if ((it->first == espece) && (it->second->getNom() == debut1->first)) {
				it->second->setNom(debut1->second);
				compteur++;
			}
		}
	}
	return compteur;
}

