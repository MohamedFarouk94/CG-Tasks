#include <GL/glut.h>

float theta = 0.0f;

void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    /* glRotatef(theta, 0.0f, 0.0f, 1.0f); */ /* uncomment to enable rotation */

    /* --- Red Quad (top-right) --- */
    glPointSize(10);
    glLineWidth(5);
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f( 0.9f,  0.9f);
        glVertex2f( 0.0f,  0.9f);
        glVertex2f( 0.0f,  0.1f);
        glVertex2f( 0.9f,  0.1f);
    glEnd();

    /* --- Green Triangle (top-left) --- */
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.1f,  0.1f);
        glVertex2f(-0.5f,  0.9f);
        glVertex2f(-0.9f,  0.1f);
    glEnd();

    /* --- White Points (eyes on triangle) --- */
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex2f(-0.3f,  0.8f);
        glVertex2f(-0.7f,  0.8f);
    glEnd();

    /* --- Blue Polygon (bottom-left) --- */
    glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(-0.35f,  0.0f);
        glVertex2f(-0.5f,   0.0f);
        glVertex2f(-0.9f,  -0.3f);
        glVertex2f(-0.9f,  -0.6f);
        glVertex2f(-0.5f,  -0.9f);
        glVertex2f(-0.35f, -0.9f);
        glVertex2f( 0.0f,  -0.6f);
        glVertex2f( 0.0f,  -0.3f);
    glEnd();

    /* --- Green Line Loop Triangle (bottom-right) --- */
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f( 0.5f,  0.0f);
        glVertex2f( 0.1f, -0.9f);
        glVertex2f( 0.9f, -0.9f);
    glEnd();

    glPopMatrix();

    glutSwapBuffers();

    theta += 1.0f;
}

void timer(int value)
{
    glutPostRedisplay();            /* request a redraw */
    glutTimerFunc(1, timer, 0);    /* re-register: fires every 1 ms */
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27)   /* ESC key */
        exit(0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(256, 256);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Sample");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1, timer, 0);    /* start the animation timer */

    glutMainLoop();
    return 0;
}
