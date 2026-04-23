#include <GL/glut.h>
#include <math.h>

#define PI 3.1416f

float theta = 0.0f;

void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    /* glRotatef(theta, 0.0f, 0.0f, 1.0f); */

    // circle بالزوايا من 0 ل 360
    float r = 0.5;
    //glColor3f(1.0f,0.0f,1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 0.0f); // center
        for (int deg = 0; deg <= 360; deg++)
        {
            float angle = deg * PI / 180.0f; // نحول لRadians
            float x = 0 + r * cos(angle);
            float y = 0 + r * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();

    // Oval
    /*float a = 0.3f;   // نصف العرض  (ellipse width control)
    float b = 0.7f;   // نصف الارتفاع (ellipse height control)
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int deg = 0; deg <= 360; deg++) {
        float angle = deg * ((22/7.0) / 180.0f);  // Degree → Radian
        float x = 0+ a * cos(angle);
        float y = 0+ b * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();*/

    //😀 الوجه (دائرة صفراء)
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f);  // مركز الوجه
        for(int i = 0; i <= 360; i++)
        {
            float angle = i * PI / 180.0f;
            float x = 0.7f * cos(angle);
            float y = 0.7f * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();

    // 👀 العين الشمال
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(-0.25f, 0.2f);
        for(int i = 0; i <= 360; i++)
        {
            float angle = i * PI / 180.0f;
            float x = -0.25f + 0.08f * cos(angle);
            float y = 0.2f   + 0.08f * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();

    // 👀 العين اليمين
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.25f, 0.2f);
        for(int i = 0; i <= 360; i++)
        {
            float angle = i * PI / 180.0f;
            float x = 0.25f + 0.08f * cos(angle);
            float y = 0.2f  + 0.08f * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();

    // 🙂 الفم (قوس)
    glLineWidth(4.0f);
    glBegin(GL_LINE_STRIP);
        for(int i = 200; i <= 340; i++)
        {
            float angle = i * PI / 180.0f;
            float x = 0.0f + 0.4f * cos(angle);
            float y = -0.1f + 0.4f * sin(angle);
            glVertex2f(x, y);
        }
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