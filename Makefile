CC = gcc -g -Wall -O3

projet : fonctions carte minimap bresenham ia
	$(CC) -o bin/snake src/main.c obj/fonctions.o obj/carte.o obj/minimap.o obj/bresenham.o obj/ia.o -lGL -lGLU -lglut -lSDLmain -lSDL -lm

fonctions : inc/fonctions.h
	$(CC) -c src/fonctions.c -o obj/fonctions.o -lGL -lGLU -lglut -lSDLmain -lSDL

carte : inc/carte.h
	$(CC) -c src/carte.c -o obj/carte.o -lGL -lGLU -lglut -lSDLmain -lSDL

minimap : inc/minimap.h
	$(CC) -c src/minimap.c -o obj/minimap.o -lGL -lGLU -lglut -lSDLmain -lSDL

ia : inc/ia.h
	$(CC) -c src/ia.c -o obj/ia.o -lm

bresenham :
	$(CC) -c src/bresenham.c -o obj/bresenham.o

clean:
	rm -f obj/* src/*~ bin/snake


