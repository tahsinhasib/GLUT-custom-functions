#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>
using namespace std;


struct Color
{
    int r;
    int g;
    int b;
};


struct Scence
{
    Color new_color;
};


void _quad(vector<pair<float, float>> coord, Color color = {0, 0, 0}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_QUADS);
    for (int i = 0; i < coord.size(); i++) {
        glVertex2f(Tx + s * coord[i].first, Ty + s * coord[i].second);
    }
    glEnd();
}


void display() {
	glClearColor(1, 1, 1, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	_quad({{2,0},{4,0},{4,4},{2,4}});


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
