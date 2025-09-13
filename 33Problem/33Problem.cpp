
#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for using std::string.
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for time() to seed the random generator.

enum enCharType { SmallLetter = 1, CapitalLetter, SpecialChar, Digit };
using namespace std;

int Read_NumberOfKeys(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number <= 0);
	return number;
}
int RandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
char GenerateChar(enCharType CharType) {

	switch (CharType) {
	case enCharType::SmallLetter:
		return char(RandomNumber(97, 122));
	case enCharType::CapitalLetter:
		return char(RandomNumber(65, 90));
	case enCharType::SpecialChar:
		return char(RandomNumber(32, 47));
	case enCharType::Digit:
		return char(RandomNumber(48, 57));
	}
}
string GenerateWord(enCharType CharType, short length) {
	string word = "";
	for (int i = 1; i <= length; i++) {
		word += GenerateChar(CharType);

	}

	return word;
}

string GenerateKey(short length ) {
	string key = "";
	for (int i = 1; i <= length; i++) {
			if (i < length)
				key += GenerateWord(enCharType::CapitalLetter, 4) + "-";
			else
				key += GenerateWord(enCharType::CapitalLetter, 4);
		}
	return key;
}

void FillArrayWithKeys(short NumberOfKeys, string arr[100]) {

	for (int i = 0; i < NumberOfKeys; i++) {
		arr[i] = GenerateKey(4);
	}
}
void Print_StringArray(string arr[100], short NumberOfKeys) {
	cout << "Array Elements:\n\n";
	for (int i = 0; i < NumberOfKeys; i++) {
		cout << "Array[" << i << "]: "<<arr[i];
		cout << endl;
	}

}
int main()
{
	srand((unsigned)time(NULL));
	string arr[100];
	short NumberOfKeys = Read_NumberOfKeys("Please Enter how many keys to generate: ");
	cout << endl;
	FillArrayWithKeys(NumberOfKeys,arr);
	Print_StringArray(arr, NumberOfKeys);
}
