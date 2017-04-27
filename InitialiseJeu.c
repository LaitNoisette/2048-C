/**
 * \file initialiseJeu.c
 * \brief Programme d'initialisation de partie.
 * \author Franck Meyer et Henri Pissa
 * \version 3.2
 * \date 10 février 2017
 *
 * Initialisation de la partie
 * Libération de la mémoire
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/**
 * 
 * \brief Strucure Jeu.
 *
 * Définition de la strucuture de Jeu.
 */
struct Jeu{
	int n; // taille de la grille
	int valMax; // valeur à atteindre pour gagner
	int nbCasesLibres; // nombre de cases libres sur la grille
	int *grille; // pointeur d'entier permettant de stocker la grille
	int score; // score atteint par le joueur
	char *nom; //nom du joueur
};

typedef struct Jeu jeu;

struct Joueur { 
    char nom[10]; 
    char prenom[10];
    jeu p; 
}; 

typedef struct Joueur Joueur;

struct Score { 
    char *nom1; 
    int score1; 
	char *nom2; 
    int score2;
	char *nom3; 
    int score3;
}; 

typedef struct Score score;


void* malloc(size_t n);
/**
 * Alloue la grille de la variable jeu passée par adresse
 * Initialise les cases de la grille avec des cases vides (valeurs nulles)
 * Initialise les champs n et valMax avec les valeurs passées en paramètre
 *
 * \param p: pointeur sur la partie de 2048
 * \param n: taille de la grille
 * \param valMax: valeur à atteindre pour ganger 
 *
 */
void initialiseJeu(jeu *p, int n, int valMax)
	{
		int i=0;
		(*p).n=n;
		(*p).valMax=valMax;
		(*p).nbCasesLibres=n*n;
		(*p).score=0; // Initialisation du score
		(*p).grille= (int*)malloc((n*n)*sizeof(int));
		(*p).nom="toto";
		if((*p).grille==NULL)
		{
		    printf("Erreur allocation!\n");
		    exit(-1); 
		}
		for(i=0;i<n*n;i++)
		{
			(*p).grille[i]=0;
		}
	}


/**
 * Libère la mémoire alloue à la grille du jeu passée par adresse
 *
 * \param p: pointeur sur la partie de 2048
 *
 */
void libereMemoire(jeu *p)
{
    free((*p).grille);

}