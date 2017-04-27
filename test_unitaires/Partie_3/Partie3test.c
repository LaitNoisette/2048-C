/**
 * \file Partie3test.c
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
#include "setVal.h"
#include "getVal.h"
#include "caseVide.h"

int termine(const char *ch)
{
    printf("******************************************\n");
    printf("************  PROBLEME  ******************\n");
    printf("* %s *\n", ch);
    printf("******************************************\n");
    return 0;
}


int test_fonction_mouvementLigne()
{
    int i;
    int n=4;
    int Vmax=2048;
    int somme=0;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);
    // Mouvement sur une grille vide
    int res=mouvementLigne(tmp, 0, 1);
    if(res!=0)
        return termine("mouvementLigne ne retourne pas la bonne valeur!");
    /** Mouvement vers la gauche **/
    //Mouvement avec 1, 2, et n valeurs
    setVal(tmp, 0, (n-1), 2);
    res=mouvementLigne(tmp, 0, 1);
    if(res!=1)
        return termine("mouvementLigne n'effectue pas correctement le mouvement vers la gauche!");
    res=mouvementLigne(tmp, 0, 1);
    if(res!=0)
        return termine("mouvementLigne effectue le mouvement vers la gauche quand il ne faut pas!");
    setVal(tmp, 0, 0, 0);setVal(tmp, 0,(n-1), 2);setVal(tmp, 0, 1, 4);
    res=mouvementLigne(tmp, 0, 1);
    if(res!=1)
        return termine("mouvementLigne n'effectue pas correctement le mouvement vers la gauche avec plusieurs valeurs!");
    for(i=0; i<n; i++)
    {
            tp.grille[i]=2*i;
    }
    for(i=0; i<n; i++)
    
    res=mouvementLigne(tmp, 0, 1); 
    res=mouvementLigne(tmp, 0, 1);
    if(res!=0)
        return termine("cas supposé sans tassement");
    for(i=0; i<n*n; i++)
    {
            tp.grille[i]=i+1;
    }
    res=mouvementLigne(tmp, 1, 1);
    if(res!=0)
        return termine("mouvementLigne ne retourne pas la bonne valeur 0!");
    //Mouvement avec addition et second tassement avec 2 et n valeurs
    libereMemoire(tmp);
    initialiseJeu(tmp, n, Vmax);
    setVal(tmp, 0, 0, 2);setVal(tmp, 0, (n-1), 2);
    mouvementLigne(tmp, 0, 1);
    res=getVal(tmp,0,0);
    if(res!=4)
        return termine("mouvementLigne à gauche n'effectue pas l'addition à 2 valeurs correctement");
    setVal(tmp, 0, 0, 4);setVal(tmp, 0, (n-1), 8);
    res=mouvementLigne(tmp, 0, 1);
    if(res!=1)
        return termine("mouvementLigne à gauche s'exécute pas");
     res=getVal(tmp,0,0);
     if(res!=4)
        return termine("mouvementLigne à gauche effectue une addition supplémentaire!");
    for(i=0;i<n;i++)
        tp.grille[i]=4;
    somme=0;
    
    res=mouvementLigne(tmp, 0, 1);
    somme=0;
    for(i=0; i<n; i++)
    {
            if(tp.grille[i]!=0)
                somme++;
    }
    
    
    if(somme!=2)
        return termine("l'addition complexe à gauche ne s'effectue pas correctement!");
    //Cas n est impair
    libereMemoire(tmp);
    n=5;
    initialiseJeu(tmp, n, 2048);
    for (i=0; i<n;i++)
       tp.grille[i]=4;
   
    mouvementLigne(tmp, 0, 1);
    somme=0;
    for(i=0; i<n; i++)
    {
            if(tp.grille[i]!=0)
                somme++;
    }
    if(somme!=(n+1)/2)
        return termine("l'addition complexe à gauche pour n impair ne s'effectue pas correctement!");
    







    /** Mouvement vers la droite **/
    //Mouvement avec 1, 2, et n valeurs
    n=4;
    libereMemoire(tmp);
    initialiseJeu(tmp, n, Vmax);
    setVal(tmp, 0, 0, 2);
    res=mouvementLigne(tmp, 0, -1);
    if(res!=1)
        return termine("mouvementLigne n'effectue pas correctement le mouvement vers la droite!");
    res=mouvementLigne(tmp, 0, -1);
    if(res!=0)
        return termine("mouvementLigne effectue le mouvement vers la droite quand il ne faut pas!");
    setVal(tmp, 0, 0, 0);setVal(tmp, 0,2, 2);setVal(tmp, 0, 1, 4);
    res=mouvementLigne(tmp, 0, -1);
    if(res!=1)
        return termine("mouvementLigne n'effectue pas correctement le mouvement vers la droite avec plusieurs valeurs!");
    for(i=0; i<n; i++)
    {
            tp.grille[i]=2*i;
    }
    for(i=0; i<n; i++)
    
    res=mouvementLigne(tmp, 0, -1); 
    res=mouvementLigne(tmp, 0, -1);
    if(res!=0)
        return termine("cas supposé sans tassement");
    for(i=0; i<n*n; i++)
    {
            tp.grille[i]=i+1;
    }
    res=mouvementLigne(tmp, 1, -1);
    if(res!=0)
        return termine("mouvementLigne ne retourne pas la bonne valeur 0!");
    //Mouvement avec addition et second tassement avec 2 et n valeurs
    libereMemoire(tmp);
    initialiseJeu(tmp, n, Vmax);
    setVal(tmp, 0, 0, 2);setVal(tmp, 0, 1, 2);
    mouvementLigne(tmp, 0, -1);
    res=getVal(tmp,0,0);
    if(res==4)
        return termine("mouvementLigne à droite n'effectue pas l'addition à 2 valeurs correctement");
    setVal(tmp, 0, 0, 4);setVal(tmp, 0, 1, 8);
    res=mouvementLigne(tmp, 0, -1);
    if(res!=1)
        return termine("mouvementLigne à droite s'exécute pas");
     res=getVal(tmp,0,n-1);
     if(res==8)
        return termine("mouvementLigne à gauche effectue une addition supplémentaire!");
    for(i=0;i<n;i++)
        tp.grille[i]=4;
    somme=0;
    
    res=mouvementLigne(tmp, 0, -1);
    somme=0;
    for(i=0; i<n; i++)
    {
            if(tp.grille[i]!=0)
                somme++;
    }
    
    
    if(somme!=2)
        return termine("l'addition complexe à gauche ne s'effectue pas correctement!");
    //Cas n est impair
    libereMemoire(tmp);
   
    
    return 1;
}



