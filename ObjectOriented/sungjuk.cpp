#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

#define WIDTH 10 //정보 출력 시 줄간격
using namespace std;

struct Subject { //과목 정보
	string SubName; //과목이름
	int Hakjum; //과목학점
	string Grade; //과목등급
	float GPA; //과목평점
};

struct Student { //학생 정보
	string StdName; //학생이름
	int Hakbun; //학번
	Subject* Sub; //과목
	int SubNum; //과목 수
	float AveGPA; //교과목 평균 평점
};


/* ****함수들**** */

//메뉴 출력
inline void PrintMenu() {
	cout << "----- 메뉴 -----\n";
	cout << "1. 학생 성적 입력\n";
	cout << "2. 전체 학생 성적 보기\n";
	cout << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n";
	cout << "5. 학생 정보 수정\n";
	cout << "6. 프로그램 종료\n\n";
	cout << "원하는 기능을 입력하세요 : ";
}

//교과목의 평점 계산
float CalcGPA(struct Subject& Sub) {
	float grade = 0;

	//평점 변환
	if (Sub.Grade =="A+" || Sub.Grade == "A" || Sub.Grade == "A0") {
		grade += 4;
		if (Sub.Grade == "A+") {
			grade += 0.5;
		}
	}
	else if (Sub.Grade == "B+" || Sub.Grade == "B" || Sub.Grade == "B0") {
		grade += 3;
		if (Sub.Grade == "B+") {
			grade += 0.5;
		}
	}
	else if (Sub.Grade == "C+" || Sub.Grade == "C" || Sub.Grade == "C0") {
		grade += 2;
		if (Sub.Grade == "C+") {
			grade += 0.5;
		}
	}
	else if (Sub.Grade == "D+" || Sub.Grade == "D" || Sub.Grade == "D0") {
		grade += 1;
		if (Sub.Grade == "D+") {
			grade += 0.5;
		}
	}
	else {
		return grade;
	}

	//변환한 학점으로 평점내서 저장(리턴)
	grade *= Sub.Hakjum;
	return grade;
}

//개인 학생의 평균 평점 계산(AveGPA)
float CalcAveGPA(Subject* Sub) {
	float AveGPA = 0;
	for (int i = 0; i < 3; i++)
		AveGPA += (Sub + i)->GPA;

	return AveGPA / 3;
}
 
//버퍼 초기화 함수 (요구사항은 x)
void InitializeInput() {
	cin.clear();
	cin.ignore();
}

//이름, 과목명, 과목 등급 입력
inline string InputValue(string str) {
	getline(cin, str);
	return str;
}

//메뉴번호, 전체학생 수, 과목 수, 학번, 학점 입력
inline void InputValue(int& i) {
	cin >> i;
	InitializeInput();
}

//학생 정보 입력(요구사항은 x)
void inputStudentinfo(Student* Std) {
	cout << "이름: ";
	Std->StdName = InputValue(Std->StdName);
	cout << "학번: ";
	InputValue(Std->Hakbun);
}

//과목 정보 입력(요구사항은 x)
void inputSubjectinfo(Subject* Sub) {
	cout << "교과목명: ";
	Sub->SubName = InputValue(Sub->SubName); //정보 수정 시 중복을 막기 위해 초기화 x
	cout << "과목학점수: ";
	InputValue(Sub->Hakjum);
	cout << "과목등급(A+ ~ F): ";	
	Sub->Grade = InputValue(Sub->Grade);
	Sub->GPA = CalcGPA(*Sub); //평점 계산 후 구조체에 포함
	cout << "\n";
}

//전체학생 신상 정보 및 성적 정보 입력 -> 메뉴 1번
void InputData(Student* pSt, int StudentNum) {
	for (int i = 0; i < StudentNum; i++) {
		cout << "\n\n* " << i + 1 << "번째 학생 이름과 학번을 입력하세요. *\n";
		inputStudentinfo(&pSt[i]); //학생 정보 입력받는 함수
		cout << "\n\n수강한 과목 수 입력: ";
		InputValue((pSt + i)->SubNum); //과목을 입력받으면
		(pSt + i)->Sub = new Subject[(pSt + i)->SubNum]; //입력받은 과목 수 만큼 과목 구조체 배열 생성

		cout << "\n\n* 수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		for (int j = 0; j < (pSt + i)->SubNum; j++) {
			inputSubjectinfo(&(pSt[i].Sub[j])); //과목 입력받는 함수
		}
		(pSt + i)->AveGPA = CalcAveGPA((pSt + i)->Sub); //입력받은 과목들을 종합하여 전체 평점 계산
	}
}

