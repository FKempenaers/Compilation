#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "SDL/SDL.h"
#include "../inc/fonctions.h"


int main (int argc, char* argv[]){
  
  init_snake();

  SDL_Event event;
  Uint32 last_time = SDL_GetTicks();
    Uint32 current_time,ellapsed_time;
    Uint32 start_time;

  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("SnakeVSold",NULL);
  SDL_SetVideoMode(TAILLE_X,TAILLE_Y,32,SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);

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
	    angle -= PI/4;
	    break;
	  case SDLK_RIGHT:
	    angle += PI/4;
	    break;
	  }
        }
      affichage();
      anime_snake();

      ellapsed_time = SDL_GetTicks() - start_time;

      if (ellapsed_time < 1000){
	  SDL_Delay(1000 - ellapsed_time);
        }
    }

  return 0;
}
