#pragma once
#include <iostream>
#include <string>
#include "InputUtil.h"
using namespace std;

class IOInterface {
protected:
	string m_name;
	int m_data;
public:
	IOInterface();
	IOInterface(string m_name);
	~IOInterface();

	void InputData() {
		cout << "학생이름: ";
		InputUtil::InputValue(m_name);
		cout << "data: ";
		InputUtil::InputValue(m_data);
		cout << "\n";
	};
	void PrintData() const {
		cout << "m_name: " << m_name << endl;
		cout << "m_data: " << m_data << endl;
	};
	void Modify() {
		int num;
		cout << "수정할 부분: m_name = 1, m_data = 2";
		InputUtil::InputValue(num);
		switch (num) {
		case 1:
			cout << "수정할 이름: ";
			InputUtil::InputValue(m_name);
			break;
		case 2:
			cout << "수정할 data: ";
			InputUtil::InputValue(m_data);
			break;
		default:
			cout << "잘못된 입력입니다.\n";
			break;
		}
	};
	string GetName() {
		return m_name;
	};
	int GetData() {
		return m_data;
	};
};

IOInterface::IOInterface() {
	cout << "IOInterface 기본 생성자 호출\n";
	this->m_name = "";
	this->m_data = 0;
	//생성자, 기본 초기화
};

IOInterface::IOInterface(string m_name) {
	cout << "IOInterface  인자있는 생성자 호출\n";
	//생성자, 인자의 값으로 m_name 초기화
	this->m_name = m_name;
	this->m_data = (rand() % 5 + 1) * 100;
};

IOInterface::~IOInterface() {
	cout << "IOInterface 소멸자 호출\n";
	//소멸자, 작업 x
};
