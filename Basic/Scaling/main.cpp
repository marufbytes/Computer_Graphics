#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Original square (Red)
    glColor3f(1.0f, 0.0f, 0.0f);
    glLoadIdentity();
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();

    // Scaled square (Blue)
    glColor3f(0.0f, 0.0f, 1.0f);
    glLoadIdentity();
    glScalef(1.5f, 0.5f, 0.0f);   // Scaling factors
    glBegin(GL_QUADS);
        glVertex2f(-0.4f, -0.4f);
        glVertex2f( 0.4f, -0.4f);
        glVertex2f( 0.4f,  0.4f);
        glVertex2f(-0.4f,  0.4f);
    glEnd();

    glFlush();
}

// Initialization function
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_MODELVIEW);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Scaling Transformation Visualization");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
