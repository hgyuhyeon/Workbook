/***************************************************/
/*            HW#3 : 3D 가스켓 프로그램            */
/*  작성자 : 황규현      날짜 : 2020년 10월 7일    */
/*                                                 */
/* 문제 정의 : 2D triangle Gasket을                */
/*             3D tetrahedron Gasket으로 변경      */
/***************************************************/
#include <GL/glut.h>
#include <stdlib.h> // rand() 함수 사용 용도
void MyInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); // 하얀배경으로 세팅
	glColor3f(1.0, 0.0, 0.0); // 빨간점으로 세팅
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 500, 0, 500, -1, 1);
}
void MyDisplay(void)
{
	float vertices[4][3] = { 
		{ 0.0, 250.0, 0.0 }, 
		{ 500.0, 250.0, 250.0 }, 
		{ 250.0, 500.0, 100.0 }, 
		{ 250.0, 100.0, 250.0 } /* 3차원이므로 점 1개 추가 */
	};
	// 초기 세모
	int i, j;
	float p[3] = { 250.0, 100.0, 250.0 };
	// 찍힐 포인트
	glClear(GL_COLOR_BUFFER_BIT);
	for (j = 0; j < 50000; j++)
	{
		i = rand() % 4; // 임의의 점 선택. 0-3의 값(3차원이므로)
		p[0] = (p[0] + vertices[i][0]) / 2.0;
		p[1] = (p[1] + vertices[i][1]) / 2.0;
		p[2] = (p[2] + vertices[i][2]) / 2.0;
		// 새로 선택된 좀과 현재 점을 기준으로 새로운 점 위치 계산( 중점의 위치 계산 )
		glBegin(GL_POINTS);
		glVertex3fv(p); // 찍힐 위치에 점 찍기
		/* 3차원이므로 glVertex2fv에서 glVertex3fv로 함수 변환 */
		glEnd();
	}
	glFlush();
}
void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500; //reshape 비율 측정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0 * Widthfactor, 500.0 * Widthfactor, 0.0 * 
		Heightfactor, 500.0 * Heightfactor, -500.0, 500.0); //그 비율대로 그래픽 재조정
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Sierpinski Gasket");
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	MyInit();
	glutMainLoop();
}
