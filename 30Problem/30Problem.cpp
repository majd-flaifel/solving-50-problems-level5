
#include <iostream>
#include <cstdlib>
#include <ctime>

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
void FillArraysWithRandomNumbers(int arr[100], int arrLength) {
	for (int m = 0; m < arrLength; m++) {
		arr[m] = RandomNumber(1, 100);
	}
	cout << endl;
}
void Print_ArrayElements(int arr[100], int arrLength) {
	for (int m = 0; m < arrLength; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}
void SumOfTwoArrays(int arrSum[100], int arr1[100], int arr2[100], int arrLength) {
	for (int m = 0; m < arrLength; m++) {
		arrSum[m] = arr1[m] + arr2[m];
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arr2[100];
	int arrLength = Read_PositiveNumber("Enter the number of elements you want in each Array: ");
	FillArraysWithRandomNumbers(arr1, arrLength);
	FillArraysWithRandomNumbers(arr2, arrLength);

	cout << "Array 1 elements:\n";
	Print_ArrayElements(arr1, arrLength);
	cout << "Array 2 elements:\n";
	Print_ArrayElements(arr2, arrLength);

	int arrSum[100];
	SumOfTwoArrays(arrSum, arr1, arr2, arrLength);
	cout << "Sum of array1 and array2 elements:\n";
	Print_ArrayElements(arrSum, arrLength);

}
