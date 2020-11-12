/***************************************************/
/*   HW#5 : 계층적 모델링, 시점변환                */
/*  작성자 : 황규현      날짜 : 2020년 10월 28일   */
/*                                                 */
/* 문제 정의 : gluLookAt()의 실시간 제어           */
/*                                                 */
/***************************************************/
#include <gl/glut.h>
GLdouble posx = -1.0, posy = 0.5, posz = 3.5; //Position
GLdouble focx = 0, focy = 0, focz = 0; //Focus

void DrawGround() {
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_LINES);
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}
	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(posx, posy, posz, focx, focy, focz, 0.0, 1.0, 0.0);
	DrawGround();
	glColor3f(1.0, 1.0, 0.0);
	glutWireTeapot(1.0);
	glFlush();
}
void MyReshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'A': case 'a': focx += 0.1; break;
	case 'F': case 'f': focx -= 0.1; break;
	case 'R': case 'r': focy += 0.1; break;
	case 'V': case 'v': focy -= 0.1; break;
	case 'Z': case 'z': focz += 0.1; break;
	case 'T': case 't': focz -= 0.1; break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		posx -= 0.1;
		break;
	case GLUT_KEY_RIGHT:
		posx += 0.1;
		break;
	case GLUT_KEY_UP:
		posy += 0.1;
		break;
	case GLUT_KEY_DOWN:
		posy -= 0.1;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("VCS (View Coordinate System)");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}
