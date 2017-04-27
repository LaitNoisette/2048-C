all: main.o    getVal.o indiceValide.o InitialiseJeu.o  setVal.o getVal.o finPartie.o gagne.o	Partie2test.o ajouteValalea.o perdu.o caseVide.o
	gcc -Wall -o main main.o    getVal.o indiceValide.o InitialiseJeu.o  setVal.o Partie2test.o  ajouteValalea.o finPartie.o gagne.o perdu.o caseVide.o

main.o: main.c
	gcc -c main.c

getVal.o: getVal.c
	gcc -c getVal.c 

indiceValide.o: indiceValide.c
	gcc -c indiceValide.c 

InitialiseJeu.o: InitialiseJeu.c
	gcc -c InitialiseJeu.c 



caseVide.o : caseVide.c
	gcc -c caseVide.c

setVal.o: setVal.c
	gcc -c setVal.c 

ajouteValalea.o: ajouteValalea.c
	gcc -c ajouteValalea.c

Partie2test.o: Partie2test.c
	gcc -c Partie2test.c


finPartie.o: finPartie.c
	gcc -c finPartie.c 

gagne.o: gagne.c
	gcc -c gagne.c

perdu.o: perdu.c
	gcc -c perdu.c 
