
#include <iostream>
using namespace std;
void Print_TableHeader() {
	cout << "\n\n\t\t\t Multiblication Table from 1 to 10:\n\n";
	cout << "\t";
	for (int i = 1; i <= 10; i++)
		cout << i << "\t";
	cout << endl;
	cout  << "___________________________________________________________________________________\n";
}
string ColumnSeperator(int i) {
	if (i <= 9)
		return "   |";
	else
		return "  |";
}
void Print_MultiblicationTable() {
	Print_TableHeader();
	for (int i = 1; i <= 10; i++) {
		cout << " " << i << ColumnSeperator(i) << "\t";
		for (int m = 1; m <= 10; m++)
			cout << i * m << "\t";

		cout << endl;

	}

}

int main()
{
	Print_MultiblicationTable();
}
