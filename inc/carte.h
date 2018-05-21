#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"


int **carte;
int genCarteOK;

void affiche_mur( int x1, int y1, int z1, int x2,int y2, int z2);
void affiche_carte(int *carte[4],int x);
void affiche_cube(int x1, int y1, int z1, int x2,int y2, int z2,double color);
void affiche_pente(int x1, int y1, int z1, int x2,int y2, int z2);
void affiche_sol();
void gencarte(int n);
