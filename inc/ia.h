#ifndef _IA_H
#define _IA_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"
#include "carte.h"

typedef struct point {
    double x;
    double y;
    double z;
} point;

/*
 * Retourne la case vers laquelle l'IA va se diriger (4 dimensions)
 */
int choix_case(point depart, point arrive);

/*
 * Retourne le point du serpent joueur le plus proche de l'IA
 */
point distance(point depart);

/*
 * Le tableau représentant l'IA prend la nouvelle tête et déplace le reste des points
 */
void avancer_corps(point ia[], point nouvelle_tete);

/*
 * Le tableau représentant l'IAavance d'une caseen direction du point le plus proche du serpent joueur
 */
void mouvement_ia(point ia[]);

#endif