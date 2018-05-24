#include "../inc/menu.h"


void menu(){
  //glDisable(GL_LIGHTING);
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1300, 0, 700);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  ligne(10,20,40);

  glFlush();
  SDL_GL_SwapBuffers();
  sleep(60);
  
  
}

void ligne(int x1,int y1,int y2){
  int i,j;
  glColor3ub(255,255,255);
  glBegin(GL_POINTS);
  for(i = y1;i < y2;i++){
    glVertex2i(50+i,50+i);
    glVertex2i(600+i,0+i);
    glVertex2i(600+i,700+i);
    glVertex2i(0+i,700+i);

  }
  glEnd();
}
