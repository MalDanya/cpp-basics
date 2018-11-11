#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

template <size_t N, class Type>
void ReadArray(Type a[N][N], string name) {
	ifstream fin(name + ".txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fin >> a[i][j];
		}
	}
	fin.close();
}

template <size_t N, class Type>
void PrintArray(Type a[N][N]) {
	cout << "Array: " << endl;
	for (int i = 0; i < N; i++) {
		cout << "|";
		for (int j = 0; j < N; j++) {
			cout << setw(3) << a[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << endl << endl;
}

template <size_t N, class Type>
void CyclePush(Type a[N][N], int k) {
	Type b[N], c[N], d[N], e[N];
	for (int i = 0; i < k; i++)
	{
		for (int i = 0; i < N; i++)
		{
			b[i] = a[0][i];
			c[i] = a[N - i - 1][N - 1];
			d[i] = a[N - 1][i];
			e[i] = a[i][0];
		}
		for (int i = 0; i < N; i++)
		{
			a[0][N - i - 1] = e[i];
			a[i][N - 1] = b[i];
			a[N - 1][i] = c[i];
			a[i][0] = d[i];
		}
	}
}

template <class TypeAr>
void start(string name) {
	int const kCol = 3,
		kRow = 3;
	TypeAr a[kRow][kCol];
	ReadArray<kRow, TypeAr>(a, name);
	PrintArray<kRow, TypeAr>(a);

	cout << "Enter k(k>0): ";
	int k;
	cin >> k;
	cout << endl << "Result:\n\n";
	CyclePush<kRow, TypeAr>(a, k);
	PrintArray<kRow, TypeAr>(a);
}

int main() {
error:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	string select;
	cin >> select;
	if (select == "0") {
		start<int>("int");
	}
	else if (select == "1") {
		start<double>("double");
	}
	else if (select == "2") {
		start<float>("float");
	}
	else {
		cout << "Error input! (Only 0/1/2)" << endl;
		goto error;
	}
	return 0;
}