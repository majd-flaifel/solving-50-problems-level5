
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
		arr[m] = m + 1;
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
void Swap(int &A, int &B) {

	int Temp = A;
	A = B;
	B = Temp;

}
void ShuffleArray(int arr[100], int arrLength) {

	for (int m = 0; m < arrLength-1; m++) {

		int FirstIndex = RandomNumber(0, arrLength-1) ;
		int SecondIndex = RandomNumber(0, arrLength-1) ;

		Swap(arr[FirstIndex], arr[SecondIndex]);
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
	ShuffleArray(arr, arrLength);
	cout << "Array elements After shuffle:\n";
	Print_ArrayElements(arr, arrLength);
}
