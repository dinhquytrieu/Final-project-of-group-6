void addStudent(Student*& pStudent, char* yearName, char* className, Student *& newStu, int add) {
	Student * cur = pStudent;
	while (cur != nullptr) {
		if  (strcmp(cur -> studentID, newStu -> studentID) == 0) {
			cout << "Failed to add a new student!!\n";
			cout << "The student you are about to add has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		cur = cur -> studentNext;
	}
	char dirD[] = { "C:\\Github\\Final-project-of-group-6\\DataProject\\" };
	char d[505] = ""; char d2[300]="";
	strcat(d2,dirD);
	strcat(d2, "Account_student.txt");
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	strcat(d, "\\");
	strcat(d, "Student.txt");
     
	ofstream fOut;
	fstream fOut2;   	
	if (add)
	{
		fOut.open(d);
		fOut2.open(d2);
		fOut2.seekg(0,fOut2.end);
		fOut2 << newStu -> studentID << ' ' << '1' <<'\n';
		
	}
		

    newStu -> sClass = className;
	newStu -> enrolledSession = new bool* [8];
	for (int i = 0; i < 7; i++) {
		newStu -> enrolledSession[i] = new bool[5];
		for (int j = 0; j < 4; j++)
			newStu -> enrolledSession[i][j] = false;
	}

	if (pStudent == nullptr) {
		pStudent = newStu;
		if (add)
		{
				fOut << pStudent -> studentID << ',' << pStudent -> Name << ',' << pStudent -> DOB.year << "-" << pStudent -> DOB.month << "-" << pStudent -> DOB.day << ',' << pStudent -> gender << '\n';
				//fOut2 << pStudent -> studentID << " " << "1" <<'\n';
		}
	}
	else {
		Student* pCur = pStudent;
		while (pCur -> studentNext != nullptr) {
			pCur = pCur -> studentNext;
			if (add)
			{
				fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
				//fOut2 << pCur -> studentID << " " << "1" <<'\n';	
			}
		}
		if (add)
		{
				fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
				//fOut2 << pCur -> studentID << " " << "1" <<'\n';
		}
		pCur -> studentNext = newStu;
		pCur = pCur -> studentNext;
		if (add)
			{
			fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
			//fOut2 << pCur -> studentID << " " << "1" <<'\n';
			}
	}
	if (add)
		{
		fOut.close();
		fOut2.close();
		}
	
}
