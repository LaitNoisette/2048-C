/**
 * \file main.c
 * \brief Programme d'affichage menu.
 * \author Franck Meyer et Henri Pissa
 * \version 0.1
 * \date 18 février 2017
 *
 * Menu Interactif
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "couleurs_terminal.h"
#include "saisieM.h"
#include "saisieMD.h"

/*
 *Menu Interactif :
 *Utilisation des flèches directionnelles Haut & Bas pour naviguer dans le menu
 *Flèche Gauche & Echap permet de quitter le menu(retourne à la partie en cours)
 *Flèche Droite permet de valider l'option du menu sélectionné
 */
 
int menu() {
   system("clear");
   printf("\n\n\t\t\t2048");
   printf("\n\t\t      THE GAME");
   color_printf(WHITE, BLACK, "\n\n\t\tJOUER");
   printf("\n\n\t\tSAUVEGARDER");
   printf("\n\n\t\tCHARGER");
   printf("\n\n\t\tQUITTER");
   printf("\n\n");
   printf("\n");    
        color_printf(WHITE,BLACK,"Echap / Flèche Gauche : Retour à la partie");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Droite : Valider l'option'");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Haut : Déplacement Menu | Flèche Bas : Déplacement Menu");
        printf("\n");
   int saisie; 
   int nMenu = 0;
   do {
      saisie = saisieMD();

      //Partie du code gérant le déplacement de le menu à l'aide des flèches
      if (saisie == 2 && nMenu > 0) {
         nMenu--;
      }

      if (saisie == 0 && nMenu < 3) {
         nMenu++;
      }

      //Partie du code gérant l'affichage de l'option sélectionné dans le menu.
      if (nMenu == 0) {
         system("clear");
         printf("\n\n\t\t\t2048");
         printf("\n\t\t      THE GAME");
         color_printf(WHITE, BLACK, "\n\n\t\tJOUER");
         printf("\n\n\t\tSAUVEGARDER");
         printf("\n\n\t\tCHARGER");
         printf("\n\n\t\tQUITTER");
         printf("\n\n");
         printf("\n");    
        color_printf(WHITE,BLACK,"Echap / Flèche Gauche : Retour à la partie");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Droite : Valider l'option'");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Haut : Déplacement Menu | Flèche Bas : Déplacement Menu");
        printf("\n");
      }

      if (nMenu == 1) {
         system("clear");
         printf("\n\n\t\t\t2048");
        printf("\n\t\t      THE GAME");
         printf("\n\n\t\tJOUER");
         color_printf(WHITE, BLACK, "\n\n\t\tSAUVEGARDER");
         printf("\n\n\t\tCHARGER");
         printf("\n\n\t\tQUITTER");
         printf("\n\n");
         printf("\n");    
        color_printf(WHITE,BLACK,"Echap / Flèche Gauche : Retour à la partie");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Droite : Valider l'option'");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Haut : Déplacement Menu | Flèche Bas : Déplacement Menu");
        printf("\n");
      }

      if (nMenu == 2) {
         system("clear");
         printf("\n\n\t\t\t2048");
         printf("\n\t\t      THE GAME");
         printf("\n\n\t\tJOUER");
         printf("\n\n\t\tSAUVEGARDER");
         color_printf(WHITE, BLACK, "\n\n\t\tCHARGER");
         printf("\n\n\t\tQUITTER");
         printf("\n\n");
         printf("\n");    
        color_printf(WHITE,BLACK,"Echap / Flèche Gauche : Retour à la partie");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Droite : Valider l'option'");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Haut : Déplacement Menu | Flèche Bas : Déplacement Menu");
        printf("\n");
      }

      if (nMenu == 3) {
         system("clear");
         printf("\n\n\t\t\t2048");
         printf("\n\t\t      THE GAME");
         printf("\n\n\t\tJOUER");
         printf("\n\n\t\tSAUVEGARDER");
         printf("\n\n\t\tCHARGER");
         color_printf(WHITE, BLACK, "\n\n\t\tQUITTER");
         printf("\n\n");
         printf("\n");    
        color_printf(WHITE,BLACK,"Echap / Flèche Gauche : Retour à la partie");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Droite : Valider l'option'");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Haut : Déplacement Menu | Flèche Bas : Déplacement Menu");
        printf("\n");
      }

   } while (saisie != 1 && saisie != -1 && saisie != 3);
   system("clear");
   if (saisie == -1 || saisie == 3) {
      printf("Partie en cours !");
      return -1; // retourne à la partie en cours
   }

   if (saisie == 1) {
      // valide l'option sélectionné dans le menu
      if (nMenu == 0) {
         printf("Nouvelle partie !");
         return 0;
         //créer une nouvelle partie
      }

      if (nMenu == 1) {
         printf("Sauvegarde !");
         return 1;
         //sauvegarde la partie en cours
      }

      if (nMenu == 2) {
         printf("Charge !");
         return 2;
         //charge une partie
      }

      if (nMenu == 3) {
         printf("Merci d'avoir joué ! A bientôt ! \n");
         return 3;
         //quitte le jeu
      }
   }

}

