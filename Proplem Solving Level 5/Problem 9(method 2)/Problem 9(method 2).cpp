
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
int CountDigitFrequancy(int number, short digit) {
    int counter = 0;

    while (number > 0) {
        int remainder = number % 10;
        if (remainder == digit) {
            counter++;
        }
        number = number / 10;
    }
    return counter;
}
void Print_AllDigitFrequancy(int number) {
    short counter;
    for (int i = 0; i <= 9; i++) {
        counter = CountDigitFrequancy(number, i);
    if(counter>0)
        cout << "Digit " << i << " Frequancy is " << counter << " Time(s)\n";

    }
}

int main()
{
    int number = read_PositiveNumber("Please enter number: ");
    Print_AllDigitFrequancy(number);

}