/***************************************************/
/*   HW#4 : Callback 프로그래밍  - 키보드콜백(1)   */
/*  작성자 : 황규현      날짜 : 2020년 10월 14일   */
/*                                                 */
/* 문제 정의 : Timer Callback 응용                 */
/*                                                 */
/***************************************************/
#include <GL/glut.h>
#include <stdlib.h>

GLfloat Delta = 0.0;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f((float)(rand() % 10) / (float)10, (float)(rand() % 10) / (float)10, (float)(rand() % 10) / (float)10);
    /* 색상 15가지긴 한데... 그냥 다 랜덤! */
    glVertex3f(-1.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, -0.5, 0.0);
    glVertex3f(0.0 + Delta, 0.5, 0.0);
    glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd();
    glutSwapBuffers();
}
void MyTimer(int Value) {
    Delta = Delta + 0.001;

    glutPostRedisplay();
    glutTimerFunc(40, MyTimer, 1);
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Timer Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutTimerFunc(40, MyTimer, 1);

    glutMainLoop();
    return 0;
}
