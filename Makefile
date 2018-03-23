CC = gcc -Wall -O3

projet : fonctions
	$(CC) -o tp main.c fonctions.o -lGL -lGLU -lglut -lm

fonctions : fonctions.c fonctions.h
	$(CC) -c fonctions.c -o fonctions.o -lGL -lGLU -lglut
clean:
	rm -f *.o *~ tp


