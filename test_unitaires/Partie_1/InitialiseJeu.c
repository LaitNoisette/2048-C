#include <stdio.h>
#include <stdlib.h>


struct Jeu{
	int n;
	int valMax;
	int nbCasesLibres;
	int *grille;
	int score;
};

typedef struct Jeu jeu;

struct Joueur { 
    char nom[10]; 
    char prenom[10];
    jeu p; 
}; 

typedef struct Joueur Joueur;

void* malloc(size_t n);

void initialiseJeu(jeu *p, int n, int valMax)
	{
		int i=0;
		(*p).n=n;
		//printf("n= %d et p.n= %d \n", n, (*p).n);
		(*p).valMax=valMax;
		(*p).nbCasesLibres=n*n;
		(*p).score=0;
		//printf("\n le score est de %d\n", (*p).score);
		//printf("Case libre =%d\n et n*n= %d\n", (*p).nbCasesLibres, n*n);
		(*p).grille= (int*)malloc((n*n)*sizeof(int));
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

void libereMemoire(jeu *p)
{
    free((*p).grille);
	//(*p).grille=NULL;

}