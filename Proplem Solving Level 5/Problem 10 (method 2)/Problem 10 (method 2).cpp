
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
int ReverseNumber(int number) {
    int reversed = 0;
    do {
        int remainder = number % 10;
        number = number / 10;
        reversed = reversed * 10 + remainder;

    } while (number > 0);

    return reversed;

}
int PrintDigits(int number) {
  
    while (number > 0) {
        int remainder = number % 10;
        number = number / 10;
        cout << remainder<<endl;
    }
}
int main()
{
    PrintDigits(ReverseNumber(read_PositiveNumber("Please,enter positive number: ")));
}

