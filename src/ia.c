#include "../inc/ia.h"

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

    if (check_case(1, depart) == 1 && retour == 1) {
        if (check_case(4, depart) == 4) {
            if (check_case(2, depart) == 2) {
                retour = 3;
            }
            else {
                retour = 2;
            }
        }
        else {
            retour = 4;
        }
    }
    else if (check_case(2, depart) == 2 && retour == 2) {
        if (check_case(1, depart) == 1) {
            if (check_case(3, depart) == 3) {
                retour = 4;
            }
            else {
                retour = 3;
            }
        }
        else {
            retour = 1;
        }
    }
    else if (check_case(3, depart) == 3 && retour == 3) {
        if (check_case(2, depart) == 2) {
            if (check_case(4, depart) == 4) {
                retour = 1;
            }
            else {
                retour = 4;
            }
        }
        else {
            retour = 2;
        }
    }
    else if (check_case(4, depart) == 4 && retour == 4) {
        if (check_case(3, depart) == 3) {
            if (check_case(1, depart) == 1) {
                retour = 2;
            }
            else {
                retour = 1;
            }
        }
        else {
            retour = 4;
        }
    }


    return retour;
}

int choix_casev3(point depart, point arrive) {
    int retour = 0;
    int random = rand()%2;
    
    if (arrive.x >= depart.x) {
        if (arrive.y >= depart.y) {
            if (random == 0) {
                retour = 1;
            }
            else {
                retour = 4;
            }
        }
        else {
           if (random == 0) {
                retour = 1;
            }
            else {
                retour = 2;
            }
        }
    }
    else {
        if (arrive.y >= depart.y) {
            if (random == 0) {
                retour = 3;
            }
            else {
                retour = 4;
            }
        }
        else {
           if (random == 0) {
                retour = 2;
            }
            else {
                retour = 3;
            }
        }
    }

    return retour;
}

int check_case(int choix_case, point tete_ia) {
    if (choix_case == 1) {
        if(carteT[(int)(tete_ia.x+1)][(int)tete_ia.y] == 1 || carteT[(int)(tete_ia.x+1)][(int)tete_ia.y]) {
            return 1;
        }
    }
    else if (choix_case == 2) {
        if(carteT[(int)(tete_ia.x)][(int)tete_ia.y-1] == 1 || carteT[(int)(tete_ia.x)][(int)tete_ia.y-1]) {
            return 2;
        }
    }
    else if (choix_case == 3) {
        if(carteT[(int)(tete_ia.x-1)][(int)tete_ia.y] == 1 || carteT[(int)(tete_ia.x-1)][(int)tete_ia.y]) {
            return 3;
        }
    }
    else if (choix_case == 4) {
        if(carteT[(int)(tete_ia.x)][(int)tete_ia.y+1] == 1 || carteT[(int)(tete_ia.x)][(int)tete_ia.y+1]) {
            return 4;
        }
    }

    return 0;
}

point distance(point depart) {
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

void mouvement_ia_attentiste(point ia[]) {
    point nouveau;
    point cible = distance(ia[0]);

    double distance = sqrt(pow(cible.x - ia[0].x, 2) + pow(cible.y - ia[0].y, 2));

    nouveau.x = ia[0].x;
    nouveau.y = ia[0].y;
    nouveau.z = ia[0].z;

    if (distance < 20) {
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
}

void mouvement_ia_fantome (point ia[]) {
    point nouveau;
    point cible = distance(ia[0]);
    fprintf(stderr, "test1\n");
    nouveau.x = ia[0].x;
    nouveau.y = ia[0].y;
    nouveau.z = ia[0].z;

    switch(choix_casev3(ia[0], cible)){
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

int check_impact(point ia[]){
    int i;

    for (i = 1; i < TAILLE_MAX; i++) {
      if ((int)ia[0].x == (int)snake[i][0] && (int)ia[0].y == (int)snake[i][1]) {
            return 1;
        }
    }
    return 0;
}

int check_impact_ia (point ia[]) {
    int i;

    for (i = 0; i < TAILLE_MAX; i++) {
      if ((int)snake[0][0] == (int)ia[i].x && (int)snake[0][1] == (int)ia[i].y) {
            return 1;
        }
    }

    return 0;
}

point* creer_ia(double case_init_z) {
    int i;
    point* nouvelle_ia;
    point case_init;
    int check = 1;

    nouvelle_ia = (point*)malloc(sizeof(point) * TAILLE_MAX);

    while (check) {

        case_init.x = rand()%(MAXX - 25) + 25;
        case_init.y = rand()%(MAXY - 25) + 25;
        case_init.z = case_init_z;

        if (carteT[(int)case_init.x][(int)case_init.y] != 1 && carteT[(int)case_init.x][(int)case_init.y] != 3) {
            check = 0;
        }
    }

    for (i = 0; i < TAILLE_MAX; i++) {
        nouvelle_ia[i].x = case_init.x;
        nouvelle_ia[i].y = case_init.y;
        nouvelle_ia[i].z = case_init.z;
    }
    
    return nouvelle_ia;
}
