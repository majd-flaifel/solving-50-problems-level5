

#include <iostream>
#include<cmath>
using namespace std;
float Read_Numbers() {
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}
float MyABS(float number) {
    if (number > 0)
        return number;
    else
      return  number * -1;
   
    
}
int main()
{
    float number = Read_Numbers();
    cout<<"My abs Result: "<< MyABS(number)<<endl;
    cout << "C++ abs Result: " << abs(number) << endl;

}

