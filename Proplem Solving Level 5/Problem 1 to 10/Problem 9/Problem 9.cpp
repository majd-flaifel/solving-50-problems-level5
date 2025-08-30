
#include <iostream>
#include<string>
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


    
void Print_AllDigitFrequancy( int number) {
    int counter = 0;
    int x[100];
    
   int remainder = number % 10;
    cout << "Digit " << remainder << " Frequancy is " << CountDigitFrequancy(number, remainder) << " Time(s)\n";
    number = number / 10;

    for (int i = 1; number>0; i++) {
        bool check_remainder = true;
        
        x[counter] = remainder;
        counter++;
         remainder = number % 10;

        for (int m = 0; m < counter; m++) {
            if (x[m] == remainder) 
                check_remainder = false;
        }
        if(check_remainder)
            cout << "Digit " << remainder << " Frequancy is " << CountDigitFrequancy(number, remainder) << " Time(s)\n";
        number = number / 10;

    }
}

int main()
{
    int number = read_PositiveNumber("Please enter number: ");
    cout << endl;
    Print_AllDigitFrequancy(number);
    cout << endl;
}
