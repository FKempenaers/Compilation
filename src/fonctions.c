#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "SDL/SDL.h"
#include <math.h>
#include "../inc/fonctions.h"
#include "../inc/point.h"

void affichage(){
  int i,j;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE  );

  glLightx(GL_LIGHT0,GL_POSITION,1,1,0);
  glLightx(GL_LIGHT0,GL_AMBIENT,0,0,0,1);
  glLightx(GL_LIGHT0,GL_DIFFUSE,1,1,1,1);
  glLightx(GL_LIGHT0,GL_SPECULAR,1,1,1,1);

  GLint white[] = {1,1,1,1};
  glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
  GLint color[] = {0,0,0,1};
  glMaterialiv(GL_FRONT_AND_BACK,GL_EMISSION,color);
  
  int LightPos[4] = {0,0,3,1};
  glLightiv(GL_LIGHT0,GL_POSITION,LightPos);


  
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(100,(double)TAILLE_X/TAILLE_Y,0.1,100);
  //gluLookAt(MAXX/2,-20,40,MAXX/2,0,0,0,0,1);
  gluLookAt(xs,ys-5,20,xs,ys,0,0,0,1);
  //glRotatef(angle,0,0,1);
  trace_grille();

  /*****************************/
  
  if(genCarteOK != 0 && genCarteOK != 1) genCarteOK = 0;
  if(genCarteOK == 0){
    gencarte(10);
    genCarteOK = 1;
  }
  affiche_carte(carte,10);
  affiche_snake(xs,ys,zs);

  affiche_snake(xs,ys,zs);
  /* for(i=MINX; i < MAXX;i++)
    maison(3*i,0,0,3);
  for(i=MINY; i < MAXY;i++)
    maison(0,3*i,0,3);
  */
  glFlush();
  SDL_GL_SwapBuffers();
}

void animer(){
  int i,j,increment2;
  
  /* angle += increment;
  if(angle > 360)
    angle = 0;
  */
  increment2 = 0;
  compteur++;
  if(compteur > RAYON*2){
    compteur = 0;
    increment2 = RAYON*2;
  }
  /*
  printf("sphere 1 : %lf %lf\n",snake[0][0],snake[0][1]);
  printf("sphere 2 : %lf %lf\n",snake[1][0],snake[1][1]);
  printf("sphere 3 : %lf %lf\n",snake[2][0],snake[2][1]);
  printf("compteur : %d\n",compteur);
  printf("increment : %d\n",increment2);
  */

  
  
  
  switch(direction){
  case 0 :
    xs+=increment2;
    break;
  case 1 :
    ys+=increment2;
    break;
  case 2 :
    xs-=increment2;
    break;
  case 3 :
    ys-=increment2;
    break;
  }
  /* if(xD==0&&xs>=MAXX)
    xD++;
  if(xD==1&&ys>=MAXY)
    xD++;
  if(xD==2&&xs<=MINX)
    xD++;
  if(xD==3&&ys<=MINY)
    xD=0;
  */
  if(increment2>0){
    for(i=TAILLE_MAX; i>0; i--){
	snake[i][0] = snake[i-1][0];//-snake[i][j];
	snake[i][1] = snake[i-1][1];
    }
    snake[0][0] = xs;
    snake[0][1] = ys;
    snake[0][2] = zs;
  }


  
  
  
  // glutPostRedisplay();
}

void clavier(unsigned char key, int x, int y){
  //increment = -increment;
  //  pause();
  glutPostRedisplay();
}


void fleches(int key, int x, int y){
  switch(key)
    {
      //les ifs servent à empecher de prendre la direction opposée à la direction courante
    case GLUT_KEY_UP:
      if(direction!=3)
      direction = 1;
      break;
    case GLUT_KEY_DOWN:
      if(direction!=1)
      direction = 3;
      break;
    case GLUT_KEY_LEFT:
      if(direction!=0)
      direction = 2;
      break;
    case GLUT_KEY_RIGHT:
      if(direction!=2)
      direction = 0;
      break;
    }
}


