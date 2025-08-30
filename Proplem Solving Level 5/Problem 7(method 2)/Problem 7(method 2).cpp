

#include <iostream>
#include<string>
using namespace std;
int read_PositiveNumber(string message) {
    int number = 0;
    do {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}
int ReverseNumber(int number) {
    int reversed = 0;
    do {
        int remainder = number % 10;
        number = number / 10;
        reversed = reversed * 10 + remainder;

    } while (number > 0);

    return reversed;

}
int main()
{

    cout << "\nReversed number is: \n" << ReverseNumber(read_PositiveNumber("Please,enter positive number: ")) << endl;
}
