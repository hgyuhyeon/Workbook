#include <iostream>
#include "Subject.h"
using namespace std;

void FSubject() {
	Subject sub1, sub2, sub3[2], * sub4;
	int i;
	sub1.Initialize();
	sub2.Initialize("사진학", 3, "A+");
	for (i = 0; i < 2; i++)
		sub3[i].Initialize("컴퓨터", 3, "C ");
	sub4 = new Subject[2];
	sub1.InputData(); // 화면에서 입력
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintTitle(); sub1.PrintData();
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintTitle(); sub2.PrintData();
	cout << "\n" << "sub3 정보" << "\n";
	sub3[0].PrintTitle();
	for (i = 0; i < 2; i++) sub3[i].PrintData();
	for (i = 0; i < 2; i++) (sub4 + i)->InputData();
	cout << "\n" << "sub4 정보" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++) (sub4 + i)->PrintData();
	delete[] sub4;
}
