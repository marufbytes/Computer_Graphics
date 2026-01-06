#include<gl/GlUT.h>

void init()
{
    glClearColor(1,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(100,0,100,0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(32,52);
    glVertex2f(22,94);
    glVertex2f(25,34);
    glVertex2f(34,65);
    glVertex2f(85,25);

    glEnd();
    glFlush();

}


int main(int a, char **b)
{
    glutInit(&a, b);
    glutInitWindowSize(200,200);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("Polygon");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;

}
