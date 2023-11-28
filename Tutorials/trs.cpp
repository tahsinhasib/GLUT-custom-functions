#include <windows.h>            // for MS Windows
#include <GL/glut.h>            // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);       // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);               // Clear the color buffer (background)
	//glPointSize(5.0);
	// Draw a Red 1x1 Square centered at origin
	glLoadIdentity();                           //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    /*Transalation*/
    //glTranslatef(0.0f, 0.0f, 0.0f);
    /*Rotation*/
	//glRotatef(200,0.0f, 0.0f, 1.0f);
	/*Scaling*/
	glScalef(0.1f, -2.0f, 0.0f);
	glBegin(GL_POLYGON);                        // Each set of 4 vertices form a quad
	glColor3f(1.0f, 0.0f, 0.0f);                // Red
	glVertex2f(0.2f,0.0f);
	glVertex2f(0.5f,0.0f);
	glVertex2f(0.5f,0.2f);
	glVertex2f(0.2f,0.2f);                      // x, y

	glEnd();

	glFlush();
	glPopMatrix();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);                      // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test");      // Create a window with the given title
	glutInitWindowSize(320, 320);
	gluOrtho2D(-3,3,-3,3);                      // Set the window's initial width & height
	glutDisplayFunc(display);                   // Register display callback handler for window re-paint
	glutMainLoop();                             // Enter the event-processing loop
	return 0;
}
