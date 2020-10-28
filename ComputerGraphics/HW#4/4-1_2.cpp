/***************************************************/
/*   HW#4 : Callback 프로그래밍  - 키보드콜백(1)   */
/*  작성자 : 황규현      날짜 : 2020년 10월 14일   */
/*                                                 */
/* 문제 정의 : Keyboard Callback 응용1, 2          */
/*                                                 */
/***************************************************/
#include <GL/glut.h>
float tx = 0, ty = 0, tr = 0.5, tg = 0.5, tb = 0.5, zoom = 1;
/* tx, ty = 물체 이동 시 좌표값 
   tr, tg, tb = 물체 색상 변경 시 색상값 
   zoom = 물체 확대/축소 시 확댓값
*/

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(tr, tg, tb);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + tx, -0.5 + ty, 0.0);
	glVertex3f(0.5 + tx, -0.5 + ty, 0.0);
	glVertex3f(0.5 + tx, 0.5 + ty, 0.0);
	glVertex3f(-0.5 + tx, 0.5 + ty, 0.0); /* 변환된 좌표로 ReDisplay */
	glEnd();
	glFlush();
}
void MyKeyboard(unsigned char key, int x, int y) { /* HW#1 - 설정한 키를 누르면 이동 */
	switch (key) {
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 'A': case 'a': if (tx <= 0.5 && tx > -0.5) tx -= 0.1; break;
	case 'F': case 'f': if (tx < 0.4 && tx >= -0.5) tx += 0.1; break;
	case 'R': case 'r': if (ty <= 0.5 && ty > -0.5) ty -= 0.1; tr = 1.0; tg = 0.0; tb = 0.0; break;
	case 'V': case 'v': if (ty < 0.4 && ty >= -0.5) ty += 0.1; break; /* Windows 화면을 벗어나지 않도록 조건 */
	case 'b': tr = 0.0, tg = 0.0, tb = 1.0; break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();
}
void MySpecial(int key, int x, int y) { /* HW#2 - 특수 키보드로 이동, 줌인/아웃 */
	switch (key) {
	case GLUT_KEY_LEFT:
		if (tx <= 0.5 && tx > -0.5) tx -= 0.1;
		break;
	case GLUT_KEY_RIGHT:
		if (tx < 0.4 && tx >= -0.5) tx += 0.1;
		break;
	case GLUT_KEY_UP:
		if (ty < 0.4 && ty >= -0.5) ty += 0.1;
		break;
	case GLUT_KEY_DOWN:
		if (ty <= 0.5 && ty > -0.5) ty -= 0.1; /* Windows 화면을 벗어나지 않도록 조건 */
		break;
	case GLUT_KEY_PAGE_UP:
		if (zoom >= 0.5 && zoom < 2) zoom *= 2;
		glScalef(zoom, zoom, 0.0);
		break;
	case GLUT_KEY_PAGE_DOWN:
		if (zoom > 0.5 && zoom <= 2) zoom /= 2; /* 물체가 사라져버리거나, Windows 화면을 최대한 벗어나지 않도록 조건 */
		glScalef(zoom, zoom, 0.0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}
