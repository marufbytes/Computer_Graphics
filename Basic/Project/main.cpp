#include <GL/glut.h>
#include <cmath>

int W = 900, H = 600;
float cloudX = -300;
bool isNight = false;

// ------------------------------------------------------------
// Basic Shapes
// ------------------------------------------------------------
void drawCircle(float cx, float cy, float r, int seg = 80) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= seg; i++) {
        float a = 2 * 3.1416f * i / seg;
        glVertex2f(cx + r * cos(a), cy + r * sin(a));
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

// ------------------------------------------------------------
// Gradient Rectangle
// ------------------------------------------------------------
void drawGradientRect(
    float x1, float y1, float x2, float y2,
    float r1, float g1, float b1,
    float r2, float g2, float b2
) {
    glBegin(GL_QUADS);
    glColor3f(r1, g1, b1); glVertex2f(x1, y1);
    glColor3f(r1, g1, b1); glVertex2f(x2, y1);
    glColor3f(r2, g2, b2); glVertex2f(x2, y2);
    glColor3f(r2, g2, b2); glVertex2f(x1, y2);
    glEnd();
}

// ------------------------------------------------------------
// Sky (Day / Night)
// ------------------------------------------------------------
void sky() {
    if (!isNight) {
        drawGradientRect(0, 320, 900, 600,
            0.7f, 0.9f, 1.0f,
            0.3f, 0.65f, 0.95f);
    } else {
        drawGradientRect(0, 320, 900, 600,
            0.05f, 0.05f, 0.2f,
            0.0f, 0.0f, 0.1f);
    }
}

// ------------------------------------------------------------
// Sun / Moon
// ------------------------------------------------------------
void sunMoon() {
    if (!isNight) {
        glColor3f(1.0f, 0.9f, 0.2f);
        drawCircle(780, 520, 40);
    } else {
        glColor3f(0.9f, 0.9f, 0.95f);
        drawCircle(780, 520, 35);
    }
}

// ------------------------------------------------------------
// Cloud
// ------------------------------------------------------------
void cloud(float x, float y) {
    glColor3f(1, 1, 1);
    drawCircle(x, y, 18);
    drawCircle(x + 20, y + 10, 22);
    drawCircle(x + 45, y, 18);
    drawRect(x - 5, y - 15, x + 60, y + 5);
}

// ------------------------------------------------------------
// Scene Objects
// ------------------------------------------------------------
void hills() {
    glColor3f(isNight ? 0.1f : 0.2f, isNight ? 0.3f : 0.6f, isNight ? 0.15f : 0.3f);
    drawCircle(150, 300, 140);
    drawCircle(350, 300, 160);
    drawCircle(580, 310, 190);
    drawCircle(800, 300, 160);
}

void ground() {
    if (!isNight)
        drawGradientRect(0, 120, 900, 320, 0.1f, 0.55f, 0.2f, 0.25f, 0.75f, 0.3f);
    else
        drawGradientRect(0, 120, 900, 320, 0.05f, 0.2f, 0.1f, 0.1f, 0.35f, 0.15f);
}

void river() {
    if (!isNight)
        drawGradientRect(0, 0, 900, 120, 0.1f, 0.35f, 0.65f, 0.35f, 0.7f, 0.95f);
    else
        drawGradientRect(0, 0, 900, 120, 0.02f, 0.05f, 0.2f, 0.1f, 0.2f, 0.35f);
}

void road() {
    glColor3f(0.15f, 0.15f, 0.15f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 190);
    glVertex2f(900, 240);
    glVertex2f(900, 170);
    glVertex2f(0, 120);
    glEnd();
}

void tree(float x, float y) {
    glColor3f(0.4f, 0.25f, 0.1f);
    drawRect(x - 6, y, x + 6, y + 40);
    glColor3f(isNight ? 0.05f : 0.1f, isNight ? 0.3f : 0.6f, isNight ? 0.1f : 0.2f);
    drawCircle(x, y + 55, 22);
}

// ------------------------------------------------------------
// Display
// ------------------------------------------------------------
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    sunMoon();

    cloud(80 + cloudX, 540);
    cloud(300 + cloudX * 0.7f, 500);
    cloud(550 + cloudX * 0.5f, 545);

    hills();
    ground();
    road();
    river();

    tree(100, 210);
    tree(300, 215);
    tree(600, 220);

    glutSwapBuffers();
}

// ------------------------------------------------------------
// Animation Logic
// ------------------------------------------------------------
void timer(int) {
    cloudX += 1.0f;
    if (cloudX > 1000) cloudX = -400;

    // 🌙 Night when cloud covers sun
    if (cloudX > 650 && cloudX < 850)
        isNight = true;
    else
        isNight = false;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

// ------------------------------------------------------------
// Setup
// ------------------------------------------------------------
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 900, 0, 600);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Village Scenery - Day to Night");

    glClearColor(1, 1, 1, 1);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}
