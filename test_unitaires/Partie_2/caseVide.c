#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"

int caseVide(jeu *p,int i,int j)
{
	if(indiceValide(p,i,j)==0)
	{
		return 0; //Faux, la case n'est pas vide'
	}

	else
	{
		if(getVal(p,i,j)==0)
		{
			return 1;//Vrai, la case est vide (=0)
		}
	}

	return 0;
}
