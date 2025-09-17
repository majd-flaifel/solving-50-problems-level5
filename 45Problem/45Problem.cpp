#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>

using namespace std;
int Read_Number(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number <= 0 || number > 100);
	return number;
}
int RandomNumber(int from, int to) {
	int RandNumber = rand() % (to - from + 1) + from;
	return RandNumber;
}
void FillArray1WithRandomNumbers(int arr1[100], int NumberOfElements) {

	for (int m = 0; m < NumberOfElements; m++) {

		arr1[m] = RandomNumber(-100, 100);
	}

	cout << endl;

}
void Print_ArrayElements(int arr[100], int NumberOfElements) {
	for (int m = 0; m < NumberOfElements; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}

int NegativeCount(int arr1[100], int NumberOfElements) {
	int counter = 0;
	for (int m = 0; m < NumberOfElements; m++) {
		if (arr1[m] < 0) {
			counter++;
		}
	}
	return counter;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int NumberOfElements = Read_Number("Enter the number of element you want in the array: ");
	FillArray1WithRandomNumbers(arr1, NumberOfElements);
	cout << "Array 1 Elements: ";
	Print_ArrayElements(arr1, NumberOfElements);

	cout << "Negative Numbers Count is: " << NegativeCount(arr1, NumberOfElements); cout << endl;

}
