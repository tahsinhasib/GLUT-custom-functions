#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
using namespace std;


void Circle(float radius, float Tx, float Ty, float red, float green, float blue)
{
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
}





void display() {
	glClearColor(1, 1, 1, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

    Circle(30, 300,300, 255, 0, 0);

	glFlush();  								// Render now
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
	glutMainLoop();
	return 0;
}
