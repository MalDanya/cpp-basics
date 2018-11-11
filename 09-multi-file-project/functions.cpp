#include "functions.h"

void PrintArray(int array[], int size) {
	cout << string(61, '-') << endl;
	cout << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(2) << "[" << i << "]" << setw(2) << "|";
	}

	cout << "<- Index";
	cout << endl << string(61, '-') << endl << "|";

	for (int i = 0; i < size; i++) {
		cout << setw(3) << array[i] << setw(3) << "|";
	}

	cout << "<- array[i]";
	cout << endl;
	cout << string(61, '-') << endl;
	cout << endl;
}

void SortArray(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (abs(array[j]) > abs(array[j + 1])) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}

int Zeroes(int a[], int size) {
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] == 0)
		{
			result++;
		}
	}
	return result;
}

int SumAfterMax(int a[], int size, int max_modulo) {
	int result = 0;
	for (int i = max_modulo; i < size; i++)
	{
		result += a[i];
	}
	return result;
}