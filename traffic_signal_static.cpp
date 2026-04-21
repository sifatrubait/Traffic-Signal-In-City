#include <windows.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

#define PI 3.14159265358979323846

GLfloat x, y, radius, twicePi;
int triangleAmount;
int cnt = 0;
char *c;

// ═════════════════════════════════════════════════════════════════
// DRAWING PRIMITIVES
// ═════════════════════════════════════════════════════════════════

void drawCircle(GLfloat cx, GLfloat cy, GLfloat r, int R, int G, int B) {
    x = cx; y = cy; radius = r;
    triangleAmount = 50;
    twicePi = 2.0f * PI;
    glColor3ub(R, G, B);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for(int i = 0; i <= triangleAmount; i++) {
        glVertex2f(x + (radius * cos(i * twicePi / triangleAmount)),
                   y + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, int R, int G, int B) {
    glColor3ub(R, G, B);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// ═════════════════════════════════════════════════════════════════
// TREES
// ═════════════════════════════════════════════════════════════════

void tree() {
    // Tree 1 - Circle type (left)
    glLineWidth(10.0f);
    drawLine(-1.5f, 0.8f, -1.5f, 0.55f, 153, 51, 51);
    drawCircle(-1.45f, 0.82f, 0.08f, 0, 153, 51);
    drawCircle(-1.5f, 0.85f, 0.08f, 0, 153, 51);
    drawCircle(-1.55f, 0.82f, 0.08f, 0, 153, 51);
    
    glPointSize(5.0);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(-1.53f, 0.85f);
    glVertex2f(-1.47f, 0.8f);
    glEnd();

    // Tree 2 - Circle type (middle)
    glLineWidth(10.0f);
    drawLine(-0.8f, 0.8f, -0.8f, 0.57f, 153, 51, 51);
    drawCircle(-0.85f, 0.82f, 0.08f, 0, 153, 51);
    drawCircle(-0.8f, 0.85f, 0.08f, 0, 153, 51);
    drawCircle(-0.75f, 0.82f, 0.08f, 0, 153, 51);

    // Tree 3 - Triangle type (right-up)
    glBegin(GL_LINES);
    glColor3ub(153, 51, 51);
    glVertex2f(1.55f, 0.65f);
    glVertex2f(1.55f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 51);
    glVertex2f(1.45f, 0.7f);
    glVertex2f(1.55f, 0.95f);
    glVertex2f(1.65f, 0.7f);
    glEnd();

    // Tree 4 - Triangle type (center)
    glBegin(GL_LINES);
    glColor3ub(153, 51, 51);
    glVertex2f(-0.2f, 0.65f);
    glVertex2f(-0.2f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 51);
    glVertex2f(-0.3f, 0.7f);
    glVertex2f(-0.2f, 0.95f);
    glVertex2f(-0.1f, 0.7f);
    glEnd();

    // Tree 5 - Triangle type (right)
    glBegin(GL_LINES);
    glColor3ub(153, 51, 51);
    glVertex2f(1.9f, 0.7f);
    glVertex2f(1.9f, 0.85f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 51);
    glVertex2f(1.8f, 0.75f);
    glVertex2f(1.9f, 1.0f);
    glVertex2f(2.0f, 0.75f);
    glEnd();

    // Tree 6 - Extra tree (new - far left)
    glLineWidth(10.0f);
    drawLine(-1.95f, 0.75f, -1.95f, 0.50f, 153, 51, 51);
    drawCircle(-1.90f, 0.77f, 0.07f, 0, 153, 51);
    drawCircle(-1.95f, 0.80f, 0.07f, 0, 153, 51);
    drawCircle(-2.0f, 0.77f, 0.07f, 0, 153, 51);

    // Tree 7 - Extra tree (new - far right)
    glBegin(GL_LINES);
    glColor3ub(153, 51, 51);
    glVertex2f(2.1f, 0.65f);
    glVertex2f(2.1f, 0.8f);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 51);
    glVertex2f(2.0f, 0.7f);
    glVertex2f(2.1f, 0.95f);
    glVertex2f(2.2f, 0.7f);
    glEnd();
}

// ═════════════════════════════════════════════════════════════════
// SHOPS
// ═════════════════════════════════════════════════════════════════

void shop() {
    // Left shop
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 255);
    glVertex2f(-1.95f, 0.5f);
    glVertex2f(-1.95f, 0.75f);
    glVertex2f(-1.55f, 0.75f);
    glVertex2f(-1.55f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(-1.95f, 0.75f);
    glVertex2f(-1.95f, 0.85f);
    glVertex2f(-1.55f, 0.85f);
    glVertex2f(-1.55f, 0.75f);
    glEnd();

    glColor3f(1, 1, 1);
    c = "BFC";
    glRasterPos2f(-1.8, 0.78);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c[i]);

    // Right shop
    glBegin(GL_POLYGON);
    glColor3ub(255, 204, 102);
    glVertex2f(-0.75f, 0.5f);
    glVertex2f(-0.75f, 0.8f);
    glVertex2f(-0.2f, 0.8f);
    glVertex2f(-0.2f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(179, 89, 0);
    glVertex2f(-0.75f, 0.85f);
    glVertex2f(-0.75f, 0.8f);
    glVertex2f(-0.2f, 0.8f);
    glVertex2f(-0.2f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(77, 38, 0);
    glVertex2f(-0.73f, 0.6f);
    glVertex2f(-0.73f, 0.75f);
    glVertex2f(-0.22f, 0.75f);
    glVertex2f(-0.22f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128, 64, 0);
    glVertex2f(-0.73f, 0.5f);
    glVertex2f(-0.73f, 0.6f);
    glVertex2f(-0.22f, 0.6f);
    glVertex2f(-0.22f, 0.5f);
    glEnd();

    glColor3ub(255, 255, 0);
    c = "Candy Shop";
    glRasterPos2f(-0.6, 0.84);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c[i]);
}

// ═════════════════════════════════════════════════════════════════
// HOUSES
// ═════════════════════════════════════════════════════════════════

void house() {
    // Left house
    glBegin(GL_POLYGON);
    glColor3ub(224, 228, 231);
    glVertex2f(-1.4f, 0.5f);
    glVertex2f(-1.4f, 1.0f);
    glVertex2f(-0.9f, 1.0f);
    glVertex2f(-0.9f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(179, 230, 255);
    glVertex2f(-1.35f, 0.55f);
    glVertex2f(-1.35f, 0.65f);
    glVertex2f(-1.25f, 0.65f);
    glVertex2f(-1.25f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(179, 230, 255);
    glVertex2f(-1.05f, 0.55f);
    glVertex2f(-1.05f, 0.65f);
    glVertex2f(-0.95f, 0.65f);
    glVertex2f(-0.95f, 0.55f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(179, 230, 255);
    glVertex2f(-1.35f, 0.85f);
    glVertex2f(-1.35f, 0.95f);
    glVertex2f(-1.25f, 0.95f);
    glVertex2f(-1.25f, 0.85f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(153, 153, 153);
    glVertex2f(-1.2f, 0.5f);
    glVertex2f(-1.2f, 0.65f);
    glVertex2f(-1.1f, 0.65f);
    glVertex2f(-1.1f, 0.5f);
    glEnd();

    // Right house
    glBegin(GL_POLYGON);
    glColor3ub(153, 51, 0);
    glVertex2f(-0.15f, 0.5f);
    glVertex2f(-0.15f, 0.8f);
    glVertex2f(0.35f, 0.8f);
    glVertex2f(0.35f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(77, 184, 255);
    glVertex2f(0.05f, 0.6f);
    glVertex2f(0.05f, 0.7f);
    glVertex2f(0.15f, 0.7f);
    glVertex2f(0.15f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(77, 184, 255);
    glVertex2f(0.2f, 0.6f);
    glVertex2f(0.2f, 0.7f);
    glVertex2f(0.3f, 0.7f);
    glVertex2f(0.3f, 0.6f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(77, 77, 77);
    glVertex2f(-0.1f, 0.5f);
    glVertex2f(-0.1f, 0.65f);
    glVertex2f(0.0f, 0.65f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

// ═════════════════════════════════════════════════════════════════
// ROAD & FOOTPATH
// ═════════════════════════════════════════════════════════════════

void road_footpath() {
    // Main roads
    glBegin(GL_POLYGON);
    glColor3ub(95, 96, 91);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(2.0f, 0.5f);
    glVertex2f(2.0f, -0.5f);
    glVertex2f(-2.0f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(95, 96, 91);
    glVertex2f(0.4f, 1.0f);
    glVertex2f(1.4f, 1.0f);
    glVertex2f(1.4f, -1.0f);
    glVertex2f(0.4f, -1.0f);
    glEnd();

    // Footpaths
    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(-2.0f, 0.5f);
    glVertex2f(-2.0f, 0.3f);
    glVertex2f(0.6f, 0.3f);
    glVertex2f(0.6f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(176, 191, 189);
    glVertex2f(-2.0f, -0.5f);
    glVertex2f(-2.0f, -0.3f);
    glVertex2f(0.6f, -0.3f);
    glVertex2f(0.6f, -0.5f);
    glEnd();

    // Road markings
    glLineWidth(3.0f);
    glColor3ub(255, 255, 255);
    glBegin(GL_LINES);
    for(float x = -2.0f; x < 0.1f; x += 0.2f) {
        glVertex2f(x, 0);
        glVertex2f(x + 0.1f, 0);
    }
    glEnd();

    // Zebra crossing
    glLineWidth(5.0f);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0.2f, 0.3f);
    glVertex2f(0.2f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.4f, 0.3f);
    glEnd();
}

// ═════════════════════════════════════════════════════════════════
// TRAFFIC LIGHTS
// ═════════════════════════════════════════════════════════════════

void traffic_light1() {
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(0.45f, 0.38f);
    glVertex2f(0.45f, 0.42f);
    glVertex2f(0.55f, 0.42f);
    glVertex2f(0.55f, 0.38f);
    glEnd();

    glLineWidth(5.0f);
    drawLine(0.55f, 0.4f, 0.7f, 0.4f, 153, 0, 0);
    drawLine(0.7f, 0.4f, 0.7f, 0.15f, 153, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(204, 122, 0);
    glVertex2f(0.65f, 0.15f);
    glVertex2f(0.75f, 0.15f);
    glVertex2f(0.75f, -0.05f);
    glVertex2f(0.65f, -0.05f);
    glEnd();

    // Traffic lights
    if(cnt == 0) {
        drawCircle(0.7f, 0.1f, 0.02f, 255, 51, 51);
        drawCircle(0.7f, 0.05f, 0.02f, 255, 204, 0);
        drawCircle(0.7f, 0.0f, 0.02f, 0, 128, 0);
    } else {
        drawCircle(0.7f, 0.1f, 0.02f, 204, 0, 0);
        drawCircle(0.7f, 0.05f, 0.02f, 255, 204, 0);
        drawCircle(0.7f, 0.0f, 0.02f, 0, 255, 0);
    }
}

void traffic_light2() {
    glBegin(GL_POLYGON);
    glColor3ub(128, 0, 0);
    glVertex2f(1.28f, -0.35f);
    glVertex2f(1.32f, -0.35f);
    glVertex2f(1.32f, -0.45f);
    glVertex2f(1.28f, -0.45f);
    glEnd();

    glLineWidth(5.0f);
    drawLine(1.3f, -0.35f, 1.3f, -0.2f, 153, 0, 0);
    drawLine(1.3f, -0.2f, 1.0f, -0.2f, 153, 0, 0);

    glBegin(GL_POLYGON);
    glColor3ub(204, 122, 0);
    glVertex2f(0.9f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(0.9f, -0.3f);
    glEnd();

    // Traffic lights
    if(cnt == 0) {
        drawCircle(0.95f, -0.15f, 0.02f, 204, 0, 0);
        drawCircle(0.95f, -0.2f, 0.02f, 255, 204, 0);
        drawCircle(0.95f, -0.25f, 0.02f, 0, 255, 0);
    } else {
        drawCircle(0.95f, -0.15f, 0.02f, 255, 51, 51);
        drawCircle(0.95f, -0.2f, 0.02f, 255, 204, 0);
        drawCircle(0.95f, -0.25f, 0.02f, 0, 128, 0);
    }
}

// ═════════════════════════════════════════════════════════════════
// FENCE
// ═════════════════════════════════════════════════════════════════

void fence() {
    glColor3ub(204, 0, 0);
    glBegin(GL_LINES);
    drawLine(-2.0f, 0.6f, 0.39f, 0.6f, 204, 0, 0);
    drawLine(-2.0f, 0.53f, 0.39f, 0.53f, 204, 0, 0);
    
    float x_pos[] = {-1.98f, -1.5f, -1.45f, -0.4f, -0.85f, -0.8f, -0.17f, 0.37f};
    for(float xp : x_pos) {
        glVertex2f(xp, 0.5f);
        glVertex2f(xp, 0.63f);
    }
    
    drawLine(2.0f, 0.6f, 1.42f, 0.6f, 204, 0, 0);
    drawLine(2.0f, 0.53f, 1.42f, 0.53f, 204, 0, 0);
    
    for(float xp = 1.45f; xp <= 1.96f; xp += 0.05f) {
        glVertex2f(xp, 0.5f);
        glVertex2f(xp, 0.63f);
    }
    glEnd();
}

// ═════════════════════════════════════════════════════════════════
// RIVER
// ═════════════════════════════════════════════════════════════════

void river() {
    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 255);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, -0.55f);
    glVertex2f(0.35f, -0.55f);
    glVertex2f(0.35f, -2.0f);
    glEnd();

    // River waves (static)
    float rx[] = {1.0f, 0.5f, 0.0f, -0.5f, -1.0f, -1.5f, -2.0f};
    for(float xr : rx) {
        drawCircle(xr, -1.3f, 0.6f, 0, 191, 255);
    }
}

// ═════════════════════════════════════════════════════════════════
// BOATS (STATIC)
// ═════════════════════════════════════════════════════════════════

void boats() {
    // Boat 1
    glBegin(GL_POLYGON);
    glColor3ub(255, 140, 26);
    glVertex2f(-0.3f, -0.75f);
    glVertex2f(-0.3f, -0.8f);
    glVertex2f(-0.15f, -0.8f);
    glVertex2f(-0.15f, -0.75f);
    glEnd();

    drawCircle(-0.15f, -0.8f, 0.05f, 255, 140, 26);
    drawCircle(-0.3f, -0.8f, 0.05f, 179, 89, 0);

    // Boat 2
    glBegin(GL_POLYGON);
    glColor3ub(230, 230, 0);
    glVertex2f(-0.75f, -0.6f);
    glVertex2f(-0.75f, -0.65f);
    glVertex2f(-0.6f, -0.65f);
    glVertex2f(-0.6f, -0.6f);
    glEnd();

    drawCircle(-0.6f, -0.65f, 0.05f, 153, 153, 0);
    drawCircle(-0.75f, -0.65f, 0.05f, 230, 230, 0);
}

// ═════════════════════════════════════════════════════════════════
// SCREEN DISPLAY
// ═════════════════════════════════════════════════════════════════

void start() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);

    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 0);
    glVertex2f(-2, 2);
    glColor3ub(147, 112, 219);
    glVertex2f(2, 2);
    glColor3ub(30, 144, 255);
    glVertex2f(2, -2);
    glColor3ub(70, 130, 180);
    glVertex2f(-2, -2);
    glEnd();

    glColor3ub(255, 255, 255);
    c = "Traffic Signal In The City";
    glRasterPos2f(-0.25f, 0.7f);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);

    glColor3ub(0, 0, 0);
    c = "Press 'R' = Red(Horizontal), Green(Vertical)";
    glRasterPos2f(-0.5f, 0.2f);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);

    c = "Press 'G' = Green(Horizontal), Red(Vertical)";
    glRasterPos2f(-0.5f, 0.0f);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);

    glColor3ub(255, 0, 0);
    c = "Press F to START";
    glRasterPos2f(-0.15f, -0.7f);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c[i]);

    glFlush();
}

void day() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Background
    glBegin(GL_POLYGON);
    glColor3ub(51, 204, 51);
    glVertex2f(2.0f, 1.0f);
    glVertex2f(2.0f, -1.0f);
    glVertex2f(-2.0f, -1.0f);
    glVertex2f(-2.0f, 1.0f);
    glEnd();

    river();
    boats();
    tree();
    road_footpath();
    traffic_light1();
    traffic_light2();
    fence();
    shop();
    house();

    // Shop sign
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 204);
    glVertex2f(-1.72f, 0.57f);
    glVertex2f(-1.72f, 0.6f);
    glVertex2f(-1.65f, 0.6f);
    glVertex2f(-1.65f, 0.57f);
    glEnd();

    glColor3ub(255, 51, 0);
    c = "open";
    glRasterPos2f(-1.715f, 0.58f);
    for(int i = 0; c[i] != '\0'; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, c[i]);

    glFlush();
}

// ═════════════════════════════════════════════════════════════════
// INPUT & SETUP
// ═════════════════════════════════════════════════════════════════

void button(unsigned char key, int x, int y) {
    if(key == 'f') {
        glutDisplayFunc(day);
        glutPostRedisplay();
    } else if(key == 'r') {
        cnt = 1;
        glutPostRedisplay();
    } else if(key == 'g') {
        cnt = 0;
        glutPostRedisplay();
    }
}

void inigl() {
    glClearColor(1, 1, 1, 1);
    gluOrtho2D(-2, 2, -1, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1430, 800);
    glutCreateWindow("Traffic Signal In The City");

    cout << "═════════════════════════════════════════════\n";
    cout << "  Traffic Signal In The City\n";
    cout << "═════════════════════════════════════════════\n";
    cout << "Controls:\n";
    cout << "  F - Start\n";
    cout << "  R - Red (Horizontal), Green (Vertical)\n";
    cout << "  G - Green (Horizontal), Red (Vertical)\n";
    cout << "═════════════════════════════════════════════\n";

    glutDisplayFunc(start);
    inigl();
    glutKeyboardFunc(button);
    glutMainLoop();

    return 0;
}
