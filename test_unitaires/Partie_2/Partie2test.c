/**
 * \file Partie3test.c
 * \brief Programme de test.
 * \author Franck Meyer et Henri Pissa
 * \version 2.1
 * \date 17 février 2017
 *
 * Programme de test Partie 2 du jeu 2048
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"
#include "setVal.h"
#include "getVal.h"
#include "finPartie.h"
#include "caseVide.h"
#include "ajouteValAlea.h"



int termine(const char *ch)
{
    printf("******************************************\n");
    printf("************  PROBLEME  ******************\n");
    printf("* %s *\n", ch);
    printf("******************************************\n");
    return 0;
}

int test_fonction_caseVide()
{
    int i;
    int j;
    int n=4;
    int Vmax=2048;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);

    int somme = 0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
           somme+=caseVide(tmp,i,j);
        }
    }

    if (somme != n*n)
    {
        return termine("caseVide ne retourne pas 1 correctement !");
    }

    if(caseVide(tmp,-1,2)||caseVide(tmp,n,2))
    {
        return termine("caseVide ne retourne pas 0 correctement");
    }

    if(caseVide(tmp,3,-1)||caseVide(tmp,3,n))
    {
      return termine("caseVide ne retourne pas 0 correctement");
    }
    int res= caseVide(tmp,1,1);
    if (res==0)
    {
      return termine("Il semble que caseVide ne renvoie pas la bonne valeur");
    }
    if (somme!=tmp->nbCasesLibres)
    {
       return termine("le nombre de cases vides est différent de la des valeurs retournées par caseVides");
    }
    setVal(tmp,0,2,3);
    if(caseVide(tmp,0,2)!=0)
    {
      return termine("caseVide ne renvoie pas la bonne valeur !");
    }
    libereMemoire(tmp);
    return 1;
}


int test_fonction_ajouteValAlea()
{
    int n=4;
    int Vmax=2048;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);
    int i, j;
    int somme=0;
    ajouteValAlea(tmp);
    for(i=0; i<n*n; i++)
    {
        somme+=tp.grille[i];
    }
    if (somme==n*n)
    {
        return termine("ajouteValAlea ne modifie pas correctement !");
    }
    if (somme!=2 && somme!=4)
    {
        return termine("ajouteValAlea ne remplit pas les cases avec 2 ou 4 correctement !");
    }
    for (i=0; i<(n*n)-2; i++)
    {
      tp.grille[i]=i+1;
    }

    somme=0;
    for(i=0; i<n*n; i++)
    {
        somme+=tp.grille[i];
    }
    ajouteValAlea(tmp);
    int somme2=0;
    for(i=0; i<n*n; i++)
    {
        somme2+=tp.grille[i];
    }
    if (somme2<=somme)
    {
        return termine("ajouteValAlea ne modifie pas les cases avec 2 ou 4 correctement !");
    }
    if ((somme2!=somme+2)&&(somme2!=somme+4))
    {
        return termine("ajouteValAlea ne modifie pas les cases avec les valeurs 2 ou 4 !");
    }
    for (i=0; i<(n*n)-1; i++)
    {
      tp.grille[i]=i+1;
    }
    for (i=0; i<(n*n); i++)
    {
      tp.grille[i]=i+1;
    }
    somme=0;
    somme2=0;
    n=3;
    Vmax=2048;
    libereMemoire(tmp);
    initialiseJeu(tmp, n, Vmax);
    for(i=0; i<n*n; i++)
    {
        somme+=tp.grille[i];
    }
    ajouteValAlea(tmp);
    for(i=0; i<n*n; i++)
    {
        somme2+=tp.grille[i];
    }
    if (somme2==somme)
    {
        return termine("ajouteValAlea modifie où il ne faut pas!");
    }
    libereMemoire(tmp);

    return 1;
}


int test_fonction_gagne()
{
    int n=6;
    int Vmax=2048;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);
    int i, j;
    int res= gagne(tmp);
    if(res!=0)
        return termine("gagne ne retourne pas la bonne valeur!");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            setVal(tmp,i,j, 4+i);
        }
    }
    res= gagne(tmp);
    if(res!=0)
        return termine("gagne ne retourne pas la bonne valeur!");
    setVal(tmp,2,2, Vmax);
    res= gagne(tmp);
    if(res!=1)
        return termine("gagne ne retourne pas la bonne valeur!");
    setVal(tmp,2,2, Vmax+20);
    res= gagne(tmp);
    if(res!=1)
        return termine("gagne ne retourne pas la bonne valeur!");
    libereMemoire(tmp);
    return 1;
}


int test_fonction_perdu()
{
    int n=6;
    int Vmax=2048;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);
    int i, j;
    int res= perdu(tmp);
    if(res!=0)
        return termine("perdu devrait retourner 0 car la partie continue!");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            setVal(tmp,i,j, 4+i);
        }
    }
    res= perdu(tmp);
    if(res!=0)
        return termine("perdu doit retourner 0 car la partie est impossible!");
    for (i=0; i<(n*n)-1; i++)
    {
      tp.grille[i]=i+1;
    }
    res= perdu(tmp);
    if(res==0)
        return termine("Il reste un 0, perdu doit retourner 0!");
    for (i=0; i<(n*n); i++)
    {
      tp.grille[i]=i+1;
    }
    res= perdu(tmp);
    if(res!=1)
        return termine("la fonction perdu ne retourne pas la bonne valeur!");
    setVal(tmp, 0,0,1);
    res= perdu(tmp);
    if(res!=1)
        return termine("perdu ne retourne pas la bonne valeur!");
    setVal(tmp, 0, 2,0);
    res= perdu(tmp);
    if(res!=0)
        return termine("perdu ne retourne pas la bonne valeur!");
    libereMemoire(tmp);
    return 1;
}

int test_fonction_finPartie()
{
    int n=6;
    int Vmax=2048;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);
    int i, j;
    int res= finPartie(tmp);
    if(res!=0)
        return termine("finPartie ne retourne pas la bonne valeur après une initialisation! ");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            setVal(tmp,i,j, 4+i);
        }
    }
    res= finPartie(tmp);
    if(res!=0)
        return termine("finPartie ne retourne pas la bonne valeur si gange faux!");
    setVal(tmp,2,2, Vmax);
    res= finPartie(tmp);
    if(res!=1)
        return termine("finPartie ne retourne pas la bonne valeur si gagne vraie!");
    setVal(tmp,2,2, Vmax+20);
    res= finPartie(tmp);
    if(res!=1)
        return termine("finPartie ne retourne pas la bonne valeur en cas de victoire!");
    for (i=0; i<(n*n); i++)
    {
      tp.grille[i]=i+1;
    }
    res= finPartie(tmp);
    if(res!=1)
        return termine("la fonction perdu ne retourne pas la bonne valeur an cas de défaite!");
    libereMemoire(tmp);
    return 1;
}


void test_partie2()
{
    int somme=0;
    somme+= test_fonction_caseVide();
    somme+= test_fonction_ajouteValAlea();
    somme+= test_fonction_gagne();
    somme+= test_fonction_perdu();
    somme+= test_fonction_finPartie();

    if (somme!=5)
    {
        termine("TOUS LES TESTS DE LA PARTIE 2 NE SONT PAS PASSES !");
    }
    else
    {
        termine("TEST PARTIE 2 OK");
    }
}

