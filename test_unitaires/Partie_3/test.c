#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Jeu{
	int n;
	int valMax;
	int nbCasesLibres;
	int score;
	int *grille;
};

typedef struct Jeu jeu;



void* malloc(size_t n);

void initialiseJeu(jeu *p, int n, int valMax)
	{
		int i=0;
		(*p).n=n;
		printf("n= %d et p.n= %d \n", n, (*p).n);
		(*p).valMax=valMax;
		(*p).nbCasesLibres=0;
		(*p).score=0;
		printf("\n le score est de %d\n", (*p).score);
		printf("Case libre =%d\n et n*n= %d\n", (*p).nbCasesLibres, n*n);
		(*p).grille= (int*)malloc((n*n)*sizeof(int));
		if((*p).grille==NULL)
		{
		    printf("Erreur allocation!\n");
		    exit(-1);
		}
		for(i=0;i<n*n;i++)
		{
			(*p).grille[i]=0;
			(*p).nbCasesLibres++;
		}
		printf("\n le score est de %d\n", (*p).score);
		printf("\n Case libre =%d\n et n*n= %d\n", (*p).nbCasesLibres, n*n);
	}


int indiceValide(jeu *p, int i, int j)
	{
		if (i>=(*p).n || i<0)
			{
				return 0;
			}
		else
		{
			if (j>=0 && j<(*p).n)
			{
				return 1;
			}
		}

		return 0;
	}


int getVal(jeu *p,int ligne,int colonne) //Penser à utiliser modulo n de la colonne
{
    int i;
	if(indiceValide(p,ligne,colonne)==0)
	{
		return -1; //Faux retourne -1
	}

	else
	{
		for(i=0;i<ligne;i++)
		{
			colonne=colonne+(*p).n;
		}

		return (*p).grille[colonne]; //Vrai retourne la valeur
	}
}


int setVal(jeu *p,int ligne,int colonne,int val)
{
    int i;
	if(indiceValide(p,ligne,colonne)==1)
	{
		for(i=0;i<ligne;i++)
		{
			colonne=colonne+(*p).n;
		}
		if ((*p).grille[colonne]==0)
		{
			(*p).grille[colonne]=val;
			(*p).nbCasesLibres-=1;
			return 1;
		}
		else{
			(*p).grille[colonne]=val;
			return 1;
		}
		
	}
	else
	{
	    return 0;
	}
}

void affichage(jeu *p)
{
    int i;
	for(i=0;i<((*p).n*(*p).n);i++)
	{
		printf("%d\t",(*p).grille[i]);
        if((i%((*p).n))==(*p).n-1)
		{
			printf("\n");
		}
	}
}

int caseVide(jeu *p,int i,int j)
{
	if(indiceValide(p,i,j)==0)
	{
		return 0; //Faux, la case n'est pas vide'
	}

	else
	{
		if(getVal(p,i,j)==0)
		{
			return 1;//Vrai, la case est vide (=0)
		}
	}

	return 0;
}

void ajouteValAlea(jeu *p)
{
	int i;
	int j;
	int val=0;
	int bool1=0;
	time_t t;

	srand((unsigned) time(&t));

	i=rand()%(*p).n;
	j=rand()%(*p).n;

	while(bool1==0) //booléen tant que la case sélectionner n'est pas vide on boucle
	{
		if(caseVide(p,i,j)==1)
		{
			while(val!=2 && val!=4)
			{
				val=rand()%5;
			}
			bool1=1;
		}
		else //change la valeur de la ligne et de la colonne
		{
			i=rand()%(*p).n;
			j=rand()%(*p).n;
		}

	}

	setVal(p,i,j,val);
}

