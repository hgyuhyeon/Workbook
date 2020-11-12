/***************************************************/
/*   HW#5 : 계층적 모델링, 시점변환                */
/*  작성자 : 황규현      날짜 : 2020년 10월 28일   */
/*                                                 */
/* 문제 정의 : 로봇 팔 응용                        */
/*                                                 */
/***************************************************/
#include <gl/glut.h>
#include<stdlib.h>
static int shoulder = 0, elbow = 0, fing1 = 0, fing2 = 0, fing3 = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix(); //전역 좌표계 push
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix(); //팔1 좌표계 push
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0); //팔1


	glPopMatrix(); //팔1 좌표계 pop
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix(); //팔2 좌표계 push
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0); //팔2


	glPopMatrix(); //팔2 좌표계 pop
	glTranslatef(0.2, 0.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix(); //손바닥 좌표계 push
	glScalef(0.5, 0.5, 0.5);
	glutWireCube(1.0); //손바닥



	glPopMatrix(); //손바닥 좌표계 pop
	glPushMatrix(); //손바닥 좌표계 재push
	glTranslatef(0.3, 0.15, 0.0);
	glRotatef((GLfloat)fing1, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); //손가락1 좌표계 push
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 1-1

	glPopMatrix(); //손가락1 좌표계 pop
	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)fing1, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); //손가락2 좌표계 push
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 1-2

	glPopMatrix(); //손가락2 좌표계 pop
	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)fing1, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 1-3


	glPopMatrix(); //손바닥 좌표계 pop
	glPushMatrix(); //손바닥 좌표계 재push
	glTranslatef(0.3, 0.0, 0.0);
	glRotatef((GLfloat)fing2, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 2-1

	glPopMatrix(); //손가락1 좌표계 pop
	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)fing2, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); //손가락2 좌표계 push
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 2-2

	glPopMatrix(); //손가락2 좌표계 pop
	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)fing2, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 2-3


	glPopMatrix(); //손바닥 좌표계 pop
	glPushMatrix(); //손바닥 좌표계 재push
	glTranslatef(0.3, -0.15, 0.0);
	glRotatef((GLfloat)fing3, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix();
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 3-1

	glPopMatrix(); //손가락1 좌표계 pop
	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)fing3, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glPushMatrix(); //손가락2 좌표계 push
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 3-2

	glPopMatrix(); //손가락2 좌표계 pop
	glTranslatef(0.4, 0.0, 0.0);
	glRotatef((GLfloat)fing3, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);
	glScalef(0.4, 0.1, 0.1);
	glutWireCube(1.0); //손가락 3-3


	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glShadeModel(GL_FLAT);
}
void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 's':
		shoulder = (shoulder + 5) % 180 + 180;
		break;
	case 'S':
		shoulder = (shoulder - 5) % 180 + 180;
		break;
	case 'e':
		elbow = (elbow + 5) % 180;
		break;
	case 'E':
		elbow = (elbow - 5) % 180;
		break;
	case '1':
		if (fing1 == 0)
			fing1 = 30;
		else
			fing1 = 0;
		break;
	case '2':
		if (fing2 == 0)
			fing2 = 30;
		else
			fing2 = 0;
		break;
	case '3':
		if (fing3 == 0)
			fing3 = 30;
		else
			fing3 = 0;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON) { /* 마우스 왼쪽 클릭 시 */
		if (fing1 == -30)
			return;
		shoulder = (shoulder - 20) % 180;
		elbow = (elbow - 30) % 180;
		fing1 = fing2 = fing3 = -30;
		glutPostRedisplay();
	}
	if (Button == GLUT_RIGHT_BUTTON) { /* 마우스 오른쪽 클릭 시 */
		shoulder = elbow = fing1 = fing2 = fing3 = 0;
		glutPostRedisplay();
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1200, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Robot Arm");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}
