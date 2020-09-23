#include <stdlib.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
int MyListID; //DisplayList는 정수 ID에 의해 식별
GLUquadricObj* qobj = gluNewQuadric(); // 새로운 Quadric 생성

// Display List 생성
void MyCreateList() {
	MyListID = glGenLists(1); // DisplayList 선언
	// 아이디를 가진 리스트 1개를 새로 만들되,
	// 실행하지 않고 컴파일 완료된 버전을 만든다.
	glNewList(MyListID, GL_COMPILE);
	gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정
	gluQuadricNormals(qobj, GLU_SMOOTH); // 법선벡터 제어
	gluQuadricOrientation(qobj, GLU_OUTSIDE); // 법선벡터 내부 및 외부 등과 같은 방향 지정
	gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
	//gluSphere(qobj, 1.0, 10, 10); // Sphere 생성
	//gluCylinder(qobj, 1.0, 0.0, 2.0, 20, 8);
	//gluDisk(qobj, 0.5, 2.0, 20, 3);
	gluPartialDisk(qobj, 0.0, 1.0, 26, 13, 270, 120);
	glEndList();
}

//조명 설정
void MyInit(void) {
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 }; //주변광
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 }; //반사광
	GLfloat mat_shininess[] = { 50.0 }; //선명도
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 }; //조명 위치
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH); // 각 정점에 정한 색상을 보간하여 혼합하여 칠하게 설정
	glViewport(0, 0, 600, 600);
	glCallList(MyListID); // 컴파일이 완료된 리스트가 실제로 실행
	glutSwapBuffers();
}

void Reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Example Drawing");
	//glClearColor(1.0, 1.0, 1.0, 1.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, -1.0);
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Reshape);
	MyCreateList(); // Display List 생성
	glutMainLoop();
	return 0;
}
