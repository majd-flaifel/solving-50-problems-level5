
#include <iostream>
using namespace std;
struct stStudentsInfo {
    string StudentName="";
    string TeacherName="";
    int ClassNuber=0, Fees=0,StudentAge=0;
};

int Read_StudentAge(stStudentsInfo ArrStudentsInfo[100], int StudentNumber) {

  
    do {
        cout << "How old is the student? ";
        cin >> ArrStudentsInfo[StudentNumber].StudentAge;
    } while (ArrStudentsInfo[StudentNumber].StudentAge < 5|| ArrStudentsInfo[StudentNumber].StudentAge>18);
    return ArrStudentsInfo[StudentNumber].StudentAge;
}
string Read_StudentName(stStudentsInfo ArrStudentsInfo[100], int StudentNumber) {
  
    cout << "What is the student name?\n";
    cin >> ArrStudentsInfo[StudentNumber].StudentName;
        return ArrStudentsInfo[StudentNumber].StudentName;
}
void GetStudentsInfo(stStudentsInfo ArrStudentsInfo[100]) {

    for (int StudentNumber = 0; StudentNumber < 3; StudentNumber++) {
        Read_StudentName(ArrStudentsInfo, StudentNumber);
        Read_StudentAge( ArrStudentsInfo, StudentNumber);

        if (ArrStudentsInfo[StudentNumber].StudentAge >= 16) {
            ArrStudentsInfo[StudentNumber].TeacherName = "Ibrahim";
            ArrStudentsInfo[StudentNumber].ClassNuber = 3;
            ArrStudentsInfo[StudentNumber].Fees = 3000;
        }
        else if (ArrStudentsInfo[StudentNumber].StudentAge >= 11) {
            ArrStudentsInfo[StudentNumber].TeacherName = "Mohammed";
            ArrStudentsInfo[StudentNumber].ClassNuber = 2;
            ArrStudentsInfo[StudentNumber].Fees = 2000;
        }
        else if (ArrStudentsInfo[StudentNumber].StudentAge >= 5) {
            ArrStudentsInfo[StudentNumber].TeacherName = "Leen";
            ArrStudentsInfo[StudentNumber].ClassNuber = 1;
            ArrStudentsInfo[StudentNumber].Fees = 800;
            cout << endl;
        }
    }
}
void Print_StudentsInfo(stStudentsInfo ArrStudentsInfo[100]) {
    for (int StudentNumber = 0; StudentNumber < 3; StudentNumber++) {

        cout << "\nStudent " << StudentNumber + 1 << " Name is: " << ArrStudentsInfo[StudentNumber].StudentName <<endl;
        cout << "Student " << StudentNumber + 1 << " Age is: "<< ArrStudentsInfo[StudentNumber].StudentAge << endl;


        cout << "Teacher's name is: " << ArrStudentsInfo[StudentNumber].TeacherName << endl;
        cout << "Class Number is: " << ArrStudentsInfo[StudentNumber].ClassNuber << endl;
        cout << "Fees: " << ArrStudentsInfo[StudentNumber].Fees << endl<<endl;
    }
}
int main()
{
    stStudentsInfo ArrStudentsInfo[100];

    GetStudentsInfo(ArrStudentsInfo);
    Print_StudentsInfo(ArrStudentsInfo);
}

