

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int Read_PositiveNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number <= 0);
	return number;
}
int RandomNumber(int from,int to) {
	int RandNumber = rand() % (to - from + 1) + from;
	return RandNumber;
}
void FillArrayWithRandomNumbers(int arr[100],int NumberOfElements) {
	for (int m = 0; m < NumberOfElements; m++) {
		arr[m] = RandomNumber(1, 100);
	}
}
void Print_ArrayElements(int arr[100], int NumberOfElements) {
	cout << "Array Elements: ";
	for (int m = 0; m < NumberOfElements; m++) {
		cout << arr[m] << " ";
	}
	cout << endl;
}
int main()
{
	srand((unsigned)time(NULL));
    int arr[100];
	int NumberOfElements = Read_PositiveNumber("Enter the number of element you want in the array: ");
	FillArrayWithRandomNumbers(arr, NumberOfElements);
	Print_ArrayElements(arr, NumberOfElements);

}
