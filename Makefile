CC = gcc -Wall -O3

projet : fonctions carte
	$(CC) -o bin/snake src/main.c obj/fonctions.o obj/carte.o -lGL -lGLU -lglut -lSDLmain -lSDL -lm

fonctions : inc/fonctions.h
	$(CC) -c src/fonctions.c -o obj/fonctions.o -lGL -lGLU -lglut -lSDLmain -lSDL

carte : inc/carte.h
	$(CC) -c src/carte.c -o obj/carte.o -lGL -lGLU -lglut -lSDLmain -lSDL

clean:
	rm -f obj/* src/*~ bin/snake


