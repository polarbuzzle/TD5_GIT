/****************************************************************************
 * Fichier     : gene.cpp
 * Auteur      : 
 * Travail     : TP5
 * Description : Impl�mentation de la classe Gene
 ***************************************************************************/

#include "gene.h"

/****************************************************************************
 * Description      : Constructeur de Gene par param�tres
 * Param�tres       :	- id (unsigned int): identificateur unique
 *						- nom (string): nom du g�ne
 *						- desc (string): description du g�ne
 *						- espece (string): esp�ce 
 *						- contenu (string): contenu en nucl�otides A G C et T
 * Valeur de retour : Aucune
 ***************************************************************************/
Gene::Gene(unsigned int id, string nom, string desc, string espece, string contenu)
:id_(id), nom_(nom), desc_(desc), espece_(espece), contenu_(contenu)
{
}

/****************************************************************************
 * Description      : Retourne l'identificateur du g�ne
 * Param�tres       : Aucun
 * Type de retour   : string
 ***************************************************************************/
unsigned int Gene::getId() const
{
	return id_;
}

/****************************************************************************
 * Description      : Retourne le nom du g�ne
 * Param�tres       : Aucun
 * Type de retour   : string
 ***************************************************************************/
string Gene::getNom() const
{
	return nom_;
}

/****************************************************************************
 * Description      : Retourne la description du g�ne
 * Param�tres       : Aucun
 * Type de retour   : unsigned int
 ***************************************************************************/
string Gene::getDesc() const
{
	return desc_;
}

/****************************************************************************
 * Description      : Retourne l'esp�ce � laquelle appartient le g�ne
 * Param�tres       : Aucun
 * Type de retour   : string
 ***************************************************************************/
string Gene::getEspece() const
{
	return espece_;
}

/****************************************************************************
 * Description      : Retourne le contenu du g�ne en nucl�otides
 * Param�tres       : Aucun
 * Type de retour   : string
 ***************************************************************************/
string Gene::getContenu() const
{
	return contenu_;
}

/****************************************************************************
 * Description      : Modifie le nom du g�ne
 * Param�tres       : Aucun
 * Type de retour   : string
 ***************************************************************************/
void Gene::setNom(string nom)
{
	nom_ = nom;
}

/****************************************************************************
 * Description      : Affiche le g�ne dans un ostream
 * Param�tres       : ostream
 * Type de retour   : void
 ***************************************************************************/
void Gene::afficher(ostream& out) const
{
	out << "\t" << id_ << "\t" << nom_ << endl;
	out << "\t" << espece_ << endl;
	out << "\t" << desc_ << endl;
	//out << "\t" << contenu_;
	unsigned int i = 0, n = 65;
	while (i < contenu_.size())
	{
		string toPrint = contenu_.substr(i, n);
		out << "\t" << toPrint << endl;
		i += n+1;
	
	}
}

/****************************************************************************
 * Description      : Surcharge l'operateur de sortie pour pouvoir 
 *                    afficher un g�ne
 * Param�tres       : ostream& out, const Gene& g2
 * Type de retour   : ostream&
 ***************************************************************************/
ostream& operator << (ostream& out, const Gene& gene)
{
	gene.afficher(out);
	return out;
}

ostream& operator << (ostream& out, Gene* gene)
{
	gene->afficher(out);
	return out;
}