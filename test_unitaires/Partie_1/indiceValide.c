#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"

int indiceValide(jeu *p, int i, int j)
	{
		if (i>=(*p).n || i<0)
			{
				return 0;
			}
		else
		{
			if (j>=0 && j<(*p).n)
			{
				return 1;
			}
		}

		return 0;
	}
