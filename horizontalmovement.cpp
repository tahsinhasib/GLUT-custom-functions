#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
using namespace std;

float _move = 0;
void Circle(float radius, float Tx, float Ty, float red, float green, float blue)
{
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    glTranslatef(_move, 0, 0);

    glBegin(GL_POLYGON);
    for(int i=0; i<250; i++){
        glColor3ub(red, green, blue);
        float pi = 3.1416;
        float A = (i*2*pi)/250;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x+Tx, y+Ty);
    }

    glEnd();
    glPopMatrix();
}


void _movefunc(int val)
{
    _move += 4;
    if (_move > 700)
    {
        _move = -100;
    }
    glutPostRedisplay();
    glutTimerFunc(20, _movefunc, 0);
}


void display() {
	glClearColor(1, 1, 1, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

    Circle(30, 100,300, 255, 0, 0);

	glFlush();  // Render now
    glutSwapBuffers();
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(700, 600);

	//glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1100)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("Window Name");

    //this line must be below of glutCreateWindow();
    gluOrtho2D(0, 700, 0, 600);
	glutDisplayFunc(display);
	glutTimerFunc(20, _movefunc, 0);
	glutMainLoop();
	return 0;
}
