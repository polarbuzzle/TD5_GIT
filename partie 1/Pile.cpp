///*!
//* \file Pile.cpp 
//* \author	Jean-Frederic Fontaine
//*			Samuel Ferront
//* \date		2017-03-23
//* Implementation de la classe Pile 
//*/
//#include "Pile.h"
//
///*!
//* \brief Constructeur par defaut de l'objet pile 
//* \return retourne un booleen si l'ajout a ete correctement effectue
//*/
//template <typename T1>
//Pile<T1>::Pile() : capacite_(10), nombreElements_(0) {
//	elements_ = new T1[10];
//}
//
///*!
//* \brief Constructeur par parametre de l'objet Pile
//* \param (int)capacite	Capacite de la pile que l'on veut construire 
//*/
//template <typename T1>
//Pile<T1>::Pile(int capacite) : capacite_(capacite), nombreElements_(0) {
//	
//}
//
///*!
//* \brief Destructeur
//* \param (int)capacite	Capacite de la pile que l'on veut construire
//*/
//template <typename T1>
//Pile<T1>::~Pile(){
//	delete[] elements_;
//}
///*!
//* \brief Fonction qui permet d'empiler un nouvel element sur la pile 
//* \param premier Objet de type T1 que l'on veut empiler sur la pile 
//* \param [name of output parameter] [its description]
//* \return retourne un booleen si l'ajout a ete correctement effectue
//*/
//template <typename T1>
//bool Pile<T1>::empiler(T1 premier)
//{
//	if (capacite_ == nombreElements_) 
//	{
//		*elements_[nombreElements_++] = premier;
//		return true; 
//	}
//	return false; 
//}
///*!
//* \brief Fonction qui permet de depiler  l'element sur la pile
//* \return retourne un booleen si l'element a ete correctement depiler
//*/
//template <typename T1>
//bool Pile<T1>::depiler()
//{
//	if (nombreElements_ != 0) 
//	{
//		delete elements_[--nombreElements_];
//		return true; 
//	}
//	return false; 
//}
///*!
//* \brief Fonction qui permet de verifier si la pile est vide 
//* \return retourne un booleen si la pile est vide ou non 
//*/
//template <typename T1>
//bool Pile<T1>::estVide() const {
//	if (nombreElements_ == 0) {
//		return true;
//	}
//	return false; 
//}
///*!
//* \brief Fonction qui permet de verifier si la pile est pleine 
//* \return retourne un booleen si la pile est pleine ou non
//*/
//template <typename T1>
//bool Pile<T1>::estPleine() const {
//	if (capacite_ == nombreElements_)
//		return true;
//	return false; 
//}
//
///*!
//* \brief Fonction qui retourne une reference de l'element au dessus de la pile
//* \return retourne la reference de l'element au dessus de la pile
//*/
//template <typename T1>
//T1* Pile<T1>::obtenirSommet() const {
//	return elements_[nombreElements_];
//}
//
///*!
//* \brief Fonction qui retourne le nomre d'elements actuellement dans la pile
//* \return retourne le nombre d'elements dans la pile
//*/
//template <typename T1>
//int Pile<T1>::obtenirTaille() const {
//	return nombreElements_;
//}