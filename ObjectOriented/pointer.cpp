#include <iostream>
#include <Windows.h>
using namespace std;

void textcolor(int text, int background) {
	int color = text + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main(void) {

	int M[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int(*ptr)[3]; int* p; int** pt;

	ptr = M; //배열 M을 가리키는 포인터 배열
	textcolor(9, 0);
	cout << "ptr = M\n";
	textcolor(15, 0);
	cout << "ptr = " << ptr << "\tM = " << M << "\n"; //배열과 배열 포인터의 주소가 같아짐(가리켰기 때문에)
	cout << "ptr + 1 = " << ptr + 1 << "\tM + 1 = " << M + 1 << "\n"; //배열의 두 번째 행의 주소값과 배열 포인터의 두 번째 행의 주소값이 동일함
	cout << "*(ptr + 1) = " << *(ptr + 1) << "\tptr[1] = " << ptr[1] << "\t*(M + 1) = " << *(M + 1) << "\tM[1] = " << M[1] << "\n"; //배열 포인터가 가리키는 항목의 주소값과 배열 포인터의 두 번째 행의 주소값이 동일하며, 이는 배열의 두 번째 행, 첫 번째 항목의 주소값과 동일하다.
	cout << "**(ptr + 1) = " << **(ptr + 1) << "\t**(M + 1)" << **(M + 1) << "\t*M[1] = " << *M[1] << "\tM[1][0] = " << M[1][0] << "\n"; //배열 포인터를 두 번 참조했을 때 항목값을 알 수 있으며, 배열에 포인터를 지정할 경우 해당하는 행의 첫 번째 항목을 표시한다.

	p = M[0]; //포인터 p가 배열 M의 첫 번째 줄을 가리킨다.
	textcolor(9, 0);
	cout << "\np = M[0]\n";
	textcolor(15, 0);
	cout << "p = " << p << "\tM[0] = " << M[0] << "\t*M = " << *M << "\n"; //포인터 p와 배열M의 첫번째 줄의 주소, 배열 M의 주소값이 같아졌다.
	cout << "p + 1 = " << p + 1 << "\tM[0] = " << M[0] + 1 << "\t*M + 1 = " << *M + 1 << "\n"; //1을 증가시켰더니 주소값이 4 증가했고, 이는 첫 번째 줄의 두 번째 항목을 가리킨다.
	cout << "*(p + 1) = " << *(p + 1) << "\t*(M[0] + 1) = " << *(M[0] + 1) << "\t*(*M + 1) = " << *(*M + 1) << "\n"; //항목값을 체크한 결과 2가 나왔다. 전줄의 M[0][1]을 가리킨다는 것이 증명되었다.

	pt = &p; // 이중 포인터 pt가 포인터 p를 가리킨다.
	textcolor(9, 0);
	cout << "\npt = &p\n";
	textcolor(15, 0);
	cout << "*pt = " << *pt << "\tp = " << p << "\n"; //포인터 pt가 가리키는 주소값과 p가 가리키는 주소값이 동일하다.
	cout << "**pt = " << **pt << "\t*p = " << *p << "\n"; //포인터 pt가 가리키는 주소값의 항목값과 p가 가리키는 주소값의 항목값이 동일하다.

	cout << "\n2019038071 황규현";
	return 0;
}
