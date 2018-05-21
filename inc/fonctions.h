#ifndef _FONCTIONS_H
#define _FONCTIONS_H


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define PIXELS_X 1600
#define PIXELS_Y 900
#define RATIO = PIXELS_X/PIXELS_Y

#define TAILLE_X PIXELS_X
#define TAILLE_Y PIXELS_Y

#define TAILLE_MAX 10
#define PI 3.14159265
 
#define MAXX 300
#define MAXY 300
#define MINX 0
#define MINY 0
#define TAILLE_PIXEL 0.5
#define RAYON 1

int k,direction;
double xs,ys,zs;
double angle;
double increment;
double snake[TAILLE_MAX][3];
double vitesse;
int compteur;
int xSouris,ySouris;


void affichage();
void animer();
void clavier(unsigned char key,int x, int y);
void fleches(int key, int x, int y);
void trace_grille();
void affiche_snake(double x, double y, double z);
void maison(double x, double y, double z, double c);
void init_snake();
void anime_snake();
void affiche_mur( int x1, int y1, int z1, int x2,int y2, int z2);
void affiche_carte(int *carte[4],int x);
void affiche_cube(int x1, int y1, int z1, int x2,int y2, int z2,double color);
void affiche_pente(int x1, int y1, int z1, int x2,int y2, int z2);
void affiche_sol();
void gencarte(int n);

#endif
