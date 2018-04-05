#include "../inc/karbre.h"
#include <stdio.h>

karbre kArbreVide(){
  return NULL;
}

karbre kConsArbre(element e, point s1, point s2, karbre b, ...){
  karbre A,arbre;
  va_list params;
  va_start(params,b);
  
  double x1 = s1.p[0];
  double y1 = s1.p[1];
  double z1 = s1.p[2];
  double x2 = s2.p[0];
  double y2 = s2.p[1];
  double z2 = s2.p[2];
  
  A = (karbre) malloc(sizeof(struct_karbre));
  A->fils = (karbre*)malloc(K*sizeof(struct_karbre));
  A->e = e;
  A->s1 = s1;
  A->s2 = s2;
  arbre = b;
  for(int i=0; i < K; i++){
    if(arbre != NULL){
      A->fils[i] = (karbre) malloc(sizeof(struct_karbre));
      A->fils[i] = arbre;
      arbre = va_arg(params, karbre);
    }else{
      A->fils[i] = (karbre) malloc(sizeof(struct_karbre));
      A->fils[i] = NULL;
      arbre = va_arg(params, karbre);
    }
  }
  va_end(params);
  return A;
}

karbre kFils(int ieme, karbre A){
  if(A->fils!=NULL)
  return A->fils[ieme];
  else
    return NULL;
}

element kRacine(karbre A){
  return A->e;
}

int kEstVide(karbre A){
  if(A == NULL)
    return 1;
  else
    return 0;
}

void kAfficher(karbre A){
  if(A!=NULL){
    printf("%d",A->e);
      for(int i=0; i<K; i++){
	if(!kEstVide(A->fils[i])){
	   kAfficher(A->fils[i]);
	   }
      }
      printf("\n");
  }
}
