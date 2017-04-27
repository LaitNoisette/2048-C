#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"


int gagne(jeu *p)
{
  int i;
	for(i=0;i<(*p).n*(*p).n;i++)//parcoure le tableau en entier (n*n) indice
	{
		if((*p).grille[i]>=(*p).valMax)
		{
			return 1; //Partie gagné
		}
	}

	return 0; //Partie en cours (continue la partie)
}
