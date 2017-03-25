/*!
* \file		Foncteur.h
* \author	Jean-Frederic Fontaine
*			Samuel Ferront
* \date		2017-03-23
* \brief	Implementation des foncteurs
*/

#pragma once

#include "Gene.h"

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
	bool operator()(const Gene* &gene) const
	{
		return id_ == gene->getId();
	};

private:
	int id_;
};

class MemeEspace
{
public:
	/*!
	* \brief	Constructeur par parametre
	* \param	-espece espece de gene
	*/
	MemeEspace(const string espece) : espece_(espece) {};

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

class DetruireGenes
{
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
	void operator()(Gene* gene)
	{
		if (gene->getEspece() == espece_)
		{
			delete gene;
		}
	};

private:
	string espece_;
};