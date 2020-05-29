#pragma once
#include <iostream>
#include <string>
using namespace std;

class InputUtil {
public:
	inline static void InputValue(int& i) {
		do cin >> i;
		while (!CheckType());
	};
	inline static void InputValue(string& str) {
		getline(cin, str);
		/* string은 전부 문자열로 처리해버리기 때문에 웬만해선 버퍼에 값이 남지 않는다... */
	};
	inline static void InputValue(char *ch) {
		do cin >> ch;
		while (!CheckType());
	};
	inline static void InputValue(float &f) {
		do cin >> f;
		while (!CheckType());
	};
	inline static void InputValue(double &d) {
		do cin >> d;
		while (!CheckType());
	};
	static bool CheckType() { //변수의 자료형(타입) 체크하는 함수
		if (cin.fail()) {
			cout << "잘못된 값이 입력되었습니다." << endl; //에러 메시지 띄우고
			cin.clear(); //버퍼를
			cin.ignore(10, '\n'); //비워 준 다음에
			return false; //오류 반환
		}
		cin.clear(); //getline방식의 입력 가능성을 위해
		cin.ignore(10, '\n'); //버퍼를 비워 준 다음에
		return true; //정상값 반환
	};
};
