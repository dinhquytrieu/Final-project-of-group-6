#include <iostream>
#include <fstream>
#include <string.h>
#include "Course.h"

using namespace std;

void createNewYear(Year* &pYear, string yearName, int add) {
	Year* pCur = pYear;
	while (pCur != nullptr) {
		if (pCur -> nameYear == yearName)) {
			cout << "Failed to create a new year!!\n";
			cout << "The year you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		pCur = pCur -> pYearNext;
	}

	ofstream fout;
	if (add)
		fout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\Year.txt", ios_base::app);

	pCur = pYear;
	if (pYear == nullptr) {
		pYear = new Year;
		pYear -> nameYear = yearName;
		if (add)
			fout << pYear -> nameYear;
	}
	else {
		while (pCur -> pYearNext != nullptr) {
			if (add)
				fout << pCur -> nameYear << '\n';
			pCur = pCur -> pYearNext;
		}
		if (add)
			fout << pCur -> nameYear << '\n';
		pCur -> pYearNext = new Year;
		pCur = pCur -> pYearNext;
		pCur -> nameYear = yearName;
		if (add)
			fout << pCur -> nameYear;
	}
	if (add)
		fout.close();

	char dirD[] = "C:\\GitHub\\Final-project-of-group-6\\datafile\\";
	char c[500] = "";
	strcat(c, "mkdir ");
	strcat(c, dirD);
	strcat(c, yearName);
	system(c);
}
