

void createNewYear(Year* &pYear, string yearName, int modd) {
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
	if (modd)
		fout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\Year.txt", ios_base::app);

	pCur = pYear;
	if (pYear == nullptr) {
		pYear = new Year;
		pYear -> nameYear = yearName;
		if (modd)
			fout << pYear -> nameYear;
	}
	else {
		while (pCur -> pYearNext != nullptr) {
			if (add)
				fout << pCur -> nameYear << '\n';
			pCur = pCur -> pYearNext;
		}
		if (modd)
			fout << pCur -> nameYear << '\n';
		pCur -> pYearNext = new Year;
		pCur = pCur -> pYearNext;
		pCur -> nameYear = yearName;
		if (modd)
			fout << pCur -> nameYear;
	}
	if (modd)
		fout.close();

	char dirD[] = "C:\\GitHub\\Final-project-of-group-6\\datafile\\";
	char c[500] = "";
	strcat(c, "mkdir ");
	strcat(c, dirD);
	strcat(c, yearName);
	system(c);
}
