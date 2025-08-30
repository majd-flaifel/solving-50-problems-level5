
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
void Print_NumberInReversed(int number) {
  
    do {
        int remainder = number % 10;
        number = number / 10;
        cout << remainder<<endl;

    } while (number > 0);

}
int main()
{
    Print_NumberInReversed(read_PositiveNumber("Please,enter positive number: "));
}

