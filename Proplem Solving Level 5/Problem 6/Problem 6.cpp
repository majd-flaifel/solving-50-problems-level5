

#include <iostream>
using namespace std;
int read_PositiveNumber(string message) {
    int number = 0;
    do {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}
int Sum_Of_Digits(int number) {

    int sum = 0;
    while (number > 0) {
        int remainder = number % 10;
        number = number / 10;
        sum += remainder;
    }
     return sum;
}
void Print_SumOfDigits(int sum) {
    cout << "Sum of Digits = " << sum;
}
int main()
{
    Print_SumOfDigits(Sum_Of_Digits(read_PositiveNumber("Please,enter positive number: ")));
    cout << endl;
}

