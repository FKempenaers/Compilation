#ifndef _LISTE_H
#define _LISTE_H

#include <stdio.h>
#include <stdlib.h>
#include "carte.h"

typedef struct map{
  int nelem;
  int **carte;
  int **carteT;
}map;

struct cellule{
  int i;
  map m;
  struct cellule *suivant;
};

typedef struct cellule *liste;

liste liste_map;

liste creer_liste_vide();
void detruire_liste(liste);
int est_vide(liste);

liste empile(map,liste);
map nieme(liste,int);

#endif
