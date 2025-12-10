#include<GL/glut.h>
#include<math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<360;i++)
    {
        float angle = i * 3.1416/180;
        glVertex2f(0.5*cos(angle), 0.5*sin(angle));
    }
    glEnd();
    glFlush();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("None");

    glClearColor(1,1,1,1);
    gluOrtho2D(-1,1,-1,1);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
