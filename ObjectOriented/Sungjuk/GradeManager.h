#pragma once
#include <iostream>
#include <string>
#include "Student.h"
#include "InputUtil.h"
using namespace std;

class GradeManager {
protected:
	Student* m_std; //전체 학생 정보를 담고 있는 객체
	int m_stdnum; //관리하고 있는 전체 학생수

public:
	GradeManager();
	GradeManager(int m_stdnum);
	~GradeManager();

	void Execute() { //학생 성적을 관리하는 함수
		int menunum = 0;

		while (menunum != 6) {
			PrintMenu();
			InputUtil::InputValue(menunum);

			switch (menunum) {
			case 1: //학생 성적 입력, Student class의 InputData()
				for (int i = 0; i < m_stdnum; i++) {
					m_std[i].InputData();
				}
				break;

			case 2: //전체 성적 보기, Student class의 PrintData();
				for (int i = 0; i < m_stdnum; i++) {
					m_std[i].PrintData();
				}
				break;

			case 3: {//학생 검색
				string stdname;
				cout << "검색할 학생 이름 입력: ";
				InputUtil::InputValue(stdname); //학생 이름을 받고
				Student* std = StdSearch(stdname); //학생정보 찾기
				if (std != NULL) //학생 정보가 있으면
					std->PrintData(); //정보 출력
				break;
			}

			case 4: //학생 목록 보기
				PrintAllStdList();
				break;

			case 5: //학생 정보 수정
				Modify();
				break;

			case 6: //프로그램 종료
				break;

			default: //예외 처리
				cout << "잘못된 입력" << endl;
				break;
			}
		}
	};
protected:
	static void PrintMenu() { //메뉴 출력
		cout << endl;
		cout << "===== 메뉴 =====" << endl;
		cout << "1. 학생 성적 입력" << endl;
		cout << "2. 전체 성적 보기" << endl;
		cout << "3. 학생 검색" << endl;
		cout << "4. 학생 목록 보기" << endl;
		cout << "5. 학생 정보 수정" << endl;
		cout << "6. 프로그램 종료" << endl;
		cout << endl;

		cout << "원하는 기능을 입력하세요(번호입력) : ";
	};
	Student* StdSearch(string stdname) const { //원하는 학생 검색
		for (int index = 0; index < m_stdnum; index++)
			if (m_std[index].GetName() == stdname) //해당 학생을 찾아서
				return &m_std[index]; //그 학생의 메모리 주소 리턴

		cout << "해당하는 학생이 없습니다.\n";
		return NULL;
	};
	void PrintAllStdList() const { //전체 학생 목록 출력
		cout << "===============================" << endl;
		cout.width(11);
		cout << "이름";
		cout.width(17);
		cout << "학번" << endl;
		for (int i = 0; i < m_stdnum; i++) {
			cout.width(12);
			cout << m_std[i].GetName();
			cout.width(18);
			cout << m_std[i].GetHakbun() << endl;
		}
	};
	void Modify() { //원하는 학생의 정보 수정
		string stdname;
		cout << "수정할 학생의 이름을 입력하세요: ";
		InputUtil::InputValue(stdname);
		Student* std = StdSearch(stdname);
		if (std != NULL) {
			std->Modify();
		}
	};
};

GradeManager::GradeManager() {
	cout << "* 관리 생성자 호출 *\n";
	m_std = NULL;
	m_stdnum = 0;
};
GradeManager::GradeManager(int m_stdnum) {
	cout << "* 관리 생성자 호출 *\n";
	m_std = new Student[m_stdnum]; //학생 수만큼 메모리 할당
	this->m_stdnum = m_stdnum;
};
GradeManager::~GradeManager() {
	cout << "* 관리 소멸자 호출 *\n";
	delete[] m_std; //할당된 메모리 해제
};
