
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>

using namespace std;
enum enPrimeNotPrime{prime=1,notprime=2};

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

enPrimeNotPrime CheckPrime(int number) {
	for (int m = 2; m <= number / 2; m++) {
		if (number % m == 0)
			return enPrimeNotPrime::notprime;
	}
	return enPrimeNotPrime::prime;
}
void FillElementsInArray2(int arr2[100],int &arraylength,int number) {
	arraylength++;
	arr2[arraylength - 1] = number;
}
void CopyPrimeNumbers(int arr1[100], int NumberOfElements, int arr2[100], int& arraylength) {
	for (int m = 0; m < NumberOfElements; m++) {
		if (CheckPrime(arr1[m]) == enPrimeNotPrime::prime)
			FillElementsInArray2(arr2, arraylength, arr1[m]);
	}

}
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int NumberOfElements = Read_PositiveNumber("Enter the number of element you want in the array: ");
	FillArray1WithRandomNumbers(arr1, NumberOfElements);
	cout << "Array 1 Elements:\n";
	Print_ArrayElements(arr1, NumberOfElements);

	int arr2[100];
	int arraylength = 0;
	CopyPrimeNumbers(arr1, NumberOfElements, arr2, arraylength);
	cout << "Array 2 Prime numbers:\n";
	Print_ArrayElements(arr2, arraylength);

}


