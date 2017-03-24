#pragma once
#include <vector>

template <typename T1>
class Pile {

public:
	//Constructeurs et destructeur
	Pile() : capacite_(10), nombreElements_(0) {
		elements_ = new T1[10];
	};

	Pile(int capacite) : capacite_(capacite), nombreElements_(0) {
		elements_ = new T1[capacite];
	};
	~Pile() {
		delete[] elements_;
	};

	bool empiler(T1 premier) {
		if (capacite_ != nombreElements_)
		{
			elements_[nombreElements_++] = premier;
			return true;
		}
		return false;
	};

	bool depiler() {
		if (nombreElements_ != 0)
		{
			--nombreElements_;
			return true;
		}
		return false;
	};

	bool estVide() const {
		if (nombreElements_ == 0) {
			return true;
		}
		return false;
	};

	bool estPleine() const {
		if (capacite_ == nombreElements_)
			return true;
		return false;
	};

	T1* obtenirSommet() const {
		return &elements_[nombreElements_];
	};

	int obtenirTaille() const {
		return nombreElements_;
	};

private:

	int capacite_;
	int nombreElements_;
	T1* elements_;

};