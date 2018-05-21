#include "../inc/carte.h"

void affiche_carte(int *carte[4],int x){
  int i;
  for(i=0;i<x;i++){
    affiche_mur(carte[0][i],carte[1][i],0,carte[2][i],carte[3][i],10);
  }
  affiche_sol();
}

void affiche_sol(){
  int mi;
  if(MINY < 0){
    mi = MINY*-1;
    mi*=2;
    mi-=10;
  }
  affiche_cube(MINX,MINY,0,MAXX-20,MAXY,1,0.8);
  affiche_cube(MAXX,MINY,0,MAXX-20,MAXY-10,1,0.8);
  affiche_pente(MINX + 5, MINY , 1,MINX+20,MINY+10,10);
  affiche_pente(MAXX - 5, MAXY, -10,MAXX-20,MAXY-10,1);
}

void affiche_mur( int x1, int y1, int z1, int x2,int y2, int z2){
  affiche_cube(x1,y1,z1,x2,y2,z2,0.3);
}

void affiche_pente(int x1, int y1, int z1, int x2,int y2, int z2){
  glBegin(GL_QUADS);
  glColor3f(0.9, 0.9, 0.9);
  glVertex3f(x1, y1, z1);
  glVertex3f(x2, y1, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x1, y2, z1);
  glEnd();
}

void affiche_cube(int x1, int y1, int z1, int x2,int y2, int z2,double color){

  int x3,x4,y3,y4;
  x3 = x1 + 1;
  x4 = x2 - 1;
  y3 = y1 + 1;
  y4 = y2 - 1;
  
  x1--;
  y1--;
  x2++;
  y2++;
  
  glBegin(GL_QUADS);
  glColor3f(0.9, 0.9, 0.9);
  glVertex3f(x1, y1, z1);
  glVertex3f(x2, y2, z1);
  glVertex3f(x3, y3, z2);
  glVertex3f(x4, y4, z2);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(0, 0.8, 0.8);
  glVertex3f(x1, y1, z1);
  glVertex3f(x3, y3, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x4, y4, z1);
  glEnd();
  
  glBegin(GL_QUADS);
  glColor3f(0.7, 0.7, 0);
  glVertex3f(x1, y1, z1);
  glVertex3f(x3, y3, z1);
  glVertex3f(x2, y2, z1);
  glVertex3f(x4, y4, z1);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(color, 0, color);
  glVertex3f(x1, y1, z2);
  glVertex3f(x3, y3, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x4, y4, z2);
  glEnd();
  
  glBegin(GL_QUADS);
  glColor3f(0, 0.3, 0.6);
  glVertex3f(x1, y1, z1);
  glVertex3f(x3, y3, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x4 , y4, z1);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.4, 0.4, 0.4);
  glVertex3f(x1, y1, z2);
  glVertex3f(x3, y3, z1);
  glVertex3f(x2, y2, z1);
  glVertex3f(x4, y4, z2);
  glEnd();
  
}

void gencarte(int n){
  srand(getpid());
  int i,res;
  int dim;
  carteT = (int**) malloc(sizeof(int*)*(MAXY-MINY));
  for(i = 0;i < (MAXX-MINX);i++){
    carteT[i] = (int*)calloc((MAXY-MINY),sizeof(int));
  }
  carte = (int**) malloc(sizeof(int*)*4);
  for(i=0; i  < 4 ; i ++){
    carte[i] = (int*)malloc(sizeof(int)*n);
    if(carte[i] == NULL){
      printf("error gen carte allocation mémoire\n");
      exit (-1);
    }
  }
  if(MINX < 0) dim = (MINX*-1)+MAXX;
  else if(MINX == 0) dim = MAXX;
  else dim = MAXX-MINX;
  
  carte[0][0] = MINX+1; carte[1][0] = MINY+1; carte[2][0] = MINX+1; carte[3][0] = MAXY-1;
  carte[0][1] = MINX+1; carte[1][1] = MAXY-1; carte[2][1] = MAXX-1; carte[3][1] = MAXY-1;
  carte[0][2] = MAXX-1; carte[1][2] = MAXY-1; carte[2][2] = MAXX-1; carte[3][2] = MINY+1;
  carte[0][3] = MAXX-1; carte[1][3] = MINY+1; carte[2][3] = MINX+1; carte[3][3] = MINY+1;

  for(i = 4; i < n;i++){
    carte[0][i] = rand()%dim;
    carte[1][i] = rand()%dim;
    res = rand()%dim;
    while(carte[0][i]>res){
      res = rand()%dim;
    }
    carte[2][i] =  res;
    res = rand()%dim;
    while(carte[1][i]> res){
      res = rand()%dim;
    }
    carte[3][i] = res;
    if(MINX < 0){
      carte[0][i] += MINX;
      carte[1][i] += MINX;
      carte[2][i] += MINX;
      carte[3][i] += MINX;
    }
    else{
      carte[0][i] -= MINX;
      carte[1][i] -= MINX;
      carte[2][i] -= MINX;
      carte[3][i] -= MINX;
    }
    Bresenham_enti(carte[0][i],carte[1][i],carte[2][i],carte[3][i]);
  }
  int j;
  printf("ici!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  for(i = MINX; i < MAXX;i++){
    for(j=MINY;j<MAXY;j++){
      printf("%d ",carteT[i][j]);
    }
    printf("\n");
  }
}

void Bresenham_enti(int x1, int y1, int x2, int y2){
  int x,y;
  int ax = x2 - x1;
  int ay = y2 - y1;
  int erreur = ax*(-1);

  if(x1 > x2){
    ay = y2;
    y2 = y1;
    y1 = ay;
    ay = y2 - y1;
    ax = x2;
    x2 = x1;
    x1 = ax;
    ax = x2-x1;
    erreur = ax*(-1);
  }
  
  if(y2 > y1){
    for(x = x1, y = y1; x <= x2; x++){
      trace_point2(x,y);
      erreur += (2*ay);
      if(erreur >= 0){
	y++;
	erreur -= (2*ax);
      }
    }
  }
  else{
    for(x = x1, y = y1; x <= x2; x++){
      trace_point2(x,y);
      erreur += (2*ay);
      if(erreur <= 0){
	y--;
	erreur += (2*ax);
      }
    }
  }
  
}
void trace_point2(int x,int y){
  carteT[x][y] = 1;
}
