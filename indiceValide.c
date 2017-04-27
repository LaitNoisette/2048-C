#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"

/**
 * \file indicevalide.c
 * \brief Programme de gestion des indices
 * \author Franck Meyer et Henri Pissa
 * \version 1.0
 * \date 13 février 2017
 *
 */

 /**
 * Fonction vérifiant la valididté d'un indice
 *
 * \param p: pointeur sur la partie de 2048
 * \param i: entier correspondant au numéro de ligne
 * \param j: entier correspondant au numéro de colonne
 * \return 1 : si l'indice est valide
 * \return 0 : si l'indice est invalide
 */

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
