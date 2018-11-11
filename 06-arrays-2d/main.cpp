#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

template <size_t N, size_t M>
void ReadArray(int a[N][M], string name) {
	ifstream fin(name + ".txt");
	if (!fin.is_open()) {
		cout << "can't open file" << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			fin >> a[i][j];
		}
	}
	fin.close();
}

template <size_t N, size_t M>
void PrintArray(int a[N][M]) {
	cout << "Array: " << endl;
	for (int i = 0; i < N; i++) {
		cout << "|";
		for (int j = 0; j < M; j++) {
			cout << setw(3) << a[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << endl << endl;
}

template <size_t N>
void CyclePush(int a[N][N], int k) {
	int b[N], c[N], d[N], e[N];
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

int main() {
	int const kCol = 3,
		kRow = 3;
	int a[kRow][kCol];
	ReadArray<kRow, kCol>(a, "file");
	PrintArray<kRow, kCol>(a);

	cout << "Enter k(k>0): ";
	int k;
	cin >> k;
	cout << endl << "Result:\n\n";
	CyclePush<kCol>(a, k);
	PrintArray<kRow, kCol>(a);
	return 0;
}