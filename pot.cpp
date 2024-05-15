#include <windows.h>
#include <GL/freeglut.h>

float angle = 0.0f;

void drawTeapot() {
    glPushMatrix();
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glutWireTeapot(0.5);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -2.0f);
    drawTeapot();
    glutSwapBuffers();
}

void update(int value) {
    angle += 2.0f;
    if (angle > 360) {
        angle -= 360;
    }
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teapot Rotation");

    glutDisplayFunc(display);

    glutTimerFunc(25, update, 0);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glutMainLoop();

    return 0;
}
