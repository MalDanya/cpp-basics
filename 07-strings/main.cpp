#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string Replace(char s) {
	string TranslatedNumber = " ";
	switch (s) {
	case '0':
		TranslatedNumber = "zero";
		break;
	case '1':
		TranslatedNumber = "one";
		break;
	case '2':
		TranslatedNumber = "two";
		break;
	case '3':
		TranslatedNumber = "three";
		break;
	case '4':
		TranslatedNumber = "four";
		break;
	case '5':
		TranslatedNumber = "five";
		break;
	case '6':
		TranslatedNumber = "six";
		break;
	case '7':
		TranslatedNumber = "seven";
		break;
	case '8':
		TranslatedNumber = "eight";
		break;
	case '9':
		TranslatedNumber = "nine";
		break;
	}
	return TranslatedNumber;
}

int main() {
	string file_name;

	cout << "Write  file name (default name 'file.txt') -> ";
	cin >> file_name;
	/*file_name += ".txt";*/
	ifstream fin(file_name);

	if (!fin.is_open()) {
		cout << "can't open file!" << endl;
		return 1;
	}

	char s;
	while (!fin.eof()) {
		fin.get(s);
		if ((s <= '9') && (s >= '0')) {
			cout << Replace(s);
		}
		else
			cout << s;
	}

	fin.close();
	return 0;
}