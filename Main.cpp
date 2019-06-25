#include<iostream>
#include "Binary_tree_class.h"
#include "Node_class.h"
using namespace std;

int main()
{
	int Nombre;
	cin >> Nombre;
	Noeud* curr = NULL;
	ArbreBinaire Arbre(Nombre); // Appel de la classe Arbre Binaire
	Arbre.ReceptionDeDonne(Nombre); // Recevoir les donnees du fichier d'entree
	int val = 0;
	Arbre.inserer(val, curr); //inserer a partir de la premiere donne
	Arbre.afficherPreOrdre(val); cout << endl; // affiche en preordre
	Arbre.afficherSuffixe(val); cout << endl; //En suffixe
	Arbre.Largeur(); cout << endl; // Puis en largeur
	Arbre.ESTILBINAIRE(); // Verifie si l'arbre est binaire
	return 0;

}