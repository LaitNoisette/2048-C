/**
 * \file saiseMD.c
 * \brief Programme de gestion du mouvement
 * \author Franck Meyer
 * \version 5.0
 * \date 21 février 2017
 *
 * Fonction de controle avec flèches du jeu 2048
 *
 */

#include "saisieM.h"
#include "couleurs_terminal.h"

/**
 * Fonction permettant la saisie d'une direction ou l'arrêt du jeu
 *La saisie est répétée pour les autres touches
 *
 * \return -1 : si l'utilisateur arrete le jeu
 * \return 0 : si l'utilisateur souhaite déplacer vers le bas
 * \return 1 : si l'utilisateur souhaite déplacer vers la droite
 * \return 2 : si l'utilisateur souhaite déplacer vers le haut
 * \return 3 : si l'utilisateur souhaite déplacer vers la gauche
 */

int saisieMD()
{
    //Début du mode saisie des flèches ou de la touche Echap sans appuyer sur entrée pour valider
	debutTerminalSansR();

	Key touche;//Définition d'une touche

	touche = lectureFleche();//On lit une flèche (ou la touche echap)

	while ( touche != KEY_ESCAPE)//Tant que l'on n'a pas appuyé sur la touche echap
	{
		//On affiche quelle flèche a été saisie
		if (touche == KEY_UP)
        {
            //color_printf(RED,BLUE,"FLECHE HAUT");
            finTerminalSansR();
            return 2;
        }
		else if (touche == KEY_DOWN)
        {
            //color_printf(MAGENTA,BLACK,"FLECHE BAS");
            finTerminalSansR();
            return 0;
        }
		else if (touche == KEY_LEFT)
        {
            //color_printf(CYAN,YELLOW,"FLECHE GAUCHE");
            finTerminalSansR();
            return 3;
        }
		else if (touche == KEY_RIGHT)
        {
            //color_printf(GREEN,WHITE,"FLECHE DROITE");
            finTerminalSansR();
            return 1;
        }
			
		else //touche vaut la valeur NO_KEY
			//printf("Pas de flèche saisie");
		//printf("\n");

		touche = lectureFleche();//On lit une flèche (ou la touche echap)

	}
	finTerminalSansR();

	return -1;
}