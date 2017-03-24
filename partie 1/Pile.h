//* \file Pile.cpp 
//* \author	Jean-Frederic Fontaine
//*			Samuel Ferront
//* \date		2017-03-23
//* \brief  Implementation de la classe Pile 
//*/
#pragma once
#include <vector>

template <typename T1>
class Pile {

public:
//* \brief Constructeur par defaut de l'objet pile 
//* \return retourne un booleen si l'ajout a ete correctement effectue
//*/
	Pile() : capacite_(10), nombreElements_(0) {
		elements_ = new T1[10];
	};
//* \brief Constructeur par parametre de l'objet Pile
//* \param (int)capacite	Capacite de la pile que l'on veut construire 
//*/
	Pile(int capacite) : capacite_(capacite), nombreElements_(0) {
		elements_ = new T1[capacite];
	};
//* \brief Destructeur
//* \param (int)capacite	Capacite de la pile que l'on veut construire
//*/
	~Pile() {
		delete[] elements_;
	};
//* \brief Fonction qui permet d'empiler un nouvel element sur la pile 
//* \param premier Objet de type T1 que l'on veut empiler sur la pile 
//* \param [name of output parameter] [its description]
//* \return retourne un booleen si l'ajout a ete correctement effectue
//*/
	bool empiler(T1 premier) {
		if (capacite_ != nombreElements_)
		{
			elements_[nombreElements_++] = premier;
			return true;
		}
		return false;
	};
//* \brief Fonction qui permet de depiler  l'element sur la pile
//* \return retourne un booleen si l'element a ete correctement depiler
//*/
	bool depiler() {
		if (nombreElements_ != 0)
		{
			--nombreElements_;
			return true;
		}
		return false;
	};
//* \brief Fonction qui permet de verifier si la pile est vide 
//* \return retourne un booleen si la pile est vide ou non 
//*/
	bool estVide() const {
		if (nombreElements_ == 0) {
			return true;
		}
		return false;
	};
//* \brief Fonction qui permet de verifier si la pile est pleine 
//* \return retourne un booleen si la pile est pleine ou non
//*/
	bool estPleine() const {
		if (capacite_ == nombreElements_)
			return true;
		return false;
	};
//* \brief Fonction qui retourne une reference de l'element au dessus de la pile
//* \return retourne la reference de l'element au dessus de la pile
//*/
	T1* obtenirSommet() const {
		return &elements_[nombreElements_];
	};
//* \brief Fonction qui retourne le nomre d'elements actuellement dans la pile
//* \return retourne le nombre d'elements dans la pile
//*/
	int obtenirTaille() const {
		return nombreElements_;
	};

private:
	int capacite_;
	int nombreElements_;
	T1* elements_;

};