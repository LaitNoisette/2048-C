int test_fonction_mouvementLignes()
{
    int i;
    int j;
    int n=4;
    int Vmax=2048;
    int somme=0;
    jeu tp;
    jeu *tmp=&tp;
    initialiseJeu(tmp, n, Vmax);
    int res=mouvementLignes(tmp, 1);
    if(res!=0)
        return termine("mouvementLignes ne retourne pas la bonne valeur 0!");
    setVal(tmp, 1, 3, 4);
    mouvementLignes(tmp, 1);
    res= getVal(tmp, 1, 0);
    if(res==0)
        return termine("Erreur de déplacement!");
    /** Mouvement vers la gauche **/
    libereMemoire(tmp);
    initialiseJeu(tmp, 5, Vmax);
    setVal(tmp, 1, 3, 4);setVal(tmp, 2, 3, 4);setVal(tmp, 1, 1, 4);setVal(tmp, 4, 3, 4);
    res=mouvementLignes(tmp, 1);
    if(res!=1)
        return termine("mouvementLignes ne retourne pas la bonne valeur 1!");
    for (i=0; i<n; i++)
        tp.grille[i]=2*i;
    res=mouvementLignes(tmp, 1);
    if(res!=1)
        return termine("mouvementLignes n'effectue pas de mouvement si une ligne bouge pas!");
    for (i=0; i<n*n; i++)
        tp.grille[i]=4;
    res=mouvementLignes(tmp, 1);
    if(res!=1)
        return termine("mouvementLignes n'effectue pas de mouvement si une ligne bouge pas!");
    for (i=0; i<(n*n); i++)
    {
      if(tp.grille[i]!=0)
        somme++;
    }
    if(somme!=15)
        return termine("mouvementLignes n'effectue pas d'addition bouge pas!");
    /** Mouvement vers la droite **/
    libereMemoire(tmp);
    initialiseJeu(tmp, 5, Vmax);
    setVal(tmp, 1, 3, 4);setVal(tmp, 2, 3, 4);setVal(tmp, 1, 1, 4);setVal(tmp, 4, 3, 4);
    res=mouvementLignes(tmp, -1);
    if(res!=1)
        return termine("mouvementLignes ne retourne pas la bonne valeur 1!");
    for (i=0; i<n; i++)
        tp.grille[i]=2*i;
    res=mouvementLignes(tmp, -1);
    if(res!=1)
        return termine("mouvementLignes n'effectue pas de mouvement si une ligne bouge pas!");
    for (i=0; i<n*n; i++)
        tp.grille[i]=4;
    res=mouvementLignes(tmp, -1);
    if(res!=1)
        return termine("mouvementLignes n'effectue pas de mouvement si une ligne bouge pas!");
    for (i=0; i<(n*n); i++)
    {
      if(tp.grille[i]!=0)
        somme++;
    }
    if(somme!=15)
        return termine("mouvementLignes n'effectue pas d'addition bouge pas!");
    libereMemoire(tmp);
    return 1;
}

