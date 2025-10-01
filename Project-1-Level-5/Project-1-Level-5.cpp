
#include <iostream>
#include <cstdlib>
using namespace std;
enum enChoiceType{stone=1,paper=2,scissor=3};
int Read_RoundTimes() {
    int number = 0;
    do {
        cout << "How Many Rounds 1 to 10 ?\n";
        cin >> number;
        cout << endl;
    } while (number <= 0);
    return number;
}
void CountRoundTimes( int& CountRounds) {
    
        cout << "Round [" << CountRounds << "] begins:\n\n";
       
        CountRounds++;

    }
int GetRandomNumber(int from, int to) {

    return rand() % (to - from + 1) + from;

}
void AskPlayersChoices(int &PlayerChoice, int &ComputerChoice) {
  
    do {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissor ?";
        cin >> PlayerChoice;
        cout << endl << endl;
    } while (PlayerChoice < 1 || PlayerChoice>3);

    ComputerChoice = GetRandomNumber(1, 3);
   
}

string CheckPlayersChoices(int Choice) {

    switch (Choice) {
    case enChoiceType::stone:return "Stone";
    case enChoiceType::paper:return "Paper";
    case enChoiceType::scissor:return "Scissor";
    }
}
string GetWinner(int PlayerChoice, int ComputerChoice) {

    if (PlayerChoice == enChoiceType::stone && ComputerChoice == enChoiceType::scissor)
        return "Player";
    else if (PlayerChoice == enChoiceType::scissor && ComputerChoice == enChoiceType::stone)
        return "Computer";
    else if (PlayerChoice == enChoiceType::stone && ComputerChoice == enChoiceType::paper)
        return "Computer";
    else if (PlayerChoice == enChoiceType::paper && ComputerChoice == enChoiceType::stone)
        return "Player";
    else if (PlayerChoice == enChoiceType::paper && ComputerChoice == enChoiceType::scissor)
        return "Computer";
    else if (PlayerChoice == enChoiceType::scissor && ComputerChoice == enChoiceType::paper)
        return "Player";

    else   // else mean that both chose the same
        return "[No Winner]";
}

void GetColor(int PlayerChoice, int ComputerChoice) {
    if (GetWinner(PlayerChoice, ComputerChoice) == "Player") {
    //    system("cls");
        system("color 20");
    }
    else if (GetWinner(PlayerChoice, ComputerChoice) == "Computer") {
        cout << "\a";
      //  system("cls");
        system("color 40");
    }
    else
     //   system("cls");
        system("color 60");

}
void Print_EachRound(int number, int CountRounds,int PlayerChoice, int ComputerChoice) {

    while (CountRounds <= number) {
        CountRoundTimes(CountRounds);
        AskPlayersChoices(PlayerChoice, ComputerChoice);

        cout << "______________Round[" << CountRounds-1 << "]______________\n\n";

        GetColor(PlayerChoice, ComputerChoice);
        cout << "Player Choice   :" << CheckPlayersChoices(PlayerChoice) << endl;
        cout << "Computer Choice :" << CheckPlayersChoices(ComputerChoice) << endl;
        cout << "Round Winner    :" << GetWinner(PlayerChoice, ComputerChoice) << endl;

        cout << "____________________________________\n\n";

    }
}

int main()
{
    srand((unsigned)time(NULL));
    int CountRounds = 1;

    int PlayerChoice=0;
    int ComputerChoice=0;
    Print_EachRound(Read_RoundTimes(), CountRounds, PlayerChoice, ComputerChoice);
}
