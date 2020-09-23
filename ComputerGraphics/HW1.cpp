#include <iostream>
#include <gl/glut.h>
using namespace std;

void Points() { //a
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	//점 2개
	glVertex3f(-0.5, 0.0, 0.0); //v1
	glVertex3f(0.5, 0.0, 0.0); //v2
	glEnd();
	glFlush();
}

void Lines() { //b
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	//점 2개를 이은 선
	glVertex3f(-0.5, 0.0, 0.0); //v1
	glVertex3f(0.5, 0.0, 0.0); //v2
	glEnd();
	glFlush();
}

void LineStrip() { //c
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	//직사각형의 네 점과 그 점들을 연결
	glVertex3f(-0.5, 0.0, 0.0); //v1
	glVertex3f(-0.5, -0.5, 0.0); //v2
	glVertex3f(0.5, -0.5, 0.0); //v3
	glVertex3f(0.5, 0.0, 0.0); //v4
	glEnd();
	glFlush();
}

void LineLoop() { //d
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
	//직사각형의 네 점을 전부 연결(loop)
	glVertex3f(-0.5, 0.0, 0.0); 
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glEnd();
	glFlush();

}

void TriangleFan() { //e
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
	//맨위의 점을 기준으로 삼각형을 제작
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(0.7, 0.2, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.3, 0.8, 0.0);
	glVertex3f(0.14, 0.95, 0.0);
	glEnd();
	glFlush();
}

void Triangles() { //f
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	//점 3개를 이은 삼각형
	glVertex3f(-0.3, 0.0, 0.0);
	glVertex3f(0.3, 0.0, 0.0);
	glVertex3f(0.5, 0.7, 0.0);
	glEnd();
	glFlush();
}

void TriangleStrip() { //g
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_STRIP);
	//점들을 이어 삼각형형태를 만들음
	glVertex3f(0.9, -0.3, 0.0);
	glVertex3f(0.7, 0.6, 0.0);
	glVertex3f(0.6, 0.0, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.3, -0.1, 0.0);
	glVertex3f(0.04, 0.2, 0.0);
	glVertex3f(-0.1, 0.0, 0.0);
	glEnd();
	glFlush();
}

void Polygons() { //h
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	//육각형 만들기
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(-1.0, 0.5, 0.0);
	glVertex3f(-1.0, -0.5, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(1.0, -0.5, 0.0);
	glVertex3f(1.0, 0.5, 0.0);
	glEnd();
	glFlush();
}

void Quads() { //i
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	//사각형 만들기
	glVertex3f(0.8, 0.0, 0.0);
	glVertex3f(1.0, 0.5, 0.0);
	glVertex3f(0.5, 0.7, 0.0);
	glVertex3f(0.2, 0.0, 0.0);

	glVertex3f(-0.3, 0.5, 0.0);
	glVertex3f(-0.3, 0.86, 0.0);
	glVertex3f(-0.6, 0.78, 0.0);
	glVertex3f(-0.65, 0.66, 0.0);
	glEnd();
	glFlush();
}

void QuadStrip() { //j
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUAD_STRIP);
	//점을 이어서 사각형들의 모임을 만들음
	glVertex3f(0.8, 0.0, 0.0);
	glVertex3f(1.0, 0.5, 0.0);
	glVertex3f(0.2, 0.0, 0.0);
	glVertex3f(0.5, 0.7, 0.0);

	glVertex3f(-0.3, 0.5, 0.0);
	glVertex3f(-0.3, 0.86, 0.0);
	glVertex3f(-0.65, 0.66, 0.0);
	glVertex3f(-0.6, 0.78, 0.0);

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {

	char command;

	/* 지정된 명령어를 각각 입력하면 
	   구현해둔 함수들이 실행되면서 
	   해당 도형이 그려진 그래픽 화면을 디스플레이한다
	   배경은 흰색, 점과 선 색은 검은색으로 설정 */
	cout << "Points: a  Lines: b  LineStrip: c  LineLoop: d" << endl;
	cout << "TriangleFan: e  Triangles: f  TriangleStrip: g" << endl;
	cout << "Polygons: h  Quads: i  Quadstrip: j" << endl;
	cout << "명령어 입력: ";
	cin >> command;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Primitives");
	switch (command) {
	case 'a':
		glutDisplayFunc(Points);
		break;
	case 'b':
		glutDisplayFunc(Lines);
		break;
	case 'c':
		glutDisplayFunc(LineStrip);
		break;
	case 'd':
		glutDisplayFunc(LineLoop);
		break;
	case 'e':
		glutDisplayFunc(TriangleFan);
		break;
	case 'f':
		glutDisplayFunc(Triangles);
		break;
	case 'g':
		glutDisplayFunc(TriangleStrip);
		break;
	case 'h':
		glutDisplayFunc(Polygons);
		break;
	case 'i':
		glutDisplayFunc(Quads);
		break;
	case 'j':
		glutDisplayFunc(QuadStrip);
		break;
	default:
		break;
	}
	glutMainLoop();
	return 0;
}
