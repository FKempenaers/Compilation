#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include "SDL/SDL.h"
#include <math.h>
#include "../inc/fonctions.h"
#include "../inc/minimap.h"

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
  printf("test0\n");
  if(genCarteOK != 1){
   
    if(genCarteOK == 2){
      tmp = nieme(liste_map,idmap+1);
      if(tmp.nelem == -1){
	printf("ici\n");
	tmp.nelem = 15;
	tmp.carte = carte;
	tmp.carteT = carteT;
	liste_map = empile(tmp,liste_map);
	gencarte(15);
	idmap++;
      }
      else{
	printf("ici2\n");
	tmp = nieme(liste_map, idmap+1);
	carte = tmp.carte;
	carteT = tmp.carteT;
	idmap++;
      }
    }
    if(genCarteOK == 3){
       printf("ici3\n");
      tmp = nieme(liste_map, idmap-1);
      carte = tmp.carte;
      carteT = tmp.carteT;
      idmap--;
    }
    printf("ici4\n");
    genCarteOK = 1;
  }
   printf("test1\n");
  affiche_carte(carte,15);
  affiche_snake(xs,ys,zs);
  affiche_ia(ia);
<<<<<<< HEAD
printf("test2\n");
=======
  /*
  for (i = 0; i < NB_IAS; i++) {
      affiche_ia(ias[i]);
  }
  */
>>>>>>> refs/remotes/origin/dev

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

<<<<<<< HEAD

=======
>>>>>>> refs/remotes/origin/dev
void affiche_snake(double x, double y, double z){
  int i,j;
  GLUquadric* lol;
  lol = gluNewQuadric();
 

  glColor3ub(255,0,0);
  glPushMatrix();
  glTranslated(snake[0][0],snake[0][1],snake[0][2]);
  gluSphere(lol, RAYON, 10,10);

  for(i = 1; i <TAILLE_MAX;i++){
    glPopMatrix();
    glPushMatrix();
    glColor3ub(128,(i*20)%255,128);
    glTranslated(snake[i][0],snake[i][1],snake[i][2]);
    gluSphere(lol,RAYON, 10,10);
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
  k = angle = compteur = 0;
  increment = 0.25;
  vitesse = 0.10;
  direction = 0;
  xs = MINX+RAYON*2+5;
  ys = MINY+5;
  zs = RAYON;

  snake[0][0] = xs;
  snake[0][1] = ys;
  snake[0][2] = zs;

  for(int i = 1; i <TAILLE_MAX;i++){
    snake[i][0] = snake[i-1][0]-RAYON*2;
    snake[i][1] = 0;
    snake[i][2] = RAYON;
  }
}


void anime_snake(){
  int i,oldX,oldY;
  double oldAngle;
 
  oldX = xs;
  oldY = ys;
  while(angle > 2*PI)
    angle -= 2*PI;

  oldAngle = angle;
  xs += RAYON*2*sin(angle);
  ys += RAYON*2*cos(angle);

  i=1;
  while(carteT[xs][ys]==1){
    angle = oldAngle;
    xs = oldX;
    ys = oldY;
    if(i%2==0)
      angle += i*(PI/4);
    else
      angle -= i*(PI/4);
    
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
  if( (snake[0][0] > MINX+15)&&(snake[0][0]<MINX+40)&&(snake[0][1] > MINY+1)&&(snake[0][1]<MINY+13) ){
    zs = RAYON*2+((double)10/25)*(snake[0][0]-(MINX+15));

    if(zs == 5){
      genCarteOK = 2;
      xs = MAXX - 27;
      ys = MAXY - 6;
      zs = 4*RAYON;
      for(int i = 1; i <TAILLE_MAX;i++){
	snake[i][0] = snake[i-1][0]+RAYON*2;
	snake[i][1] = snake[0][1];
	snake[i][2] = snake[i-1][2]+RAYON;
      }    	 
    }  
  }else if( (snake[0][0]>MAXX-40)&&(snake[0][0]<MAXX-15)&&(snake[0][1]>MAXY-10)&&(snake[0][1]<MAXY) ){
    zs = RAYON*2+((double)-10/25)*(snake[0][0]-(MAXX-40));
    if(zs == 5){
      genCarteOK = 3;
      xs = MINX + 27;
      ys = MINY + 6;
      zs = 4*RAYON;
      for(int i = 1; i <TAILLE_MAX;i++){
	snake[i][0] = snake[i-1][0]+RAYON*2;
	snake[i][1] = snake[0][1];
	snake[i][2] = snake[i-1][2]+RAYON;
      }    	 
    }
  }else{
    zs = RAYON;
  }
}

void affiche_ia(point* ia){
  int i,j;
  GLUquadric* lol;
  lol = gluNewQuadric();
 

  glColor3ub(255,0,0);
  glPushMatrix();
  glTranslated(ia[0].x,ia[0].y,ia[0].z);
  gluSphere(lol, RAYON, 10,10);

  for(i = 1; i <TAILLE_MAX;i++){
    glPopMatrix();
    glPushMatrix();
    glColor3ub(128,(i*20)%255,128);
    glTranslated(ia[i].x,ia[i].y,ia[i].z);
    gluSphere(lol,RAYON, 10,10);
  }

  glPopMatrix();
}
