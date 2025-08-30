

#include <iostream>
using namespace std;
int read_PositiveNumber(string message) {
    int number = 0;
    do {
        cout << message;
        cin >> number;
    } while (number < 0);
    return number;
}
int CountDigitFrequancy(int number,short digit) {
    int counter = 0;
     
    while (number > 0) {
        int remainder = number % 10;
        if (remainder == digit) {
            counter++;
        }
         number = number/10;
    }
    return counter;
}
void Print_Result(short digit,int counter) {
    cout << "Digit " << digit << " Frequancy is " << counter << " Time(s)";
}
int main()
{
    int number = read_PositiveNumber("Please enter number: ");
    short digit = read_PositiveNumber("Please enter one digit to check: ");
    cout << endl;
    Print_Result(digit, CountDigitFrequancy(number, digit));
    cout << endl;
}

