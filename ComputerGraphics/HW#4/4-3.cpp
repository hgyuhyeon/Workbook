/***************************************************/
/*   HW#4 : Callback 프로그래밍  - 키보드콜백(1)   */
/*  작성자 : 황규현      날짜 : 2020년 10월 14일   */
/*                                                 */
/* 문제 정의 : Mouse Callback 응용                 */
/*                                                 */
/***************************************************/
#include <GL/glut.h>
#include <stdlib.h>
#include <time.h>

float tx = 0; /* 오른쪽으로 이동시킬 값 */

void MyDisplay() {
    glViewport(0, 0, 500, 500);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(0.0 + tx, 0.45, 0.0);
    glVertex3f(0.1 + tx, 0.45, 0.0);
    glVertex3f(0.1 + tx, 0.55, 0.0);
    glVertex3f(0.0 + tx, 0.55, 0.0);
    glEnd();
    glutSwapBuffers();
}
void MyTimer(int Value) {
    if (tx < 1.0) 
        tx += 0.05; /* 0.1칸씩 이동 */
    glutPostRedisplay(); /* 윈도우 창을 벗어나지 않는 한 ReDisplay */
    glutTimerFunc(1000, MyTimer, 1);
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON) /* 마우스 왼쪽 클릭 시 */
        glutTimerFunc(1000, MyTimer, 1);
    if (Button == GLUT_RIGHT_BUTTON) /* 마우스 오른쪽 클릭 시 */
        system("pause");
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    srand(time(NULL));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Mouse Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutMouseFunc(MyMouseClick);
    glutMainLoop();
    return 0;
}
