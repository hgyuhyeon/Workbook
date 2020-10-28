/***************************************************/
/*   HW#4 : Callback 프로그래밍  - 키보드콜백(1)   */
/*  작성자 : 황규현      날짜 : 2020년 10월 14일   */
/*                                                 */
/* 문제 정의 : Idle Callback 응용                  */
/*                                                 */
/***************************************************/
#include <GL/glut.h>
GLfloat Deltax = 0.0, Deltay;

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.8);
    glVertex3f(-0.5 + Deltax, -0.5 + Deltay, 0.0);
    glVertex3f(0.5 + Deltax, -0.5 + Deltay, 0.0);
    glVertex3f(0.5 + Deltax, 0.5 + Deltay, 0.0);
    glVertex3f(-0.5 + Deltax, 0.5 + Deltay, 0.0);
    glEnd();
    glutSwapBuffers();
}
/* 각 key event별로 idle 지정 */
void MyLeftIdle() {
    if (Deltax <= 0.5 && Deltax > -0.5)
        Deltax -= 0.001;
    glutPostRedisplay();
}
void MyRightIdle() {
    if (Deltax < 0.4 && Deltax >= -0.5)
        Deltax += 0.001;
    glutPostRedisplay();
}
void MyUpIdle() {
    if (Deltay < 0.4 && Deltay >= -0.5)
        Deltay += 0.001;
    glutPostRedisplay();
}
void MyDownIdle() {
    if (Deltay <= 0.5 && Deltay > -0.5) /* Windows 화면을 벗어나지 않도록 조건 */
        Deltay -= 0.001;
    glutPostRedisplay();
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
        glutIdleFunc(MyLeftIdle); /* 키 입력 시 발동 */
		break;
	case GLUT_KEY_RIGHT:
        glutIdleFunc(MyRightIdle); 
		break;
	case GLUT_KEY_UP:
        glutIdleFunc(MyUpIdle);
		break;
	case GLUT_KEY_DOWN:
        glutIdleFunc(MyUpIdle); 
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Idle Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutSpecialFunc(MySpecial);

    glutMainLoop();
    return 0;
}
