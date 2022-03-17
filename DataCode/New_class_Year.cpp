#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"

using namespace std;

void createNewYear(Year* &pYear, string* yearName, int add) {
	Year* pCur = pYear;
	while (pCur != nullptr) {
		if (strcmp(pCur -> YearName, yearName) == 0) {
			cout << "Failed to create a new year!!\n";
			cout << "The year you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		pCur = pCur -> yearNext;
	}

	ofstream fout;
	if (add)
		fout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\Year.txt");

	pCur = pYear;
	if (pYear == nullptr) {
		pYear = new Year;
		pYear -> YearName = yearName;
		if (add)
			fout << pYear -> YearName;
	}
	else {
		while (pCur -> yearNext != nullptr) {
			if (add)
				fout << pCur -> YearName << '\n';
			pCur = pCur -> yearNext;
		}
		if (add)
			fout << pCur -> YearName << '\n';
		pCur -> yearNext = new Year;
		pCur = pCur -> yearNext;
		pCur -> YearName = yearName;
		if (add)
			fout << pCur -> YearName;
	}
	if (add)
		fout.close();

	string dirD = "C:\\GitHub\\Final-project-of-group-6\\datafile\\";
	string c = "";
	strcat(c, "mkdir ");
	strcat(c, dirD);
	strcat(c, yearName);
	system(c);
}
