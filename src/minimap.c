#ifndef _MINIMAP_H
#define _MINIMAP_H

#include "../inc/minimap.h"
#include "../inc/fonctions.h"
#define OFFSETX 10
#define OFFSETY 10

void affiche_minimap(){
  int i,j;
  
  /*Partie affichage murs*/
  glColor3ub(255,255,255);
  for(i = 0;i < (MAXX-MINX);i++){
    for(j = 0;j < (MAXY-MINY);j++){
      if(carteT[i][j]==1){
	glBegin(GL_POINTS);
	glVertex2d(i+OFFSETX,j+OFFSETY);
	glEnd();
      }
    }
  }
  
  /*Partie affichage snake*/
  glColor3ub(0,0,255);
  for(i = 0;i < TAILLE_MAX;i++){
    glBegin(GL_POINTS);
    glVertex2d(snake[i][0]+OFFSETX,snake[i][1]+OFFSETY);
    glEnd();
  }
  
}



#endif
