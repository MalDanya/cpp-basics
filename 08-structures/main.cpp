#include <iostream>
#include <string>
#include <iomanip>

#define kNotes 3
#define kDate 3

using namespace std;

struct Note {
	string name, surname;
	string phone_number;
	int date[kDate] = { 0,0,0 };
};

void DateConvert(string s, int *a) {
	string buf;
	for (int i = 0; i < 3; i++)
	{
		buf = s[3 * i + 1];
		a[i] = atoi(buf.c_str());
		buf = s[3 * i];
		a[i] += atoi(buf.c_str()) * 10;
	}
}

bool IsDigit(char s) {
	if (((s >= '0') && (s <= '9')))
	{
		return true;
	}
	else {
		return false;
	}
}

bool IsDate(string s) {
	bool result = true;
	if (!(s.length() == 8))
		result = false;

	if (!((s[2] == '.') && (s[5] == '.')))
		result = false;

	for (int i = 0; i < 8; i += 3)
	{
		if (!IsDigit(s[i]))
			if (!IsDigit(s[i + 1])) {
				result = false;
				cout << "False date";
			}
	}
	return result;
}

bool IsPhoneNumber(string s) {
	bool result = true;
	if (s.length() > 4)
		if (s[0] = '+') {
			for (int i = 1; i < int(s.length()); i++)
			{
				if (!((s[i] >= '0') && (s[i] <= '9')))
					result = false;
			}
		}
		else
		result = false;
	return result;
}

void AddNotes(Note *a) {
	for (int i = 0; i < kNotes; i++) {
		cout << i + 1 << ". Input the name and surname (e.g., Ivan Ivanov): ";
		cin >> a[i].name >> a[i].surname;
		cin.ignore();

	wrong_number:
		cout << "Input phone number(e.g., +799999999999):";
		string s;
		cin >> s;
		if (!IsPhoneNumber(s))
		{
			cout << "Invalid number!" << endl;
			goto wrong_number;
		}
		a[i].phone_number = s;
		cin.ignore();

	wrong_input:
		cout << "Input date of born(e.g., 01.01.99):";
		cin >> s;
		if (!IsDate(s))
		{
			cout << "Invalid date of born!" << endl;
			goto wrong_input;
		}
		cout << endl;
		DateConvert(s, a[i].date);
	}
	cout << endl;
}

void PrintNotes(Note *a) {
	for (int i = 0; i < kNotes; i++) {
		cout << i + 1 << ". " << a[i].name << endl;
	}
	cout << endl;
}

bool MinNumber(string s1, string s2) {
	bool result = true;
	s1.erase(0, 1);
	s2.erase(0, 1);
	int a = atoi(s1.c_str());
	int b = atoi(s2.c_str());
	if (b > a) {
		result = false;
	}
	return result;
}

void SortNotes(Note *a) {
	for (int i = 0; i < kNotes - 1; i++) {
		for (int j = 0; j < kNotes - i - 1; j++) {
			if ((MinNumber(a[i].phone_number, a[i + 1].phone_number))) {
				swap(a[i], a[i + 1]);
			}
		}
	}
}

void FindSurname(Note *a, string surn) {
	bool find = false;
	for (int i = 0; i < kNotes; i++)
	{
		if (surn == a[i].surname) {
			find = true;
			cout << a[i].name;
			cout << " " << a[i].surname;
			cout << " " << a[i].phone_number << " ";
			for (int j = 0; j < kDate; j++)
			{
				if (j < 2) {
					cout << a[i].date[j];
					cout << ".";
				}
				else {
					cout << a[i].date[j];
				}

			}

		}
	}
	if (!find)
	{
		cout << "there is no person with that surname!";
		cout << endl;
	}
}

int main() {
	Note N[kNotes];
	AddNotes(N);

	SortNotes(N);
	PrintNotes(N);
	cout << endl << endl;

	cout << "Enter surname to find -> ";
	string surn;
	cin >> surn;
	cout << endl;
	FindSurname(N, surn);
	cout << endl;
	return 0;
}