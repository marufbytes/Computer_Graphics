#include <windows.h>
#include <GL/glut.h>
#include <cmath>

// Initialize OpenGL
void initGL()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);   // Sky blue
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // ---------------- GROUND ----------------
    glColor3f(0.2f, 0.7f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0);
    glVertex2f(100, 0);
    glVertex2f(100, 25);
    glVertex2f(0, 25);
    glEnd();

    // ---------------- ROAD ----------------
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(0, 10);
    glVertex2f(100, 10);
    glVertex2f(100, 15);
    glVertex2f(0, 15);
    glEnd();

    // ---------------- SUN ----------------
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416f / 180;
        glVertex2f(85 + cos(angle) * 6, 85 + sin(angle) * 6);
    }
    glEnd();

    // ---------------- MOUNTAINS ----------------
    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_TRIANGLES);
    glVertex2f(10, 25);
    glVertex2f(30, 70);
    glVertex2f(50, 25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(40, 25);
    glVertex2f(65, 75);
    glVertex2f(90, 25);
    glEnd();

    // ================= HOUSES =================

    // ---------- HOUSE 1 ----------
    glColor3f(0.9f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(15, 25);
    glVertex2f(25, 25);
    glVertex2f(25, 33);
    glVertex2f(15, 33);
    glEnd();

    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(14, 33);
    glVertex2f(26, 33);
    glVertex2f(20, 39);
    glEnd();

    // Door
    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(19, 25);
    glVertex2f(21, 25);
    glVertex2f(21, 31);
    glVertex2f(19, 31);
    glEnd();

    // Windows
    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(16, 28);
    glVertex2f(18, 28);
    glVertex2f(18, 30);
    glVertex2f(16, 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(22, 28);
    glVertex2f(24, 28);
    glVertex2f(24, 30);
    glVertex2f(22, 30);
    glEnd();

    // ---------- HOUSE 2 ----------
    glColor3f(0.9f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(30, 25);
    glVertex2f(40, 25);
    glVertex2f(40, 33);
    glVertex2f(30, 33);
    glEnd();

    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(29, 33);
    glVertex2f(41, 33);
    glVertex2f(35, 39);
    glEnd();

    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(34, 25);
    glVertex2f(36, 25);
    glVertex2f(36, 31);
    glVertex2f(34, 31);
    glEnd();

    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(31, 28);
    glVertex2f(33, 28);
    glVertex2f(33, 30);
    glVertex2f(31, 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(37, 28);
    glVertex2f(39, 28);
    glVertex2f(39, 30);
    glVertex2f(37, 30);
    glEnd();

    // ---------- HOUSE 3 ----------
    glColor3f(0.9f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(45, 25);
    glVertex2f(55, 25);
    glVertex2f(55, 33);
    glVertex2f(45, 33);
    glEnd();

    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(44, 33);
    glVertex2f(56, 33);
    glVertex2f(50, 39);
    glEnd();

    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(49, 25);
    glVertex2f(51, 25);
    glVertex2f(51, 31);
    glVertex2f(49, 31);
    glEnd();

    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(46, 28);
    glVertex2f(48, 28);
    glVertex2f(48, 30);
    glVertex2f(46, 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(52, 28);
    glVertex2f(54, 28);
    glVertex2f(54, 30);
    glVertex2f(52, 30);
    glEnd();

    // ---------- HOUSE 4 ----------
    glColor3f(0.9f, 0.6f, 0.4f);
    glBegin(GL_QUADS);
    glVertex2f(60, 25);
    glVertex2f(70, 25);
    glVertex2f(70, 33);
    glVertex2f(60, 33);
    glEnd();

    glColor3f(0.6f, 0.2f, 0.2f);
    glBegin(GL_TRIANGLES);
    glVertex2f(59, 33);
    glVertex2f(71, 33);
    glVertex2f(65, 39);
    glEnd();

    glColor3f(0.4f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(64, 25);
    glVertex2f(66, 25);
    glVertex2f(66, 31);
    glVertex2f(64, 31);
    glEnd();

    glColor3f(0.7f, 0.9f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(61, 28);
    glVertex2f(63, 28);
    glVertex2f(63, 30);
    glVertex2f(61, 30);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(67, 28);
    glVertex2f(69, 28);
    glVertex2f(69, 30);
    glVertex2f(67, 30);
    glEnd();

    glFlush();
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Simple Village Scene");

    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
