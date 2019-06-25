#include<iostream>
#include "Binary_tree_class.h"
#include "Node_class.h"
using namespace std;

int main()
{
	int Nombre;
	cin >> Nombre;
	Noeud* curr = NULL;
	ArbreBinaire Arbre(Nombre); // call of the binary tree class 
	Arbre.ReceptionDeDonne(Nombre); // reception of data
	int val = 0;
	Arbre.inserer(val, curr); //insert from the first data you find in file
	Arbre.afficherPreOrdre(val); cout << endl; // post(print) in preordre
	Arbre.afficherSuffixe(val); cout << endl; // post(print) in suffix
	Arbre.Largeur(); cout << endl; // Puis in width
	Arbre.ESTILBINAIRE(); // Verify if the tree is binary
	return 0;
}
