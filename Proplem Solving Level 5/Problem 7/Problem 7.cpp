

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
    string reversed ="";

    do {
        int remainder = number % 10;
        reversed += to_string(remainder);
    
        number = number / 10;
      

    } while (number > 0);

    return stoi(reversed);
   
}
int main()
{
   
    cout << "\nReversed number is: \n" << ReverseNumber(read_PositiveNumber("Please,enter positive number: "))<<endl;

   
}