//전체학생 목록(학번, 이름) 출력
void PrintAllStdList(Student* pSt, int StudentNum) {
	cout << "\n\n  전체 학생 목록 보기\n";
	cout << "=================================\n";
	cout << "        학번     이름\n";
	cout << "=================================\n";

	for (int i = 0; i < StudentNum; i++) {
		cout.width(12);
		cout << (pSt + i)->Hakbun << "  ";
		cout.width(7);
		cout << (pSt + i)->StdName << "\n";
	}
	cout << "\n";
}

//개인학생 정보 출력
void PrintOnedata(const Student& rSt) {
	cout << fixed;
	cout.precision(2);

	cout << "이름: " << rSt.StdName << "   학번: " << rSt.Hakbun << "\n";
	cout << "===========================================================\n";
	cout << "		과목명   과목학점   과목등급  과목평점\n";
	cout << "===========================================================\n";
	//과목출력
	for (int i = 0; i < rSt.SubNum; i++) {
		cout.width(22);
		cout << (rSt.Sub + i)->SubName;
		cout.width(WIDTH);
		cout << (rSt.Sub + i)->Hakjum;
		cout.width(WIDTH);
		cout << (rSt.Sub + i)->Grade;
		cout.width(WIDTH);
		cout << (rSt.Sub + i)->GPA << "\n";
	}
	cout << "===========================================================\n";
	cout.width(48);
	cout << "평균평점      " << rSt.AveGPA << "\n";
}

//전체학생 정보(학번, 이름, 과목별 성적) 출력
void PrintAllData(const Student* pSt, int studentnum) {
	for (int i = 0; i < studentnum; i++)
		PrintOnedata(pSt[i]);
}

//학생 이름 검색 & 학생정보가 있는 곳의 주소 리턴
Student* StdSearch(Student* pSt, int studentnum) {
	string student;

	cout << "\n\n검색할 학생 이름: ";
	student = InputValue(student);

	int i;

	for (i = 0; i < studentnum; i++) {
		if (pSt[i].StdName == student) { //student(입력값)과 pSt 속 학생정보 일치
			return (pSt + i);
		}
	}
	return NULL;
}

Subject* SubSearch(const Student* pSt) {
	string subject;

	cout << "\n\n검색할 과목 이름: ";
	subject = InputValue(subject);

	int i;

	for (i = 0; i < pSt->SubNum; i++) {
		if (pSt->Sub[i].SubName == subject) {
			return (&(pSt->Sub[i]));
		}
	}
	return NULL;
}

//특정 학생의 이름, 학번, 교과목 정보 수정
void ModifyStdInfo(Student* pSt, int studentnum) {
	string Types;
	Student* student = StdSearch(pSt, studentnum); //원하는 학생 정보 찾기
	if (student != NULL) {
		cout << "수정(학생정보/과목정보): ";
		Types = InputValue(Types); //Type에 학생정보or과목정보 입력받기

		if ("학생정보" == Types) { //학생정보이면
			cout << "* (" << student->StdName << ", " << student->Hakbun << ")의 정보를 수정하세요\n";
			inputStudentinfo(student); //학생정보 수정
		}
		else if ("과목정보" == Types) { //과목정보이면
			Subject* subject = SubSearch(student); //원하는 과목 정보 찾기
			if (subject != NULL) {
				cout << "* (" << subject->SubName << ", " << subject->Hakjum << ", " << subject->Grade << ")의 정보를 수정하세요\n";
				inputSubjectinfo(subject); //과목정보 수정
				student->AveGPA = CalcAveGPA(student->Sub); //전체 평점 재계산
			}
			else
				cout << "검색결과가 없습니다.\n";
		}
		else { //기타 오타등 다른 문자면
			cout << "잘못된 입력입니다.\n";
		}
	} 
	else
		cout << "검색결과가 없습니다.\n";
}

int main(void) {
	//메뉴 표시
	int menunum, studentnum; //메뉴 번호, 전체 학생 수

	//학생정보 입력
	Student* Std; //학생정보를 저장하기 위한 구조체 배열 선언
	cout << "전체 학생 수 입력: ";
	InputValue(studentnum);
	Std = new Student[studentnum];

	while (1) {

		PrintMenu();
		InputValue(menunum); //메뉴 입력

		switch (menunum) {
		case 1:
			InputData(Std, studentnum);
			break;

		case 2:
			cout << "\n\n			전체 학생 성적 보기\n";
			cout << "===========================================================\n";

			PrintAllData(Std, studentnum);
			break;

		case 3:
			Student * SearchStd;
			SearchStd = StdSearch(Std, studentnum);

			if (SearchStd != NULL)
				PrintOnedata(*SearchStd);
			else
				cout << "검색결과가 없습니다.\n";
			break;

		case 4:
			PrintAllStdList(Std, studentnum);
			break;

		case 5:
			ModifyStdInfo(Std, studentnum);
			break;

		default:
			cout << "프로그램을 종료합니다.";
			for (int i = 0; i < studentnum; i++)
				delete[](Std + i)->Sub;
			delete[] Std;
			return 0;
		}
	}
}
