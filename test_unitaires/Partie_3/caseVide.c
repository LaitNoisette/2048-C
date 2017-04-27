/**
 * \file caseVide.c
 * \brief Programme permettant de vérifier la valeur 0 d'une case.
 * \author Franck Meyer et Henri Pissa
 * \version 1.0
 * \date 10 février 2017
 */
#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"

/**
 * Fonction vérifiant au'une case est vide
 *
 * \param p: pointeur sur la partie de 2048
 * \param i: entier correspondant au numéro de ligne
 * \param j: entier correspondant au numéro de colonne
 * \return 1 : si la case est vide
 * \return 0 : si la case n'est pas vide ou n'existe pas
 */

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
