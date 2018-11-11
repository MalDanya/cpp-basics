#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

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

int main() {
	int const kArraySize = 10;
	int array[kArraySize],
		max_modulo = 0;

	srand((unsigned)time(NULL));

	//generation array
	for (int i = 0; i < kArraySize; i++) {
		array[i] = int(pow(-1, rand() % 2))*(rand() % 10); //[-9..9]
		if (abs(array[i]) > max_modulo)
			max_modulo = i;
	}
	cout << "Starting Array :" << endl;
	PrintArray(array, kArraySize);

	cout << "Number of zero elements: ";
	cout << Zeroes(array, kArraySize);
	cout << endl << endl;

	cout << "Sum of elements after max modulo element = ";
	if (max_modulo < kArraySize)
	{
		cout << SumAfterMax(array, kArraySize, max_modulo);
		cout << endl << endl;
	}
	else {
		cout << "Error: max modulo element is last";
		cout << endl << endl;
	}
	cout << "Sorted Array :" << endl;
	SortArray(array, kArraySize);
	PrintArray(array, kArraySize);

	return 0;
}