

#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for using std::string.
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for time() to seed the random generator.

using namespace std;
int Read_NumberOfKeys(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number <= 0);
	return number;
}
int RandomNumber(int from,int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}

void Key() {
	string FourChar = "";
		for (int i = 1; i <= 4; i++) {
			for (int m = 1; m <= 4; m++) {
				char Char = RandomNumber(65, 90);
				FourChar += Char;
			}
			cout << FourChar;
			FourChar = "";
			if(i<4)
			cout << "-";
		}
		
	
}
void Print_Key(int number) {
	int counter = 1;

	while (counter <= number) {
		cout << "Key[" << counter << "]: ";
		Key();
		cout << endl;
		counter++;
	}



}
int main()
{
	srand((unsigned)time(NULL));
	Print_Key(Read_NumberOfKeys("Please Enter how many keys to generate: "));
}
