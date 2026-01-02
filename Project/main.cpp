#include <windows.h>
#include <GL/glut.h>
#include <cmath>

void initGL()
{
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
}

// Function to draw a circle using polygon
void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.1416f / 180;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // -------- GROUND --------
    glColor3f(0.2f, 0.7f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2f(0, 0); glVertex2f(100, 0);
    glVertex2f(100, 25); glVertex2f(0, 25);
    glEnd();

    // -------- ROAD --------
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(0, 10); glVertex2f(100, 10);
    glVertex2f(100, 15); glVertex2f(0, 15);
    glEnd();

    // Road divider
    glColor3f(1, 1, 1);
    for (int i = 0; i < 100; i += 10)
    {
        glBegin(GL_QUADS);
        glVertex2f(i + 2, 12);
        glVertex2f(i + 6, 12);
        glVertex2f(i + 6, 13);
        glVertex2f(i + 2, 13);
        glEnd();
    }

    // -------- RIVER --------
    glColor3f(0.2f, 0.5f, 1.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 5);
    glVertex2f(100, 3);
    glVertex2f(100, 7);
    glVertex2f(0, 9);
    glEnd();

    // -------- SUN --------
    glColor3f(1, 1, 0);
    drawCircle(85, 85, 6);

    // -------- CLOUDS --------
    glColor3f(1, 1, 1);
    drawCircle(20, 85, 3);
    drawCircle(24, 85, 4);
    drawCircle(28, 85, 3);

    drawCircle(60, 80, 3);
    drawCircle(64, 80, 4);
    drawCircle(68, 80, 3);

    // -------- MOUNTAINS --------
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_TRIANGLES);
    glVertex2f(10, 25); glVertex2f(30, 70); glVertex2f(50, 25);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex2f(40, 25); glVertex2f(65, 75); glVertex2f(90, 25);
    glEnd();

    // -------- TREES --------
    for (int x = 5; x <= 90; x += 15)
    {
        glColor3f(0.5f, 0.3f, 0.1f);
        glBegin(GL_QUADS);
        glVertex2f(x, 25);
        glVertex2f(x + 2, 25);
        glVertex2f(x + 2, 35);
        glVertex2f(x, 35);
        glEnd();

        glColor3f(0.0f, 0.6f, 0.0f);
        drawCircle(x + 1, 38, 4);
    }

    // -------- HOUSES --------
    float houseX[] = {15, 30, 45, 60};

    for (int i = 0; i < 4; i++)
    {
        float x = houseX[i];

        // House body
        glColor3f(0.9f, 0.6f, 0.4f);
        glBegin(GL_QUADS);
        glVertex2f(x, 25);
        glVertex2f(x + 10, 25);
        glVertex2f(x + 10, 33);
        glVertex2f(x, 33);
        glEnd();

        // Roof
        glColor3f(0.6f, 0.2f, 0.2f);
        glBegin(GL_TRIANGLES);
        glVertex2f(x - 1, 33);
        glVertex2f(x + 11, 33);
        glVertex2f(x + 5, 39);
        glEnd();

        // Door
        glColor3f(0.4f, 0.2f, 0.1f);
        glBegin(GL_QUADS);
        glVertex2f(x + 4, 25);
        glVertex2f(x + 6, 25);
        glVertex2f(x + 6, 31);
        glVertex2f(x + 4, 31);
        glEnd();

        // Door knob
        glColor3f(1, 1, 0);
        drawCircle(x + 5.7f, 28, 0.3f);

        // Windows
        glColor3f(0.7f, 0.9f, 1.0f);
        glBegin(GL_QUADS);
        glVertex2f(x + 1, 28);
        glVertex2f(x + 3, 28);
        glVertex2f(x + 3, 30);
        glVertex2f(x + 1, 30);
        glEnd();

        glBegin(GL_QUADS);
        glVertex2f(x + 7, 28);
        glVertex2f(x + 9, 28);
        glVertex2f(x + 9, 30);
        glVertex2f(x + 7, 30);
        glEnd();

        // Window grills
        glColor3f(0, 0, 0);
        glBegin(GL_LINES);
        glVertex2f(x + 2, 28); glVertex2f(x + 2, 30);
        glVertex2f(x + 8, 28); glVertex2f(x + 8, 30);
        glEnd();
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Village Scenery - Simple OpenGL");

    initGL();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
