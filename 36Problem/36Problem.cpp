

#include <iostream>
using namespace std;
int Read_Number() {
	int number;
	
		cout << "Please enter a number? ";
		cin >> number;
	
	return number;
}
void FillArray(int arr[100], int &arraylength,int number) {
	arraylength++;
	arr[arraylength - 1] = number;
}

void AddNumbersOrNot(int arr[100], int& arraylength) {
	bool addmorenumbers;
	do {
		FillArray(arr, arraylength, Read_Number());
		cout << "Do you want to add more numbers?[0]:No,[1]:Yes?";
		cin >> addmorenumbers;
	} while (addmorenumbers);
	
	
}
void Print_ArrayElements(int arr[100],  int arraylength) {
	for (int m = 0; m < arraylength; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}

int main()
{
	int arr[100];
	int arraylength=0;
	AddNumbersOrNot(arr, arraylength);

	cout << "\n\nArray length: " << arraylength << endl;
	cout << "Array Elements: ";
	Print_ArrayElements(arr, arraylength);
}

