
#include <iostream>
#include <cstdlib>
#include <ctime>

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
void FillArray1WithRandomNumbers(int arr1[100], int arr1Length) {
	for (int m = 0; m < arr1Length; m++) {
		arr1[m] = RandomNumber(1, 100);
	}
	cout << endl;
}
void Print_ArrayElements(int arr[100], int LengthOfArray) {
	for (int m = 0; m < LengthOfArray; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}


enPrimeNotPrime CheckPrime(int arr1Length) {
	int M = round(arr1Length / 2);
	for (int m = 2; m <=M ; m++) {
		if (arr1Length % m == 0)
			return enPrimeNotPrime::notprime;
	}
	return enPrimeNotPrime::prime;
}
void FillArray2WithPrimeNumbers(int arr2[100], int arr1[100],int arr1Length, int & arr2Length) {
	int counter = 0;
	for (int m = 0; m < arr1Length; m++) {
		if (CheckPrime(arr1[m])== enPrimeNotPrime::prime) {
			arr2[counter] = arr1[m];
			counter++;
		}
	}
	arr2Length=counter;
}

int main()
{
	srand((unsigned)time(NULL));
	int arr1[100];
	int arr1Length = Read_PositiveNumber("Enter the number of element you want in the array: ");
	FillArray1WithRandomNumbers(arr1, arr1Length);
	cout << "Array 1 Elements:\n";
	Print_ArrayElements(arr1, arr1Length);

	int arr2[100];
	int arr2Length;
	FillArray2WithPrimeNumbers(arr2, arr1, arr1Length, arr2Length);
	cout << "Prime Numbers in Array 2 :\n";
	Print_ArrayElements(arr2, arr2Length);

}