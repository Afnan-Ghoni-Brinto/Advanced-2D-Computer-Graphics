#include <GL/glut.h>
void plot4(int cx,int cy,int x,int y){
 glBegin(GL_POINTS); glVertex2i(cx+x,cy+y); glVertex2i(cx-x,cy+y);
 glVertex2i(cx+x,cy-y); glVertex2i(cx-x,cy-y); glEnd();
}
void ellipse(int cx,int cy,int rx,int ry){
 long long rx2=1LL*rx*rx, ry2=1LL*ry*ry, x=0,y=ry;
 long long dx=0,dy=2*rx2*y;
 double p=ry2-rx2*ry+0.25*rx2;
 while(dx<dy){ plot4(cx,cy,x,y); x++; dx+=2*ry2;
  if(p<0) p+=ry2+dx; else {y--;dy-=2*rx2;p+=ry2+dx-dy;} }
 p=ry2*(x+0.5)*(x+0.5)+rx2*(y-1)*(y-1)-rx2*ry2;
 while(y>=0){ plot4(cx,cy,x,y); y--;dy-=2*rx2;
  if(p>0) p+=rx2-dy; else {x++;dx+=2*ry2;p+=rx2-dy+dx;} }
}
void display(){glClear(GL_COLOR_BUFFER_BIT);glColor3f(0,0,1);glPointSize(2);ellipse(250,250,150,85);glFlush();}
int main(int argc,char**argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(500,500);glutCreateWindow("Midpoint Ellipse");glClearColor(1,1,1,1);gluOrtho2D(0,500,0,500);glutDisplayFunc(display);glutMainLoop();}
