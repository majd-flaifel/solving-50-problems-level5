
#include <iostream>
#include<cmath>
using namespace std;
float Read_Numbers() {
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}
int MyCeilResult(float number) {

    int IntPartOfnumber = int(number);
    if (IntPartOfnumber == number)
        return IntPartOfnumber;
    else if (number > 0) {
        return IntPartOfnumber + 1;

    }

    else
        return IntPartOfnumber;



}
int main()
{
    float number = Read_Numbers();
    cout << "My Ceil Result is: " << MyCeilResult(number) << endl;
    cout << "C++ Ceil Result is: " << ceil(number) << endl;


}

