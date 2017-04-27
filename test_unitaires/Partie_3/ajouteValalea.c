/**
 * \file ajouteValAlea.c
 * \brief Programme de génération de valeur aléatoire
 * \author Franck Meyer et Henri Pissa
 * \version 3.0
 * \date 23 février 2017
 *
 * Gestion de valeur aléatoire
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "caseVide.h"
#include "setVal.h"

/**
 * Fonction permettant l'ajout aléatoire d'une valeur sur une case
 * Elle ajoute aléatoirement 2 ou 4
 * Elle choisie aléatoirement une case vide
 *
 * \param p: pointeur sur la partie de 2048
 *
 */
 
void ajouteValAlea(jeu *p)
{
	int i;
	int j;
	int val;
	int bool1=0;
	time_t t;

	srand((unsigned) time(&t));

	i=rand()%(*p).n;
	j=rand()%(*p).n;

	while(bool1==0) //booléen tant que la case sélectionner n'est pas vide on boucle
	{
		if(caseVide(p,i,j)==1)
		{
			while(val!=2 && val!=4)
			{
				val=rand()%5;
			}
			bool1=1;
		}
		else //change la valeur de la ligne et de la colonne
		{
			i=rand()%(*p).n;
			j=rand()%(*p).n;
		}

	}

	setVal(p,i,j,val);
}
