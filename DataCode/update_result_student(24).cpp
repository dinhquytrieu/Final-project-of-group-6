#include <fstream>
#include <string.h>
#include "staff.h"
#include "header.h"

void update_student_result(scoreboard *& pScr, char *yearName, char * semesterName, char *IDcourse, char* IDstudent) {
	scoreboard * pCur = pScr;
	while(pCur != nullptr && strcmp(pCur->stuHead->IDstudent, IDstudent) != 0){
		pCur = pCur-> pScoreboardNext;
	}	
	
	if(pCur != nullptr){
		cout << "Update Score of student " << IDstudent << ": " << endl;
		cout << "Midterm's mark: "; 
		cin >> pCur->Midterm;
		cout << "Final's mark: "; 
		cin >> pCur->Final;
		cout << "Bonus's mark: "; 
		cin >> pCur->bonus;
		cout << "Total's mark: "; 
		cin >> pCur->total;
		cout << "Update successfully!!\n";
	} else {
		cout << "Student ID not found." << '\n';
	}
	system("pause");
	system("cls");

	char locate[] = { "C:\\Github\\Final-project-of-group-6\\datafile\\" };
	char l[505] = "";
	strcat(l, dirOut);
	strcat(l, yearName);
	strcat(l, "\\Semester\\");
	strcat(l, semesterName);
	strcat(l, "\\");
	strcat(l, IDcourse);
	strcat(l, "\\");
	strcat(l, "Scoreboard.txt");

	ofstream fOut(l);

	pCur = pScr;
	int cnt = 0;
	while (pCur != nullptr) {
		fOut << ++cnt << ',' << pCur -> stuHead -> IDstudent << ',' << pCur -> stuHead -> name << ',' << pCur -> Midterm << ',' << pCur -> Final << ',' << pCur -> bonus << ',' << pCur -> total << '\n';
		pCur = pCur -> pScoreboardNext;
	}
	fOut.close();
}
