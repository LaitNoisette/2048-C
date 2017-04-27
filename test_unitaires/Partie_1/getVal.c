#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"

int getVal(jeu *p,int ligne,int colonne) //Penser à utiliser modulo n de la colonne
{
    int i;
	if(indiceValide(p,ligne,colonne)==0)
	{
		return -1; //Faux retourne -1
	}

	else
	{
		for(i=0;i<ligne;i++)
		{
			colonne=colonne+(*p).n;
		}

		return (*p).grille[colonne]; //Vrai retourne la valeur
	}
}
