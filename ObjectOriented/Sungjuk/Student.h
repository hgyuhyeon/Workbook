#pragma once
#include <iostream>
#include <string>
#include "Subject.h"
#include "InputUtil.h"
using namespace std;

class Student {
protected:
	string m_name;
	int m_hakbun;
	int m_subnum;
	Subject *m_sub;
	float m_aveGPA;

public:
	Student(); //멤버변수 초기화
	Student(string stdname, int hakbun, int subnum, Subject* subject);//인자값으로 멤버변수 초기화
	Student(const Student& std); //다른 Student클래스의 멤버변수 값으로 초기화
	~Student();

	void InputData() { //멤버변수 값 입력
		cout << "\n\n* 학생 이름과 학번을 입력하세요. *\n";
		cout << "이름: ";
		InputUtil::InputValue(m_name);
		cout << "학번: ";
		InputUtil::InputValue(m_hakbun);
		cout << "\n\n수강한 과목 수 입력: ";
		InputUtil::InputValue(m_subnum); //과목r 개수를 입력받으면
		m_sub = new Subject[m_subnum]; //입력받은 과목 수 만큼 과목 구조체 배열 생성
		cout << "\n\n* 수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (int i = 0; i < m_subnum; i++)
			m_sub[i].InputData(); //각 과목마다 값 입력받기
		CalcAveGPA(); //개인 학생의 평점 평균 계산
	};
	void PrintData() const { //멤버변수 값 충력
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
		m_aveGPA = AveGPA / m_subnum;
		//m_aveGPA = AveGPA / 3;
	};
	Subject* SubSearch(string subinfo) { //과목 탐색
		for (int index = 0; index < m_subnum; index++)
			if (m_sub[index].GetName() == subinfo) //해당 과목을 찾아서
				return &m_sub[index]; //그 과목의 주소 리턴

		cout << "일치하는 교과목이 없습니다.\n";
		return NULL;
	};
	void Modify() { //학생정보 수정
		string info;
		cout << "\n\n* 수정할 학생의 정보를 입력하세요.\n";
		cout << "이름, 학번: 학생정보\n과목이름, 학점, 평점: 과목정보\n전체:모두\n";
		InputUtil::InputValue(info);
		if (info == "학생정보") {
			cout << "\n\n* 수정할 학생의 이름, 학번을 입력하세요.\n";
			cout << "이름: ";
			InputUtil::InputValue(m_name); //정보 수정 시 중복을 막기 위해 초기화 x
			cout << "학번: ";
			InputUtil::InputValue(m_hakbun);
			CalcAveGPA(); //평점 계산 후 구조체에 포함
			cout << "\n";
		}
		else if (info == "과목정보") {
			string subinfo;
			cout << "\n* 수정할 과목의 이름을 입력하세요.\n";
			InputUtil::InputValue(subinfo); //과목 이름을 입력받고
			Subject* targetsub = SubSearch(subinfo); //과목 서치
			if (targetsub != NULL) { //targetsub에 수정할 과목정보가 들어있으면
				targetsub->Modify(); //그 과목정보를 수정
				CalcAveGPA();
			}
		}
		else if (info == "모두") {
			cout << "이름: ";
			InputUtil::InputValue(m_name);
			cout << "학번: ";
			InputUtil::InputValue(m_hakbun);
			for (int i = 0; i < m_subnum; i++)
				m_sub[i].InputData(); //각 과목마다 값 재입력받기
			CalcAveGPA(); //개인 학생의 평점 평균 계산
		}
		else
			cout << "잘못된 입력입니다.\n";
	}

	//접근자 함수
	string GetName() const {
		return m_name;
	};
	int GetHakbun() const {
		return m_hakbun;
	};
	int GetSubNum() const {
		return m_subnum;
	};
	float GetAveGPA() const {
		return m_aveGPA;
	};
};

Student::Student() { //멤버변수 초기화
	cout << "* 학생 생성자 호출 *";
	m_name = " ";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0f;
};

Student::Student(string stdname, int hakbun, int subnum, Subject* subject) { //인자값으로 멤버변수 초기화
	cout << "* 학생 생성자 호출 *\n";
	m_name = stdname;
	m_hakbun = hakbun;
	m_subnum = subnum;
	this->m_sub = new Subject[subnum];
	for (int i = 0; i < subnum; i++)
		this->m_sub[i] = Subject((subject+i)->GetName(), (subject+i)->GetHakjum(), (subject+i)->GetGrade());
	CalcAveGPA();
};

Student::Student(const Student& std) { //다른 Student클래스의 멤버변수 값으로 초기화
	cout << "* 학생 생성자 호출 *\n";
	this->m_name = std.m_name;
	this->m_hakbun = std.m_hakbun;
	this->m_subnum = std.m_subnum;
	this->m_sub = new Subject[std.m_subnum]; //동일한 과목 수 만큼 과목 구조체 배열 생성
	*(this->m_sub) = *(std.m_sub);
	CalcAveGPA();
};

Student::~Student() { //소멸자, sub에 할당된 메모리 해제(Remove 함수 대체)
	cout << "* 소멸자 호출 *\n";
	if(m_sub)
		delete[] m_sub;
};
