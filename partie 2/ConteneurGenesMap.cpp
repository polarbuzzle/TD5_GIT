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
	auto it = multiMapGene_.begin();
	const auto end = multiMapGene_.end();
	for_each(it, end, DetruireGenes());
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