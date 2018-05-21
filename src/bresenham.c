#include "../inc/bresenham.h"

void trace_segment_bresenInt(int x1, int y1, int x2, int y2){
  int deltaX = x2-x1;
  int deltaY = y2-y1;
  //on force des deltas positifs
  if(deltaX<0)
    deltaX = -deltaX;
  if(deltaY<0)
    deltaY = -deltaY;
  /****************************************************************************/
  //premier quadrant
  if(x1<=x2 && y1<=y2){
    trace_seg_bres1(x1, y1, x2, y2, deltaX, deltaY);
  }
  //second quadrant
  if(x1>x2 && y1<y2){
    trace_seg_bres2(x1, y1, x2, y2, deltaX, deltaY);
  }
  //troisieme quadrant
  if(x1>x2 && y1>y2){
    trace_seg_bres3(x1, y1, x2, y2, deltaX, deltaY);
  }
  //troisieme quadrant
  if(x1<x2 && y1>y2){
    trace_seg_bres4(x1, y1, x2, y2, deltaX, deltaY);
  }
  /******************************************************************************/

}

void trace_seg_bres1(int x1, int y1, int x2, int y2, int dx, int dy){
  int erreur,x,y;
  x = x1;
  y = y1;
  if(dx >= dy){
    erreur = -dx;
    for(x = x1; x <= x2; x++){
      trace_point2(x,y);
      erreur += 2*dy;
      if(erreur>=0){
	y++;
	erreur-=2*dx;
      }
    }
  }
  else{
    erreur = -dy;
    //second octant
    for(y = y1; y <= y2; y++){
      trace_point2(x,y);
      erreur += (2*dx);
      if(erreur>=0){
	x++;
	erreur-=2*dy;
      }
    }
  }
}

void trace_seg_bres2(int x1, int y1, int x2, int y2, int dx, int dy){
  int erreur,x,y;
  x = x1;
  y = y1;
  if(dx >= dy){
    erreur = -dx;
    for(x = x1; x >= x2; x--){
      trace_point2(x,y);
      erreur += 2*dy;
      if(erreur>=0){
	y++;
	erreur-=2*dx;
      }
    }
  }
  else{
    erreur = -dy;
    for(y = y1; y <= y2; y++){
      trace_point2(x,y);
      erreur += 2*dx;
      if(erreur>=0){
	x--;
	erreur-=2*dy;
      }
    }
      
  }
}

void trace_seg_bres3(int x1, int y1, int x2, int y2, int dx, int dy){
  int erreur,x,y;
  x = x1;
  y = y1;
  if(dx >= dy){
    erreur = -dx;
    for(x = x1; x >= x2; x--){
      trace_point2(x,y);
      erreur += 2*dy;
      if(erreur>=0){
	y--;
	erreur-=2*dx;
      }
    }
  }
  else{
    erreur = -dy;
    for(y = y1; y >= y2; y--){
      trace_point2(x,y);
      erreur += 2*dx;
      if(erreur>=0){
	x--;
	erreur-=2*dy;
      }
    }
      
  }
}

void trace_seg_bres4(int x1, int y1, int x2, int y2, int dx, int dy){
  int erreur,x,y;
  x = x1;
  y = y1;
  if(dx >= dy){
    erreur = -dx;
    for(x = x1; x <= x2; x++){
      trace_point2(x,y);
      erreur += 2*dy;
      if(erreur>=0){
	y--;
	erreur-=2*dx;
      }
    }
  }
  else{
    erreur = -dy;
    for(y = y1; y >= y2; y--){
      trace_point2(x,y);
      erreur += 2*dx;
      if(erreur>=0){
	x++;
	erreur-=2*dy;
      }
    }
      
  }
}
