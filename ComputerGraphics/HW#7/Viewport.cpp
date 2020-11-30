/***************************************************/
/*   HW#7 : 계층적 모델링, 시점변환                */
/*  작성자 : 황규현      날짜 : 2020년 10월 28일   */
/*                                                 */
/* 문제 정의 : 뷰폿 분할 응용                      */
/*                                                 */
/* 키보드 제어                                     */
/* 좌하단, a: 왼쪽,  s: 아래쪽, d: 오른쪽, w: 위쪽 */
/* z값) +: c, -: x , x초점) +: r, -:e              */
/* 우상단, j: 왼쪽, k: 아래쪽, l: 오른쪽, i: 위쪽  */
/* z값) +: m, -: n, x초점) +: u, -: y              */
/*                                                 */
/* 마우스 제어                                     */
/* 좌클릭: 빨강색으로 변환                         */
/* 우클릭: 파랑색으로 변환                         */
/***************************************************/
#include <gl/glut.h>
int Width, Height;
float pox1 = 0, poy1 = 0, poz1 = 1, pox2 = 0, poy2 = 0, poz2 = 5;
float focx1 = 0, focx2 = 0;
float cr = 0.3, cb = 0.7;

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void DrawScene() {
	glColor3f(0.7, 0.7, 0.7);
	glPushMatrix();
	glTranslatef(0.0, -1.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(2.0, 0.0, 2.0);
	glVertex3f(2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, -2.0);
	glVertex3f(-2.0, 0.0, 2.0);
	glEnd();
	glPopMatrix();
	glColor3f(cr, 0.3, cb);
	glPushMatrix();
	glTranslatef(0.0, 0.0, -0.5);
	glutWireTeapot(1.0);
	glPopMatrix();
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	// 좌하단 뷰폿
	glViewport(0, 0, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-7.6, 4, -2.7, 3, -10, 20);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(pox1, poy1, poz1, focx1, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	// 우상단 뷰폿
	glViewport(Width / 2, Height / 2, Width / 2, Height / 2);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(20, 1.3, 3.0, 50);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(pox2, poy2, poz2, focx2, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glFlush();
}

void MyReshape(int w, int h) {
	int result = (w < h) ? w : h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 500.0 * result, 0.0, 500.0 * result, -1.0, 1.0);
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': exit(0); break;
	case 'q': exit(0); break;
	case 'A': case 'a': pox1 -= 0.1; break;
	case 'D': case 'd': pox1 += 0.1; break;
	case 'S': case 's': poy1 -= 0.1; break;
	case 'W': case 'w': poy1 += 0.1; break; 
	case 'X': case 'x': poz1 -= 0.1; break;
	case 'C': case 'c': poz1 += 0.1; break;
	case 'E': case 'e': focx1 -= 0.1; break;
	case 'R': case 'r': focx1 += 0.1; break;

		/* 좌하단, a: 왼쪽,  s: 아래쪽, d: 오른쪽, w: 위쪽
		   z값) +: c, -: x , x초점) +: r, -:e */

	case 'J': case 'j': pox2 -= 0.1; break;
	case 'L': case 'l': pox2 += 0.1; break;
	case 'K': case 'k': poy2 -= 0.1; break;
	case 'I': case 'i': poy2 += 0.1; break;
	case 'N': case 'n': poz2 -= 0.1; break;
	case 'M': case 'm': poz2 += 0.1; break;
	case 'Y': case 'y': focx2 -= 0.1; break;
	case 'U': case 'u': focx2 += 0.1; break;

		/* 우상단, j: 왼쪽, k: 아래쪽, l: 오른쪽, i: 위쪽 
		   z값) +: m, -: n, x초점) +: u, -: y */

	case 27: exit(0); break;
	}
	glutPostRedisplay();
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON) {/* 마우스 왼쪽 클릭 시 */
		cr = 0.7;
		cb = 0.3;
	}
	if (Button == GLUT_RIGHT_BUTTON) { /* 마우스 오른쪽 클릭 시 */
		cr = 0.3;
		cb = 0.7;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	Width = 500;
	Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Viewpory Partition");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}
