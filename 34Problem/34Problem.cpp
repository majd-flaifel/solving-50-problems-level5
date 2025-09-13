
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

short FindnumberpositionInArray(int NumberToSearch, int NumberOfElements,int arr1[100]) {

	for (int m = 0; m < NumberOfElements; m++) {
		if (arr1[m] == NumberToSearch) {
			return m;
		}
	}
	return -1;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int NumberOfElements = Read_PositiveNumber("Enter the number of element you want in the array: ");
	FillArray1WithRandomNumbers(arr1, NumberOfElements);
	cout << "Array 1 Elements:\n";
	Print_ArrayElements(arr1, NumberOfElements);

	int NumberToSearch= Read_PositiveNumber("Please Enter a number to search for: ");
	cout << "The number you are searching for is: " << NumberToSearch << endl;

	short numberposition= FindnumberpositionInArray( NumberToSearch, NumberOfElements, arr1);
	if (numberposition==-1) {
		cout << "The number is not found: -(\n";
	}
	else {
		cout << "The number found at position: " << numberposition << endl;
		cout << "The number found its order: " << numberposition + 1 << endl;
	}
	}
	
