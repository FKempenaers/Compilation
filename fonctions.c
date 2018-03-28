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
  //gluLookAt(MAXX/2,-5,40,MAXX/2,0,0,0,0,1);
  gluLookAt(xs,ys-5,20,xs,ys,0,0,0,1);
  glRotatef(angle,0,0,1);
  trace_grille();

  /*****************************/


  affiche_snake(xs,ys,zs);
  /* for(i=MINX; i < MAXX;i++)
    maison(3*i,0,0,3);
  for(i=MINY; i < MAXY;i++)
    maison(0,3*i,0,3);
  */
    
  glutSwapBuffers();
}

void animer(){
  int i,j;
  /* angle += increment;
  if(angle > 360)
    angle = 0;
  */
  increment = 0;
  compteur += 1;
  if(compteur > RAYON){
    compteur = 0;
    increment = RAYON;
  }
  
  
  switch(direction){
  case 0 :
    xs+=increment;
    break;
  case 1 :
    ys+=increment;
    break;
  case 2 :
    xs-=increment;
    break;
  case 3 :
    ys-=increment;
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
  if(increment>0){
    for(i=TAILLE_MAX; i>0; i--){
      for(j=0; j<3; j++){
	snake[i][j] += snake[i-1][j]-snake[i][j];
      }
    }
    snake[0][0] = xs;
    snake[0][1] = ys;
    snake[0][2] = zs;
  }


  
  
  
    glutPostRedisplay();
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

  printf("sphere 1 : %lf %lf\n",snake[0][0],snake[0][1]);
  printf("sphere 2 : %lf %lf\n",snake[1][0],snake[1][1]);
  printf("sphere 3 : %lf %lf\n",snake[2][0],snake[2][1]);

  

  glColor3ub(255,0,0);
  glPushMatrix();
  glTranslated(x,y,z);
  glutSolidSphere(RAYON/2, 10, 10);

  for(i = 1; i <TAILLE_MAX;i++){
    glPopMatrix();
    glPushMatrix();
    glColor3ub(128,(i*20)%255,128);
    glTranslated(snake[i][0],snake[i][1],0);
    glutSolidSphere(RAYON/2, 10, 10);
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
