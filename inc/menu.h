#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "SDL/SDL.h"

int diff;
int nbetage;
void menu();
void bouton(int,int,char *string);
void boutoncadre(int,int,int,int);
void Gestionclic(int,int,int,int);
void jouerM();
void scoreM();
int in(int*,int,int);
void editbox(int x1,int y1);
void readtextbox(int x1,int y1,char* string);

