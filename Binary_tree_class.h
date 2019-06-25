#pragma once
#include<iostream>
#include "Node_class.h"
using namespace std;
class ArbreBinaire // class qui permet de construire l'arbre 
{
public:

	ArbreBinaire(int N) // ce constructeur prend trois tableaux  pour construire l'arbre puis initialise le nombre de noeud a la taille et initialise la racine a NULL
	{
		I = new int[N];
		G = new int[N];
		D = new int[N];
		NombreDeNoeud = N;
		racine = NULL;
	}
	void ReceptionDeDonne(int N) // fonction permettant de recevoir les donnees
	{
		for (int i = 0; i < N; i++)
		{
			int indice;
			cin >> indice;
			I[i] = indice;
			int leftchild;
			cin >> leftchild;
			G[i] = leftchild;
			int rightchild;
			cin >> rightchild;
			D[i] = rightchild;
		}
	}

	void inserer(int val, Noeud* a)// fonction recursive qui ajoute les noeuds à partir de l'entree (les trois tableau)
	{
		if (val == -1) { return; }
		else
		{
			if (racine == NULL)
			{
				a = racine = new Noeud(I[val]);
				inserer(G[val], a->gauche);
				inserer(D[val], a->droite);
			}
			else
			{
				a = new Noeud(I[val]);
				inserer(G[val], a->gauche);
				inserer(D[val], a->droite);
			}

		}
	}
	void afficherPreOrdre(int val) // fonction permettant d'afficher les enfants de l'arbre en PreOrdre
	{
		if (val == -1) { return; }
		else
		{
			cout << I[val] << " ";
			afficherPreOrdre(G[val]);
			afficherPreOrdre(D[val]);
		}
	}
	void afficherSuffixe(int val) // fonction permettant d'afficher les enfants de l'arbre en Suffixe
	{
		if (G[val] == -1 && D[val] == -1)
		{
			cout << I[val] << " ";
		}
		else
		{
			if (G[val] != -1)
			{
				afficherSuffixe(G[val]);
				if (D[val] != -1)
				{
					afficherSuffixe(D[val]);
				}
				cout << I[val] << " ";
			}
			else if (D[val] != -1)
			{
				afficherSuffixe(D[val]);
				cout << I[val] << " ";
			}
		}
	}
	void Largeur() // affiche les enfants du pere aux enfants puis enfants des enfants de la gauche vers la droite 
	{
		int* T = new int[NombreDeNoeud];
		int i = 0;
		int k = 0;
		T[k] = I[k];
		cout << T[k] << " ";
		for (int j = 1; j < NombreDeNoeud; j++)
		{
			while (T[k] != I[i])
			{
				i++;
			}
			if (T[k] == I[i])
			{
				if (G[i] != -1)
				{
					T[j] = I[G[i]];
					cout << T[j] << " ";
				}
				if (D[i] != -1)
				{
					if (G[i] != -1)
					{
						j++;
					}
					T[j] = I[D[i]];
					cout << T[j] << " ";

				}
				if (G[i] == -1 && D[i] == -1)
				{
					j--;
				}
				k++;
				i = 0;
			}
		}
	}
	void ESTILBINAIRE() // Fonction pouvant verifier si un arbre est binaire ou non qui affiche true si c'est le cas ou False le contraire 
	{
		int* T = new int[NombreDeNoeud];
		int i = 0;
		int k = 0;
		int cmpt = 0;
		for (int j = 0; j < NombreDeNoeud; j++)
		{
			T[k] = I[k];
			while (T[k] != I[i])
			{
				i++;
			}
			if (G[i] != -1 && D[i] != -1)
			{
				if (I[G[i]] < I[i] && I[D[i]] >I[i]) { cmpt++; }
				else
				{
					j = NombreDeNoeud;
				}
			}
			if (G[i] == -1 && D[i] == -1) { cmpt++; }
			if (G[i] == -1 && D[i] != -1)
			{
				if (I[D[i]] > I[i]) { cmpt++; }
				else
				{
					j = NombreDeNoeud;
				}
			}
			if (D[i] == -1 && G[i] != -1)
			{
				if (I[G[i]] < I[i]) { cmpt++; }
				else
				{
					j = NombreDeNoeud;
				}
			}
			k++;
			i = 0;
		}
		if (cmpt == NombreDeNoeud) { cout << "True" << endl; }
		else { cout << "False" << endl; }
	}
private:
	Noeud* racine;
	int* I, * G, * D;
	int NombreDeNoeud;
};