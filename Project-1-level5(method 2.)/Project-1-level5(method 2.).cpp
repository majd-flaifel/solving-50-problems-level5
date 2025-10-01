
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enChoiceType { stone = 1, paper = 2, scissor = 3 };
enum enWinner{Player=1,Computer=2,Draw=3};
struct stRoundInfo {
    short CurrentRound=0;
    short PlayerChoice = 0;
    short ComputerChoice = 0;
    enWinner RoundWinner= Player;
    string NameRoundWinner="";
};
struct stGameResults {
    short GameRounds = 0;
    short PlayerWonTimes = 0;
    short ComputerWonTimes = 0;
    short DrawTimes = 0;
    enWinner FinalWinner=Player;
    string NameFinalWinner="";
};
short Read_RoundTimes() {
    short number = 0;
    do {
        cout << "How Many Rounds 1 to 10 ?)-\n";
        cin >> number;
        cout << endl;
    } while (number < 1 || number>10);
    return number;
}
 short GetRandomNumber(int from, int to) {

     return   rand() % (to - from + 1) + from;
}
short GetComputerChoice() {
    return GetRandomNumber(1, 3);
}
int AskPlayersChoices () {
    short choice;
    do {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissor ?";
        cin >> choice;
        cout << endl << endl;
    } while (choice < 1 || choice>3);
    return choice;
}
string NamePlayersChoices(short choice) {

   switch(choice){
   case enChoiceType::paper :
       return "Paper";
   case enChoiceType::scissor :
       return "Scissor";
   case enChoiceType::stone :
       return "Stone";
}
}
enWinner RoundWinner() {
    stRoundInfo RoundInfo;
    if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice) {
        return enWinner::Draw;
    }
    switch (RoundInfo.PlayerChoice) {
    case enChoiceType::paper : 
        if (RoundInfo.ComputerChoice == enChoiceType::scissor) {
            return enWinner::Computer;
        }
    case enChoiceType::scissor :
        if (RoundInfo.ComputerChoice == enChoiceType::stone) {
            return enWinner::Computer;
        }
    case enChoiceType::stone :
        if (RoundInfo.ComputerChoice == enChoiceType::paper) {
            return enWinner::Computer;
        }
    default: return enWinner::Player;
    }
}
string NameRoundWinner(short RoundWinner) {
    string NameWinner[3] = { "Player","Computer","Draw" };
    return NameWinner[RoundWinner - 1];
}
void GetScreenColor(enWinner Winner) {

    switch (Winner) {

    case enWinner::Player :
           system("color 20");
           break;

    case   enWinner::Computer :
        cout << "\a";
        system("color 40");
        break;

    default:  system("color 60");
        break;
    }
   
}
void Print_EachRound() {
    stRoundInfo RoundInfo;
    cout << "----------Round[" << RoundInfo.CurrentRound << "]----------\n\n";

    cout << "Player Choice    : " << NamePlayersChoices(RoundInfo.PlayerChoice) << endl;
    cout << "Computer Choice  : " << NamePlayersChoices(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner     : " << RoundInfo.NameRoundWinner << endl << endl;
    GetScreenColor(RoundInfo.RoundWinner);
    cout << "----------------------\n\n";
}
enWinner FinalWinner() {
    stRoundInfo RoundInfo;
    stGameResults GameResults;

    if (GameResults.PlayerWonTimes == GameResults.ComputerWonTimes)
        return enWinner::Draw;
    else if (GameResults.PlayerWonTimes > GameResults.ComputerWonTimes)
        return enWinner::Player;
    else
        return enWinner::Computer;
}
string NameFinalWinner(enWinner Winner) {

    string FinalWinner[3]={ "Player","Computer","Draw" }; 
    return FinalWinner[Winner - 1];

}
stGameResults FillGameResults(int GameRounds,int PlayerWonTimes ,int ComputerWonTimes,int DrawTimes) {

    stGameResults GameResults;

    GameResults.GameRounds = GameRounds;
    GameResults.PlayerWonTimes = PlayerWonTimes;
    GameResults.ComputerWonTimes = ComputerWonTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.FinalWinner = FinalWinner();
    GameResults.NameFinalWinner = NameFinalWinner(GameResults.FinalWinner);
    return GameResults;
}
void FormRounds(short RoundTimes) {

    stRoundInfo RoundInfo;
    int PlayerWonTimes = 0, ComputerWonTimes = 0, DrawTimes = 0;

    for (int CurrentRound = 1; CurrentRound <= RoundTimes; CurrentRound++) {
        RoundInfo.CurrentRound = CurrentRound;
        cout << "Round [" << CurrentRound << "] begins:\n";
        RoundInfo.PlayerChoice = AskPlayersChoices();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.RoundWinner = RoundWinner();
        RoundInfo.NameRoundWinner = NameRoundWinner(RoundInfo.RoundWinner);
        Print_EachRound();

        if (RoundInfo.RoundWinner == enWinner::Player)
            PlayerWonTimes++;
        else if (RoundInfo.RoundWinner == enWinner::Computer)
            ComputerWonTimes++;
        else
            DrawTimes++;
    }
    stGameResults GameResults=FillGameResults( RoundTimes,  PlayerWonTimes,  ComputerWonTimes,  DrawTimes);
}
void Print_GameOverScreen() {

    cout << "\t" << "---------------\n";
    cout << "+++ Game Over +++\n";
    cout << "\t" << "---------------\n";
}
void Print_GameResults() {

    stGameResults GameResults;
    cout << "\t" << "-----" << "[Game Results]" << "-----\n\n";

    cout << "Game Rounds        : " << GameResults.GameRounds << endl;
    cout << "Player won times   : " << GameResults.PlayerWonTimes << endl;
    cout << "Computer won times : " << GameResults.ComputerWonTimes << endl;
    cout << "Draw times         : " << GameResults.DrawTimes << endl;
    cout << "Final Winner       : " << GameResults.NameFinalWinner << endl;
    GetScreenColor(GameResults.FinalWinner);
    cout << "\t" << "-------------------------\n";

}
void ResetScreen() {
    system("cls");
    system("color 0F");
}
void StartGame() {

    char PlayAgain='y';
    do {
        ResetScreen();
        FormRounds(Read_RoundTimes());
        Print_GameOverScreen();
        Print_GameResults();
        cout << "Do you want to play again ? Y/N?";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
int main()
{
    srand((unsigned)time(NULL));  // Seed random number generator.
    StartGame();
}

