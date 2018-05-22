#include "../inc/carte.h"

void affiche_carte(int *carte[4],int x){
  int i;
  for(i=0;i<x;i++){
    affiche_mur(carte[0][i],carte[1][i],0,carte[2][i],carte[3][i],10);
  }
  affiche_sol();
}

void affiche_sol(){
  int mi;
  if(MINY < 0){
    mi = MINY*-1;
    mi*=2;
    mi-=10;
  }
  affiche_cube_sol(MINX,MINY,0,MAXX-40,MAXY,1,0.8);
  affiche_cube_sol(MAXX,MINY,0,MAXX-40,MAXY-10,1,0.8);
  affiche_pente(MINX + 15, MINY+1 , 1,MINX+40,MINY+13,10);
  affiche_pente(MAXX - 15, MAXY, -10,MAXX-40,MAXY-10,1);
}

void affiche_mur( int x1, int y1, int z1, int x2,int y2, int z2){
  affiche_cube(x1,y1,z1,x2,y2,z2,0.3);
}

void affiche_pente(int x1, int y1, int z1, int x2,int y2, int z2){
  glBegin(GL_QUADS);
  glColor3f(0.9, 0.9, 0.9);
  glVertex3f(x1, y1, z1);
  glVertex3f(x2, y1, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x1, y2, z1);
  glEnd();
}

void affiche_cube_sol(int  x1, int y1, int z1, int x2,int y2, int z2,double color){
  glBegin(GL_QUADS);
  glColor3f(0.9, 0.9, 0.9);
  glVertex3f(x1, y1, z1);
  glVertex3f(x2, y1, z1);
  glVertex3f(x2, y1, z2);
  glVertex3f(x1, y1, z2);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(0, 0.8, 0.8);
  glVertex3f(x1, y1, z1);
  glVertex3f(x1, y2, z1);
  glVertex3f(x1, y2, z2);
  glVertex3f(x1, y1, z2);
  glEnd();
  
  glBegin(GL_QUADS);
  glColor3f(0.7, 0.7, 0);
  glVertex3f(x1, y1, z1);
  glVertex3f(x1, y2, z1);
  glVertex3f(x2, y2, z1);
  glVertex3f(x2, y1, z1);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(color, 0, color);
  glVertex3f(x1, y1, z2);
  glVertex3f(x1, y2, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x2, y1, z2);
  glEnd();
  
  glBegin(GL_QUADS);
  glColor3f(0, 0.3, 0.6);
  glVertex3f(x2, y1, z1);
  glVertex3f(x2, y2, z1);
  glVertex3f(x2, y2, z2);
  glVertex3f(x2, y1, z2);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.4, 0.4, 0.4);
  glVertex3f(x1, y2, z1);
  glVertex3f(x1, y2, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x2, y2, z1);
  glEnd();
}

void affiche_cube(int x1, int y1, int z1, int x2,int y2, int z2,double color){

  int x3,x4,y3,y4;
  if((x1 - x2)^2 <= (y1 - y2)^2){
    x3 = x1 + 1;
    x4 = x2 + 1;
    y3 = y1;
    y4 = y2;
    x1--;
    x2--;
  }
  else{
    x3 = x1;
    x4 = x2;
    y3 = y1 + 1;
    y4 = y2 + 1;
    y1--;
    y2--;
  }
  
  glBegin(GL_QUADS);
  glColor3f(0, 0, 0);
  glVertex3f(x1, y1, z1);
  glVertex3f(x2, y2, z1);
  glVertex3f(x4, y4, z1);
  glVertex3f(x3, y3, z1);
  glEnd();
  glBegin(GL_QUADS);
  glColor3f(1, 1,1);
  glVertex3f(x1, y1, z1);
  glVertex3f(x1, y1, z2);
  glVertex3f(x2, y2, z2);
  glVertex3f(x2, y2, z1);
  glEnd();
  
  glBegin(GL_QUADS);
  glColor3f(0.7, 0.7, 0);
  glVertex3f(x1, y1, z1);
  glVertex3f(x3, y3, z1);
  glVertex3f(x3, y3, z2);
  glVertex3f(x1, y1, z2);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(1, 1, 1);
  glVertex3f(x3, y3, z1);
  glVertex3f(x4, y4, z1);
  glVertex3f(x4, y4, z2);
  glVertex3f(x3, y3, z2);
  glEnd();
  
  glBegin(GL_QUADS);
  glColor3f(0, 0, 0);
  glVertex3f(x1, y1, z2);
  glVertex3f(x3, y3, z2);
  glVertex3f(x4, y4, z2);
  glVertex3f(x2, y2, z2);
  glEnd();

  glBegin(GL_QUADS);
  glColor3f(0.7, 0.7, 0);
  glVertex3f(x2, y2, z1);
  glVertex3f(x4, y4, z1);
  glVertex3f(x4, y4, z2);
  glVertex3f(x2, y2, z2);
  glEnd();
  
}

