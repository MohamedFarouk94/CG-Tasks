#include <GL/glut.h>
#include <math.h>

#define PI 3.1416f

float theta = 0.0f;

void display(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    /* glRotatef(theta, 0.0f, 0.0f, 1.0f); */
    glColor3f(0.77647058823f, 1.0f, 0.32549019607f);

    // Upper half circle
    glBegin(GL_TRIANGLE_FAN);
        float cx = 0.0f;   
        float cy = 0.5f;
        float r  = 0.4f;
        glVertex2f(cx, cy);
        for(int i = 0; i <= 180; i++)
        {
            float angle = i * PI / 180.0f;
            glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
        }
    glEnd();
    
    // Middle rectangle
    glBegin(GL_POLYGON);
        glVertex2f(0.4, 0.4);
        glVertex2f(-0.4, 0.4);
        glVertex2f(-0.4, -0.2);
        glVertex2f(0.4, -0.2);

    glEnd();

    // Right quarter circle
    glBegin(GL_TRIANGLE_FAN);
        cx = 0.3f;   
        cy = -0.2f;
        r  = 0.1f;
        glVertex2f(cx, cy);
        for(int i = 360; i >= 270; i--)
        {
            float angle = i * PI / 180.0f;
            glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
        }
    glEnd();

    // Left quarter circle
    glBegin(GL_TRIANGLE_FAN);
        cx = -0.3f;   
        cy = -0.2f;
        r  = 0.1f;
        glVertex2f(cx, cy);
        for(int i = 180; i <= 270; i++)
        {
            float angle = i * PI / 180.0f;
            glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
        }
    glEnd();

    // Rectangle between two quarter circles
    glBegin(GL_POLYGON);
        glVertex2f(0.3f, -0.2f);
        glVertex2f(-0.3f, -0.2f);
        glVertex2f(-0.3f, -0.3f);
        glVertex2f(0.3f, -0.3f);
    glEnd();

    // Horns
    glLineWidth(10.0f);
    glBegin(GL_LINES);
        glVertex2d(0.2f, 0.8f);
        glVertex2d(0.3f, 0.95f);
        glVertex2d(-0.2f, 0.8f);
        glVertex2d(-0.3f, 0.95f);
    glEnd();


    glPopMatrix();

    glutSwapBuffers();
    theta += 1.0f;
}

void timer(int value)
{
    glutPostRedisplay();
    glutTimerFunc(1, timer, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) /* ESC */
        exit(0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Sample");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(1, timer, 0);

    glutMainLoop();
    return 0;
}