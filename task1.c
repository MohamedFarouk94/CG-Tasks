#include <GL/glut.h>

float theta = 0.0f;

void display(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // Diamond
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.0f, 0.6f);
        glVertex2f(-0.6f, 0.0f);
        glVertex2f(0.0f, -0.6f);
        glVertex2f(0.6f, 0.0f);
    glEnd();

    // Diamond lines
    glLineWidth(10.0f);
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f( 0.0f,  0.6f);
        glVertex2f(-0.6f,  0.0f);
        glVertex2f( 0.0f, -0.6f);
        glVertex2f( 0.6f,  0.0f);
    glEnd();

    // Vertical rectangle
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.1f, 0.9f);
        glVertex2f(-0.1f, 0.9f);
        glVertex2f(-0.1f, -0.9f);
        glVertex2f(0.1f, -0.9f);
    glEnd();

    // Vertical rectangle lines
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.1f, 0.9f);
        glVertex2f(-0.1f, 0.9f);
        glVertex2f(-0.1f, -0.9f);
        glVertex2f(0.1f, -0.9f);
    glEnd();

    // Horizontal rectangle
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(-0.9f, 0.1f);
        glVertex2f(-0.9f, -0.1f);
        glVertex2f(0.9f, -0.1f);
    glEnd();

    // Horizontal rectangle lines
    glBegin(GL_LINE_LOOP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(-0.9f, 0.1f);
        glVertex2f(-0.9f, -0.1f);
        glVertex2f(0.9f, -0.1f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); glVertex2f(0.1f, 0.1f);
        glColor3f(1.0f, 0.0f, 0.0f); glVertex2f(-0.1f, 0.1f);
        glColor3f(0.0f, 0.0f, 1.0f); glVertex2f(-0.1f, -0.1f);
        glColor3f(0.0f, 0.0f, 0.0f); glVertex2f(0.1f, -0.1f);
    glEnd();

    glPointSize(10);
    glBegin(GL_POINTS);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(0.1f, 0.9f);
        glVertex2f(-0.1f, 0.9f);
        glVertex2f(-0.1f, -0.9f);
        glVertex2f(0.1f, -0.9f);
        glVertex2f(0.9f, 0.1f);
        glVertex2f(-0.9f, 0.1f);
        glVertex2f(-0.9f, -0.1f);
        glVertex2f(0.9f, -0.1f);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(-0.1f, 0.1f);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f(0.1f, -0.1f);
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
