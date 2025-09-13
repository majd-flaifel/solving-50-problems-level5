
#include <iostream>
using namespace std;
void FillArray1(int arr1[100],short &arr1length) {
	arr1length = 15;
	 arr1[0] = 10;
	 arr1[1] = 10;
	 arr1[2] = 10;
	 arr1[3] = 50;
	 arr1[4] = 50;
	 arr1[5] = 70;
	 arr1[6] = 70;
	 arr1[7] = 70;
	 arr1[8] = 70;
	 arr1[9] = 90;
	 arr1[10] = 100;
	 arr1[11] = 100;
	 arr1[12] = 100;
	 arr1[13] = 120;
	 arr1[14] = 500;

}
void Print_ArrayElements(int arr[100], short arrlength) {
	for (int m = 0; m < arrlength; m++) {
		cout << arr[m] << " ";
	}
	cout << endl << endl;
}

void FillElementsInArray2(int arr2[100], short &arr2length,int number) {
	arr2length++;
	arr2[arr2length - 1] = number;

 }
bool CheckNumber(int arr2[100], short arr2length,int number) {

	for (int m = 0; m < arr2length; m++) {
		if (arr2[m] == number)
			return true;
	}
	return false;
}
void CopyDistinctNumbersToArray(int arr2[100], short &arr2length, int arr1[100], short arr1length) {

	for (int m = 0; m < arr1length; m++) {
		if (!(CheckNumber(arr2, arr2length, arr1[m])))
			FillElementsInArray2(arr2, arr2length, arr1[m]);
	}
}
int main()
{
	int arr1[100];
	short arr1length = 0;
	FillArray1(arr1,arr1length);
	cout << "Array 1 Elements:\n";
	Print_ArrayElements(arr1, arr1length);

	int arr2[100];
	short arr2length = 0;
	CopyDistinctNumbersToArray(arr2, arr2length, arr1, arr1length);
	cout << "Array 2 distinct Elements:\n";
	Print_ArrayElements(arr2, arr2length);
}

