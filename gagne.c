/**
 * \file gagne.c
 * \brief Programme de gestion de condition de victoire
 * \author Franck Meyer et Henri Pissa
 * \version 3.0
 * \date 23 février 2017
 *
 * Fonction partie gagnée
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"

/**
 * Fonction permettantde vérifier si une partie est gagnée
 *
 * \param p: pointeur sur la partie de 2048
 * \return 0: si le joueur ne dépasse pas valMax
 * \return 1:si le joueur atteint ou dépasse la valeur valMax 
 */
 
int gagne(jeu *p)
{
  int i;
	for(i=0;i<(*p).n*(*p).n;i++)//parcoure le tableau en entier (n*n) indice
	{
		if((*p).grille[i]>=(*p).valMax)
		{
			printf("Vous avez perdu !!! \n");
			return 1; //Partie gagné
		}
	}

	return 0; //Partie en cours (continue la partie)
}
