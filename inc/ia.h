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
 * Retourne la case vers laquelle l'IA va se diriger (4 dimensions)
 */
int choix_casev3(point depart, point arrive);

/*
 * Vérifie si la case vers laquelle l'IA va est une case valide ou non
 */
int check_case(int choix_case, point tete_ia);

/*
 * Retourne le point du serpent joueur le plus proche de l'IA
 */
point distance(point depart);

/*
 * Le tableau représentant l'IA prend la nouvelle tête et déplace le reste des points
 */
void avancer_corps(point ia[], point nouvelle_tete);

/*
 * Le tableau représentant l'IA avance d'une caseen direction du point le plus proche du serpent joueur
 */
void mouvement_ia(point ia[]);

/*
 * L'IA avance vers le joueur uniquement si elle est proche de lui
 */
void mouvement_ia_attentiste(point ia[]);

/*
 * L'IA peut traverser les murs
 */
void mouvement_ia_fantome(point ia[]);

/*
 * Renvoie 0 si l'IA n'a pas rencontré le corps du snake et 1 si la tête de l'IA 
 */
int check_impact(point ia[]);

/*
 * Renvoie le numéro de l'IA touché par la tête du serpent et 0 sinon
 */
int check_impact_ia(point ia[]);

/*
 * Retourne le tableau de point d'un serpent IA à une hauteur donnée z, la position est aléatoire
 */
point* creer_ia(double case_init_z);

#endif
