#include "../inc/ia.h"

int choix_case(point depart, point arrive) {
    int retour = 0;
    
    if (arrive.x > depart.x && arrive.x > arrive.y && - arrive.x < arrive.y) {
        if (carte[(int)depart.x+1][(int)depart.y] != 1) {
            //La case arrive se trouve à droite de la case depart
            retour = 1;
        }
        else {
            //On ne peut pas aller à droite
            retour = 0;
        }
    }
    else if (arrive.y < depart.y && (arrive.x < - arrive.y || - arrive.x < - arrive.y)) {
        if (carte[(int)depart.x][(int)depart.y-1] != 1) {
            //La case arrive se trouve en dessous de la case depart
            retour = 2;
        }
        else {
            retour = 0;
        }
    }
    else if (arrive.x < depart.x && (- arrive.x > - arrive.x || - arrive.x < arrive.x)) {
        if (carte[(int)depart.x-1][(int)depart.y] != 1) {
            //La case arrive se trouve à gauche de la case depart
            retour = 3;
        }
        else {
            retour = 0;
        }
    }
    else if (arrive.y > depart.y && arrive.x < arrive.y && arrive.x > - arrive.y) {
        if (carte[(int)depart.x][(int)depart.y+1] != 1) {
            //La case arrive se trouve en ahut de la case depart
            retour = 4;
        }
        else {
            retour = 0;
        }
    }

    return retour;
}

int choix_casev2(point depart, point arrive) {
    int retour = 0;

    if (arrive.x >= depart.x) {
        //Moitié de droite
        if (arrive.y >= depart.y) {
            //Quart haut-droite
            if (abs(arrive.x) > abs(arrive.y)) {
                //printf("haut droite droite\n");
                retour = 1;
            }
            else {
                //printf("haut droite haut\n");
                retour = 4;
            }
        }
        else {
            //Quart bas-droite
            if (abs(arrive.x) > abs(arrive.y)) {
                //printf("bas droite droite\n");
                retour = 1;
            }
            else {
                //printf("bas droite bas\n");
                retour = 2;
            }
        }
    }
    else {
        if (arrive.y >= depart.y) {
            //Quart haut-gauche
            if (abs(arrive.y) > abs(arrive.x)) {
                //printf("haut gauche haut\n");
                retour = 4;
            }
            else {
                //printf("haut gauche gauche\n");
                retour = 3;
            }
        }
        else {
            //Quart bas-gauche
            if (abs(arrive.y) > abs(arrive.x)) {
                //printf("bas gauche bas\n");
                retour = 2;
            }
            else {
                //printf("bas gauche gauche\n");
                retour = 3;
            }
        }
    }

    return retour;
}

point distance (point depart) {
    int i;
    point retour;
    double distance;
    double min = 10000;

    for (i = 0; i < TAILLE_MAX; i++) {
        distance = sqrt(pow(snake[i][0] - depart.x, 2) + pow(snake[i][1] - depart.y, 2));

        if (distance < min) {
            retour.x = snake[i][0];
            retour.y = snake[i][1];
        }
    }

    return retour;
}

void avancer_corps(point ia[], point nouvelle_tete) {
    int i;
    point tmp[TAILLE_MAX];

    tmp[0].x = nouvelle_tete.x;
    tmp[0].y = nouvelle_tete.y;
    tmp[0].z = nouvelle_tete.z;
    
    for (i = 1; i < TAILLE_MAX; i++) {
        tmp[i].x = ia[i-1].x;
        tmp[i].y = ia[i-1].y;
        tmp[i].z = ia[i-1].z;
    }

    for (i = 0; i < TAILLE_MAX; i++) {
        ia[i].x = tmp[i].x;
        ia[i].y = tmp[i].y;
        ia[i].z = tmp[i].z;
    }
}

void mouvement_ia(point ia[]) {
    point nouveau;
    point cible = distance(ia[0]);

    nouveau.x = ia[0].x;
    nouveau.y = ia[0].y;
    nouveau.z = ia[0].z;

    switch(choix_casev2(ia[0], cible)){
    case(1):
        nouveau.x += 1;
        break;
    case(2):
        nouveau.y -= 1;
        break;
    case(3):
        nouveau.x -= 1;
        break;
    case(4):
        nouveau.y += 1;
        break;
    default:
        break;
    }

    avancer_corps(ia, nouveau);
}

int main () {
    int i;
    point ia[TAILLE_MAX];

    for (i = 0; i < TAILLE_MAX; i++) {
        snake[i][0] = 0;
        snake[i][1] = 0;
        snake[i][2] = 0;

        ia[i].x = 10;
        ia[i].y = 20;
        ia[i].z = 10;
    }

    mouvement_ia(ia);
    /*
    for (i = 0; i < TAILLE_MAX; i++) {
        printf("%f %f %f\n", ia[i].x, ia[i].y, ia[i].z);
    }
    */
}