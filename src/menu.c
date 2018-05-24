#include "../inc/menu.h"

int jouer[2];
int score[2];

void menu(){
  int b = 0;
  SDL_Event event;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1300, 0, 700);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  bouton(450,400,"JOUER");
  bouton(450,200,"SCORE");
  jouer[0] = 450;jouer[1] = 400;
  score[0] = 450,jouer[1] = 200;
  glFlush();
  SDL_GL_SwapBuffers();
  b = 0;
  while(b == 0){
    SDL_WaitEvent(&event);
    switch(event.type){
    case SDL_QUIT:
      exit(0);
      break;
    case SDL_MOUSEBUTTONUP:
      if(in(jouer,event.button.x,event.button.y)){
	b = 1;
      }
      if(in(score,event.button.x,event.button.y)){
	b = 2;
      }
      break;
    }
  }
  if(b == 1){
    jouerM();
  }
  if(b == 8){
    scoreM();
  }

}

void jouerM(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1300, 0, 700);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  bouton(450,400,"JOUER");
  jouer[0] = 450;jouer[1] = 400;

  glFlush();
  SDL_GL_SwapBuffers();
}

void scoreM(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1300, 0, 700);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  bouton(450,400,"SCORE");
  jouer[0] = 450;jouer[1] = 400;

  glFlush();
  SDL_GL_SwapBuffers();

}

void bouton(int x1,int y1,char* string){
  int i,j;
  boutoncadre(450,x1+200,y1,y1+100);
  glColor3d(0.2,0.6,0.2);
  glRasterPos2i(x1+20,y1+50);
  j = strlen(string);
  for(i = 0; i < j;i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);

}

void boutoncadre(int x1,int x2,int y1,int y2){
  glColor3ub(255,255,255);
  glBegin(GL_QUADS);
  glVertex2i(x1,y1);
  glVertex2i(x2,y1);
  glVertex2i(x2,y2);
  glVertex2i(x1,y2);
  glEnd();
}

int in(int *bouton,int x, int y){
  if(x >= bouton[0] && x <= bouton[0]+200){
    if(y >= bouton[1] && y <= bouton[1]+100){
      return 1;
    }
  }
  return 0;
}
