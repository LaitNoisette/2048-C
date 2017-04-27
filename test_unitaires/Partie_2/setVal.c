#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"

int setVal(jeu *p,int ligne,int colonne,int val)
{
    int i;
	if(indiceValide(p,ligne,colonne)==1)
	{
		for(i=0;i<ligne;i++)
		{
			colonne=colonne+(*p).n;
		}
		if ((*p).grille[colonne]==0)
		{
			(*p).grille[colonne]=val;
			(*p).nbCasesLibres-=1;
			return 1;
		}
		else{
			(*p).grille[colonne]=val;
			return 1;
		}
		
	}
	else
	{
	    return 0;
	}

}
