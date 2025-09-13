
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
using namespace std;
int Read_PositiveNumber(string message) {
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
		arr1[m] = RandomNumber(1, 100);
	}
	cout << endl;
}
void Print_ArrayElements(int arr[100], int NumberOfElements) {
	for (int m = 0; m < NumberOfElements; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}

void CopyArrayInReverOrder(int arr1[100], int arr2[100], int NumberOfElements) {
	for (int i = 0; i < NumberOfElements; i++) {
		arr2[i] = arr1[NumberOfElements - 1 - i];
	}

}
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arr2[100];
	int NumberOfElements = Read_PositiveNumber("Enter the number of element you want in the array: ");
	FillArray1WithRandomNumbers(arr1, NumberOfElements);
	CopyArrayInReverOrder(arr1, arr2, NumberOfElements);

	cout << "Array 1 Elements:\n";
	Print_ArrayElements(arr1, NumberOfElements);
	cout << "Array 1 Elements reversed:\n";
	Print_ArrayElements(arr2, NumberOfElements);

}

