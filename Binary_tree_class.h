#pragma once
#include<iostream>
#include "Node_class.h"
using namespace std;
class ArbreBinaire // Class that create the tree
{
public:

	ArbreBinaire(int N) 
	{	// This constructor take three array to create the tree and initialize the number of node at to the to N which is going to be the number 
					//data in file and the root at NULL   
		I = new int[N];
		G = new int[N];
		D = new int[N];
		NombreDeNoeud = N;
		racine = NULL;
	}
	void ReceptionDeDonne(int N) // function that helps to receive the data
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

	void inserer(int val, Noeud* a)
	{			// recursive function that add the nodes from the entries
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
	void afficherPreOrdre(int val) // Print in PreOrdre
	{
		if (val == -1) { return; }
		else
		{
			cout << I[val] << " ";
			afficherPreOrdre(G[val]);
			afficherPreOrdre(D[val]);
		}
	}
	void afficherSuffixe(int val) // Print in  Suffixe
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
	void Largeur()
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
	void ESTILBINAIRE() 
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
