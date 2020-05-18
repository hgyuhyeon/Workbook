#pragma once
#include <iostream>
#include <string>
#include "Subject.h"
using namespace std;

class Student {
protected:
	string m_name;
	int m_hakbun;
	int m_subnum;
	Subject* m_sub;
	float m_aveGPA;

public:
	void Initialize() { //멤버변수 초기화
		m_name = " ";
		m_hakbun = 0;
		m_subnum = 0;
		m_sub = NULL;
		m_aveGPA = 0.0f;
	};
	void Initialize(string stdname, int hakbun, int subnum, Subject* subject) { //인자값으로 멤버변수 초기화
		m_name = stdname;
		m_hakbun = hakbun;
		m_subnum = subnum;
		m_sub = subject;
		CalcAveGPA();
	};
	void Remove() { //동적메모리 해제(m_sub)
		delete[] m_sub;
	};
	void InputValue(int& i) {
		cin >> i;
		cin.clear();
		cin.ignore();
	};
	void InputValue(string& str) {
		getline(cin, str);
	};
	void InputData() { //멤버변수 값 입력
		cout << "\n\n* 학생 이름과 학번을 입력하세요. *\n";
		cout << "이름: ";
		InputValue(m_name);
		cout << "학번: ";
		InputValue(m_hakbun);
		cout << "\n\n수강한 과목 수 입력: ";
		InputValue(m_subnum); //과목r 개수를 입력받으면
		m_sub = new Subject[m_subnum]; //입력받은 과목 수 만큼 과목 구조체 배열 생성
		for (int i = 0; i < m_subnum; i++)
			m_sub[i].InputData(); //각 과목마다 값 입력받기
		CalcAveGPA(); //개인 학생의 평점 평균 계산
	};
	void PrintData() { //멤버변수 값 충력
		cout << "=====================================================\n";
		cout << " 이름: " << m_name << "          학번: " << m_hakbun << endl;
		m_sub->PrintTitle(); //과목정보 타이틀
		for (int i = 0; i < m_subnum; i++)
			(m_sub + i)->PrintData(); //과목정보 출력
		cout << "-----------------------------------------------------\n";
		cout << "                            평균평점: " << m_aveGPA << endl;
	};
	void CalcAveGPA() { //평균 평점 계산
		float AveGPA = 0;
		for (int i = 0; i < m_subnum; i++)
			AveGPA += m_sub[i].GetGPA();
		m_aveGPA = AveGPA / 3;
	};
	friend void ShowData(const Student& s);
};
