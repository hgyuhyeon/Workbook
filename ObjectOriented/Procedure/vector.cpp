#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct WORD {
	string str; //각 단어의 내용
	int count; //각 단어의 사용 빈도
};

vector<WORD*> words;

int CountWords(string buffer);
void PrintWords();
void RemoveAll();

int main(void) {

	cout << "문자열 입력(종료: Ctrl+Z)\n";
	string buffer;
	
	while (cin >> buffer) {
		if (buffer == "^Z")
			break;
		CountWords(buffer);
	}

	PrintWords();
	RemoveAll();

	return 0;
}

int CountWords(string buffer) {

	int i = 0;
	WORD* temp;
	temp = new WORD;
	temp->str = buffer;
	temp->count = 1;

	while (i<words.size()) {
		if (words.empty())
			break;
		if (words[i]->str == temp->str) {
			++words[i]->count;
			delete temp;
			return 1;
		}
		i++;
	}
	words.push_back(temp);
	return 0;
}

void PrintWords() {
	cout << "=====\n";
	for (int i = 0; i < words.size(); i++) {
		cout << words[i]->str << " : " << words[i]->count << "\n";
	}
	cout << "=====\n";
}

void RemoveAll() {
	for (int i = 0; i < words.size(); i++)
		delete words[i];
}
