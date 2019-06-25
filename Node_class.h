#pragma once
#include<iostream>
class Noeud // class Noeud contenant les caracteristiques d'un Noeud
{
public:
	Noeud(int element) {
		cle = element;
		gauche = droite = NULL;
	}
private:
	int cle;
	Noeud* gauche, * droite;
	friend class ArbreBinaire;
};