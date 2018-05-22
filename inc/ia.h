#ifndef _IA_H
#define _IA_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"
#include "carte.h"
#include "point.h"

/*
 * Retourne la case vers laquelle l'IA va se diriger (4 dimensions)
 */
int choix_casev2(point depart, point arrive);

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

/*
 * Retourne le tableau de point d'un serpent IA à une hauteur donnée z, la position est aléatoire.
 */
point* creer_ia(double case_init_z);

#endif
