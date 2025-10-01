
#include <iostream>
using namespace std;
struct stCars {
    string Brand;
    string Model;
    int Year=0;
};
int main()
{
    /*cars mycar1;
    mycar1.Brand = "BMW";
    mycar1.Model = "x5";
    mycar1.Year = 2000;

    cars mycar2;
    mycar2.Brand = "Ford";
    mycar2.Model = "Mustang";
    mycar2.Year = 2020;

    cars mycar3;
    mycar3.Brand = "Mit";
    mycar3.Model = "Lancer";
    mycar3.Year = 1999;

    cout << "My car 1 info:\n";
    cout << mycar1.Brand << " " << mycar1.Model << " " << mycar1.Year << endl << endl;

    cout << "My car 2 info:\n";
    cout << mycar2.Brand << " " << mycar2.Model << " " << mycar2.Year << endl << endl;

    cout << "My car 3 info:\n";
    cout << mycar3.Brand << " " << mycar3.Model << " " << mycar3.Year << endl << endl;*/

    stCars ArrCars[3];
    ArrCars[0] = { "BMW","X5",2000 };
    ArrCars[0].Brand = "Zopy";
    ArrCars[1] = { "Ford","Mustang",2020 };
    ArrCars[2] = { "Mit","Lancer",1999 };
    for (int i = 0; i < 3; i++) {

        cout << "My car " << i+1 << " info fucker:\n";
        cout << ArrCars[i].Brand << " " << ArrCars[i].Model << " " << ArrCars[i].Year << endl << endl;
    }
}

