
#include <iostream>
#include <cstdlib>
using namespace std;

//enum enChoiceType { stone = 1, paper = 2, scissor = 3 };

short Read_RoundTimes() {
    short number = 0;
    do {
        cout << "How Many Rounds 1 to 10 ?\n";
        cin >> number;
        cout << endl;
    } while (number < 1 || number>10);
    return number;
}
void FormRounds(short RoundTimes) {

    for (int CurrentRound = 1; CurrentRound <= RoundTimes; CurrentRound++) {
        cout<<|""

    }
}
int main()
{
    std::cout << "Hello World!\n";
}

