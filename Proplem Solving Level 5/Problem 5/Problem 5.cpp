

#include <iostream>
#include<string>
using namespace std;
int read_Number(string message) {
    int number;

    cout << message;
    cin >> number;
    return number;
}
void read_Array(int number,int x[]) {

    
    for (int i = 0; i < number; i++) {
        cout << "enter a number : ";
        cin >> x[i];
    }
}
void Print_result(int number,int x[]) {
    for(int m=number-1;m>=0;m--)
    cout <<x[m]  << endl;
}

int main()
{
   int number = read_Number("how many digits you want to enter? ");
    int x[100];
    read_Array(number, x);
    cout << endl;
   Print_result(number, x);
   

}

