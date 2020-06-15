#pragma once
#include <iostream>
#include <string>
#include "InputUtil.h"
using namespace std;

class IOInterface {
public:

	virtual void InputData() = 0;
	virtual void PrintData() const = 0;
	virtual void Modify() = 0;


	virtual ~IOInterface() {
		cout << "IOInterface 소멸자 호출\n";
		//소멸자, 작업 x
	};
};
