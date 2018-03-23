#include <stdio.h>

#define PIXELS_X 1600
#define PIXELS_Y 900
#define RATIO = PIXELS_X/PIXELS_Y

#define TAILLE_X PIXELS_X
#define TAILLE_Y PIXELS_Y
 
#define MAXX 32
#define MAXY 32
#define MINX 0
#define MINY 0
#define TAILLE_PIXEL 0.5
#define RAYON 0.5

int k,xC,yC,xD,yD;
double xs,ys,zs;
double angle;
double increment;
double snake[3][3];
double vitesse;
double compteur;

void affichage();
void animer();
void clavier(unsigned char key,int x, int y);
void trace_grille();
void affiche_snake(double x, double y, double z);
void maison(double x, double y, double z, double c);