void trace_grille(){
  int i,j;
  glColor3ub(255,255,255);
  for(i = MINX; i <= MAXX; i++){
    for(j = MINY; j <= MAXY; j++){
      glBegin(GL_LINES);
      glVertex2i(i,MINY);
      glVertex2i(i,MAXY);
      glEnd();
      glBegin(GL_LINES);
      glVertex2i(MINX,j);
      glVertex2i(MAXX,j);
      glEnd();
    }
  }
  glColor3ub(0,255,255);
  glBegin(GL_LINES);
  glVertex2i(0,MINY);
  glVertex2i(0,MAXY);
  glEnd();
  glBegin(GL_LINES);
  glVertex2i(MINX,0);
  glVertex2i(MAXX,0);
  glEnd();
}

void affiche_snake(double x, double y, double z){
  int i,j;
  GLUquadric* lol;
  lol = gluNewQuadric();
 

  glColor3ub(255,0,0);
  glPushMatrix();
  glTranslated(snake[0][0],snake[0][1],z);
  gluSphere(lol, RAYON, 10,10);

  for(i = 1; i <TAILLE_MAX;i++){
    glPopMatrix();
    glPushMatrix();
    glColor3ub(128,(i*20)%255,128);
    glTranslated(snake[i][0],snake[i][1],snake[i][2]);
    gluSphere(lol,RAYON, 10,10);
  }

  glPopMatrix();
}

void maison(double x, double y, double z, double c){
  glColor3ub(0,0,255);
  glBegin(GL_QUAD_STRIP);

  glVertex3d(x,y,z);
  glVertex3d(x,y,z+c);
  glVertex3d(x,y+c,z);
  glVertex3d(x,y+c,z+c);

  glVertex3d(x+c,y+c,z);
  glVertex3d(x+c,y+c,z+c);
  glVertex3d(x+c,y,z);
  glVertex3d(x+c,y,z+c);

  glVertex3d(x,y,z);
  glVertex3d(x,y,z+c);

  glEnd();

  glColor3ub(255,0,0);
  glBegin(GL_TRIANGLE_STRIP);

  glVertex3d(x,y,z+c);
  glColor3ub(0,0,255);
  glVertex3d(x,y+c,z+c);
  glColor3ub(0,255,0);
  glVertex3d(x+c/2,y+c/2,z+3*c/2);

  glVertex3d(x+c,y+c,z+c);
  glVertex3d(x+c,y,z+c);
  glVertex3d(x+c/2,y+c/2,z+3*c/2);
  glVertex3d(x,y,z+c);
  glVertex3d(x,y+c,z+c);
  
  glEnd();
}

void init_snake(){
   k = angle = compteur = 0;
  increment = 0.25;
  vitesse = 0.10;
  direction = 0;
  xs = MINX+RAYON*2;
  ys = MINY;
  zs = RAYON;

  snake[0][0] = xs;
  snake[0][1] = ys;
  snake[0][2] = zs;

  for(int i = 1; i <TAILLE_MAX;i++){
    snake[i][0] = snake[i-1][0]-RAYON*2;
    snake[i][1] = 0;
    snake[i][2] = RAYON;
  }
}

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

void anime_snake(){
  int i,timer;
  int xO,yO,xM,yM;
  int xU,yU,xV,yV;
  SDL_GetMouseState(&xSouris,&ySouris);

  /*calculer le vecteur entre milieu écran et position curseur
    en déduire l'angle par rapport à l'horizontale
    déplacer le snake en le faisant tourner

soit A le point du curseur
On veut calculer les vecteurs OA (u)  et OM (v) et trouver l'angle*/
  /*
  xO = TAILLE_X/2;
  yO = TAILLE_Y/2;
  xM = TAILLE_X/2;
  yM = 0;

  xU = xSouris-xO;
  yU = ySouris-yO;
  xV = xM-xO;
  yV = yM-yO;
  
  angle = acos( (xU*xV+yU*yV)/(sqrt(xU*xU+yU*yU)*sqrt(xV*xV+yV*yV)) );
  printf("angle : %lf",angle*180/PI);
  */
  xs += RAYON*2*sin(angle);
  ys += RAYON*2*cos(angle);

  for(i=TAILLE_MAX; i>0; i--){
    snake[i][0] = snake[i-1][0];//-snake[i][j];
    snake[i][1] = snake[i-1][1];
  }
  snake[0][0] = xs;
  snake[0][1] = ys;
  snake[0][2] = zs;

  for(timer = 0;timer <500;timer++);
  printf("x= %d, y= %d\n",xSouris,ySouris);
}

void gencarte(int n){
  srand(getpid());
  /*int **carte,*/
  int i,res;
  int dim;
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
  }

  //return carte;
  
}