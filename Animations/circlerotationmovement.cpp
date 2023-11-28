#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
using namespace std;


float _move  = 0;
float _angle = 0;


void wheel(float radius, float red, float green, float blue)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(_move, 0, 0);
    // here the code will reposition the circle
    glTranslatef(100, 200, 0);
    glRotatef(_angle, 0, 0, 1);

    glLineWidth(10);
    glBegin(GL_LINES);

    for(int i=0; i<200; i++)
    {
        glColor3ub(red, green, blue);
        float pi = 3.1416;
        float A = (i*2*pi)/200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}



void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);

    wheel(50, 0, 255, 0);
    glPopMatrix();
    glutSwapBuffers();
}



void _moveFunc(int val)
{
    _move += 4;

    if (_move > 700)
    {
        _move = -100;
    }
    glutPostRedisplay();
    glutTimerFunc(20, _moveFunc, 0);
}



void _rotateFunc(int val)
{
    _angle += 2.0f;

    if (_angle > 360.0)
    {
        _angle -= 360;
    }
    glutPostRedisplay();                //Notify GLUT that the display has changed
    glutTimerFunc(20, _rotateFunc, 0);      //Notify GLUT to call update again in 25 milliseconds
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(200, 50);
    glutCreateWindow("Window Name");


    gluOrtho2D(0, 700, 0, 600);
    glutDisplayFunc(Display);

    glutTimerFunc(20, _moveFunc, 0); //Add a timer
    glutTimerFunc(20, _rotateFunc, 0); //Add a timer

    glutMainLoop();
    return 0;
}
