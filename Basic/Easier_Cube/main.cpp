#include <GL/glut.h>

float angle = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, -5);     // Move cube back
    glRotatef(angle, 1, 1, 0);  // Rotate cube

    glBegin(GL_QUADS);

    // Front face (Red)
    glColor3f(1, 0, 0);
    glVertex3f(-1,-1, 1);
    glVertex3f( 1,-1, 1);
    glVertex3f( 1, 1, 1);
    glVertex3f(-1, 1, 1);

    // Back face (Green)
    glColor3f(0, 1, 0);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1, 1,-1);
    glVertex3f( 1, 1,-1);
    glVertex3f( 1,-1,-1);

    // Top face (Blue)
    glColor3f(0, 0, 1);
    glVertex3f(-1, 1,-1);
    glVertex3f(-1, 1, 1);
    glVertex3f( 1, 1, 1);
    glVertex3f( 1, 1,-1);

    // Bottom face (Yellow)
    glColor3f(1, 1, 0);
    glVertex3f(-1,-1,-1);
    glVertex3f( 1,-1,-1);
    glVertex3f( 1,-1, 1);
    glVertex3f(-1,-1, 1);

    // Right face (Cyan)
    glColor3f(0, 1, 1);
    glVertex3f( 1,-1,-1);
    glVertex3f( 1, 1,-1);
    glVertex3f( 1, 1, 1);
    glVertex3f( 1,-1, 1);

    // Left face (Magenta)
    glColor3f(1, 0, 1);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,-1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1,-1);

    glEnd();
    glutSwapBuffers();
}

void timer(int)
{
    angle += 1.0f;              // Increase rotation angle
    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, (float)w / h, 1, 100);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotating Cube - 6 Colors");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
