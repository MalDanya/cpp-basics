#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string Replace(char s) {
	string result = " ";
	switch (s) {
	case '0':
		result = "zero";
		break;
	case '1':
		result = "one";
		break;
	case '2':
		result = "two";
		break;
	case '3':
		result = "three";
		break;
	case '4':
		result = "four";
		break;
	case '5':
		result = "five";
		break;
	case '6':
		result = "six";
		break;
	case '7':
		result = "seven";
		break;
	case '8':
		result = "eight";
		break;
	case '9':
		result = "nine";
		break;
	}
	return result;
}

int main() {
	string file_name;

	cout << "Write  file name (default name 'file') -> ";
	cin >> file_name;
	file_name += ".txt";
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