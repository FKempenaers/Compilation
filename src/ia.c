#include "../inc/ia.h"

int choix_case(point depart, point arrive) {
    int retour = 0;
    
    if (arrive.x > depart.x && arrive.y > - arrive.x && arrive.y < arrive.x) {
        //La case arrive se trouve à droite de la case depart
        retour = 1;
    }
    else if (arrive.y < depart.y && arrive.x < arrive.y && arrive.x > - arrive.y) {
        //La case arrive se trouve en dessous de la case depart
        retour = 2;
    }
    else if (arrive.x < depart.x && arrive.y > - arrive.x && arrive.y < arrive.x) {
        //La case arrive se trouve à gauche de la case depart
        retour = 3;
    }
    else if (arrive.y > depart.y && arrive.x < arrive.y && arrive.x > - arrive.y) {
        //La case arrive se trouve en ahut de la case depart
        retour = 4;
    }

    return retour;
}

point distance (point depart, point serpent[]) {
    int i;
    point retour;
    double distance;
    double min = 10000;

    for (i = 0; i < TAILLE_MAX; i++) {
        distance = sqrt(pow(serpent[i].x - depart.x, 2) + pow(serpent[i].y - depart.y, 2));

        if (distance < min) {
            retour.x = serpent[i].x;
            retour.y = serpent[i].y;
        }
    }

    return retour;
}

int main () {
    printf("ok\n");
}