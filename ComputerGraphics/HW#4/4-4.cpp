/***************************************************/
/*   HW#4 : Callback 프로그래밍  - 키보드콜백(1)   */
/*  작성자 : 황규현      날짜 : 2020년 10월 14일   */
/*                                                 */
/* 문제 정의 : Menu Callback 응용                  */
/*                                                 */
/***************************************************/
#include <GL/glut.h>

GLboolean IsSmall = true;
GLint shape = 1, color = 1;
/* shape
   1 = Sphere, 2 = Torus, 3 = Teapot
   color
   1 = red, 2 = green, 3 = blue */

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    switch (color) { /* 색 지정 */
    case 1:
        glColor3f(0.5, 0.0, 0.0);
        break;
    case 2:
        glColor3f(0.0, 0.5, 0.0);
        break;
    case 3:
        glColor3f(0.0, 0.0, 0.5);
        break;
    }

    switch (shape) { /* 그릴 모형 지정 */
    case 1:
        if(IsSmall)
            glutWireSphere(0.5, 30, 30);
        else
            glutWireSphere(0.7, 30, 30);
        break;
    case 2:
        if(IsSmall)
            glutWireTorus(0.1, 0.3, 40, 20);
        else
            glutWireTorus(0.2, 0.5, 40, 20);
        break;
    case 3:
        if (IsSmall)
            glutWireTeapot(0.3);
        else
            glutWireTeapot(0.5);
        break;
    }
    glFlush();
}

void MyMainMenu(int entryID) {
    if (entryID == 1)
        exit(0);

    glutPostRedisplay();
}

void MySphereMenu(int entryID) {
    shape = 1;
    if (entryID == 1)            IsSmall = true;
    else if (entryID == 2)      IsSmall = false;

    glutPostRedisplay();
}
void MyTorusMenu(int entryID) {
    shape = 2;
    if (entryID == 1)            IsSmall = true;
    else if (entryID == 2)      IsSmall = false;

    glutPostRedisplay();
}
void MyTeapotMenu(int entryID) {
    shape = 3;
    if (entryID == 1)            IsSmall = true;
    else if (entryID == 2)      IsSmall = false;

    glutPostRedisplay();
}

void MyColorMenu(int entryID) {
    if (entryID == 1) color = 1;
    else if (entryID == 2) color = 2;
    else if (entryID == 3) color = 3;

    glutPostRedisplay();
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    GLint MySphereID = glutCreateMenu(MySphereMenu);
    glutAddMenuEntry("Small Sphere", 1);
    glutAddMenuEntry("Large Sphere", 2);

    GLint MyTorusID = glutCreateMenu(MyTorusMenu);
    glutAddMenuEntry("Small Torus", 1);
    glutAddMenuEntry("Large Torus", 2);

    GLint MyTeapotID = glutCreateMenu(MyTeapotMenu);
    glutAddMenuEntry("Small Teapot", 1);
    glutAddMenuEntry("Large Teapot", 2);

    GLint MyColorID = glutCreateMenu(MyColorMenu);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Green", 2);
    glutAddMenuEntry("Blue", 3);

    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddSubMenu("Draw Sphere", MySphereID);
    glutAddSubMenu("Draw Torus", MyTorusID);
    glutAddSubMenu("Draw Teapot", MyTeapotID);
    glutAddSubMenu("Change Color", MyColorID);
    glutAddMenuEntry("Exit", 1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Menu Callback");
    MyInit();
    glutDisplayFunc(MyDisplay);

    glutMainLoop();
    return 0;
}