int test_fonction_mouvementColonne()
{
    int i;
    int n=4;
    int Vmax=2048;
    int somme=0;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);
    // Mouvement sur une grille vide
    int res=mouvementColonne(tmp, 0, 1);
    if(res!=0)
        return termine("mouvementColonne ne retourne pas la bonne valeur!");
    /** Mouvement vers la haut **/
    //Mouvement avec 1, 2, et n valeurs
    setVal(tmp, (n-1), 0, 2);
    for(i=0;i<n*n;i++){
        printf("\t%d\t", tp.grille[i]);
        if(i%4==0&&i!=0)
            printf("\n");
    }
    res=mouvementColonne(tmp, 0, 1);
    if(res!=1)
        return termine("mouvementColonnee n'effectue pas correctement le mouvement vers le haut!");
    res=mouvementColonne(tmp, 0, 1);
    if(res!=0)
        return termine("mouvementColonne effectue le mouvement vers la gauche quand il ne faut pas!");
    setVal(tmp, 0, 0, 0);setVal(tmp, (n-1),0, 2);setVal(tmp, 1, 0, 4);
    res=mouvementColonne(tmp, 0, 1);
    if(res!=1)
        return termine("mouvementColonne n'effectue pas correctement le mouvement vers la gauche avec plusieurs valeurs!");
    for(i=0; i<n; i++)
    {
            tp.grille[i]=2*i;
    }
    for(i=0; i<n; i++)
    
    res=mouvementColonne(tmp, 0, 1); 
    res=mouvementColonne(tmp, 0, 1);
    if(res!=0)
        return termine("cas supposé sans tassement");
    for(i=0; i<n*n; i++)
    {
            tp.grille[i]=i+1;
    }
    res=mouvementColonne(tmp, 1, 1);
    if(res!=0)
        return termine("mouvementColonne ne retourne pas la bonne valeur 0!");
    //Mouvement avec addition et second tassement avec 2 et n valeurs
    libereMemoire(tmp);
    initialiseJeu(tmp, n, Vmax);
    setVal(tmp, (n-1), 0, 2);setVal(tmp, 1, 0, 2);
    mouvementColonne(tmp, 0, 1);
    res=getVal(tmp,0,0);
    if(res!=4)
        return termine("mouvementColonne en haut n'effectue pas l'addition à 2 valeurs correctement");
    setVal(tmp, 2, 0, 4);setVal(tmp, (n-1), 0, 8);
    res=mouvementColonne(tmp, 0, 1);
    if(res!=1)
        return termine("mouvementColonne en haut ne s'exécute pas");
     res=getVal(tmp,0,0);
     if(res!=8)
        return termine("mouvementColonne en haut effectue une addition supplémentaire!");
    for(i=0;i<n*n;i++)
        tp.grille[i]=4;
    somme=0;
    
    res=mouvementColonne(tmp, 0, 1);
    somme=0;
    for(i=0; i<n*n; i++)
    {
            if(tp.grille[i]!=0)
                somme++;
    }
    
    
    if(somme==2)
        return termine("l'addition complexe à gauche ne s'effectue pas correctement!");
    //Cas n est impair
    libereMemoire(tmp);
    n=5;
    initialiseJeu(tmp, n, 2048);
    for (i=0; i<n*n;i++)
       tp.grille[i]=4;
   
    mouvementLigne(tmp, 0, 1);
    somme=0;
    for(i=0; i<n; i++)
    {
            if(tp.grille[i]!=0)
                somme++;
    }
    if(somme!=(n+1)/2)
        return termine("l'addition complexe à gauche pour n impair ne s'effectue pas correctement!");

    
    return 1;
}









