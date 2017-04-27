/**
 * \file getVal.c
 * \brief Programme permettant de récupérer la valeur d'une case.
 * \author Franck Meyer et Henri Pissa
 * \version 2.0
 * \date 10 février 2017
 */
#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"

/**
 * Fonction retournant la valeur de la case (ligne, colonne) de la partie p
 *
 * \param p: pointeur sur la partie de 2048
 * \param ligne: entier correspondant au numéro de ligne
 * \param colonne: entier correspondant au numéro de colonne
 * \return -1 : si la case n'existe pas
 * \return case : retourne valeur de la case
 */


int getVal(jeu *p,int ligne,int colonne) 
{
    int i;
	if(indiceValide(p,ligne,colonne)==0)
	{
		return -1; 
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
