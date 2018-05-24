#include "../inc/menu.h"


void menu(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  
  ligne(i,int y1,int y2);
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
