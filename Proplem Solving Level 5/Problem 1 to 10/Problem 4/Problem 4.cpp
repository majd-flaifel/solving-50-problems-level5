

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
bool Check_PerfectNumber(int m) {
    int sum = 0;
    for (int i = 1; i <= round(m / 2); i++) {
        if (m % i == 0)
            sum += i;
    }
    return sum == m;
}
void Print_PerfectNumbersFrom1ToN(int number) {
    for (int m = 1; m <= number; m++) {
        if (Check_PerfectNumber(m))
            cout << m << " is a perfect number\n";
       /* else
            cout<< m << " is not a perfect number\n";*/
    }

}
int main()
{
    Print_PerfectNumbersFrom1ToN(read_PositiveNumber("Please,enter positive number: "));

}

