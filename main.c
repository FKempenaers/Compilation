#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "fonctions.h"


int main (int argc, char* argv[]){

  k = angle = compteur = 0;
  increment = 0.25;
  vitesse = 0.10;
  xD=0;
  xs = MINX+RAYON*4;
  ys = MINY;
  zs = 0;

  snake[0][0] = xs;
  snake[0][1] = ys;
  snake[0][2] = 0;
  snake[1][2] = 0;
  snake[2][2] = 0;

  snake[1][0] = MINX+RAYON*2;
  snake[2][0] = MINX;


  printf("start\n");
  printf("sphere 1 : %lf %lf\n",snake[0][0],snake[0][1]);
  printf("sphere 2 : %lf %lf\n",snake[1][0],snake[1][1]);
  printf("sphere 3 : %lf %lf\n",snake[2][0],snake[2][1]);
  printf("fin start\n");
  
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

  glutInitWindowSize(TAILLE_X, TAILLE_Y);
  glutInitWindowPosition(800, 50);

  glutCreateWindow("une fenêtre OpenGL");

  glutDisplayFunc(affichage);
  glutKeyboardFunc(clavier);
  glutIdleFunc(animer);


  glutMainLoop();
  
  return 0;
}
