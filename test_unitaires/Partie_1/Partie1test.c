/**
 * \file main.c
 * \brief Programme de test.
 * \author Franck Meyer et Henri Pissa
 * \version 0.1
 * \date 10 février 2017
 *
 * Programme de test Partie 1 du jeu 2048
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "InitialiseJeu.h"
#include "indicevalide.h"
#include "setVal.h"
#include "getVal.h"

int termine(const char *ch)
{
    printf("******************************************\n");
    printf("************  PROBLEME  ******************\n");
    printf("* %s *\n", ch);
    printf("******************************************\n");
    return 0;
}

int test_creer_initialiseJeu() {
  int i;
  int n = 4;
  int vMax = 2048;

  jeu tp;
  jeu *tmp=&tp;

  initialiseJeu(tmp, n, vMax);

  if (tmp-> valMax != vMax)
    return termine("La valeur maximum a atteindre n'est pas correcte !");

  if (tmp-> nbCasesLibres != n * n)
    return termine("Le nombre de cases libres n'est pas correct !");

  int somme = 0;
  for (i = 0; i < n * n; i++)
    somme += tmp->grille[i];

  if (somme != 0)
    return termine("La cases ne contient pas que des cases libres !");

  //Le test est réussi !
  //libereMemoire(tmp);

  return 1;
}

int test_indice_valide() {

  int n = 4;
  int vMax = 2048;

  jeu tp;
  jeu *tmp=&tp;

  initialiseJeu(tmp, n, vMax);

  int i, j;

  int somme = 0;
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      somme += indiceValide(tmp, i, j);

  if (somme != n * n)
    return termine("indiceValide ne retourne pas 1 correctement !");

  if (indiceValide(tmp, -1, 2) || indiceValide(tmp, n, 2))
    return termine("indiceValide ne retourne pas 0 correctement !");

  if (indiceValide(tmp, 3, -1) || indiceValide(tmp, 3, n))
    return termine("indiceValide ne retourne pas 0 correctement !");

  //Le test est réussi !
  //libereMemoire(tmp);
  return 1;
}

int test_fonction_get_val() {
  int n = 6;
  int vMax = 2048;

  jeu tp;
  jeu *tmp=&tp;

  initialiseJeu(tmp, n, vMax);

  int i, j;

  int somme = 0;
  for (i = -1; i <= n; i++)
    for (j = -1; j <= n; j++)
      somme += getVal(tmp, i, j);

  if (somme != -28)
    return termine("La cases n'est pas vide ou getVal ne retourne pas -1 quand on n'est pas sur la cases !");

  //On met quelques valeur dans la grille
  for (i = 7; i <= 10; i++)
    tmp->grille[i] = i - 6;

  somme = 0;
  for (i = 0; i <= 5; i++)
    for (j = 0; j <= 5; j++)
      somme += getVal(tmp, i, j);

  if (somme != 10)
    return termine("getVal ne retourne pas la bonne valeur !");

  //Le test est réussi
  //libereMemoire(tmp);
  return 1;
}

int test_fonction_set_val() {
  int n = 6;
  int vMax = 2048;

  jeu tp;
  jeu *tmp=&tp;

  initialiseJeu(tmp, n, vMax);

   int res = setVal(tmp, 1, 1, 5);
   if (res != 1)
      return termine("setVal ne renvoie pas la bonne valeur !");

   if (tmp->grille[7] != 5)
      return termine("setVal ne modifie pas correctement la case !");

   res = setVal(tmp, 18, 2, 5);
   if (res != 0)
      return termine("setVal ne renvoie pas la bonne valeur ! L'indice n'est pas bon !");

   res = setVal(tmp, -1, 2, 7);
   if (res != 0)
      return termine("setVal ne renvoie pas la bonne valeur ! L'indice de ligne n'est pas bon!");

   res = setVal(tmp, 0, 2, 3);
   if (res != 1)
      return termine("setVal ne renvoie pas la bonne valeur !");

   if (tmp->grille[2] != 3)
      return termine("setVal ne modifie pas correctement la valeur !");

   res = setVal(tmp, 1, 1, 3);
   if (res != 1)
      return termine("setVal ne renvoie pas la bonne valeur !");

   if (tmp->grille[7] != 3)
      return termine("setVal ne modifie pas correctement le jeu !");

   res = setVal(tmp, 1, 1, 0);

   if (res != 1)
      return termine("setVal ne renvoie pas la bonne valeur !");

   if (tmp->grille[7] != 0)
      return termine("setVal ne modifie pas correctement le jeu !");


  //Le test est réussi
  //libereMemoire(tmp);
  return 1;
}

void test_partie1() {
   int somme = 0;

   // test_fonction_affichage_gratte_ciel();

   somme += test_creer_initialiseJeu();
   somme += test_indice_valide();
   somme += test_fonction_get_val();
   somme += test_fonction_set_val();

   if (somme != 4)
      termine("TOUS LES TESTS DE LA PARTIE 1 NE SONT PAS PASSES !");
   else {
      printf("***************************\n");
      printf("***  TESTS PARTIE 1 OK  ***\n");
      printf("***************************\n");
   }
}

/* *************************************************
 ************* Fin fonctions de tests ************
 ************************************************* */
