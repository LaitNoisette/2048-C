#ifndef INITIALISEJEU_H_INCLUDED
#define INITIALISEJEU_H_INCLUDED

struct Jeu{
	int n;
	int valMax;
	int nbCasesLibres;
	int *grille;
	int score;
	char *nom;
};

typedef struct Jeu jeu;

void* malloc(size_t n);

void initialiseJeu(jeu *p, int n, int valMax);

void libereMemoire(jeu *p);

#endif // INITIALISEJEU_H_INCLUDED
