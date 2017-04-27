/**
 * \file gagne.c
 * \brief Programme de gestion de condition d'arret d'une partie
 * \author Franck Meyer et Henri Pissa
 * \version 2.0
 * \date 23 février 2017
 *
 * Fonction partie finPartie
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "gagne.h"
#include "perdu.h"

/**
 * Fonction permettantde vérifier si une partie est fini
 *
 * \param p: pointeur sur la partie de 2048
 * \return 0: si la partie n'est ni gagnée ni perdue
 * \return 1:si la partie est remportée ou perdue
 */

int finPartie(jeu *p)
{
    if(gagne(p)==1 || perdu(p)==1)
    {
        printf("Appuyer sur une touche pour continuer\n");
        saisieMD();
        return 1;
    }
    else
    {
        return 0;
    }
}
