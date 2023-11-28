#include <windows.h>  
#include <GL/glut.h> 
void rectangle()
{
    glBegin(GL_POLYGON);           
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f(0.2f,0.0f);
    glVertex2f(0.5f,0.0f);
    glVertex2f(0.5f,0.2f);
    glVertex2f(0.2f,0.2f);  
    glEnd();
}
void triangle()
{
    glBegin(GL_POLYGON);              
    glColor3f(1.0f, 0.0f, 0.0f); 
    glVertex2f(0.2f,0.0f);
    glVertex2f(0.5f,0.0f);
    glVertex2f(0.5f,0.2f);
    //glVertex2f(0.2f,0.2f); 
    glEnd();
}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT);        


    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(0.5f, 0.0f, 0.0f);

    rectangle();
    glTranslatef(-1.5f, -1.0f, 0.0f);
    triangle();
    glFlush();
    glPopMatrix();  // Render now
}




int main(int argc, char** argv) {
    glutInit(&argc, argv);             
    glutCreateWindow("OpenGL Setup Test"); 
    glutInitWindowSize(320, 320);
    gluOrtho2D(-3,3,-3,3); 
    glutDisplayFunc(display);
    glutMainLoop();         
    return 0;
}
