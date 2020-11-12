/***************************************************/
/*   HW#5 : 계층적 모델링, 시점변환                */
/*  작성자 : 황규현      날짜 : 2020년 10월 28일   */
/*                                                 */
/* 문제 정의 : 전신 Can Robot 제작                 */
/*                                                 */
/***************************************************/
#include <gl/glut.h>
#include<stdlib.h>
static int lshoulder = 0, lelbow = 0, lleg = 0;
static int rshoulder = 0, relbow = 0, rleg = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	/* 몸통 */
	glPushMatrix(); //전역 좌표계
	glutWireCube(1.4);

	/* 목 */
	glTranslatef(0.0, 0.7, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.2, 0.0);
	glPushMatrix(); //목 기준 좌표계
	glScalef(0.5, 0.5, 0.5);
	glutWireCube(0.7);

	/* 머리 */
	glTranslatef(0.0, 1.0, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.2, 0.0); 
	glScalef(1.5, 1.5, 1.5);
	glutWireCube(1.0); 

	glPopMatrix(); //목 좌표계 복원
	glPopMatrix(); //전역 좌표계 복원
	
	/* 왼쪽 팔 */
	glPushMatrix(); //전역 좌표계 저장

	glTranslatef(-0.8, 0.7, 0.0); //돌릴 때 기준점
	glRotatef((GLfloat)lshoulder, 0.0, 0.0, 1.0); //돌리기, 축 설정
	glTranslatef(0.0, -0.5, 0.0); //도형 그릴 때 기준점
	glPushMatrix(); //어깨 기준 좌표계
	glScalef(0.3, 1.2, 0.3); //사이즈
	glutWireCube(1.0); //팔1

	glPopMatrix();
	glTranslatef(0.0, -0.6, 0.0);
	glRotatef((GLfloat)lelbow, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.4, 0.0);
	glPushMatrix(); //팔꿈치 기준 좌표계
	glScalef(0.3, 0.9, 0.3);
	glutWireCube(1.0); //팔2

	glPopMatrix(); //팔꿈치 기준 좌표계 pop
	glPushMatrix(); //다시 스택에 push(나머지손가락을 위해)
	glTranslatef(0.17, -0.5, 0.0);
	glScalef(0.1, 0.2, 0.1);
	glutWireCube(1.0); //엄지손가락

	glPopMatrix();
	glTranslatef(-0.1, -0.6, 0.0);
	glScalef(-0.35, 0.4, 0.35);
	glutWireCube(1.0); //나머지손가락

	glPopMatrix(); //어깨 좌표계 pop
	glPopMatrix(); //전역 좌표계 pop


	/* 오른쪽 팔 */
	glPushMatrix(); //전역 좌표계 저장

	glTranslatef(0.8, 0.7, 0.0);
	glRotatef((GLfloat)rshoulder, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glPushMatrix(); //어깨 기준 좌표계
	glScalef(0.3, 1.2, 0.3);
	glutWireCube(1.0); //팔1

	glPopMatrix();
	glTranslatef(0.0, -0.6, 0.0);
	glRotatef((GLfloat)relbow, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.4, 0.0);
	glPushMatrix(); //팔꿈치 기준 좌표계
	glScalef(0.3, 0.9, 0.3);
	glutWireCube(1.0); //팔2

	glPopMatrix(); //팔꿈치 기준 좌표계 pop
	glPushMatrix(); //다시 스택에 push(나머지손가락을 위해)
	glTranslatef(-0.17, -0.5, 0.0); 
	glScalef(0.1, 0.2, 0.1);
	glutWireCube(1.0); //엄지손가락
	
	glPopMatrix();
	glTranslatef(0.1, -0.6, 0.0);
	glScalef(0.35, 0.4, 0.35);
	glutWireCube(1.0); //나머지손가락

	glPopMatrix(); //어깨 좌표계 pop
	glPopMatrix(); //전역 좌표계 pop


	/* 왼쪽 다리 */
	glPushMatrix(); //전역 좌표계 push

	glTranslatef(-0.3, -0.7, 0.0);
	glRotatef((GLfloat)lleg, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glPushMatrix(); //허벅지 기준 좌표계
	glScalef(0.5, 1.0, 0.5);
	glutWireCube(1.0); //허벅지
	
	glPopMatrix(); //허벅지 좌표계 pop
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef((GLfloat)rleg, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glPushMatrix(); //종아리 기준 좌표계
	glScalef(0.5, 0.9, 0.5);
	glutWireCube(1.0); //종아리

	glPopMatrix(); //종아리 좌표계 pop
	glTranslatef(-0.1, -0.15, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glScalef(0.7, 0.3, 0.7);
	glutWireCube(1.0); //발

	glPopMatrix(); //전역 좌표계 pop

	/* 오른쪽 다리 */
	glPushMatrix(); //전역 좌표계 push

	glTranslatef(0.3, -0.7, 0.0);
	glRotatef((GLfloat)rleg, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glPushMatrix(); //허벅지 기준 좌표계
	glScalef(0.5, 1.0, 0.5);
	glutWireCube(1.0); //허벅지

	glPopMatrix(); //허벅지 좌표계 pop
	glTranslatef(0.0, -0.4, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glPushMatrix(); //종아리 기준 좌표계
	glScalef(0.5, 0.9, 0.5);
	glutWireCube(1.0); //종아리

	glPopMatrix(); //종아리 좌표계 pop
	glTranslatef(0.1, -0.15, 0.0);
	glRotatef(0.0, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -0.5, 0.0);
	glScalef(0.7, 0.3, 0.7);
	glutWireCube(1.0); //발


	glPopMatrix(); //전역 좌표계 pop

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
	switch (key) { /* 팔 무빙 */
	case 'A': case 'a':
		lshoulder = (lshoulder + 5) % 360;
		break;
	case 'S': case 's':
		rshoulder = (rshoulder - 5) % 360;
		break; // a(왼), s(오): 어깨가 돌아감
	case 'D': case 'd':
		lelbow = (lelbow + 5) % 90;
		break;
	case 'F': case 'f':
		relbow = (relbow - 5) % 90;
		break; // d(왼), f(오): 팔꿈치가 돌아감
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void MyTimer(int Value) {
	lshoulder = 0;
	rshoulder = 0;
	lelbow = 0;
	relbow = 0;
	lleg = 0;
	rleg = 0;
	glutPostRedisplay();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_RIGHT_BUTTON) { /* 마우스 오른쪽 클릭 시 */
		glutTimerFunc(1000, MyTimer, 1);
		lshoulder = 320;
		rshoulder = 80;
		lelbow = 60;
		relbow = 280;
		lleg = 290;
		rleg = 30;
		glutPostRedisplay();
	}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
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
