#pragma once

template <typename T1>
class Pile {

public:
	//Constructeurs et destructeur
	Pile();
	Pile(int capacite);
	~Pile();



	bool empiler(T1 premier);
	bool depiler();

	bool estVide() const;
	bool estPleine() const;
	T1* obtenirSommet() const;
	int obtenirTaille() const;

private:

	int capacite_;
	int nombreElements_;
	T1* elements_;

};