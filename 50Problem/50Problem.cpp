
#include <iostream>
#include<cmath>
using namespace std;
float Read_Numbers() {
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}
float MySqrt(int number) {
    return pow(number, 0.5);
}
int main()
{
    int number = Read_Numbers();
    cout << "\nMy Sqrt Result is: " << MySqrt(number)<<endl;
    cout << "\nC++ Sqrt Result is: " << sqrt(number) << endl;

}


