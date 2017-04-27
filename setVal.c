/**
 * \file setVal.c
 * \brief Programme permettant de modifier une case.
 * \author Franck Meyer et Henri Pissa
 * \version 2.0
 * \date 10 février 2017
 */
#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"

/**
 * Fonction modifiant la valeur de la case (ligne, colonne) de la partie p avec la valeur val
 *
 * \param p: pointeur sur la partie de 2048
 * \param val: entier à mettre dans la case (i,j) si elle existe
 * \param ligne: entier correspondant au numéro de ligne
 * \param colonne: entier correspondant au numéro de colonne
 * \return 1 : si la valeur a été correctement modifiée
 * \return 0 : si la valeur n'a pas été modifiée
 */

int setVal(jeu *p,int ligne,int colonne,int val)
{
    int i;
	if(indiceValide(p,ligne,colonne)==1)
	{
		for(i=0;i<ligne;i++)
		{
			colonne=colonne+(*p).n;
		}
		if ((*p).grille[colonne]==0) // Cas où la valeur à modifier est null
		{
			(*p).grille[colonne]=val;
			(*p).nbCasesLibres-=1;
			return 1;
		}
		else{ // Cas où la valeur à modifier est différent de 0
			(*p).grille[colonne]=val;
			return 1;
		}
		
	}
	else
	{
	    return 0;
	}

}
