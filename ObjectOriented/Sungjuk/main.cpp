#include <iostream>
#include "Student.h"
#include "Subject.h"
#include "IOInterface.h"

int main() {
	
	Subject sub("컴퓨터", 3, "C");
	cout << "-----------------------------\n";
	//IOInterface Class에서 상속받은 GetData() 호출;
	cout << "m_data: " << sub.GetData() << endl;
	//Subject Class에서 재정의된 GetName() 호츨;
	cout << "교과목 이름: " << sub.GetName() << endl;
	//IOInterface Class의 GetName() 호출;
	cout << "부모클래스의 이름: " << sub.IOInterface::GetName() << endl;
	cout << "-----------------------------\n\n";
	Student std("홍길동", 2013909845, 1, &sub);
	cout << "-----------------------------\n";
	//IOInterface Class에서 상속받은 GetData() 호출;
	cout << "m_data: " << std.GetData() << endl;
	//Student Class에서 재정의된 GetName() 호츨;
	cout << "학생 이름: " << std.GetName() << endl;
	//IOInterface Class의 GetName() 호출;
	cout << "부모클래스의 이름: " << std.IOInterface::GetName() << endl;
	cout << "-----------------------------\n\n";

	return 0;
}
