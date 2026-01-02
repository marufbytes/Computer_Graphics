// Village Scenery using OpenGL + GLUT (C++)
// Features: sky, sun, clouds (animated), hills, river, road, houses, trees
// Build (Linux): g++ village.cpp -lGL -lGLU -lglut -o village
// Run: ./village

#include <GL/glut.h>
#include <cmath>

// Window
int W = 900, H = 600;

// Cloud animation offset
float cloudX = 0.0f;

// Helpers
void drawCircle(float cx, float cy, float r, int segments = 80) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float a = 2.0f * 3.1415926f * i / segments;
        glVertex2f(cx + r * cosf(a), cy + r * sinf(a));
    }
    glEnd();
}

void drawRect(float x1, float y1, float x2, float y2) {
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Scene objects
void cloud(float x, float y, float scale = 1.0f) {
    glColor3f(1, 1, 1);
    drawCircle(x, y, 18 * scale);
    drawCircle(x + 20 * scale, y + 10 * scale, 22 * scale);
    drawCircle(x + 45 * scale, y, 18 * scale);
    drawRect(x - 5 * scale, y - 15 * scale, x + 60 * scale, y + 5 * scale);
}

void tree(float x, float y, float s = 1.0f) {
    // trunk
    glColor3f(0.45f, 0.25f, 0.10f);
    drawRect(x - 6*s, y, x + 6*s, y + 40*s);

    // leaves
    glColor3f(0.1f, 0.6f, 0.2f);
    drawCircle(x, y + 50*s, 22*s);
    drawCircle(x - 16*s, y + 42*s, 18*s);
    drawCircle(x + 16*s, y + 42*s, 18*s);
}

void house(float x, float y, float s = 1.0f) {
    // base
    glColor3f(0.92f, 0.75f, 0.55f);
    drawRect(x, y, x + 120*s, y + 80*s);

    // roof
    glColor3f(0.70f, 0.15f, 0.15f);
    drawTriangle(x - 10*s, y + 80*s, x + 60*s, y + 130*s, x + 130*s, y + 80*s);

    // door
    glColor3f(0.35f, 0.2f, 0.05f);
    drawRect(x + 52*s, y, x + 75*s, y + 45*s);

    // window
    glColor3f(0.75f, 0.9f, 1.0f);
    drawRect(x + 15*s, y + 30*s, x + 40*s, y + 55*s);
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_LINES);
    glVertex2f(x + 27.5f*s, y + 30*s); glVertex2f(x + 27.5f*s, y + 55*s);
    glVertex2f(x + 15*s, y + 42.5f*s); glVertex2f(x + 40*s, y + 42.5f*s);
    glEnd();
}

void river() {
    glColor3f(0.2f, 0.55f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 120);
    glVertex2f(260, 140);
    glVertex2f(520, 115);
    glVertex2f(900, 135);
    glVertex2f(900, 0);
    glVertex2f(0, 0);
    glEnd();

    // river highlight waves
    glColor3f(0.75f, 0.9f, 1.0f);
    for (int i = 0; i < 10; i++) {
        float x = 60 + i * 80;
        glBegin(GL_LINE_STRIP);
        for (int j = 0; j <= 40; j++) {
            float t = j / 40.0f;
            glVertex2f(x + t * 60.0f, 55 + 10.0f * sinf(t * 2.0f * 3.1415926f));
        }
        glEnd();
    }
}

void road() {
    // road body
    glColor3f(0.18f, 0.18f, 0.18f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 190);
    glVertex2f(900, 240);
    glVertex2f(900, 170);
    glVertex2f(0, 120);
    glEnd();

    // center dashed line
    glColor3f(1, 1, 0.2f);
    for (int i = 0; i < 18; i++) {
        float x1 = 20 + i * 50;
        drawRect(x1, 175, x1 + 25, 180);
    }
}

void hills() {
    glColor3f(0.2f, 0.7f, 0.3f);
    drawCircle(150, 300, 140);
    drawCircle(340, 300, 160);
    drawCircle(560, 310, 190);
    drawCircle(780, 300, 160);
}

void ground() {
    glColor3f(0.2f, 0.75f, 0.25f);
    drawRect(0, 120, 900, 320);
}

void sky() {
    glColor3f(0.55f, 0.85f, 1.0f);
    drawRect(0, 320, 900, 600);
}

void sun() {
    glColor3f(1.0f, 0.9f, 0.1f);
    drawCircle(760, 520, 40);

    // rays
    glColor3f(1.0f, 0.85f, 0.05f);
    glBegin(GL_LINES);
    for (int i = 0; i < 12; i++) {
        float a = i * (2.0f * 3.1415926f / 12.0f);
        float x1 = 760 + cosf(a) * 50;
        float y1 = 520 + sinf(a) * 50;
        float x2 = 760 + cosf(a) * 70;
        float y2 = 520 + sinf(a) * 70;
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    sun();

    // clouds (animated)
    cloud(80 + cloudX, 540, 1.0f);
    cloud(300 + cloudX * 0.7f, 500, 1.2f);
    cloud(560 + cloudX * 0.5f, 545, 0.9f);

    hills();
    ground();
    road();
    river();

    // houses
    house(120, 235, 1.0f);
    house(420, 240, 0.9f);

    // trees
    tree(80, 220, 1.1f);
    tree(280, 210, 1.0f);
    tree(610, 215, 1.2f);
    tree(820, 205, 1.0f);

    // small bushes
    glColor3f(0.05f, 0.55f, 0.15f);
    drawCircle(350, 210, 18);
    drawCircle(370, 210, 16);
    drawCircle(360, 225, 16);

    glFlush();
    glutSwapBuffers();
}

void timer(int) {
    // move clouds to the right; wrap around
    cloudX += 0.8f;
    if (cloudX > 900) cloudX = -400;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

void reshape(int w, int h) {
    W = w; H = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900, 0, 600); // fixed world coords
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(W, H);
    glutCreateWindow("Village Scenery - GLUT");

    glClearColor(1, 1, 1, 1);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}

