#include <iostream>
#include "Student.h"
#include "Subject.h"

void ShowData(const Student& s);

int main(void) {
	Subject sub1("컴퓨터", 3, "C");
	Subject sub2(sub1);
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintData();
	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintData();
	sub2.Modify();
	//Student st1;
	Student st2("홍길동", 2013909845, 1, &sub1);
	Student st3("김성령", 2015909845, 1, &sub2);
	//st1 = st2;
	Student st1(st2); //(+)
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData();
	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData();
	st2.Modify();
	cout << "\n" << "수정된 st2 정보" << "\n";
	st2.PrintData();
	st1.PrintData();
	cout << "\n" << "st3 정보" << "\n";
	st3.PrintData();

	return 0;
}

void ShowData(const Student& s) {
	cout << s.m_name << "이 수강한 과목은 총 " << s.m_subnum << "개로 ";
	cout << "수강한 과목의 평균평점은" << s.m_aveGPA << "입니다.\n";
}