/*Menu gérant le choix de la taille de la grille */

int menuTailleGrille() {
   system("clear");
   printf("\n\n\t\t\tTaille de la Grille :");
   color_printf(WHITE, BLACK, "\n\n\t\t3\t\t");
   printf("\n\n\t\t4");
   printf("\n\n\t\t5");
   printf("\n\n\t\t6");
   printf("\n\n\t\t7");
   printf("\n\n\t\t8");
   printf("\n\n");
   int saisie; 
   int nMenu = 0;
   do {
      saisie = saisieMD();

      //Partie du code gérant le déplacement de le menu à l'aide des flèches
      if (saisie == 2 && nMenu > 0) {
         nMenu--;
      }

      if (saisie == 0 && nMenu < 5) {
         nMenu++;
      }

      //Partie du code gérant l'affichage de l'option sélectionné dans le menu.
      if (nMenu == 0) {
        system("clear");
         printf("\n\n\t\t\tTaille de la Grille :");
         color_printf(WHITE, BLACK, "\n\n\t\t3\t\t");
         printf("\n\n\t\t4");
         printf("\n\n\t\t5");
         printf("\n\n\t\t6");
         printf("\n\n\t\t7");
         printf("\n\n\t\t8");
         printf("\n\n");
      }

      if (nMenu == 1) {
          system("clear");
         printf("\n\n\t\t\tTaille de la Grille :");
         printf("\n\n\t\t3");
         color_printf(WHITE, BLACK, "\n\n\t\t4\t\t");
         printf("\n\n\t\t5");
         printf("\n\n\t\t6");
         printf("\n\n\t\t7");
         printf("\n\n\t\t8");
         printf("\n\n");
      }

      if (nMenu == 2) {
          system("clear");
         printf("\n\n\t\t\tTaille de la Grille :");
         printf("\n\n\t\t3");
         printf("\n\n\t\t4");
         color_printf(WHITE, BLACK, "\n\n\t\t5\t\t");
         printf("\n\n\t\t6");
         printf("\n\n\t\t7");
         printf("\n\n\t\t8");
         printf("\n\n");
      }

      if (nMenu == 3) {
          system("clear");
         printf("\n\n\t\t\tTaille de la Grille :");
         printf("\n\n\t\t3");
         printf("\n\n\t\t4");
         printf("\n\n\t\t5");
         color_printf(WHITE, BLACK, "\n\n\t\t6\t\t");
         printf("\n\n\t\t7");
         printf("\n\n\t\t8");
         printf("\n\n");
      }

      if (nMenu == 4) {
          system("clear");
         printf("\n\n\t\t\tTaille de la Grille :");
         printf("\n\n\t\t3");
         printf("\n\n\t\t4");
         printf("\n\n\t\t5");
         printf("\n\n\t\t6");
         color_printf(WHITE, BLACK, "\n\n\t\t7\t\t");
         printf("\n\n\t\t8");
         printf("\n\n");
      }

      if (nMenu == 5) {
          system("clear");
         printf("\n\n\t\t\tTaille de la Grille :");
         printf("\n\n\t\t3");
         printf("\n\n\t\t4");
         printf("\n\n\t\t5");
         printf("\n\n\t\t6");
         printf("\n\n\t\t7");
         color_printf(WHITE, BLACK, "\n\n\t\t8\t\t");
         printf("\n\n");
      }

   } while (saisie != 1);
   system("clear");

   if (saisie == 1) {
      // valide l'option sélectionné dans le menu
      if (nMenu == 0) {
         return 3;
      }

      if (nMenu == 1) {
         return 4;
      }

      if (nMenu == 2) {
         return 5;

      }

      if (nMenu == 3) {
         return 6;
      }

      if (nMenu == 4) {
         return 7;
      }

      if (nMenu == 5) {
         return 8;
      }
   }

}


