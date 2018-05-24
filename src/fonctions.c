#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "SDL/SDL.h"
#include <math.h>
#include "../inc/fonctions.h"
#include "../inc/minimap.h"
#include "../inc/menu.h"

void affichage(){
  int i,j;
  map tmp;
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE  );

  glLightx(GL_LIGHT0,GL_POSITION,1,1,0);
  glLightx(GL_LIGHT0,GL_AMBIENT,0,0,0,1);
  glLightx(GL_LIGHT0,GL_DIFFUSE,1,1,1,1);
  glLightx(GL_LIGHT0,GL_SPECULAR,1,1,1,1);

  GLint white[] = {1,1,1,1};
  glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,white);
  GLint color[] = {0,0,0,1};
  glMaterialiv(GL_FRONT_AND_BACK,GL_EMISSION,color);
  
  int LightPos[4] = {0,0,3,1};
  glLightiv(GL_LIGHT0,GL_POSITION,LightPos);


  
 
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(100,(double)TAILLE_X/TAILLE_Y,0.1,100);
  //gluLookAt(MAXX/2,-20,40,MAXX/2,0,0,0,0,1);
  gluLookAt(xs,ys-5,20,xs,ys,0,0,0,1);
  //glRotatef(angle,0,0,1);
  //trace_grille();

  /*****************************/
  if(genCarteOK != 1){
   
    if(genCarteOK == 2){
      tmp = nieme(liste_map,idmap+1);
      if(tmp.nelem == -1){
	if(idmap == nbetage-1){
	  cartefin();
	}
	else{
	  tmp.nelem = 15;
	  tmp.carte = carte;
	  tmp.carteT = carteT;
	  liste_map = empile(tmp,liste_map);
	  carte = NULL;
	  carteT = NULL;
	  gencarte(15);
	  idmap++;
	}
      }
      else{
	tmp = nieme(liste_map, idmap+1);
	carte = tmp.carte;
	carteT = tmp.carteT;
	idmap++;
      }
    }
    if(genCarteOK == 3){
      tmp.nelem = 15;
      tmp.carte = carte;
      tmp.carteT = carteT;
      liste_map = empile(tmp,liste_map);
      tmp = nieme(liste_map, idmap-1);
      carte = tmp.carte;
      carteT = tmp.carteT;
      idmap--;
    }
    genCarteOK = 1;
  }
  affiche_carte(carte,15);
  affiche_snake(xs,ys,zs);
  
  for (i = 0; i < NB_IAS; i++) {
      affiche_ia(ias[i]);
  }
  

  /*******************************************************************************/
  /*Partie 2D*/
  
  // glDisable(GL_DEPTH_TEST);
  //glDepthMask(GL_FALSE);
  glDisable(GL_LIGHTING);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, TAILLE_X, 0, TAILLE_Y);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  affiche_minimap();
  
  glFlush();
  SDL_GL_SwapBuffers();
}

void affiche_snake(double x, double y, double z){
  int i,j;
  GLUquadric* q;
  q = gluNewQuadric();
 

  glColor3ub(0,255,0);
  glPushMatrix();
  glTranslated(snake[0][0],snake[0][1],snake[0][2]);
  gluSphere(q, RAYON, 10,10);

  for(i = 1; i <TAILLE_MAX;i++){
    glPopMatrix();
    glPushMatrix();
    glColor3ub(128,192,(i*10)%255);
    glTranslated(snake[i][0],snake[i][1],snake[i][2]);
    gluSphere(q,RAYON, 10,10);
  }

  glPopMatrix();
}

void maison(double x, double y, double z, double c){
  glColor3ub(0,0,255);
  glBegin(GL_QUAD_STRIP);

  glVertex3d(x,y,z);
  glVertex3d(x,y,z+c);
  glVertex3d(x,y+c,z);
  glVertex3d(x,y+c,z+c);

  glVertex3d(x+c,y+c,z);
  glVertex3d(x+c,y+c,z+c);
  glVertex3d(x+c,y,z);
  glVertex3d(x+c,y,z+c);

  glVertex3d(x,y,z);
  glVertex3d(x,y,z+c);

  glEnd();

  glColor3ub(255,0,0);
  glBegin(GL_TRIANGLE_STRIP);

  glVertex3d(x,y,z+c);
  glColor3ub(0,0,255);
  glVertex3d(x,y+c,z+c);
  glColor3ub(0,255,0);
  glVertex3d(x+c/2,y+c/2,z+3*c/2);

  glVertex3d(x+c,y+c,z+c);
  glVertex3d(x+c,y,z+c);
  glVertex3d(x+c/2,y+c/2,z+3*c/2);
  glVertex3d(x,y,z+c);
  glVertex3d(x,y+c,z+c);
  
  glEnd();
}

