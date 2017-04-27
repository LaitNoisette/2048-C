#include <stdio.h>
#include <stdlib.h>
#include "InitialiseJeu.h"
#include "gagne.h"
#include "perdu.h"

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
