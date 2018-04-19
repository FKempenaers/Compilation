CC = gcc -Wall -O3

projet : fonctions
	$(CC) -o bin/snake src/main.c obj/fonctions.o -lGL -lGLU -lglut -lSDLmain -lSDL -lm

fonctions : src/fonctions.c inc/fonctions.h
	$(CC) -c src/fonctions.c -o obj/fonctions.o -lGL -lGLU -lglut -lSDLmain -lSDL
clean:
	rm -f obj/* src/*~ bin/snake


