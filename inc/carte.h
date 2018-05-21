#ifndef _CARTE_H
#define _CARTE_H

#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "SDL/SDL.h"


int **carte;
int **carteT;
int genCarteOK;

void affiche_mur( int x1, int y1, int z1, int x2,int y2, int z2);
void affiche_carte(int *carte[4],int x);
void affiche_cube(int x1, int y1, int z1, int x2,int y2, int z2,double color);
void affiche_pente(int x1, int y1, int z1, int x2,int y2, int z2);
void affiche_sol();
void gencarte(int n);
void Bresenham_enti(int x1, int y1, int x2, int y2);
void trace_point2(int x,int y);

#endif