void gencarte(int n){
  srand(getpid());
  int i,ii,jj,res;
  int dim;
  carteT = (int**) calloc((MAXY-MINY),sizeof(int*));
  for(i = 0;i < (MAXX-MINX);i++){
    carteT[i] = (int*)calloc((MAXY-MINY),sizeof(int));
  }
  carte = (int**) malloc(sizeof(int*)*4);
  for(i=0; i  < 4 ; i ++){
    carte[i] = (int*)malloc(sizeof(int)*n);
    if(carte[i] == NULL){
      printf("error gen carte allocation mémoire\n");
      exit (-1);
    }
  }
  if(MINX < 0) dim = (MINX*-1)+MAXX;
  else if(MINX == 0) dim = MAXX;
  else dim = MAXX-MINX;
  
  carte[0][0] = MINX+1; carte[1][0] = MINY+1; carte[2][0] = MINX+1; carte[3][0] = MAXY-1;
  trace_segment_bresenInt(carte[0][0],carte[1][0],carte[2][0],carte[3][0]);
  carte[0][1] = MINX+1; carte[1][1] = MAXY-1; carte[2][1] = MAXX-1; carte[3][1] = MAXY-1;
  trace_segment_bresenInt(carte[0][1],carte[1][1],carte[2][1],carte[3][1]);
  carte[0][2] = MAXX-1; carte[1][2] = MAXY-1; carte[2][2] = MAXX-1; carte[3][2] = MINY+1;
  trace_segment_bresenInt(carte[0][2],carte[1][2],carte[2][2],carte[3][2]);
  carte[0][3] = MAXX-1; carte[1][3] = MINY+1; carte[2][3] = MINX+1; carte[3][3] = MINY+1;
  trace_segment_bresenInt(carte[0][3],carte[1][3],carte[2][3],carte[3][3]);

  trace_segment_bresenInt(MAXX-1,MAXY-10,MAXX-40,MAXY-10);
  carte[0][4] = MAXX-40; carte[1][4] = MAXY-10; carte[2][4] = MAXX-2; carte[3][4] = MAXY-10;
  trace_segment_bresenInt(MINX+40,MINY+13,MINX+15,MINY+13);
  carte[0][5] = MINX+40; carte[1][5] = MINY+13; carte[2][5] = MINX+15; carte[3][5] = MINY+13;
  trace_segment_bresenInt(MINX+41,MINY+3,MINX+41,MINY+13);
  carte[0][6] = MINX+41; carte[1][6] = MINY+13; carte[2][6] = MINX+41; carte[3][6] = MINY+1;

  
  for(ii = 0; ii < MAXY;ii++){
    for(jj = 0;jj < MAXX;jj++){
      if(carteT[ii][jj] == 2){
	carteT[ii][jj] = 1;
      }
    }
  }
  for(ii = MAXX-15;ii > MAXX-40;ii--){
    for(jj = MAXY-3; jj > MAXY-10;jj--){
      carteT[ii][jj] = 3;
    }
  }
  for(ii = MINX+15;ii < MINX+40;ii++){
    for(jj = MINY+3; jj <MINY+13;jj++){
      carteT[ii][jj] = 3;
    }
  }

  for(i = 7; i < n;i++){
    carte[0][i] = rand()%dim;
    carte[1][i] = rand()%dim;
    res = rand()%dim;
    while(carte[0][i]>res){
      res = rand()%dim;
    }
    carte[2][i] =  res;
    res = rand()%dim;
    while(carte[1][i]> res){
      res = rand()%dim;
    }
    carte[3][i] = res;
    if(MINX < 0){
      carte[0][i] += MINX;
      carte[1][i] += MINX;
      carte[2][i] += MINX;
      carte[3][i] += MINX;
    }
    else{
      carte[0][i] -= MINX;
      carte[1][i] -= MINX;
      carte[2][i] -= MINX;
      carte[3][i] -= MINX;
    }
     
    if(trace_segment_bresenInt(carte[0][i],carte[1][i],carte[2][i],carte[3][i]) == 1){
      for(ii = MINX; ii < MAXY;ii++){
	for(jj = MINY;jj < MAXX;jj++){
	  if(carteT[ii][jj] == 2){
	    carteT[ii][jj] = 1;
	  }
	}
      }
    }
    else{
      for(ii = MINX; ii < MAXY;ii++){
	for(jj = MINY;jj < MAXX;jj++){
	  if(carteT[ii][jj] == 2){
	    carteT[ii][jj] = 0;
	  }
	}
      }
      i--;
    }
  }
}

