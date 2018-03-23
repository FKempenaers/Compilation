#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "fonctions.h"


int main (int argc, char* argv[]){
  int i;
  /*snake = malloc(3*sizeof(double*));
  for(i=0;i<3;i++)
    snake[i]=malloc(3*sizeof(double));
  */k = 0;
  angle = 0;
  increment = 0.25;
  vitesse = 0.5;
  xD=0;
  xs = MINX;
  ys = MINY;
  zs = 0;

  snake[0][0] = MINX+4*RAYON;
  snake[0][1] = MINY+4*RAYON;
  snake[0][2] = 0;
  snake[1][2] = 0;
  snake[2][2] = 0;

  for(i=1; i<3; i++){
    snake[i][0] = snake[i-1][0]-2*RAYON;
  }

  
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
