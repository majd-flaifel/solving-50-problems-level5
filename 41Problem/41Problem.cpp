
#include <iostream>
using namespace std;
void FillArray1(int arr1[100], short& arr1length) {
	arr1length = 6;
	arr1[0] = 10;
	arr1[1] = 20;
	arr1[2] = 30;
	arr1[3] = 30;
	arr1[4] = 20;
	arr1[5] = 10;
}
void Print_ArrayElements(int arr[100], short arrlength) {
	for (int m = 0; m < arrlength; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}

bool IsPalindromArray(int arr1[100], short arr1length) {
	int counter = arr1length - 1;
	for (int m = 0; m < arr1length; m++) {
		if (arr1[m] != arr1[counter])
			return false;
		else
			counter--;
	}
		return true;
}

int main()
{
	int arr1[100];
	short arr1length = 0;
	FillArray1(arr1, arr1length);
	cout << "Array 1 Elements:\n";
	Print_ArrayElements(arr1, arr1length);

	if (IsPalindromArray(arr1, arr1length))
		cout << "\nYes array is Palindrome\n";
	else
		cout << "\nNo array is NOT Palindrome\n";
}

