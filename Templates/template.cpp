#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
using namespace std;



void display() {
	glClearColor(1, 1, 1, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);


	glFlush();  								// Render now
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(700, 600);

	//glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-1100)/2,(glutGet(GLUT_SCREEN_HEIGHT)-600)/2);
	glutInitWindowPosition(200, 50);
	glutCreateWindow("Window Name");
    
    //this line must be below of glutCreateWindow();
    gluOrtho2D(0, 32, -2, 27);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