int menuValMax() {
   system("clear");
   printf("\n\n\t\t\tValeur pour gagner :");
   color_printf(WHITE, BLACK, "\n\n\t\t512\t\t");
   printf("\n\n\t\t1024");
   printf("\n\n\t\t2048");
   printf("\n\n\t\t4096");
   printf("\n\n\t\t8192");
   printf("\n\n");
   int saisie; // à modifier le nom 
   int nMenu = 0;
   do {
      saisie = saisieMD();

      //Partie du code gérant le déplacement de le menu à l'aide des flèches
      if (saisie == 2 && nMenu > 0) {
         nMenu--;
      }

      if (saisie == 0 && nMenu < 4) {
         nMenu++;
      }

      //Partie du code gérant l'affichage de l'option sélectionné dans le menu.
      if (nMenu == 0) {
         system("clear");
   printf("\n\n\t\t\tValeur pour gagner :");
   color_printf(WHITE, BLACK, "\n\n\t\t512\t\t");
   printf("\n\n\t\t1024");
   printf("\n\n\t\t2048");
   printf("\n\n\t\t4096");
   printf("\n\n\t\t8192");
   printf("\n\n");
      }

      if (nMenu == 1) {
         system("clear");
   printf("\n\n\t\t\tValeur pour gagner :");
   printf("\n\n\t\t512");
   color_printf(WHITE, BLACK, "\n\n\t\t1024\t\t");
   printf("\n\n\t\t2048");
   printf("\n\n\t\t4096");
   printf("\n\n\t\t8192");
   printf("\n\n");
      }

      if (nMenu == 2) {
         system("clear");
   printf("\n\n\t\t\tValeur pour gagner :");
   printf("\n\n\t\t512");
   printf("\n\n\t\t1024");
   color_printf(WHITE, BLACK, "\n\n\t\t2048\t\t");
   printf("\n\n\t\t4096");
   printf("\n\n\t\t8192");
   printf("\n\n");
      }

      if (nMenu == 3) {
         system("clear");
   printf("\n\n\t\t\tValeur pour gagner :");
   printf("\n\n\t\t512");
   printf("\n\n\t\t1024");
   printf("\n\n\t\t2048");
   color_printf(WHITE, BLACK, "\n\n\t\t4096\t\t");
   printf("\n\n\t\t8192");
   printf("\n\n");
      }

      if (nMenu == 4) {
         system("clear");
   printf("\n\n\t\t\tValeur pour gagner :");
   printf("\n\n\t\t512");
   printf("\n\n\t\t1024");
   printf("\n\n\t\t2048");
   printf("\n\n\t\t4096");
   color_printf(WHITE, BLACK, "\n\n\t\t8192\t\t");
   printf("\n\n");
      }

   } while (saisie != 1);
   system("clear");

   if (saisie == 1) {
      // valide l'option sélectionné dans le menu
      if (nMenu == 0) {
         return 512;
      }

      if (nMenu == 1) {
         return 1024;
      }

      if (nMenu == 2) {
         return 2048;

      }

      if (nMenu == 3) {
         return 4096;
      }

      if (nMenu == 4) {
         return 8192;
      }
   }

}

