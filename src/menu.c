#include "../inc/menu.h"


void menu(){
  int b = 0;
  
  int jouer[2];
  int score[2];
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
  if(b == 2){
    scoreM();
  }

}

void jouerM(){
  int b,i;
  
  int jouer[2];
  char nombre[4];
  SDL_Event event;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1300, 0, 700);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  bouton(450,400,"JOUER");
  jouer[0] = 450;jouer[1] = 200;
  editbox(500,500);

  glFlush();
  SDL_GL_SwapBuffers();
  i = 0;
  nombre[0] = '\0';
  nombre[1] = '\0';
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
      break;
    case SDL_KEYDOWN:
      switch(event.key.keysym.sym){
      case 8:
	if(i > -1){
	  i--;
	  nombre[i] = '\0';
	}
	if(i < 0){
	  i = 0;
	}
	break;
      case 224:
	nombre[i] = '0';
	if(i<3)i++;
	nombre[i] = '\0';	  
	break;
      case 38:
	nombre[i] = '1';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 233:
	nombre[i] = '2';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 34:
	nombre[i] = '3';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 39:
	nombre[i] = '4';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 40:
	nombre[i] = '5';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 45:
	nombre[i] = '6';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 232:
	nombre[i] = '7';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 95:
	nombre[i] = '8';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      case 231:
	nombre[i] = '9';
	if(i<3)i++;
	nombre[i] = '\0';
	break;
      default:
	break;
      }
      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, 1300, 0, 700);

      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      bouton(450,400,"JOUER");
      editbox(500,500);
      readtextbox(500,500,nombre);
      SDL_GL_SwapBuffers();
    default:
      break;
    }
    
  }
  diff = b;
  nbetage = atoi(nombre);
  if(nbetage > 100){
    nbetage = 100;
  }
  if(nbetage < 1){
    nbetage = 1;
  }
}

void scoreM(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1300, 0, 700);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  bouton(450,400,"SCORE");
  //jouer[0] = 450;jouer[1] = 400;

  glFlush();
  SDL_GL_SwapBuffers();

}
void readtextbox(int x1,int y1,char* string){
  int i,j;
  glColor3d(0.2,0.6,0.2);
  glRasterPos2i(x1,y1);
  j = strlen(string);
  for(i = 0; i < j;i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}
void bouton(int x1,int y1,char* string){
  int i,j;
  boutoncadre(x1,x1+200,y1,y1+100);
  glColor3d(0.2,0.6,0.2);
  glRasterPos2i(x1+20,y1+50);
  j = strlen(string);
  for(i = 0; i < j;i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);

}
void editbox(int x1,int y1){
  boutoncadre(x1,x1+100,y1,y1+50);
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
