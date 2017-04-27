/**
 * \file Partie4test.c
 * \brief Programme de test.
 * \author Franck Meyer et Henri Pissa
 * \version 1.0
 * \date 20 février 2017
 *
 * Programme de test Partie 2 du jeu 2048
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "InitialiseJeu.h"
#include "mouvement.h"

int termine(const char *ch)
{
    printf("******************************************\n");
    printf("************  PROBLEME  ******************\n");
    printf("* %s *\n", ch);
    printf("******************************************\n");
    return 0;
}

void test_partie4()
{
    int somme=0;
    somme+= test_fonction_sauvegarde();
    somme+= test_fonction_chargement();

    if (somme!=2)
    {
        termine("TOUS LES TESTS DE LA PARTIE 4 NE SONT PAS PASSES !");
    }
    else
    {
        termine("TEST PARTIE 4 OK");
    }
}

