/**
 * \file mouvement.c
 * \brief Programme de gestion du mouvement
 * \author Franck Meyer et Henri Pissa
 * \version 12.4
 * \date 21 février 2017
 *
 * Mouvement du jeu 2048
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "ajouteValAlea.h"


/**
 * Fonction effectuant les mouvements gauche ou droite des cases d'une ligne
 * Les mouvements se font à l'aide du procédé TAT(Tasse-Additionne-Tasse) 
 *
 * \param p: pointeur sur la partie de 2048
 * \param ligne: entier correspondant au numéro de ligne
 * \param direction: 1 pour le déplacement vers la gauche et -1 pour le déplacement vers la droite
 * \return 1 : si au moins une case déplacée
 * \return 0 : si aucun déplacement
 */
int mouvementLigne(jeu *p, int ligne, int direction)
{
		if (ligne<(*p).n)
		{
			int jmin=0; // Borne inférieur
			int jmax=0; // Borne supérieur
			int j=0;
			int i;
			int mouv=0; // Vérifie le mouvement
			int tasse=0; 
			int add=0;
			for (i=0; i<=ligne; i++)
			{
					jmax+=(*p).n;
			}
			jmin=jmax-(*p).n;
			jmax=jmax-1;
			j=jmax;
			if (direction==-1)
			{
				for(tasse=0;tasse<(*p).n; tasse++) //tasse
				{
					for(j=jmax;j>jmin;j--)
					{
						if((*p).grille[j]==0 && (*p).grille[j-1]!=0)
						{
							(*p).grille[j]=(*p).grille[j-1];
							(*p).grille[j-1]=0;
							mouv++;
						}
					}
				}

				    int addnb=0;
					for(j=jmax;j>jmin;j--)
					{
						
						if((*p).grille[j]==(*p).grille[j-1]&&((*p).grille[j]!=0 && (*p).grille[j-1] !=0))
						{
							(*p).grille[j]=(*p).grille[j]*2;
							(*p).grille[j-1]=0;
							(*p).nbCasesLibres++;
							(*p).score=(*p).score+1;
							j--; 
							mouv++;
							addnb++;
						}

						if(addnb>((((*p).n/2)-1)))
						{
							j=jmin;
						}
					}
				
			
				for(tasse=0;tasse<(*p).n; tasse++) //tasse
				{
					for(j=jmax;j>jmin;j--)
					{
						if((*p).grille[j]==0 && (*p).grille[j-1]!=0)
						{
							(*p).grille[j]=(*p).grille[j-1];
							(*p).grille[j-1]=0;
							mouv++;
						}
					}
				}
				
			}
			
			else if (direction==1)
				{
					for(tasse=0;tasse<(*p).n; tasse++)
					{
						for(j=jmin;j<jmax;j++)
						{
							if((*p).grille[j]==0 && (*p).grille[j+1]!=0)
							{
								(*p).grille[j]=(*p).grille[j+1];
								(*p).grille[j+1]=0;
								mouv++;
							}
						}
					}

				
						int addnb=0;
						for(j=jmin;j<jmax;j++)
						{
							
							if((*p).grille[j]==(*p).grille[j+1]&&((*p).grille[j]!=0 && (*p).grille[j+1] !=0))
							{
								(*p).grille[j]=(*p).grille[j]*2;
								(*p).grille[j+1]=0;
								(*p).nbCasesLibres++;
								(*p).score=(*p).score+1;
								j++; 
								mouv++;
								addnb++;
							}

							if(addnb>((((*p).n/2)-1)))
							{
								j=jmax;
							}
						}
					
					for(tasse=0;tasse<(*p).n; tasse++)
					{
						for(j=jmin;j<jmax;j++)
						{
							if((*p).grille[j]==0 && (*p).grille[j+1]!=0)
							{
								(*p).grille[j]=(*p).grille[j+1];
								(*p).grille[j+1]=0;
								mouv++;
							}
						}
					}
			}
			if(mouv==0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		
		else
		{
			return 0;
		}
}

/**
 * Fonction effectuant le mouvement de toutes les lignes
 *
 * \param p: pointeur sur la partie de 2048
 * \param direction:1 pour le déplacement vers la gauche et -1 pour le déplacement vers la droite
 * \return 1 : si au moins une case déplacée
 * \return 0 : si aucun déplacement
 */

int mouvementLignes(jeu *p, int direction)
{
	int i;
	int somme=0;
	for(i=0; i<(*p).n; i++)
	{
		somme+=mouvementLigne(p,i,direction);
	}
	if(somme!=0)
	    return 1;
	else
	    return 0;
}


/**
 * Fonction effectuant les mouvement haut ou bas des cases d'une colonne
 *
 * \param p: pointeur sur la partie de 2048
 * \param colonne: entier correspondant au numéro de colonne
 * \param direction: 1 pour le déplacement vers le haut et -1 pour le déplacement vers le bas
 * \return 1 : si au moins une case déplacée
 * \return 0 : si aucun déplacement
 */
int mouvementColonne(jeu *p,int colonne,int direction)
{
	if (colonne<(*p).n)
		{
			int jmin=colonne;
			int jmax=((*p).n*(((*p).n)-1))+colonne;
			int j=0;
			int mouv=0;
			int tasse=0;
			int add=0;
			if (direction==-1)
			{
				for(tasse=0;tasse<(*p).n; tasse++) //tasse
				{
					for(j=jmax;j>jmin;(j-=((*p).n)))
					{
						if((*p).grille[j]==0 && (*p).grille[j-(*p).n]!=0 )
						{
							(*p).grille[j]=(*p).grille[j-(*p).n];
							(*p).grille[j-(*p).n]=0;
							mouv++;
						}
					}
				}

				
					int addnb=0;
					for(j=jmax;j>jmin;j-=(*p).n)
					{
						
						if((*p).grille[j]==(*p).grille[j-(*p).n]&&((*p).grille[j]!=0 && (*p).grille[j-(*p).n] !=0))
						{
							(*p).grille[j]=(*p).grille[j]*2;
							(*p).grille[j-(*p).n]=0;
							(*p).nbCasesLibres++;
							(*p).score=(*p).score+1;
							j-=(*p).n; 
							mouv++;
							addnb++;
						}
						
						if(addnb>((((*p).n/2)-1)))
						{
							j=jmin;
						}

					}
				
				for(tasse=0;tasse<(*p).n; tasse++) //tasse
				{
					for(j=jmax;j>jmin;(j-=((*p).n)))
					{
						if((*p).grille[j]==0 && (*p).grille[j-(*p).n]!=0)
						{
							(*p).grille[j]=(*p).grille[j-(*p).n];
							(*p).grille[j-(*p).n]=0;
							mouv++;
						}
				}


			    }
			}
			else if (direction==1)
			{
				for(tasse=0;tasse<(*p).n; tasse++)
				{
					for(j=jmin;j<jmax;j+=(*p).n)
					{
						if((*p).grille[j]==0 && (*p).grille[j+(*p).n]!=0)
						{
							(*p).grille[j]=(*p).grille[j+(*p).n];
							(*p).grille[j+(*p).n]=0;
							mouv++;
						}
					}
				}
				
				int addnb=0;
				for(j=jmin;j<jmax;j+=(*p).n)
				{
						if((*p).grille[j]==(*p).grille[j+(*p).n]&&((*p).grille[j]!=0 && (*p).grille[j+(*p).n] !=0))
						{
							(*p).grille[j]=(*p).grille[j]*2;
							(*p).grille[j+(*p).n]=0;
							(*p).nbCasesLibres++;
							(*p).score=(*p).score+1;
							j+=(*p).n; 
							mouv++;
							addnb++;
						}

						if(addnb>((((*p).n/2)-1)))
						{
							j=jmax;
						}
					}
				
				for(tasse=0;tasse<(*p).n; tasse++)
				{
					for(j=jmin;j<jmax;j+=(*p).n)
					{
						if((*p).grille[j]==0 && (*p).grille[j+(*p).n]!=0)
						{
							(*p).grille[j]=(*p).grille[j+(*p).n];
							(*p).grille[j+(*p).n]=0;
							mouv++;
						}
					}
				}
			}

			if(mouv==0)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 0;
		}
}

/**
 * Fonction effectuant le mouvement de toutes les colonnes
 *
 * \param p: pointeur sur la partie de 2048
 * \param direction:1 pour le déplacement vers le haut et -1 pour le déplacement vers le bas
 * \return 1 : si au moins une case déplacée
 * \return 0 : si aucun déplacement
 */

int mouvementColonnes(jeu *p, int direction)
{
	int i;
	int somme=0;
	for(i=0; i<(*p).n; i++)
	{
		somme+=mouvementColonne(p,i,direction);//On vérifie qu'il a a eu au moins un mouvement
	}
	if(somme!=0)
	    return 1; //Il ya a eu un mouvement
	else
	    return 0; //Il n'y a pas eu de mouvements
}

/**
 * Fonction effectuant le mouvement
 *
 * \param p: pointeur sur la partie de 2048
 * \param direction: 2 pour haut, 0 pour bas, 3 pour gauche, 1 pour droite
 * \return 1 : si au moins une case déplacée
 * \return 0 : si aucun déplacement
 * âjoute une valeur aléatoire si le mouvement vers une direction est effectué correctement
 */

int mouvement(jeu *p, int direction)
{
	if(direction==0)
	{

		if(mouvementColonnes(p, -1)==1)
		{
			ajouteValAlea(p);
		}
		else
		{
			return 0;
		}
	}
	else if(direction==1)
	{

		if(mouvementLignes(p, -1)==1)
		{
			ajouteValAlea(p);
		}
		else
		{
			return 0;
		}
	}
	else if(direction==2)
	{

		if(mouvementColonnes(p, 1)==1)
		{
			ajouteValAlea(p);
		}
		else
		{
			return 0;
		}
	}
	else if(direction==3)
	{

		if(mouvementLignes(p, 1)==1)
		{
			ajouteValAlea(p);
		}
		else
		{
			return 0;
		}
	}
	else if(direction>3)
	{
		return 0;
	}
	return 1;
}