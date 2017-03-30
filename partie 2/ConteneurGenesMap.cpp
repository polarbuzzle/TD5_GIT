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
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; ++it)
		delete it->second;
}
/*!
* \brief Fonction permettant d'ajouter un gene dans un multimap. 
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
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
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
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
*/
bool ConteneurGenesMap::retirer(unsigned int id) 
{
	const auto end = multiMapGene_.end();
	for (auto it = multiMapGene_.begin(); it != end; it++) {
		Gene bob = *(it->second);
		if (bob.getId() == id)
		{
			delete it->second;
			multiMapGene_.erase(it);
			return true;

		}
	}
	return false; 
};
/*!
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
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
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
*/
void ConteneurGenesMap::vider()
{

}
/*!
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
*/

void ConteneurGenesMap::afficherParEspeceEtNom(ostream& out) const
{

}
/*!
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
*/
void ConteneurGenesMap::afficherParLongueur(ostream& out) const
{
}
/*!
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
*/
void ConteneurGenesMap::afficherEspece(const string &espece, ostream& out) const
{

}
/*!
* \brief [brief description]
*
* [detailed description]
*
* \param[in] [name of input parameter] [its description]
* \param[out] [name of output parameter] [its description]
* \return [information about return value]
* \sa [see also section]
* \note [any note about the function you might have]
* \warning [any warning if necessary]
*/
unsigned int ConteneurGenesMap::modifierNoms(const string &espece, const map<string, string> &noms)
{
	return 0;
}

