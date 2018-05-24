#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "SDL/SDL.h"
#include "../inc/ia.h"
#include "../inc/fonctions.h"
#include "../inc/menu.h"

int main (int argc, char* argv[]){
  


  SDL_Event event;
  Uint32 last_time = SDL_GetTicks();
  Uint32 current_time,ellapsed_time;
  Uint32 start_time;
  int i;
  
  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("SnakeVSold",NULL);
  SDL_SetVideoMode(TAILLE_X,TAILLE_Y,32,SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);
  glutInit(&argc,argv);
  init_jeu();
  
  for (;;)
    {
      start_time = SDL_GetTicks();
      SDL_PollEvent(&event);
      switch(event.type)
	{
	case SDL_QUIT:
	  exit(0);
	  break;
	case SDL_KEYDOWN:
	  switch( event.key.keysym.sym ){
	  case SDLK_LEFT:
	    angle -= PI/8;
	    break;
	  case SDLK_RIGHT:
	    angle += PI/8;
	    break;
	  default:
	    break;
	  }
	default:
	  break;
	}
      affichage();
      anime_snake();
      
      for (i = 0; i < diff*3; i++) {
	if(ias[i] != NULL){
	  if(i==0||i==3||i==6)
	    mouvement_ia_attentiste(ias[i]);
	  else if(i==1||i==4||i==7)
	    mouvement_ia(ias[i]);
	  else
	    mouvement_ia_fantome(ias[i]);
	}
      }

      
      ellapsed_time = SDL_GetTicks() - start_time;

      if (ellapsed_time < 200){
	SDL_Delay(200 - ellapsed_time);
      }

      for (i = 0; i < diff*3; i++) {
	if(ias[i] != NULL){
	  if (check_impact(ias[i]) == 1) {
	    init_jeu();
	  }
      
	  if (check_impact_ia(ias[i]) != 0) {
	    free(ias[i]);
	    ias[i] = NULL;
	  }
	}
      }
    }

  return 0;
}
