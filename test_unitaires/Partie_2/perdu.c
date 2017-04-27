#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "caseVide.h"
#include "getVal.h"
#include "indicevalide.h"

int perdu (jeu *p)
{
	int l=0;
	int c=0;
	int bool1=0;

	while(l<(*p).n && bool1==0)
	{
		while(c<(*p).n && bool1==0)
		{
			if(caseVide(p,l,c)==1)
			{
				bool1=1; //Case vide dans le tableau = partie non perdu
			}
			c++;
		}
		l++;
		c=0;
	}

	l=0;
	c=0;

	if(bool1==1)
	{
		return 0; //Partie non perdu
	}

	else
	{
		while(l<(*p).n)
		{
			while(c<(*p).n)
			{
				if(indiceValide(p,l,(c+1))==1)
				{
					if(getVal(p,l,c)==getVal(p,l,(c+1)))
					{
						return 0; //Valeur consécutive égale Verticalement, partie non perdue
					}
				}

				if(indiceValide(p,(l+1),c))
				{
					if(getVal(p,l,c)==getVal(p,(l+1),c))
					{
						return 0;//Valeur consécutive égale Horizontalement, partie non perdue
					}
				}
				c++;
			}

			l++;
			c=0;
		}
	}
    printf("Vous avez perdu !!!\n");
	return 1; //Partie Perdue

}
