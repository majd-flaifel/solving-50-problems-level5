
#include <iostream>
#include<cmath>
using namespace std;
float Read_Numbers() {
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}
float GetFractionPart(float number,int IntPartOfnumber) {
    return number - IntPartOfnumber;
}
int MyRoundResult(float number) {

    int IntPartOfnumber = int(number);
    float fractionPartOfnumber = GetFractionPart(number,IntPartOfnumber);

    if (fractionPartOfnumber >= 0.5) {
        return IntPartOfnumber + 1;
    }

    else if (fractionPartOfnumber <= -0.5) {
        return IntPartOfnumber - 1;
    }
    else
        return IntPartOfnumber;
}
int main()
{
    float number = Read_Numbers();
    cout << "My Round Result is: " << MyRoundResult(number)<<endl;
    cout << "C++ Round Result is: " << round(number) << endl;
}

