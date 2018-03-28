#include <stdio.h>

#define PIXELS_X 1600
#define PIXELS_Y 900
#define RATIO = PIXELS_X/PIXELS_Y

#define TAILLE_X PIXELS_X
#define TAILLE_Y PIXELS_Y

#define TAILLE_MAX 10
 
#define MAXX 100
#define MAXY 100
#define MINX 0
#define MINY 0
#define TAILLE_PIXEL 0.5
#define RAYON 2

int k,direction;
double xs,ys,zs;
double angle;
double increment;
double snake[TAILLE_MAX][3];
double vitesse;
double compteur;

void affichage();
void animer();
void clavier(unsigned char key,int x, int y);
void fleches(int key, int x, int y);
void trace_grille();
void affiche_snake(double x, double y, double z);
void maison(double x, double y, double z, double c);
