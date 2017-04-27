/**
 * \file affichagecomplet.c
 * \brief Programme d'affichage de la gille du 2048
 * \author Franck Meyer et Henri Pissa
 * \version 3.0
 * \date 18 février 2017
 *
 * Affichage du jeu 2048
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <termios.h>
#include <unistd.h>
#include "InitialiseJeu.h"
#include "couleurs_terminal.h"

/**
 * Fonction effectuant l'affichage d'une grille de 2048 sous forme de tableau avec couleurs
 *
 * \param p: pointeur sur la partie de 2048
 * couleur : noir (couleur de la grille)
 * couleur : blanc (couleur de la police et des valeurs  2 et 4 )
 * couleur : bleu (couleur de la police et des valeurs  8 et 16 )
 * couleur : cyan (couleur de la police et des valeurs  32 et 64 )
 * couleur : vert (couleur de la police et des valeurs  128 et 256 )
 * couleur : jaune (couleur de la police et de la valeur  512 )
 * couleur : magenta (couleur de la police et de la valeur  1024 )
 * couleur : rouge (couleur de la police et de la  valeur  2048 )

 */

void affichage(jeu *p)
{
    int t=5;
    int i; //gère les lignes 
    int j; //gère les nombres d'affichages lignes par case
    int k; //gère les colonnes
    system("clear");
    printf("\n");
    color_printf(WHITE,BLACK,"Joueur :");
    printf("%s",(*p).nom);
    printf("\t\t\t");
    color_printf(WHITE,BLACK,"Score :");
    printf("%d",(*p).score);
    printf("\n");

    for(i=0;i<(*p).n;i++)
    {
        for(j=0;j<t;j++)
        {
            for(k=0;k<(*p).n;k++)
            {
                color_printf(BLACK,BLACK," ");
                if(getVal(p,i,k)==0)
                {
                    if(j==t/2)
                    {
                        printf("\t.\t");
                    }

                    else
                    {
                        printf("\t\t");
                    }
                    
                }
        
                if(getVal(p,i,k)==2 || getVal(p,i,k)==4)
                {
                    if(j==t/2)
                    {
                        color_printf(WHITE,WHITE,"\t%d\t",getVal(p,i,k));
                    }
                    
                    else
                    {
                        color_printf(WHITE,WHITE,"\t\t");
                    }
                    
                }

                if(getVal(p,i,k)==8 || getVal(p,i,k)==16)
                {
                    if(j==t/2)
                    {
                        color_printf(WHITE,BLUE,"\t%d\t",getVal(p,i,k));
                    }
                    
                    else
                    {
                        color_printf(WHITE,BLUE,"\t\t");
                    }

                }

                if(getVal(p,i,k)==32 || getVal(p,i,k)==64)
                {
                    if(j==t/2)
                    {
                        color_printf(WHITE,CYAN,"\t%d\t",getVal(p,i,k));
                    }
                    
                    else
                    {
                        color_printf(WHITE,CYAN,"\t\t");
                    }
                     
                }

                if(getVal(p,i,k)==128 || getVal(p,i,k)==256)
                {
                    if(j==t/2)
                    {
                        color_printf(WHITE,GREEN,"\t%d\t",getVal(p,i,k));
                    }
                    
                    else
                    {
                        color_printf(WHITE,GREEN,"\t\t");
                    }
                     
                }

                if(getVal(p,i,k)==512)
                {
                    if(j==t/2)
                    {
                        color_printf(WHITE,YELLOW,"\t%d\t",getVal(p,i,k));
                    }
                    
                    else
                    {
                        color_printf(WHITE,YELLOW,"\t\t");
                    }
                     
                }

                if(getVal(p,i,k)==1024)
                {
                    if(j==t/2)
                    {
                        color_printf(WHITE,MAGENTA,"\t%d\t",getVal(p,i,k));
                    }
                    
                    else
                    {
                        color_printf(WHITE,MAGENTA,"\t\t");
                    }
                     
                }

                if(getVal(p,i,k)>=2048)
                {
                    if(j==t/2)
                    {
                        color_printf(WHITE,RED,"\t%d\t",getVal(p,i,k));
                    }
                    
                    else
                    {
                        color_printf(WHITE,RED,"\t\t");
                    }
                     
                }

            }
            color_printf(BLACK,BLACK," ");
            if(j!=t-1)
            {
                printf("\n");
            }
            
        }
        printf("\n");     
        printf("\n");
        printf("\n");
    }
        printf("\n");     
        color_printf(WHITE,BLACK,"Echap : MENU");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Gauche : Déplacement Gauche | Flèche Droite : Déplacement Droite");
        printf("\n");
        color_printf(WHITE,BLACK,"Flèche Haut : Déplacement Haut | Flèche Bas : Déplacement Bas");
        printf("\n");
}
