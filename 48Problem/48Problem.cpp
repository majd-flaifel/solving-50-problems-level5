

#include <iostream>
#include<cmath>
using namespace std;
float Read_Numbers() {
    float number;
    cout << "Enter a number: ";
    cin >> number;
    return number;
}
int MyFloorResult(float number) {

    int IntPartOfnumber = int(number);
    if (IntPartOfnumber == number)
        return IntPartOfnumber;
    else if (number >0) {
        return IntPartOfnumber ;
    }

    else 
        
        return IntPartOfnumber - 1;
    
   
}
int main()
{
    float number = Read_Numbers();
    cout << "My Floor Result is: " << MyFloorResult(number) << endl;
    cout << "C++ Florr Result is: " << floor(number) << endl;
    

}

