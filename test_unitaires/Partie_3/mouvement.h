#ifndef MOUVEMENT_H_INCLUDED
#define MOUVEMENT_H_INCLUDED

int mouvement(jeu *p, int direction);
int mouvementLignes(jeu *p, int direction);
int mouvementLigne(jeu *p, int ligne, int direction);
int mouvementColonnes(jeu *p, int direction);
int mouvementColonne(jeu *p, int ligne, int direction);

#endif // MOUVEMENT_H_INCLUDED
