
#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for using std::string.
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for time() to seed the random generator.

enum enCharType{SmallLetter=1,CapitalLetter,SpecialChar,Digit};
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
	case enCharType::SmallLetter :
		return char(RandomNumber(97, 122));
	case enCharType::CapitalLetter :
		return char(RandomNumber(65, 90));
	case enCharType::SpecialChar :
		return char(RandomNumber(32, 47));
	case enCharType::Digit :
		return char(RandomNumber(48, 57));
	}
}
string GenerateWord() {
	string word = "";
	word+= GenerateChar(enCharType::CapitalLetter);
	word+= GenerateChar(enCharType::CapitalLetter);
	word+= GenerateChar(enCharType::CapitalLetter);
	word+= GenerateChar(enCharType::CapitalLetter);
	return word;
}
string GenerateKey(short length)  {
	string key = "";
	for (int i = 1; i <= length; i++) {
		if (i < 4)
			key += GenerateWord() + "-";
		else
			key += GenerateWord();
	}
	return key;
}
void GenerateKeys(short NumberOfKeys) {
	string keys;
	for (int i = 1; i <= NumberOfKeys; i++) {
		cout << "Key[" << i << "]: " << GenerateKey(4);
		cout << endl;
	}
}
int main()
{
	GenerateKeys(Read_NumberOfKeys("Please Enter how many keys to generate: "));
	cout << endl << "This is second method to Generate Keys\n";
}

