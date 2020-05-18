#include <iostream>
#include "Student.h"
#include "Subject.h"

void Fstudent() {
	Subject sub[2];
	sub[0].Initialize("컴퓨터", 3, "C");
	sub[1].Initialize("현대무용", 2, "A");
	Student st1, st2;
	st1.Initialize();
	st2.Initialize("홍길동", 2013909845, 2, sub);
	st1.InputData();
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();
	st1.Remove();
}
