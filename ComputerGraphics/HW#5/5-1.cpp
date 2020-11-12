/***************************************************/
/*   HW#5 : 계층적 모델링, 시점변환                */
/*  작성자 : 황규현      날짜 : 2020년 10월 28일   */
/*                                                 */
/* 문제 정의 : 계층구조 모델링 - 태양계            */
/*                                                 */
/***************************************************/
#include <gl/glut.h>
static int mDay = 0, mTime = 0, vDay = 0, vTime = 0, eDay = 0, eTime = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0, 0.3, 0.3);
	glutWireSphere(0.2, 20, 16); //태양
		glPushMatrix(); 
		glRotatef((GLfloat)mDay, 0.0, 1.0, 0.0); 
		glTranslatef(0.2, 0.0, 0.0); 
		glRotatef((GLfloat)mTime, 0.0, 1.0, 0.0); 
		glColor3f(0.3, 0.8, 0.4);
	glutWireSphere(0.07, 10, 8); //수성
		glPopMatrix();
		glPushMatrix();
		glRotatef((GLfloat)vDay, 0.0, 1.0, 0.0);
		glTranslatef(0.4, 0.0, 0.0);
		glRotatef((GLfloat)vTime, 0.0, 1.0, 0.0);
		glColor3f(0.8, 0.5, 0.2);
	glutWireSphere(0.08, 10, 8); //금성
		glPopMatrix();
		glPushMatrix();
		glRotatef((GLfloat)eDay, 0.0, 1.0, 0.0);
		glTranslatef(0.7, 0.0, 0.0);
		glRotatef((GLfloat)eTime, 0.0, 1.0, 0.0);
		glColor3f(0.3, 0.8, 0.9);
	glutWireSphere(0.1, 10, 8); //지구
		glPushMatrix(); 
		glRotatef((GLfloat)eTime, 0.0, 1.0, 0.0); 
		glTranslatef(0.2, 0.0, 0.0); 
		glColor3f(0.9, 0.5, 0.9);
	glutWireSphere(0.04, 10, 8); //달
	glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}
void MyTimer(int Value) {
	mDay = (mDay + 20) % 360;
	vDay = (vDay + 15) % 360;
	eDay = (eDay + 10) % 360;
	mTime = (mTime + 3) % 360;
	vTime = (vTime + 4) % 360;
	eTime = (eTime + 5) % 360; //각 행성별로 다르게 움직이도록 수정
	glutPostRedisplay();	
	glutTimerFunc(100, MyTimer, 1);
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON) /* 마우스 왼쪽 클릭 시 */
		glutTimerFunc(100, MyTimer, 1);
	if (Button == GLUT_RIGHT_BUTTON) /* 마우스 오른쪽 클릭 시 */
		system("pause");
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}
