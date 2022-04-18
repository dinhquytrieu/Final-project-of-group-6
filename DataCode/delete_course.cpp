void deleteCourse(Year * pYear, Course*& pCourse, char* semesterName, char* courseID) {
	
  if (strcmp(pCourse->id, courseID) == 0) {
        Course* pDel = pCourse;
        pCourse = pCourse->courseNext;
        delete pDel;
    }
    else {
        Course* pCur = pCourse;
        while (pCur->courseNext && strcmp(pCur->courseNext->id, courseID) != 0) {
            pCur = pCur -> courseNext;
        }
        if (pCur->courseNext) {
            Course* pDel = pCur->courseNext;
            pCur->courseNext = pDel->courseNext;
            delete pDel;
        }
    }
	char path[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
    char c[500] = "";
    strcat(c, path);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);
    strcat(c, "\\Course.txt");

    ofstream fout(c);

    Course * pCur = pCourse;
    while (pCur != nullptr) {
        fout << pCur -> id << '\n';
        fout << pCur -> name << '\n';
        fout << pCur -> lecturerName << '\n';
        fout << pCur -> numberOfCredits << '\n';
        fout << pCur -> maxStudent << '\n';
        fout << pCur -> date.d1 << '\n' << pCur->date.s1 << '\n';
	    fout << pCur -> date.d2 << '\n' << pCur->date.s2 << '\n';
    	pCur = pCur -> courseNext;
 	}
 	fout.close();
}
