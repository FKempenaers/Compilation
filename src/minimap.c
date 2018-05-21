#include "../inc/minimap.h"

void affiche_minimap(){
  int i,j;
  
  glColor3ub(255,255,255);
  for(i = 0;i < (MAXX-MINX);i++){
    for(j = 0;j < (MAXY-MINY);j++){
      if(carteT[i][j]){
	glBegin(GL_POINTS);
	glVertex2d(i,j);
	glEnd();
      }
    }
  }
}
