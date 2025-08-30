

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
bool SearchDigit(int number,int digit) {
    while (number > 0) {
        int remainder = number % 10;
        if (remainder == digit) {
            return true;
        }
        number = number / 10;
    }
}
void PrintDigits(int number) {
    for (int i = 0; i <= 9; i++)
        if (SearchDigit(number, i))
            cout << i << endl;
}
int main()
{
    PrintDigits(read_PositiveNumber("Please enter a positive number: "));
}

