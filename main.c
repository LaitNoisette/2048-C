/**
 * \file main.c
 * \brief Programme principal.
 * \author Franck Meyer et Henri Pissa
 * \version 3.2
 * \date 10 février 2017
 *
 * Programme de principal du jeu de 2048
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "InitialiseJeu.h"
#include "ajouteValAlea.h"
#include "affichagecomplet.h"
#include "jouer.h"
#include "caseVide.h"
#include "couleurs_terminal.h"
#include "finPartie.h"
#include "gagne.h"
#include "getVal.h"
#include "indicevalide.h"
#include "InitialiseJeu.h"
#include "jouer.h"
#include "menu.h"
#include "mouvement.h"
#include "perdu.h"
#include "saisieM.h"
#include "saisieMD.h"
#include "sauvegardes.h"
#include "setVal.h"
#include <string.h>


int main(void){
    jeu p;
    jeu *pc=&p;
    initialiseJeu(pc, 4, 2048);
    ajouteValAlea(pc);
    int valMenu=0;
    int tailleGrille=4;
    int valMax=2048;
    int choixSave=1;
    char nom[5];
    jouer(pc);
    while (valMenu!=3)
    {
        valMenu=menu();
        if (valMenu==-1)
        {
            jouer(pc);
        }

        if (valMenu==0)
        {
            libereMemoire(pc);
            tailleGrille=menuTailleGrille();
            valMax=menuValMax();
            do{ 
                system("clear");
                printf("Saisir votre nom (Attention maximum 4 caractères) :");
                gets(nom);
            }while(strlen(nom)>4);
            
            initialiseJeu(pc,tailleGrille, valMax);
            (*pc).nom=nom;
            ajouteValAlea(pc);
            jouer(pc);
        }

        if (valMenu==1)
        {
            choixSave=menuChoixSave();
            sauvegarde(pc,choixSave);
            printf("Partie Sauvegardée");
        }

        if (valMenu==2)
        {
            choixSave=menuChoixSave();
            chargement(pc,choixSave);
            printf("Partie Chargée");
            jouer(pc);
        }
        
    }

    libereMemoire(pc);
    return 0;
}
