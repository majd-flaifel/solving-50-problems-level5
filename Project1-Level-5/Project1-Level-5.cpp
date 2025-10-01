
#include <iostream>
#include <cstdlib>
using namespace std;
enum enChoiceType { stone = 1, paper = 2, scissor = 3 };
int Read_RoundTimes() {
    int number = 0;
    do {
        cout << "How Many Rounds 1 to 10 ?\n";
        cin >> number;
        cout << endl;
    } while (number <= 0);
    return number;
}
void CountRoundTimes(int& CountRounds) {

    CountRounds++;
    cout << "Round [" << CountRounds << "] begins:\n\n";


}
int GetRandomNumber(int from, int to) {

    return rand() % (to - from + 1) + from;

}
void AskPlayersChoices(int& PlayerChoice, int& ComputerChoice) {

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

    string x = GetWinner(PlayerChoice, ComputerChoice);
    if (x == "Player") {

        system("color 20");
    }
    else if (x == "Computer") {
        cout << "\a";

        system("color 40");
    }
    else

        system("color 60");

}
void CountWonAndDrawTimes(int& playerwon, int& computerwon, int& draw, int PlayerChoice, int ComputerChoice) {

    string x = GetWinner(PlayerChoice, ComputerChoice);
    if (x == "Player") {

        playerwon++;
    }
    else if (x == "Computer") {
        computerwon++;
    }
    else
        draw++;
}
void Print_EachRound(int number, int& CountRounds, int playerChoice, int computerChoice, int& playerwon, int& computerwon, int& draw) {

    while (CountRounds <= number) {
        AskPlayersChoices(playerChoice, computerChoice);
        CountRoundTimes(CountRounds);
        CountWonAndDrawTimes(playerwon, computerwon, draw, playerChoice, computerChoice);
        cout << "______________Round[" << CountRounds << "]______________\n\n";

        GetColor(playerChoice, computerChoice);
        cout << "Player Choice   :" << CheckPlayersChoices(playerChoice) << endl;
        cout << "Computer Choice :" << CheckPlayersChoices(computerChoice) << endl;
        cout << "Round Winner    :" << GetWinner(playerChoice, computerChoice) << endl;

        cout << "____________________________________\n\n";

    }
}

string DetermineFinalWinner(int playerwon, int computerwon, int draw) {

    if (playerwon > computerwon) {
        return "Player";
    }
    else if (computerwon > playerwon) {
        return "Computer";
    }
    else
        return "No Winner";
}
void Print_FinalResult(int number, int playerwon, int computerwon, int draw) {

    cout << "\n\n______________[Game Results]______________\n\n";
    cout << "Game Rounds        : " << number << endl;
    cout << "Player won times   : " << playerwon << endl;
    cout << "Computer won times : " << computerwon << endl;
    cout << "Draw times         : " << draw << endl;
    cout << "Final Winner       : " << DetermineFinalWinner(playerwon, computerwon, draw) << endl;
    cout << "____________________________________\n";

}

void AskUserMoreTours(int& CountRounds, int playerChoice, int computerChoice, int& playerwon, int& computerwon, int& draw) {
    char playmore;
    cout << "Do you want to play again? Y/N ?";
    cin >> playmore;
    while (playmore == 'y'||playmore=='Y') {
        CountRounds = 1;
        playerwon = 0;
        computerwon = 0;
        draw = 0;
        system("cls");
        int number = Read_RoundTimes();
        Print_EachRound(number, CountRounds, playerChoice, computerChoice, playerwon, computerwon, draw);
        Print_FinalResult(number, playerwon, computerwon, draw);
        cout << "Do you want to play again? Y/N ?";
        cin >> playmore;

    }

}
int main()
{
    srand((unsigned)time(NULL));
    int numberofrounds = Read_RoundTimes();
    int CountRounds = 0;

    int PlayerChoice = 0;
    int ComputerChoice = 0;
    int playerwon = 0, computerwon = 0, draw = 0;
    Print_EachRound(numberofrounds, CountRounds, PlayerChoice, ComputerChoice, playerwon, computerwon, draw);
    Print_FinalResult(numberofrounds, playerwon, computerwon, draw);
    AskUserMoreTours(CountRounds, PlayerChoice, ComputerChoice, playerwon, computerwon, draw);
}