int est_pas_entoure(int x,int y){
  if(carteT[x][y] != 1 && carteT[x][y] != 3){
    if(x+1 < MAXX ){
      if(carteT[x+1][y] == 1 || carteT[x+1][y] == 3){
	return 0;
      }
    }
    if(x-1 > MINX){
      if(carteT[x-1][y] == 1 || carteT[x-1][y] == 3){
	return 0;
      }
    }
    if(y+1 < MAXY){
      if(carteT[x][y+1] == 1 || carteT[x][y+1] == 3){
	return 0;
      }
      if(x+1 < MAXX){
	if(carteT[x+1][y+1] == 1 || carteT[x+1][y+1] == 3){
	  return 0;
	}
      }
      if(x-1 > MINX){
	if(carteT[x-1][y+1] == 1 || carteT[x-1][y+1] == 3){
	  return 0;
	}
      }
    }
    if(y-1 > MINY){
      if( carteT[x][y-1] == 1 || carteT[x][y-1] == 3){
        return 0;
      }
     
      if(x+1 < MAXX){
	if(carteT[x+1][y-1] == 1 || carteT[x+1][y-1] == 3){
	  return 0;
	}
      }
      if(x-1 > MINX){
	if(carteT[x-1][y-1] == 1 || carteT[x-1][y-1] == 3){
	  return 0;
	}
      }
    }
    return 1;
  }
  return 0;
}


int trace_point2(int x,int y){
  if (est_pas_entoure(x,y) == 1){
    carteT[x][y] = 2;
    if(x+1 < MAXX ){
      carteT[x+1][y] = 2;
    }
    if(x-1 > MINX){ 
      carteT[x-1][y] = 2; 
    }
    if(y+1 < MAXY){
      carteT[x][y+1] = 2;
      if(x+1 < MAXX){
	carteT[x+1][y+1] = 2;
      }
      if(x-1 > MINX){
	carteT[x-1][y+1] = 2;
      }
    }
    if(y-1 > MINY){
      carteT[x][y-1] = 2;
      if(x+1 < MAXX){
	carteT[x+1][y-1] = 2;
      }
      if(x-1 > MINX){
	carteT[x-1][y-1] = 2;
      }
    }
    return 1;
  }
  else {
    return 0;
  }
}