void init_snake(){
  angle = -PI/2;
  xs = MAXX-RAYON*2*TAILLE_MAX;
  ys = MAXY-RAYON*2*2;
  zs = RAYON;

  snake[0][0] = xs;
  snake[0][1] = ys;
  snake[0][2] = zs;

  for(int i = 1; i <TAILLE_MAX;i++){
    snake[i][0] = snake[i-1][0]+RAYON*2;
    snake[i][1] = 0;
    snake[i][2] = RAYON;
  }
}


void anime_snake(){
  int i;
  double oldAngle,oldX,oldY;
 
  oldX = xs;
  oldY = ys;
  while(angle > 2*PI)
    angle -= 2*PI;
  while(angle < 0)
    angle += 2*PI;


  oldAngle = angle;
  xs += RAYON*2*sin(angle);
  ys += RAYON*2*cos(angle);

  i=1;
  while(carteT[(int)(xs+.5)][(int)(ys+.5)]==1){
    angle = oldAngle;
    xs = oldX;
    ys = oldY;
    if(i%2==0)
      angle += i*(PI/8);
    else
      angle -= i*(PI/8);
    
    xs += RAYON*2*sin(angle);
    ys += RAYON*2*cos(angle);
    i++;
  }
  for(i=TAILLE_MAX-1; i>0; i--){
    snake[i][0] = snake[i-1][0];
    snake[i][1] = snake[i-1][1];
    snake[i][2] = snake[i-1][2];
  }
  
  snake[0][0] = xs;
  snake[0][1] = ys;
  snake[0][2] = zs;


  /***Si on est sur une pente**/
  /*
    affiche_pente(MINX + 15, MINY+1 , 1,MINX+40,MINY+13,10);
    affiche_pente(MAXX - 15, MAXY, -10,MAXX-40,MAXY-10,1);
  */
  /*On utilise genCarteOK pour signaler le chargement du nouvel etage*/
  /*On teleporte le snake sur l'autre rampe*/
  if( (snake[0][0] > MINX+15)&&(snake[0][0]<MINX+40)&&(snake[0][1] > MINY+1)&&(snake[0][1]<MINY+13) ){
    zs = RAYON*2+((double)10/25)*(snake[0][0]-(MINX+15));

    if(zs > 8){
      genCarteOK = 2;
      xs = MAXX-40+snake[0][0]-(MINX+15)-RAYON*2;
      ys = MAXY-2*RAYON*2;
      zs = RAYON*2+((double)-10/25)*(xs-(MAXX-40));
      angle = -PI/2;
      
      snake[0][0] = xs;
      snake[0][1] = ys;
      snake[0][2] = zs;
      for(int i = 1; i <TAILLE_MAX;i++){
	snake[i][0] = snake[i-1][0]+RAYON*2;
	snake[i][1] = snake[0][1];
	snake[i][2] = RAYON*2+((double)-10/25)*(snake[i][0]-(MAXX-40));
      }    	 
    }  
  }else if( (snake[0][0]>MAXX-40)&&(snake[0][0]<MAXX-15)&&(snake[0][1]>MAXY-10)&&(snake[0][1]<MAXY)&&(idmap>0)){
    zs = RAYON*2+((double)-10/25)*(snake[0][0]-(MAXX-40));
    
    if(zs < -6){
      genCarteOK = 3;
      xs = MINX+15+snake[0][0]-(MAXX-40)-RAYON*2*3;
      ys = MINY+13-2*RAYON*2;
      zs = RAYON*2+((double)10/25)*(xs-(MINX+15));
      angle = -PI/2;
      
      snake[0][0] = xs;
      snake[0][1] = ys;
      snake[0][2] = zs;
      for(int i = 1; i <TAILLE_MAX;i++){
	snake[i][0] = snake[i-1][0]+RAYON*2;
	snake[i][1] = snake[0][1];
	snake[i][2] = RAYON*2+((double)10/25)*(snake[i][0]-(MINX+15));
      }    	 
    }
  }else{
    zs = RAYON;
  }
}

void affiche_ia(point* ia){
  int i,j;
  GLUquadric* q;
  q = gluNewQuadric();
 

  glColor3ub(255,0,0);
  glPushMatrix();
  glTranslated(ia[0].x,ia[0].y,ia[0].z);
  gluSphere(q, RAYON, 10,10);

  for(i = 1; i <TAILLE_MAX;i++){
    glPopMatrix();
    glPushMatrix();
    glColor3ub(255,(i*25)%255,(i*10)%255);
    glTranslated(ia[i].x,ia[i].y,ia[i].z);
    gluSphere(q,RAYON, 10,10);
  }

  glPopMatrix();
}