int test_fonction_mouvement()
{
   int i;
    int n=4;
    int Vmax=2048;
    int somme=0;
    jeu tp;
    jeu *tmp=&tp;
    int res;
    initialiseJeu(tmp, n, Vmax);
    // Cas 1 absence de mouvement grille initiale
    res=mouvement(tmp,0);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    res=mouvement(tmp,1);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    res=mouvement(tmp,2);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    res=mouvement(tmp,3);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    
    // Cas 2 absence de mouvement partie perdu
    for(i=0;i<n*n;i++)
        tp.grille[i]=i+1;
    res=mouvement(tmp,0);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    res=mouvement(tmp,1);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    res=mouvement(tmp,2);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    res=mouvement(tmp,3);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    // Cas 3 indice invalide
    res=mouvement(tmp,4);
    if(res!=0)
        return termine ("mouvement s'exécute dans le vide");
    // Cas 5 Succès déplacement
    libereMemoire(tmp);
    initialiseJeu(tmp, n, Vmax);
    // Sous cas 1 mouvement isolé
    for(i=0;i<n*n;i++)
       tp.grille[i]=4;
     res=mouvement(tmp,0);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
    for(i=0;i<n*n;i++)
       tp.grille[i]=4;
     res=mouvement(tmp,1);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
    for(i=0;i<n*n;i++)
       tp.grille[i]=4;
     res=mouvement(tmp,2);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
    for(i=0;i<n*n;i++)
       tp.grille[i]=4;
     res=mouvement(tmp,3);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
        
     // sous cas 2 mouvement enchaîné
     
     for(i=0;i<n*n;i++)
       tp.grille[i]=4;
    res=mouvement(tmp,0);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
    res=mouvement(tmp,1);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
    res=mouvement(tmp,2);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
    res=mouvement(tmp,3);
    if(res!=1)
        return termine ("mouvement ne  s'exécute pas");
    libereMemoire(tmp);
    return 1;
}



void test_partie3()
{
    int somme=0;
    somme+= test_fonction_mouvementLigne();
    //somme+= test_fonction_mouvementLignes();
    somme+= test_fonction_mouvementColonne();
    //somme+= test_fonction_mouvementColonnes();
    somme+= test_fonction_mouvement();
    

    if (somme!=3)
    {
        termine("TOUS LES TESTS DE LA PARTIE 3 NE SONT PAS PASSES !");
    }
    else
    {
        termine("TEST PARTIE 3 OK");
    }
}





