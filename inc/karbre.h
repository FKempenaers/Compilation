#ifndef _KARBRE_H
#define _KARBRE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "point.h"

#define K 8

typedef int element;

typedef struct struct_karbre {
  element e;
  struct struct_karbre** fils;
  point s1;
  point s2;
} struct_karbre;

typedef struct_karbre *karbre;

karbre kArbreVide();
karbre kConsArbre(element e, point s1, point s2, karbre b, ...);
karbre kFils(int ieme, karbre A);
element kRacine(karbre A);
int kEstVide(karbre A);
void kAfficher(karbre A);

#endif