int menuChoixSave() {
    printf("TEST 1");
   system("clear");
   printf("\n\n\t\t\tChoisir la Sauvegarde :");
   color_printf(WHITE, BLACK, "\n\n\t\tSauvegarde 1\t\t");
   printf("\n\n\t\tSauvegarde 2");
   printf("\n\n\t\tSauvegarde 3");
   printf("\n\n\t\tSauvegarde 4");
   printf("\n\n\t\tSauvegarde 5");
   printf("\n\n");
   int saisie; // à modifier le nom 
   int nMenu = 0;
   do {
      saisie = saisieMD();

      //Partie du code gérant le déplacement de le menu à l'aide des flèches
      if (saisie == 2 && nMenu > 0) {
         nMenu--;
      }

      if (saisie == 0 && nMenu < 4) {
         nMenu++;
      }

      //Partie du code gérant l'affichage de l'option sélectionné dans le menu.
      if (nMenu == 0) {
         system("clear");
   printf("\n\n\t\t\tChoisir la Sauvegarde :");
   color_printf(WHITE, BLACK, "\n\n\t\tSauvegarde 1\t\t");
   printf("\n\n\t\tSauvegarde 2");
   printf("\n\n\t\tSauvegarde 3");
   printf("\n\n\t\tSauvegarde 4");
   printf("\n\n\t\tSauvegarde 5");
   printf("\n\n");
   printf("\n");    
      }

      if (nMenu == 1) {
        system("clear");
   printf("\n\n\t\t\tChoisir la Sauvegarde :");
   printf("\n\n\t\tSauvegarde 1");
   color_printf(WHITE, BLACK, "\n\n\t\tSauvegarde 2\t\t");
   printf("\n\n\t\tSauvegarde 3");
   printf("\n\n\t\tSauvegarde 4");
   printf("\n\n\t\tSauvegarde 5");
   printf("\n\n");
   printf("\n");    
        
      }

      if (nMenu == 2) {
          system("clear");
   printf("\n\n\t\t\tChoisir la Sauvegarde :");
   printf("\n\n\t\tSauvegarde 1");
   printf("\n\n\t\tSauvegarde 2");
   color_printf(WHITE, BLACK, "\n\n\t\tSauvegarde 3\t\t");
   printf("\n\n\t\tSauvegarde 4");
   printf("\n\n\t\tSauvegarde 5");
   printf("\n\n");
       
        
      }

      if (nMenu == 3) {
         system("clear");
   printf("\n\n\t\t\tChoisir la Sauvegarde :");
   printf("\n\n\t\tSauvegarde 1");
   printf("\n\n\t\tSauvegarde 2");
   printf("\n\n\t\tSauvegarde 3");
   color_printf(WHITE, BLACK, "\n\n\t\tSauvegarde 4\t\t");
   printf("\n\n\t\tSauvegarde 5");
   printf("\n\n");
      }

      if (nMenu == 4) {
         system("clear");
   printf("\n\n\t\t\tChoisir la Sauvegarde :");
   printf("\n\n\t\tSauvegarde 1");
   printf("\n\n\t\tSauvegarde 2");
   printf("\n\n\t\tSauvegarde 3");
   printf("\n\n\t\tSauvegarde 4");
   color_printf(WHITE, BLACK, "\n\n\t\tSauvegarde 5\t\t");
   printf("\n\n");
      }

   } while (saisie != 1);
   system("clear");

   if (saisie == 1) {
      // valide l'option sélectionné dans le menu
      if (nMenu == 0) {
         return 1;
      }

      if (nMenu == 1) {
         return 2;
      }

      if (nMenu == 2) {
         return 3;

      }

      if (nMenu == 3) {
         return 4;
      }

      if (nMenu == 4) {
         return 5;
      }
   }

}