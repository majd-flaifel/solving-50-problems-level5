
#include <iostream>
using namespace std;

int read_PositiveNumber(string message) {
    int number=0;
    do {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}
bool Check_PerfectNumber(int number) {

    int sum = 0;
    for (int counter = 1; counter <= number / 2; counter++) {
        if (number % counter == 0)
            sum += counter;
    }
   
    return sum == number;
}
void print_Result(int number) {
    
        if (Check_PerfectNumber(number) )
        cout << number << " is a perfect number\n";
    else
        cout << number << " is not a perfect number\n";

    }
int main()
{
    print_Result(read_PositiveNumber("Please,enter positive number: "));
}
