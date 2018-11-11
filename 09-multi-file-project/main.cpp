#include "functions.h"

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