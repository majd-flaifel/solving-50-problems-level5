

#include <iostream>
using namespace std;
enum enPrime_NotPrime{prime=1,notprime=2};
int read_PositiveNumber(string message) {
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number <= 0);
        return number;
}
enPrime_NotPrime Check_Prime_NotPrime(int m) {
    
        for (int counter = 2; counter <= round(m / 2); counter++) {
            if (m % counter == 0) {
                return enPrime_NotPrime::notprime;
            }
           }
        return enPrime_NotPrime::prime;
}
void print_PrimeNimberFrom1ToN(int number) {
    cout << "Prime numbers from " << 1 << " to " << number<<" are: \n";

    for (int m = 1; m <= number; m++) {

        if (Check_Prime_NotPrime(m) == enPrime_NotPrime::prime)
            cout << m << " is prime\n";

    }

}
int main()
{
    print_PrimeNimberFrom1ToN(read_PositiveNumber("Please,enter positive number: "));
}

