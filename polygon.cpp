#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <vector>

struct Color
{
    int r;
    int g;
    int b;
};

void polygon(vector<pair<float, float>> coord, Color color = {0, 0, 0}, float Tx = 0, float Ty = 0, float s = 1)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < coord.size(); i++) {
        glVertex2f(Tx + s * coord[i].first, Ty + s * coord[i].second);
    }
    glEnd();
}



// Function call
// the coordinates should be sequenced in anticlockwise order, the first coordinate will be the last coordinate
polygon({{11,5},{16,5},{16,7},{15,8.5},{12,8.5},{11,7},{11,5}});

