#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "SDL/SDL.h"
#include "../inc/ia.h"
#include "../inc/fonctions.h"

int main (int argc, char* argv[]){
  
  init_snake();

  SDL_Event event;
  Uint32 last_time = SDL_GetTicks();
  Uint32 current_time,ellapsed_time;
  Uint32 start_time;
  SDL_Surface *ecran = NULL;
  
  SDL_Init(SDL_INIT_VIDEO);
  atexit(SDL_Quit);
  SDL_WM_SetCaption("SnakeVSold",NULL);
  ecran = SDL_SetVideoMode(TAILLE_X,TAILLE_Y,32,SDL_HWSURFACE | SDL_GL_DOUBLEBUFFER | SDL_OPENGL);

  liste_map = creer_liste_vide();
  gencarte(15);
  genCarteOK = 1;
  idmap = 0;

  srand(getpid());
  
  ia = creer_ia(RAYON);;
  
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
	  default:
	    break;
	  }
      default:
	break;
      }
      affichage();
      anime_snake();
      mouvement_ia(ia);
      ellapsed_time = SDL_GetTicks() - start_time;

      if (ellapsed_time < 200){
	SDL_Delay(200 - ellapsed_time);
      }

      if (check_impact(ia) == 1) {
          printf("touché par IA !\n");
      }
      
      if (check_impact_ia(ia) != 0) {
          printf("L'IA %d a été touché !\n", check_impact_ia(ia));
      }
      
    }

  return 0;
}
