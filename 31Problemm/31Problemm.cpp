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
void FillArrayFrom1ToN(int arr[100], int arrLength) {
	for (int m = 0; m < arrLength; m++) {
		arr[m] = m+1;
	}
	cout << endl;
}
void Print_ArrayElements(int arr[100], int arrLength) {
	for (int m = 0; m < arrLength; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}

int RandomNumber(int from, int to) {
	int RandNumber = rand() % (to - from + 1) + from;
	return RandNumber;
}
void ShuffleArray(int arr[100],int arrLength) {
	
	int randomnumber;
	int counter = 0;

	arr[counter]= RandomNumber(1, arrLength);

	for  (counter = 1; counter < arrLength; counter++) {

		randomnumber = RandomNumber(1, arrLength);
		for (int m = 0; m < counter; m++) {
			if (randomnumber == arr[m]) {
				randomnumber = RandomNumber(1, arrLength);
				m = -1;
			}
				
		}
		arr[counter] = randomnumber;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int arrLength = Read_PositiveNumber("Enter the number of elements you want in Array: ");
	int arr[100];
	FillArrayFrom1ToN(arr, arrLength);

	cout << "Array elements Before shuffle:\n";
	Print_ArrayElements(arr, arrLength);
	ShuffleArray( arr,arrLength);
	cout << "Array elements After shuffle:\n";
	Print_ArrayElements(arr, arrLength);
}
