#include <iostream>
#include "Student.h"
#include "Subject.h"

void ShowData(const Student& s);

int main(void) {
	Subject sub[2];
	Student st;

	sub[0].Initialize("컴퓨터", 3, "C");
	sub[1].Initialize("현대무용", 2, "A");
	st.Initialize("홍길동", 2013909845, 2, sub);

	st.PrintData();
	ShowData(st);

	return 0;
}

void ShowData(const Student& s) {
	cout << s.m_name << "이 수강한 과목은 총 " << s.m_subnum << "개로 ";
	cout << "수강한 과목의 평균평점은" << s.m_aveGPA << "입니다.\n";
}
