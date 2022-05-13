#ifdef _APPLE_
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

GLint b=300;
float  counter=600.0;
void initOpenGl()
{
    glClearColor(0.5,0.5,1,1); //Background Color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,700,0,500);
    glMatrixMode(GL_MODELVIEW);

}

void wheel(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(0,0,0);
   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+30*cos(th),y+30*sin(th));
   }

   glEnd();

}
void circle(int x,int y)
{
   float th;
   glBegin(GL_POLYGON);
   glColor3f(1,0,0);
   for(int i=0;i<360;i++)
   {
       th=i*(3.1416/180);
       glVertex2f(x+10*cos(th),y+10*sin(th));
   }

   glEnd();

}
void road()
{
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
   glVertex2f(0,20);
   glVertex2f(700,20);
   glVertex2f(700,0);
   glVertex2f(0,0);
    glEnd();
}
void car()
{
   glLoadIdentity();
   counter=counter-0.03;
   glTranslated(counter,100,0.0);
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
   glVertex2f(0,50);
   glVertex2f(0,70);
   glVertex2f(0,85);
   glVertex2f(30,100);
   glVertex2f(100,100);
   glVertex2f(150,150);
   glVertex2f(300,150);
   glVertex2f(350,110);
   glVertex2f(400,110);
   glVertex2f(400,50);
   glEnd();
    //stick
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
   glVertex2f(390,110);
   glVertex2f(390,200);
   glVertex2f(400,200);
   glVertex2f(400,110);
    glEnd();
    //green
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
   glVertex2f(400,200);
   glVertex2f(470,200);
   glVertex2f(470,150);
   glVertex2f(400,150);

    glEnd();


   wheel(150,50);
   wheel(300,50);

   circle(435.5,175);

}

void display()
{

  glClear(GL_COLOR_BUFFER_BIT);
  //Push and pop matrix for separating circle object from Background
 // glColor3f(0.0,1.0,0.0);

  car();
  glutSwapBuffers();
  glFlush();


}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(700,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Car Moving");
    initOpenGl();
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