int sauvegarde(jeu *p)
{
    FILE *fich; /* initialisation d'un fichier*/
    fich=fopen("sauv.dat", "wb");
    int nr;
    if (fich == NULL)
    {
        printf("Erreur de fopen\n");
        exit(-1);
    }
    nr=fwrite((*p).grille,sizeof(int), (*p).n, fich);
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

int chargement(jeu *p)
{
    FILE *fichier; /* initialisation d'un fichier*/
    int nb_val_lues=(*p).n;
    int i;
    fichier=fopen("sauv.dat", "rb"); /* ouverture du fichier en lecture binaire */
    if(fichier==NULL)
    {
        printf("Erreur de fread\n");
        exit(-1);
    }
    printf("\n Liste des valeurs lues : \n");
    while ( nb_val_lues == (*p).n ) /* vrai tant que fin du fichier non atteinte */
    {
        nb_val_lues = fread((*p).grille, sizeof(int),(*p).n, fichier);
        /* Traitement des valeurs stockées dans la grille  : */
        for (i=0; i<nb_val_lues; i++) printf( "%hd", (*p).grille[i] );
    }
    fclose(fichier);
    if(nb_val_lues!=0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int gagne(jeu *p)
{
  int i;
	for(i=0;i<(*p).n*(*p).n;i++)//parcoure le tableau en entier (n*n) indice
	{
		if((*p).grille[i]>=(*p).valMax)
		{
			return 1; //Partie gagné
		}
	}

	return 0; //Partie en cours (continue la partie)
}

int perdu (jeu *p)
{
	int l=0;
	int c=0;
	int i;
	int libre=0;
	for(i=0; i<(*p).n*(*p).n; i++)
	{
		if((*p).grille[i]==0)
		{
			libre++;
		}
	}
	if((*p).nbCasesLibres==libre)
	{
		return 0;
	}
	else
	{
		for(l=0;l<(*p).n;l++)
		{
			for(c=0;c<(*p).n;c++)
			{
				if(indiceValide(p,l,(c+1))==1)
				{
					if(getVal(p,l,c)==getVal(p,l,(c+1)))
					{
						return 0; //Valeur consécutive égale Verticalement, partie non perdue
					}
				}

				if(indiceValide(p,(l+1),c))
				{
					if(getVal(p,l,c)==getVal(p,(l+1),c))
					{
						return 0;//Valeur consécutive égale Horizontalement, partie non perdue
					}
				}
			}
		}
	}
    printf("Vous avez perdu !!!\n");
	return 1; //Partie Perdue
}

int finPartie(jeu *p)
{
    if(gagne(p)==1 || perdu(p)==1)
    {
        printf("Appuyer sur une touche pour continuer\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

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
							j--; //vérfier
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
								j++; //vérifier 
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
						if((*p).grille[j]==0)
						{
							(*p).grille[j]=(*p).grille[j-(*p).n];
							(*p).grille[j-(*p).n]=0;
							mouv++;
						}
					}
				}
				for(add=0;add<(*p).n; add++)
				{
					for(j=jmax;j>jmin;j-=(*p).n)
					{
						if((*p).grille[j]==(*p).grille[j-(*p).n]&&((*p).grille[j]!=0 && (*p).grille[j-(*p).n] !=0))
						{
							(*p).grille[j]=(*p).grille[j]*2;
							(*p).grille[j-(*p).n]=0;
							(*p).nbCasesLibres++;
							(*p).score++;
							mouv++;
						}
					}
				}
				for(tasse=0;tasse<(*p).n; tasse++) //tasse
				{
					for(j=jmax;j>jmin;(j-=((*p).n)))
					{
						if((*p).grille[j]==0)
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
						if((*p).grille[j]==0)
						{
							(*p).grille[j]=(*p).grille[j+(*p).n];
							(*p).grille[j+(*p).n]=0;
							if((*p).grille[j+(*p).n]==0)
								mouv++;
						}
					}
				}
				for(add=0;add<(*p).n; add++)
				{
					for(j=jmin;j<jmax;j+=(*p).n)
					{
						if((*p).grille[j]==(*p).grille[j+(*p).n]&&((*p).grille[j]!=0 && (*p).grille[j+(*p).n] !=0))
						{
							(*p).grille[j]=(*p).grille[j]*2;
							(*p).grille[j+(*p).n]=0;
							(*p).nbCasesLibres++;
							(*p).score++;
							if((*p).grille[j+(*p).n]==0)
								mouv++;
						}
					}
				}
				for(tasse=0;tasse<(*p).n; tasse++)
				{
					for(j=jmin;j<jmax;j+=(*p).n)
					{
						if((*p).grille[j]==0)
						{
							(*p).grille[j]=(*p).grille[j+(*p).n];
							(*p).grille[j+(*p).n]=0;
							if((*p).grille[j+(*p).n]==0)
								mouv++;
							printf("mouv pfinal %d\n", mouv );
						}
					}
				}
			}
			printf("mouv final %d\n", mouv );
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

int mouvementColonnes(jeu *p, int direction)
{
	int i;
	for(i=0; i<(*p).n; i++)
	{
		mouvementColonne(p, i, direction);
		if(mouvementColonne(p,i,direction)==0)
		{
			return 0;
		}
	}
	return 1;
}

int mouvement(jeu *p, int direction)
{
	if(direction==0)
	{
		mouvementColonnes(p, -1);
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
		mouvementLignes(p, -1);
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
		mouvementColonnes(p, 1);
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
		mouvementLignes(p, 1);
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

void libereMemoire(jeu *p)
{
    free((*p).grille);
}

int termine(const char *ch)
{
    printf("******************************************\n");
    printf("************  PROBLEME  ******************\n");
    printf("* %s *\n", ch);
    printf("******************************************\n");
    return 0;
}


int main(void) {
    int i;
    int n=5;
    int Vmax=2048;
    int somme=0;
    jeu tp;
    jeu *tmp=&tp;
    int res;
    initialiseJeu(tmp, n, Vmax);
    res=mouvementLigne(tmp, 0, 1);
    if(res!=0)
        return termine("mouvementLigne ne retourne pas la bonne valeur!");
    setVal(tmp, 0, 3, 2);affichage(tmp);	
    res=mouvementLigne(tmp, 0, 1);affichage(tmp);	
    if(res!=1)
        return termine("mouvementLigne n'effectue pas correctement le mouvement vers la gauche!");    
        res=mouvementLigne(tmp, 0, 1);affichage(tmp);	
    if(res!=0)
        return termine("mouvementLigne n'effectue pas correctement le mouvement vers la gauche!");   
for(i=0; i<n; i++)
	tp.grille[i]=4;
	setVal(tmp, 0, 2, 8);
affichage(tmp);	
	
	res=mouvementLigne(tmp, 0, 1);
	affichage(tmp);
    if (res!=1)
	return termine("erreur!");
    
	return 0;
}
