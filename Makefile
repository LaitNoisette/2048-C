all: main.o affichagecomplet.o ajouteValalea.o caseVide.o couleurs_terminal.o finPartie.o gagne.o getVal.o indiceValide.o InitialiseJeu.o jouer.o menu.o mouvement.o perdu.o saisieM.o saisieMD.o sauvegardes.o setVal.o	
	gcc -Wall -o main main.o affichagecomplet.o ajouteValalea.o caseVide.o couleurs_terminal.o finPartie.o gagne.o getVal.o indiceValide.o InitialiseJeu.o jouer.o menu.o mouvement.o perdu.o saisieM.o saisieMD.o sauvegardes.o setVal.o 

main.o: main.c
	gcc -c main.c

affichagecomplet.o: affichagecomplet.c
	gcc -c affichagecomplet.c

ajouteValalea.o: ajouteValalea.c
	gcc -c ajouteValalea.c

caseVide.o: caseVide.c
	gcc -c caseVide.c

couleurs_terminal.o: couleurs_terminal.c
	gcc -c couleurs_terminal.c

finPartie.o: finPartie.c
	gcc -c finPartie.c 

gagne.o: gagne.c
	gcc -c gagne.c

getVal.o: getVal.c
	gcc -c getVal.c 

indiceValide.o: indiceValide.c
	gcc -c indiceValide.c 

InitialiseJeu.o: InitialiseJeu.c
	gcc -c InitialiseJeu.c 

jouer.o: jouer.c
	gcc -c jouer.c 

menu.o: menu.c
	gcc -c menu.c 

mouvement.o: mouvement.c
	gcc -c mouvement.c 

perdu.o: perdu.c
	gcc -c perdu.c 

saisieM.o: saisieM.c
	gcc -c saisieM.c 

saisieMD.o: saisieMD.c
	gcc -c saisieMD.c 

sauvegardes.o: sauvegardes.c
	gcc -c sauvegardes.c 

setVal.o: setVal.c
	gcc -c setVal.c 

