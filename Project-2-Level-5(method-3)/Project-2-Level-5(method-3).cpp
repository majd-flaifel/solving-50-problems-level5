
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med, Hard, Mix };
enum enOperationType { Add = 1, Sub, Mul, Div, MixOp };
struct stTestInfo {

    short num1=0, num2=0;
    int PlayerAnswer = 0;
    int RightAnswer = 0;
    enQuestionsLevel QuestionsLevel = Med;
    enOperationType OperationType = Add;
    bool IsRightAnswer=true;
};
struct stTestResult{
    stTestInfo ArrQuestionList[100];
    short NumberOfQuestions = 0;
    enQuestionsLevel QuestionsLevel = Med;
    enOperationType OperationType = Add;
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
    bool IsPass = true;
};

short Read_NumberOfQuestions() {
    short number = 1;
    do {
        cout << "How Many Questions do you want to answer? ";
        cin >> number;
        cout << endl;
    } while (number <= 0);
    return number;
}
void ResetScreen() {
    system("cls");
    system("color 0F");
}
enQuestionsLevel AskQuestionsLevel() {

    short QuestionsLevel = 1;
    do {
        cout<<"Enter Question Level [1]Easy, [2]Med, [3]Hard, [4]Mix ? ";
        cin >> QuestionsLevel;
    } while (QuestionsLevel < 1 || QuestionsLevel>4);
    return enQuestionsLevel(QuestionsLevel);
}
enOperationType AskOperationType() {

    short OperationType = 1;
    do {
        cout << " Enter Operation Type[1]Add, [2]Sub, [3]Mul, [4]Div, [5]Mix ?";
        cin >> OperationType;
    } while  (OperationType < 1 || OperationType>5);
    return enOperationType(OperationType);
}
short GetRandomNumber(int from, int to) {

    return   rand() % (to - from + 1) + from;
}
stTestInfo GetQuestionNumbers(enQuestionsLevel QuestionsLevel ) {
    stTestInfo TestInfo;

    if (QuestionsLevel == enQuestionsLevel::Mix) {

        QuestionsLevel = enQuestionsLevel(GetRandomNumber(1, 3));
        TestInfo.QuestionsLevel = QuestionsLevel;
    }

    switch (QuestionsLevel) {

    case enQuestionsLevel::Easy :
        TestInfo.num1 = GetRandomNumber(1, 10);
        TestInfo.num2 = GetRandomNumber(1, 10);
        TestInfo.QuestionsLevel = QuestionsLevel;
        break;

    case enQuestionsLevel::Med :
        TestInfo.num1 = GetRandomNumber(10, 50);
        TestInfo.num2 = GetRandomNumber(10, 50);
        TestInfo.QuestionsLevel = QuestionsLevel;
        break;


    case enQuestionsLevel::Hard :
        TestInfo.num1 = GetRandomNumber(50, 100);
        TestInfo.num2 = GetRandomNumber(50, 100);
        TestInfo.QuestionsLevel = QuestionsLevel;
        break;
    }
    return TestInfo;
}
enOperationType GetOperationType(enOperationType OperationType) {

    stTestInfo TestInfo;
    if (OperationType == enOperationType::MixOp) {

        OperationType = enOperationType(GetRandomNumber(1, 4));
    }
    TestInfo.OperationType = OperationType;
    return TestInfo.OperationType;
}
char GetOperationSymbol(enOperationType OperationType) {

    switch (OperationType) {

    case enOperationType::Add :
        return '+';
    case enOperationType::Sub :
        return '-';
    case enOperationType::Mul :
        return '*';
    case enOperationType::Div :
        return '/';
    }
}
int Read_PlayerAnswer() {

    int PlayerAnswer;
    cin >> PlayerAnswer;
    return PlayerAnswer;
}
int GetRightAnswer(stTestInfo &TestInfo) {
    
    switch (TestInfo.OperationType) {
    case enOperationType::Add :
        return TestInfo.num1 + TestInfo.num2;
    case enOperationType::Sub:
        return TestInfo.num1 - TestInfo.num2;
    case enOperationType::Mul:
        return TestInfo.num1 * TestInfo.num2;
    case enOperationType::Div:
        return TestInfo.num1 / TestInfo.num2;
    }
}
void CheckPlayerAnswer(stTestResult& TestResult,short Question) {

    if (TestResult.ArrQuestionList[Question].PlayerAnswer != TestResult.ArrQuestionList[Question].RightAnswer) {
        TestResult.ArrQuestionList[Question].IsRightAnswer = false;
        TestResult.NumberOfWrongAnswers++;

        cout << "Wrong Answer :-(\n";
        cout << "The Right Answer is: ";
        cout << TestResult.ArrQuestionList[Question].RightAnswer << endl << endl;
    }
    else {
        TestResult.ArrQuestionList[Question].IsRightAnswer = true;
        TestResult.NumberOfRightAnswers++;

        cout << "Right Answer :-)\n\n";
    }
    GetScreenColor(TestResult.ArrQuestionList[Question].IsRightAnswer);
}
stTestInfo GetQuestion(stTestResult &TestResult) {
    stTestInfo TestInfo;
    TestInfo = GetQuestionNumbers(TestResult.QuestionsLevel);
   TestInfo.OperationType = GetOperationType(TestResult.OperationType);

   return TestInfo;

}
void GetTestQuestions(stTestResult &TestResult) {

    for (short Question = 0; Question < TestResult.NumberOfQuestions; Question++) {

        TestResult.ArrQuestionList[Question] = GetQuestion(TestResult);
    }
}
void GetScreenColor(bool AnswerStatus) {

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

void PrintQuestion(stTestResult &TestResult, short Question) {

        cout << "Question [" << Question + 1 << "/" << TestResult.NumberOfQuestions << "]\n\n";

        cout << TestResult.ArrQuestionList[Question].num1 << endl;
        cout << TestResult.ArrQuestionList[Question].num2 << " ";
        cout << GetOperationSymbol(TestResult.ArrQuestionList[Question].OperationType) << endl;
        cout << "-----------\n";
}
void AskAndCorrectAnswer(stTestResult& TestResult) {
    for (short Question = 0; Question < TestResult.NumberOfQuestions; Question++) {
    
        PrintQuestion(TestResult,Question);

        TestResult.ArrQuestionList[Question].PlayerAnswer = Read_PlayerAnswer();
        TestResult.ArrQuestionList[Question].RightAnswer = GetRightAnswer(TestResult.ArrQuestionList[Question]);
        CheckPlayerAnswer(TestResult, Question);
    }
}
string GetNameOfQuestionLevel(enQuestionsLevel QuestionsLevel) {

    string ArrQuestionsLevel[4] = { "Easy","Med","Hard","Mix" };
    return ArrQuestionsLevel[QuestionsLevel - 1];
}
string GetNameOfOpType(enOperationType OperationType) {

    string ArrOperationType[5] = { "Add","Sub","Mul","Div","Mix" };
    return ArrOperationType[OperationType - 1];
}
string CheckPlayerResult(stTestResult &TestResult) {

    if (TestResult.NumberOfRightAnswers >= TestResult.NumberOfWrongAnswers) {

        TestResult.IsPass = true;
        return "PASS :-)";
        
    }
    else {
        TestResult.IsPass = false;
       return "FAIL :-(";
    }
    GetScreenColor(TestResult.IsPass);
}
void Pint_FinalResult(stTestResult TestResult) {

     cout << "\n------------------------------\n";    
     cout << "Final Result is "<< CheckPlayerResult(TestResult);
     cout << "\n------------------------------\n\n";

    cout << "Number Of Questions: " << TestResult.NumberOfQuestions << endl;
    cout << "Qestions Level:" << GetNameOfQuestionLevel(TestResult.QuestionsLevel) << endl;
    cout << "OpType: " << GetNameOfOpType(TestResult.OperationType) << endl;
    cout << "Number Of Right Answers: " << TestResult.NumberOfRightAnswers << endl;
    cout << "Number Of Wrong Answers: " << TestResult.NumberOfWrongAnswers << endl << endl;
    cout << "\n------------------------------\n";
}

void StartTest() {

    stTestResult TestResult;
   
    TestResult.NumberOfQuestions = Read_NumberOfQuestions();
    TestResult.QuestionsLevel = AskQuestionsLevel();
    TestResult.OperationType = AskOperationType();

    GetTestQuestions(TestResult);
    AskAndCorrectAnswer(TestResult);
    Pint_FinalResult(TestResult);
}
void StartGame() {

    char PlayAgain = 'Y';
    do {
        
        ResetScreen();
        StartTest();

        cout << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');

}
int main()
{

    srand((unsigned)time(NULL));  // Seed random number generator.
    StartGame();
}

