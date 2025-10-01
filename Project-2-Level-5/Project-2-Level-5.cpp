
#include <iostream>
#include <ctime>
using namespace std;
enum enQuestionsLevel{Easy=1,Med,Hard,Mix};
enum enOperationType{Add=1,Sub,Mul,Div,Mix};
struct stTestInfo {
    short NumberOfQuestion = 0;
    enQuestionsLevel QuestionsLevel = Med;
    enOperationType OperationType = Add;
};
struct stTestResult {
    short NumberOfQuestions = 0;
    short NumberOfRightQuestions = 0;
    short NumberOfWrongQuestions = 0;

};
short Read_NumberOfQuestions() {
    short number = 1;
    do {
        cout << "How Many Questions do you want to answer? ";
        cin >> number;
        cout << endl;
    } while (number <=0);
    return number;
}
void AskUserAboutTestStyle(stTestInfo &TestInfo) {

    short QuestionsLevel = 1;
    do {
        cout << "Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
        cin >> QuestionsLevel;
    } while (QuestionsLevel < 1 || QuestionsLevel>4);
    TestInfo.QuestionsLevel = enQuestionsLevel(QuestionsLevel);

    short OpType = 1;
    do {
        cout << "Enter Operation Type [1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ? ";
        cin >> OpType;
    } while (OpType < 1 || OpType>5);
    TestInfo.OperationType = enOperationType(OpType);
}
short GetRandomNumber(int from, int to) {

    return   rand() % (to - from + 1) + from;
}
void GetQuestions(int &num1,int &num2, char OpType, stTestInfo TestInfo) {

    switch (TestInfo.QuestionsLevel) {

    case enQuestionsLevel::Easy: 
        num1 = GetRandomNumber(1, 10);
        num2 = GetRandomNumber(1, 10);
        break;
    
    case enQuestionsLevel::Med:
        num1 = GetRandomNumber(11, 49);
        num2= GetRandomNumber(11, 49);
        break;

    case enQuestionsLevel::Hard:
        num1 = GetRandomNumber(50, 100);
        num2 = GetRandomNumber(50, 100);
        break;

    case enQuestionsLevel::Mix:
        num1 = GetRandomNumber(1, 100);
        num2 = GetRandomNumber(1, 100);
        break;
    }
  
    switch (TestInfo.OperationType) {

    case enOperationType::Add:
        OpType = '+';
        break;

    case enOperationType::Sub:
        OpType = '-';
        break;

    case enOperationType::Mul:
        OpType = '*';
        break;

    case enOperationType::Div:
        OpType = '/';
        break;

    case enOperationType::Mix:
        while (OpType == 44 || OpType == 46) {
            OpType = GetRandomNumber(42, 47);
        }

    }
}
int GetRightAnswer(char OpType, int num1, int num2) {

    switch (OpType) {

    case '+': 
        return num1 + num2;

    case '-':
        return num1 - num2;

    case '*':
        return num1 * num2;

    case '/':
        return num1 / num2;
    }
}
int Read_UserAnswer() {
    int UserAnswer;
    cin >> UserAnswer;
    return UserAnswer;
}
bool CheckUserAnswer(int UserAnswer,int RightAnswer ,stTestResult &TestResult) {
    if (UserAnswer == RightAnswer) {
        TestResult.NumberOfRightQuestions++;
        return true;
    }
    else {
        TestResult.NumberOfWrongQuestions++;
        return false;
    }
}
void GetScreenColor( short AnswerStatus) {

    switch (AnswerStatus) {

    case 1:
        system("color 2F");//GREEN SCREEN
        break;

    case  0:
        cout << "\a";
        system("color 4F");//RED SCREEN
        break;
    }
}
void Print_EachQuestion(int num1, int num2, char OpType, int UserAnswer,int RightAnswer, short CurrentQuestion, short NumberOfQuestions, stTestResult &TestResult) {

    cout << "Question [" << CurrentQuestion << "/" << NumberOfQuestions << "]\n\n";
    cout << num1 << endl;
    cout << num2 << " " << OpType<<endl;
    cout << "----------\n";
    UserAnswer = Read_UserAnswer();
    cout << UserAnswer<<endl;
    if (CheckUserAnswer(UserAnswer, RightAnswer, TestResult)) {
        cout << "Right Answerb :-)\n\n";
        GetScreenColor(1);
    }
    else {
        cout << "Wrong Answer :-(";
        GetScreenColor(0);
        cout << "The right answer is: " << RightAnswer << endl << endl;
    }
}

void StartTest(short NumberOfQuestions, stTestResult &TestResult, stTestInfo &TestInfo) {

    int num1=1, num2=1;
    char OpType=44;
    int RightAnswer; 
    int UserAnswer=0;
    for (short CurrentQuestion = 1; CurrentQuestion <= NumberOfQuestions; CurrentQuestion++) {

        TestInfo.NumberOfQuestion = CurrentQuestion;
        GetQuestions(num1, num2, OpType, TestInfo);
        RightAnswer = GetRightAnswer(OpType, num1, num2);
        Print_EachQuestion(num1, num2, OpType, UserAnswer, RightAnswer, CurrentQuestion, NumberOfQuestions, TestResult);
    }
    TestResult.NumberOfQuestions = NumberOfQuestions;
}
void Print_PassOrFail(stTestResult TestResult) {

    cout << "\n------------------------------\n";
    if (TestResult.NumberOfRightQuestions > TestResult.NumberOfWrongQuestions) {
        cout << "Final Result is PASS :-)";
        GetScreenColor(1);
    }
    else {
        cout << "Final Result is FAIL :-(";
        GetScreenColor(0);
    }
    cout << "\n------------------------------\n\n";
}
void Print_FinalResult(stTestResult TestResult, stTestInfo TestInfo) {

    cout << "Number Of Questions: " << TestResult.NumberOfQuestions << endl;
    cout << "Qestions Level:" << TestInfo.QuestionsLevel << endl;
    cout << "OpType: " << TestInfo.OperationType << endl;
    cout << "Number Of Right Questions: " << TestResult.NumberOfRightQuestions << endl;
    cout << "Number Of Wrong Questions: " << TestResult.NumberOfWrongQuestions << endl<<endl;
    cout << "\n------------------------------\n";
}
void ResetScreen() {
    system("cls");
    system("color 0F");
}
void StartGame() {

	char PlayAgain = 'Y';
    stTestInfo TestInfo;
    stTestResult TestResult;
	do {
        ResetScreen();
        AskUserAboutTestStyle(TestInfo);
        StartTest(Read_NumberOfQuestions(), TestResult, TestInfo);
        Print_PassOrFail(TestResult);
        Print_FinalResult(TestResult, TestInfo);

		cout << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;
	}while(PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));  // Seed random number generator.
    StartGame();
}

