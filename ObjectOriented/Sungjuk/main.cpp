#include <iostream>
#include "Student.h"
#include "Subject.h"

void main() {
	Subject sub1[2] = { Subject("컴퓨터", 3, "C"), Subject("현대무용", 2, "A") }; 
	Subject* sub2[2] = { new Subject(), new Subject("수학", 3, "C") }; 
	Student st1; 
	Student st2("홍길동", 2013909845, 2, sub1); 
	Student* st3 = new Student[2];

	cout << "\n" << "sub2[0] 입력" << "\n"; 
	sub2[0]->InputData();    
	cout << "\n" << "st1 입력" << "\n"; 
	st1.InputData();    
	cout << "\n" << "st3 입력" << "\n"; 
	for (int i = 0; i < 2; i++)   
		(st3 + i)->InputData();

	cout << "\n" << "sub1 정보 출력" << "\n"; 
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++)   
		sub1[i].PrintData(); 
	cout << "\n" << "sub2 정보 출력" << "\n"; 
	Subject::PrintTitle(); 
	for (int i = 0; i < 2; i++)   
		sub2[i]->PrintData(); 
	cout << "\n" << "st1 정보 출력" << "\n"; 
	st1.PrintData();    
	cout << "\n" << "st2 정보 출력" << "\n"; 
	st2.PrintData(); 
	cout << "\n" << "st3 정보 출력" << "\n"; 
	for (int i = 0; i < 2; i++)   
		(st3 + i)->PrintData();
}
