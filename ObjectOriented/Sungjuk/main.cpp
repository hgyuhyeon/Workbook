#include <iostream>
#include "Student.h"
#include "Subject.h"
#include "IOInterface.h"
#include "GradeManager.h"

int main() {
	
	int stdnum;
	cout << "입력할 학생 수를 입력 : ";
	InputUtil::InputValue(stdnum);
	cout << endl;
	GradeManager GradeMgr(stdnum);
	GradeMgr.Execute();

	return 0;
}
