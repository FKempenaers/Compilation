#include "../inc/liste.h"

liste empile(map e, liste L){
  liste L1 = (liste) malloc(sizeof(struct cellule));
  L1->m = e;
  L1->i = idmap;
  L1->suivant = L;
  return L1;
}

map nieme(liste L,int i){
  map tmp;
  liste L1 = L;
  if(!est_vide(L1)){
    while(!est_vide(L1) && L1->i != i){
      L1 = L1->suivant;
    }
    if(!est_vide(L1) && L1->i == i){
      return L1->m;
    }
  }
  tmp.nelem = -1;
  return tmp;
  
}

int est_vide(liste L){
  if(L==NULL){
    return 1;
  }
  return 0;
}

liste creer_liste_vide(){
  return NULL;
}

void detruire_liste(liste L){
  liste L1;
  while(L != NULL){
    L1=L->suivant;
    free(L);
    L = L1;
  }
}
