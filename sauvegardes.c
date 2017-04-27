/**
 * \file sauvegarde.c
 * \brief Programme de gestion des sauvegardes du 2048
 * \author Franck Meyer et Henri Pissa
 * \version 4.0
 * \date 21 février 2017
 *
 * Sauvegarde et Chargement de partie 2048
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "InitialiseJeu.h"

/**
 * Fonction effectuant la sauvegarde d'une partie en cours de 2048
 *
 * \param p: pointeur sur la partie de 2048
 * \return 1 : si la sauvegarde a été un succès
 * \return 0 : en cas de problème
 */

int sauvegarde(jeu *p,int emplacement)
{
    FILE *fich; /* initialisation d'un fichier*/
    int nr=0;

    if(emplacement==1)
    {
        fich=fopen("sauvegarde/sauv.dat", "wb");

        if (fich == NULL)
        {
        fprintf(stderr, "\nErreur de fopen\n");
            exit(-1);
        }

        rewind(fich);
        
        nr+=fwrite(&(*p).n,sizeof(int), 1,fich);
        nr+=fwrite(&(*p).valMax,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).nbCasesLibres,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).score,sizeof(int),1, fich);
        nr+=fwrite((*p).grille,sizeof(int),(*p).n*(*p).n,fich);
        printf("TEST 1\n");
        
    }

    if(emplacement==2)
    {
        fich=fopen("sauvegarde/sauv2.dat", "wb");
        if (fich == NULL)
        {
        fprintf(stderr, "\nErreur de fopen\n");
            exit(-1);
        }

        rewind(fich);
        printf("TEST 1\n");
        
        nr+=fwrite(&(*p).n,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).valMax,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).nbCasesLibres,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite((*p).grille,sizeof(int),(*p).n*(*p).n,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).score,sizeof(int),1, fich);
    }

    if(emplacement==3)
    {
        fich=fopen("sauvegarde/sauv3.dat", "wb");
        if (fich == NULL)
        {
        fprintf(stderr, "\nErreur de fopen\n");
            exit(-1);
        }

        rewind(fich);
        printf("TEST 1\n");
        
        nr+=fwrite(&(*p).n,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).valMax,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).nbCasesLibres,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite((*p).grille,sizeof(int),(*p).n*(*p).n,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).score,sizeof(int),1, fich);
    }

    if(emplacement==4)
    {
        fich=fopen("sauvegarde/sauv4.dat", "wb");
        if (fich == NULL)
        {
        fprintf(stderr, "\nErreur de fopen\n");
            exit(-1);
        }

        rewind(fich);
        printf("TEST 1\n");
        
        nr+=fwrite(&(*p).n,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).valMax,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).nbCasesLibres,sizeof(int), 1,fich);
        printf("TEST 1\n");
        nr+=fwrite((*p).grille,sizeof(int),(*p).n*(*p).n,fich);
        printf("TEST 1\n");
        nr+=fwrite(&(*p).score,sizeof(int),1, fich);
    }

    if(emplacement==5)
    {
        fich=fopen("sauvegarde/sauv5.dat", "wb");
        if (fich == NULL)
        {
        fprintf(stderr, "\nErreur de fopen\n");
            exit(-1);
        }

        rewind(fich);
       
        
        nr+=fwrite(&(*p).n,sizeof(int), 1,fich);
        
        nr+=fwrite(&(*p).valMax,sizeof(int), 1,fich);
        
        nr+=fwrite(&(*p).nbCasesLibres,sizeof(int), 1,fich);
        
        nr+=fwrite((*p).grille,sizeof(int),(*p).n*(*p).n,fich);
        
        nr+=fwrite(&(*p).score,sizeof(int),1, fich);
    }
    

    fclose(fich);

    if(nr!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * Fonction effectuant le chargement d'une partie présauvegardée de 2048
 *
 * \param p: pointeur sur la partie de 2048
 * \return 1 : si le chargement de la partie a été un succès
 * \return 0 : en cas de problème
 */

int chargement(jeu *p,int emplacement)
{
    int taille=((*p).n*(*p).n);
    FILE *fichier; /* initialisation d'un fichier*/
    int nb=0;

    if(emplacement==1)
    {
        fichier=fopen("sauvegarde/sauv.dat", "rb"); /* ouverture du fichier en lecture binaire */
        if(fichier==NULL)
        {
            printf("Erreur de fopen\n");
            exit(-1);
        }
        rewind(fichier);

        nb+=fread(&(*p).n,sizeof(int),1,fichier);
        printf("TEST 1\n");
        nb+=fread(&(*p).valMax,sizeof(int),1,fichier);
        printf("TEST 2\n");
        nb+=fread(&(*p).nbCasesLibres,sizeof(int),1,fichier);
        printf("TEST 3\n");
        nb+=fread(&(*p).score,sizeof(int),1,fichier);
        nb+=fread((*p).grille,malloc(sizeof(int)),taille,fichier);
        printf("TEST 4\n");
        
    }

    if(emplacement==2)
    {
        fichier=fopen("sauvegarde/sauv2.dat", "rb"); /* ouverture du fichier en lecture binaire */
        if(fichier==NULL)
        {
            printf("Erreur de fopen\n");
            exit(-1);
        }
        rewind(fichier);

        nb+=fread(&(*p).n,sizeof(int),1,fichier);
        printf("TEST 1\n");
        nb+=fread(&(*p).valMax,sizeof(int),1,fichier);
        printf("TEST 2\n");
        nb+=fread(&(*p).nbCasesLibres,sizeof(int),1,fichier);
        printf("TEST 3\n");
        nb+=fread(&(*p).score,sizeof(int),1,fichier);
        nb+=fread((*p).grille,malloc(sizeof(int)),taille,fichier);
        printf("TEST 4\n");
        
    }

    if(emplacement==3)
    {
        fichier=fopen("sauvegarde/sauv3.dat", "rb"); /* ouverture du fichier en lecture binaire */
        if(fichier==NULL)
        {
            printf("Erreur de fopen\n");
            exit(-1);
        }
        rewind(fichier);

        nb+=fread(&(*p).n,sizeof(int),1,fichier);
        printf("TEST 1\n");
        nb+=fread(&(*p).valMax,sizeof(int),1,fichier);
        printf("TEST 2\n");
        nb+=fread(&(*p).nbCasesLibres,sizeof(int),1,fichier);
        printf("TEST 3\n");
        nb+=fread(&(*p).score,sizeof(int),1,fichier);
        nb+=fread((*p).grille,malloc(sizeof(int)),taille,fichier);
        printf("TEST 4\n");
        
    }

    if(emplacement==4)
    {
        fichier=fopen("sauvegarde/sauv4.dat", "rb"); /* ouverture du fichier en lecture binaire */
        if(fichier==NULL)
        {
            printf("Erreur de fopen\n");
            exit(-1);
        }
        rewind(fichier);

        nb+=fread(&(*p).n,sizeof(int),1,fichier);
        printf("TEST 1\n");
        nb+=fread(&(*p).valMax,sizeof(int),1,fichier);
        printf("TEST 2\n");
        nb+=fread(&(*p).nbCasesLibres,sizeof(int),1,fichier);
        printf("TEST 3\n");
        nb+=fread(&(*p).score,sizeof(int),1,fichier);
        nb+=fread((*p).grille,malloc(sizeof(int)),taille,fichier);
        printf("TEST 4\n");
        
    }

    if(emplacement==5)
    {
        fichier=fopen("sauvegarde/sauv5.dat", "rb"); /* ouverture du fichier en lecture binaire */
        if(fichier==NULL)
        {
            printf("Erreur de fopen\n");
            exit(-1);
        }
        rewind(fichier);

        nb+=fread(&(*p).n,sizeof(int),1,fichier);
        printf("TEST 1\n");
        nb+=fread(&(*p).valMax,sizeof(int),1,fichier);
        printf("TEST 2\n");
        nb+=fread(&(*p).nbCasesLibres,sizeof(int),1,fichier);
        printf("TEST 3\n");
        nb+=fread(&(*p).score,sizeof(int),1,fichier);
        nb+=fread((*p).grille,malloc(sizeof(int)),taille,fichier);
        printf("TEST 4\n");
        
    }
    
    fclose(fichier);
    if(nb!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}