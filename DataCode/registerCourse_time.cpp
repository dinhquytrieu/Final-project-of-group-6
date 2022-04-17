#include "header.h"

void courseRegistration(Semester *& pSemester, Semester * totSemester, char * yearName) {

	textColor(14);
	cout << "Start Date: \n";
	textColor(7);
	cout << "Day: "; cin >> pSemester -> startReg.day;
	cout << "Month: "; cin >> pSemester -> startReg.month;
	cout << "Year: "; cin >> pSemester -> startReg.year;
	
	
	textColor(14);
	cout << "End date: \n";	
	textColor(7);
	cout << "Day: "; cin >> pSemester -> endReg.day;
	cout << "Month: "; cin >> pSemester -> endReg.month;
	cout << "Year: "; cin >> pSemester -> endReg.year;
	cout<<endl;
	textColor(10);
	cout << "The registration session for this semester is from " << pSemester -> startReg.day << '/' << pSemester -> startReg.month << '/' << pSemester -> startReg.year << " to "
			<< pSemester -> endReg.day << '/' << pSemester -> endReg.month << '/' << pSemester -> endReg.year << '\n';
			textColor(7);
	system("pause");
	system("cls");

	char dirD[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\Semester");
	strcat(c, "\\Semester.txt");

	ofstream fOut(c);

	Semester * cur = totSemester;
	while (cur != nullptr) {
		fOut << cur -> SemesterName << ' ';
		fOut << cur -> startDate.year << ' ' << cur -> startDate.month << ' ' << cur -> startDate.day << ' ';
		fOut << cur -> endDate.year << ' ' << cur -> endDate.month << ' ' << cur -> endDate.day << ' ';
		fOut << cur -> startReg.year << ' ' << cur -> startReg.month << ' ' << cur -> startReg.day << ' ';
		fOut << cur -> endReg.year << ' ' << cur -> endReg.month << ' ' << cur -> endReg.day << '\n';
		cur = cur -> semesterNext;
	}
	fOut.close();
}
