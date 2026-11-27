#include <GL/glut.h>
#include <vector>
#include <algorithm>
using namespace std;
struct P{int x,y;};
vector<P> poly={{90,100},{390,120},{330,390},{210,430},{100,300}};
void display(){
 glClear(GL_COLOR_BUFFER_BIT); glColor3f(0,0,0);glBegin(GL_LINE_LOOP);
 for(P p:poly)glVertex2i(p.x,p.y);glEnd();
 glColor3f(0.2,0.65,0.3);glBegin(GL_LINES);
 for(int y=100;y<=430;y++){vector<double> xs;
  for(int i=0;i<(int)poly.size();i++){P a=poly[i],b=poly[(i+1)%poly.size()];
   if(a.y!=b.y && y>=min(a.y,b.y) && y<max(a.y,b.y))
    xs.push_back(a.x+(double)(y-a.y)*(b.x-a.x)/(b.y-a.y));}
  sort(xs.begin(),xs.end());for(int i=0;i+1<(int)xs.size();i+=2){glVertex2d(xs[i],y);glVertex2d(xs[i+1],y);}
 }glEnd();glFlush();
}
int main(int argc,char**argv){glutInit(&argc,argv);glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);glutInitWindowSize(500,500);glutCreateWindow("Scanline Fill");glClearColor(1,1,1,1);gluOrtho2D(0,500,0,500);glutDisplayFunc(display);glutMainLoop();}
