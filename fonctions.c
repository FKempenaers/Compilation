#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include "fonctions.h"
#include "point.h"

void affichage(){
  int i,j;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(100,(double)TAILLE_X/TAILLE_Y,0.1,100);
  gluLookAt(0,-40,40,0,0,0,0,0,1);
  glRotatef(angle,0,0,1);
  trace_grille();

  /*****************************/


  affiche_snake(xs,ys,zs);
  //maison(-2,-2,0,3);
  /*
  for(i=0; i < 10;i++)
    maison(3*i,i,0,2.5);
  */
    
  glutSwapBuffers();
}

void animer(){
  angle += increment;
  if(angle > 360)
    angle = 0;
  
  switch(xD){
  case 0 :
    xs+=vitesse;
    break;
  case 1 :
    ys+=vitesse;
    break;
  case 2 :
    xs-=vitesse;
    break;
  case 3 :
    ys-=vitesse;
    break;
  }
  if(xD==0&&xs>=MAXX)
    xD++;
  if(xD==1&&ys>=MAXY)
    xD++;
  if(xD==2&&xs<=MINX)
    xD++;
  if(xD==3&&ys<=MINY)
    xD=0;
  
  
    glutPostRedisplay();
}

void clavier(unsigned char key, int x, int y){
  increment = -increment;
  glutPostRedisplay();
}


void trace_grille(){
  int i,j;
  glColor3ub(255,255,255);
  for(i = MINX; i < MAXX; i++){
    for(j = MINY; j < MAXY; j++){
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
  for(i=0; i<2; i++){
    for(j=0; j<3; j++){
      snake[i+1][j] = snake[i][j];
    }
  }
  snake[0][0] = x;
  snake[0][1] = y;
  snake[0][2] = z;

  glColor3ub(255,0,0);
  glTranslated(x,y,z);
  glPushMatrix();
  glutWireSphere(RAYON, 10, 10);

  
  glColor3ub(128,0,128);
  glTranslated((snake[1][0]-snake[0][0])*4*RAYON,(snake[1][1]-snake[0][1])*4*RAYON,0);
  glutWireSphere(RAYON, 10, 10);
  glPopMatrix();
  glPushMatrix();
  glColor3ub(0,0,255);
  glTranslated((snake[2][0]-snake[0][0])*4*RAYON,(snake[2][1]-snake[0][1])*4*RAYON,0);
  glutWireSphere(RAYON, 10, 10);
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
