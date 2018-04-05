

#define PIXELS_X 600
#define PIXELS_Y 600
#define RATIO = PIXELS_X/PIXELS_Y

#define TAILLE_X PIXELS_X
#define TAILLE_Y PIXELS_Y
 
#define MAXX 32
#define MAXY 32
#define MINX -32
#define MINY -32
#define TAILLE_PIXEL 0.5
#define RAYON 4

int k,xC,yC,xD,yD;
double xs,ys,zs;
double angle;
double increment;
double snake[3][3];
double vitesse;

void affichage();
void animer();
void clavier(unsigned char key,int x, int y);
void trace_grille();
void affiche_snake(double x, double y, double z);
void maison(double x, double y, double z, double c);
void affiche_mur( int x1, int y1, int z1, int x2, int z2);
void affiche_cube(int x1, int y1, int z1, int x2,int y2, int z2);
void affiche_sol();
