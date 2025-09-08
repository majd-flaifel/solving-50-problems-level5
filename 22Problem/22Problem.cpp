
#include <iostream>
using namespace std;
int Read_PositiveNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number <= 0);
	return number;
}
void Read_Array(int number, int arr[100]) {

	cout << "Enter Array Elements:\n";
	for (int m = 0; m < number; m++) {
		cout << "Element[" << m+1 << "]: ";
		cin >> arr[m];
	}
	}
void Print_ArrayElement(int number, int arr[100]) {
	
	cout << "Original array: ";
	for (int m = 0; m < number; m++) {
		
		cout << arr[m]<<" ";
	}
	cout << endl;
}
int TimesReapeted(int number,int arr[100],int NumberToCheck) {
	int counter = 0;
	for (int m = 0; m < number; m++) {
		if (arr[m] == NumberToCheck)
			counter++;
	}
	return counter;
}
int main()
{
	int arr[100];

	int NumberOfElements = Read_PositiveNumber("Enter the number of element you want in the array: ");
	Read_Array(NumberOfElements,arr);
	int NumberToCheck = Read_PositiveNumber("Enter the number you want to check in array: ");
	cout << "\n\n";
	Print_ArrayElement(NumberOfElements,arr);
	cout << NumberToCheck << " is repeated " << TimesReapeted(NumberOfElements,arr,NumberToCheck) << " Time(s)\n";



}

