/**
 * \file jouer.c
 * \brief Programme de controle de jeu.
 * \author Franck Meyer et Henri Pissa
 * \version 2.0
 * \date 10 février 2017
 *
 * Programme permettant de jouer la partie en cours
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "mouvement.h"
#include "finPartie.h"

/**
 * Fonction permettant de jouer la partie en cours
 *
 * \param p: pointeur sur la partie de 2048
 * \return 1 : si partie perdu ou partie gagné
 * \return 0 : si partie toujours en cours
 */

int jouer(jeu *p)
{
	int choix=0;
	do
	{
		affichage(p);
		choix=saisieMD();
		if(choix==0)
		{
			mouvement(p, 0);
		}
		else if(choix==1)
		{
			mouvement(p, 1);
		}
		else if(choix==2)
		{
			mouvement(p, 2);
		}
		else if(choix==3)
		{
			mouvement(p, 3);
		}
		finPartie(p);
        system("clear");
	}
	while(finPartie(p)!=1 && choix!=-1);
	if(finPartie(p)==1)
	{
		return 1;
	}

	return 0;
}
