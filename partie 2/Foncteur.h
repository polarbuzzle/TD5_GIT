/*!
* \file		Foncteur.h
* \author	Jean-Frederic Fontaine
*			Samuel Ferron
* \date		2017-03-23
* \brief	Implementation des foncteurs
*/

#ifndef _FONCTEUR_
#define _FONCTEUR_

#include "Gene.h"
#include <map>

/*!
* \class MemeId
*
* \brief Predicat comparante un Gene* avec un Id
*
* Foncteur binaire qui aide a identifier un gene a l'aide d'un id
*/
class MemeId
{
public:
	/*!
	* \brief	Constructeur par parametre
	* \param	-id Identificateur
	*/
	MemeId(const int &id) : id_(id) {};

	/*!
	* \brief	Predicat qui compare si l'id d'un gene est le meme que l'objet
	* \param	-gene le gene que nous voulons comparer
	* \return	true si l'id du gene est le meme que l'attribut id_
	*/
	bool operator()(const Gene* gene) const
	{
		return id_ == gene->getId();
	};

private:
	int id_;
};

/*!
* \class MemeEspece
*
* \brief Predicat comparante un Gene* avec un espece
*
* Foncteur binaire qui aide a identifier un gene a l'aide d'un espece
*/
class MemeEspece
{
public:
	/*!
	* \brief	Constructeur par parametre
	* \param	-espece espece de gene
	*/
	MemeEspece(const string espece) : espece_(espece) {};

	/*!
	* \brief	Predicat qui compare si l'espece d'un gene est le meme que l'objet
	* \param	-gene le gene que nous voulons comparer
	* \return	true si l'espace du gene est le meme que l'attribut espace_
	*/
	bool operator()(const Gene* gene) const
	{
		return espece_ == gene->getEspece();
	};

private:
	string espece_;
};

/*!
* \class MemeNom
*
* \brief Predicat comparante un Gene* avec un nom
*
* Foncteur binaire qui aide a identifier un gene a l'aide d'un nom
*/
class MemeNom
{
public:
	/*!
	* \brief	Constructeur par parametre
	* \param	-nom nom du gene
	*/
	MemeNom(const string nom) : nom_(nom) {};

	/*!
	* \brief	Predicat qui compare si le nom d'un gene est le meme que l'objet
	* \param	-gene le gene que nous voulons comparer
	* \return	true si le nom du gene est le meme que l'attribut nom_
	*/
	bool operator()(const Gene* gene) const
	{
		return nom_ == gene->getNom();
	};

private:
	string nom_;
};

/*!
* \class TriParLongueur
*
* \brief Predicat qui tri deux genes selon leur longueur
*
* Foncteur binaire qui compare deux genes par leur longueur et retourne vrai si le premier est plus petit
*/
class TriParLongueur
{
public:
	/*!
	* \brief	Constructeur par default
	*/
	TriParLongueur() {};

	/*!
	* \brief	Predicat qui indique si un gene est plus petit qu'un autre
	* \param	-gene1 le premier gene
	* \param	-gene2 le deuxieme gene
	* \return	retourne vrai si gene1 < gene 2 en terme de longueur de contenu
	*/
	bool operator()(const Gene* gene1, const Gene* gene2) const
	{
		return (gene1->getContenu().size() < gene2->getContenu().size());
	};
};

/*!
* \class TriParEspeceNom
*
* \brief Predicat qui tri deux genes selon leur espece et leur nom
*
* Foncteur binaire qui compare deux genes et retourne vrai si le premier est plus petit, soit en espece ou en nom
*/
class TriParEspeceNom
{
public:
	/*!
	* \brief	Constructeur par default
	*/
	TriParEspeceNom() {};

	/*!
	* \brief	Predicat indique si un gene est plus petit qu'un autre en terme de nom et d'espece
	* \param	-gene1 le premier gene
	* \param	-gene2 le deuxieme gene
	* \return	retourne vrai si gene1 < gene 2 en terme d'espece et de nom
	*/
	bool operator()(const Gene* gene1, const Gene* gene2) const
	{
		if (gene1->getEspece() < gene2->getEspece())
		{
			return true;
		}
		else if (gene1->getEspece() == gene2->getEspece()) {
			return gene1->getNom() < gene2->getNom();
		}
		return false;
	};
};

/*!
* \class DetruireGenes
*
* \brief Foncteur qui libere l'espace memoire d'un gene
*
* Foncteur qui delete un pointeur de gene qu'on lui envoit
*/
class DetruireGenes
{
public:
	/*!
	* \brief	Constructeur par default
	*/
	DetruireGenes() {};

	/*!
	* \brief	Foncteur qui detruit un pointeur gene
	* \param	-gene le gene que nous voulons detruire
	*/
	void operator()(Gene* gene)
	{
		delete gene;
	};
};

/*!
* \class DetruireEspece
*
* \brief Predicat qui detruit un gene si il correspond a un espece donne
*
* Foncteur binaire compare un gene avec un espece et le detruit si ils correspondent. Retourne vrai si la destruction est faite
*/
class DetruireEspece
{
public:
	/*!
	* \brief	Constructeur par parametre
	* \param	-espece espece de gene
	*/
	DetruireEspece(const string &espece) : espece_(espece) {};

	/*!
	* \brief	foncteur qui detruit un espece d'un pointeur gene
	* \param	-gene le gene que nous voulons detruire un espece
	*/
	bool operator()(Gene* gene)
	{
		if (gene->getEspece() == espece_)
		{
			delete gene;
			return true;
		}
		return false;
	};

private:
	string espece_;
};

#endif // !FONCTEUR