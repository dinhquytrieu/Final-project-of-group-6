void addStudentCSV(Student*& pStudent, char* CSV_Student_File, char* yearName, char* className, int add) {
	char dirOut[] = { "C:\\Github\\Final-project-of-group-6\\DataProject\\" };
	char d[505] = ""; char d2[300]="";
	strcat(d2,dirOut);
	strcat(d2,"Account_student.txt");
	strcat(d, dirOut);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	strcat(d, "\\");
	strcat(d, "Student.txt");

	ofstream fOut(d);
	fstream fOut2(d2);
	fOut2.seekg(0,fOut.end);
	char dirIn[] = { "C:\\Github\\Final-project-of-group-6\\DataProject\\Class_csv\\" };
	char dd[505] = "";
	strcat(dd, dirIn);
	strcat(dd, CSV_Student_File);

	ifstream fIn(dd);

	char* s = new char[505];
	while (fIn.getline(s, 505)) {
		Student *newStu = new Student;
	    inputStudentCSV(newStu, s);

	    Student *tmp = pStudent;
	    while (tmp && strcmp(tmp -> studentID, newStu -> studentID) != 0)
	    	tmp = tmp -> studentNext;
		if (tmp && strcmp(tmp -> studentID, newStu -> studentID) == 0)
			continue;
	
		newStu -> enrolledSession = new bool* [8];
		for (int i = 0; i < 7; i++) {
			newStu -> enrolledSession[i] = new bool[5];
			for (int j = 0; j < 4; j++)
				newStu -> enrolledSession[i][j] = false;
		}

		if (pStudent == nullptr)
			pStudent = newStu;
		else {
			Student* pCur = pStudent;
			while (pCur -> studentNext != nullptr)
				pCur = pCur -> studentNext;
			pCur -> studentNext = newStu;
		}
	}

	Student *pCur = pStudent;
	while (pCur != nullptr) {
		if (add)
			fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
			fOut2 << pCur -> studentID << ' ' << '1' <<'\n';
		pCur = pCur -> studentNext;
	}
	if (add)
	{
		fOut.close();
		fOut2.close();
	}
	delete[] s;
}
