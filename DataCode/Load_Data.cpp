#include <sstream>
#include <cassert>
#include <iostream>
#include <fstream>
#include <string.h>
#include "Header.h"
#include "Class.h"
#include "Course.h"
#include "Staff.h"
#include "Student.h"
#include "System.h"

using namespace std;

void loadData(Year * & pYear) {
	ifstream yearIn("C:\\GitHub\\Final-project-of-group-6\\datafile\\Year.txt");

  
// 	while (yearIn >> yearStr) { // Load Years
// 		char *yearName = new char[51];
// 		strcpy(yearName, yearStr);
// 		createNewYear(pYear, yearName, 0);

// 		Year* curYear = pYear;
// 		while(strcmp(curYear -> YearName, yearName) != 0) {
// 			curYear = curYear -> yearNext;
// 		}
  while(yearIn.eof() == 0){
  		string yearStr;
  		yearIn.ignore();
  		getline(yearIn, yearStr);
  		
  		Year *newYear = new Year;
  		newYear
  		if(pYear == nullptr){
  			
		  }
  }
    
		char dir_c[501] = "C:\\Github\\CS162FinalProject\\Data\\";
		strcat(dir_c, yearName);
		strcat(dir_c, "\\Class.txt");

 		ifstream classIn(dir_c);
		char *classStr = new char[51];
 		while (classIn >> classStr) { // Load Classes                                
 			char *className = new char[51];
 			strcpy(className, classStr);
 			createNewClass(curYear -> pClass, yearName, className, 0);
		
		    Class* curClass = curYear -> pClass;
		    while(strcmp(curClass -> ClassName, className) != 0)
		    	curClass = curClass -> classNext;
					    	    
			char dir[501] = "C:\\Github\\CS162FinalProject\\Data\\";
			strcat(dir, yearName);
			strcat(dir, "\\");
			strcat(dir, className);
			strcat(dir, "\\Student.txt");
 			ifstream studentIn(dir);

			char *s = new char[505];
			int t = 0;

			while(studentIn.getline(s, 505)) { // Load Students in class
				Student * newStu = new Student;
              	int t = 0, n = strlen(s);
              	int pos = 0;
              	char *cur = new char[505];
              	for (int i = 0; i < n; i++) {
              		if (i == n - 1 || s[i] == ',') {
              			if (t == 0) {
              				newStu -> studentID = new char[pos + 10];
              				for (int j = 0 ; j < pos; j++)
              					newStu -> studentID[j] = cur[j];
              				newStu -> studentID[pos] = '\0';					
              			} 
              			else if (t == 1) {
              				newStu -> Name = new char[pos + 10];
              				for (int j = 0 ; j < pos; j++)
              					newStu -> Name[j] = cur[j];
              				newStu -> Name[pos] = '\0';
              			}
              			else if (t == 2) {
              				newStu -> DOB.year = (cur[0] - '0') * 1000 + (cur[1] - '0') * 100 + (cur[2] - '0') * 10 + (cur[3] - '0');
              				if (cur[6] != '-') {
	              				newStu -> DOB.month = (cur[5] - '0') * 10 + (cur[6] - '0');
	              				if (pos != 9)
		              				newStu -> DOB.day = (cur[8] - '0') * 10 + (cur[9] - '0');
		              			else
		              				newStu -> DOB.day = (cur[8] - '0');
							}
							else {
	              				newStu -> DOB.month = (cur[5] - '0');
	              				if (pos != 8)
		              				newStu -> DOB.day = (cur[7] - '0') * 10 + (cur[8] - '0');
		              			else
		              				newStu -> DOB.day = (cur[7] - '0');								
							}
              			}
              			else if (t == 3) {
							newStu -> gender = s[i] - '0';
              			}
              			t++;
              			pos = 0;
              		}
              		else 
              			cur[pos++] = s[i];
              	}
				addStudent(curClass -> pStudent, yearName, className, newStu, 0);

				Student * curStudent = curClass -> pStudent;
				while(strcmp(curStudent -> Name, newStu -> Name) != 0)
					curStudent = curStudent -> studentNext;

				// Load some data to current student
			}
			studentIn.close();
 		}
 		classIn.close();

		char dir_s[501] = "C:\\Github\\CS162FinalProject\\Data\\";
		strcat(dir_s, yearName);
		strcat(dir_s, "\\Semester\\Semester.txt");

		ifstream semesterIn(dir_s);
		char* semesterStr = new char[501];
		while (semesterIn.getline(semesterStr, 500)) { // Load Semester
			istringstream iss(semesterStr);
			char * semesterName = new char[51];
			Date startDate, endDate;
			for (int _ = 0; _ < 7; _++) {				
				char * tmp = new char[51];
				iss >> tmp;				
				if (_ == 0)
					semesterName = tmp;
				else if (_ == 1)
					startDate.year = atoi(tmp);	
				else if (_ == 2)
					startDate.month = atoi(tmp);	
				else if (_ == 3)
					startDate.day = atoi(tmp);	
				else if (_ == 4)
					endDate.year = atoi(tmp);	
				else if (_ == 5)
					endDate.month = atoi(tmp);	
				else if (_ == 6)
					endDate.day = atoi(tmp);	
			}	
			createNewSemester(curYear -> pSemester, semesterName, yearName, startDate, endDate, 0);

			Semester * curSemester = curYear -> pSemester;
			while(strcmp(curSemester -> SemesterName, semesterName) != 0)
				curSemester = curSemester -> semesterNext;

			for (int _ = 7; _ < 13; _++) {
				char * tmp = new char[51];
				iss >> tmp;				
				if (_ == 7)
					curSemester -> startReg.year = atoi(tmp);
				else if (_ == 8)
					curSemester -> startReg.month = atoi(tmp);	
				else if (_ == 9)
					curSemester -> startReg.day = atoi(tmp);	
				else if (_ == 10)
					curSemester -> endReg.year = atoi(tmp);	
				else if (_ == 11)
					curSemester -> endReg.month = atoi(tmp);	
				else if (_ == 12)
					curSemester -> endReg.day = atoi(tmp);	
			}

			char dir[501] = "C:\\Github\\CS162FinalProject\\Data\\";
			strcat(dir, yearName);
			strcat(dir, "\\Semester\\");
			strcat(dir, semesterName);
			strcat(dir, "\\Course.txt");
	
			ifstream courseIn(dir);
	
			char* courseStr = new char[505];
			int _ = 0;
    		Course * newCourse;
			while (courseIn.getline(courseStr, 500)) { // Load course
				if (_ == 0)
					newCourse = new Course;

				char * tmp = new char[501];
				strcpy(tmp, courseStr);

    			if (_ == 0)
    				newCourse -> id = tmp;
    			else if (_ == 1)
    				newCourse -> name = tmp;	
    			else if (_ == 2)
    				newCourse -> lecturerName = tmp;	
    			else if (_ == 3)
    				newCourse -> numberOfCredits = atoi(tmp);	
    			else if (_ == 4)
    				newCourse -> maxStudent = atoi(tmp);	
    			else if (_ == 5)
    				newCourse -> date.d1 = tmp;	
    			else if (_ == 6)
    				newCourse -> date.s1 = tmp;	
    			else if (_ == 7)
    				newCourse -> date.d2 = tmp;	
    			else if (_ == 8)
    				newCourse -> date.s2 = tmp;	

				_ = (_ + 1) % 9;
				
				if (_ == 0) {
					addNewCourse(curSemester -> pCourse, semesterName, yearName, newCourse, 0);
		
					Course * curCourse = curSemester -> pCourse;
					while(strcmp(curCourse -> name, newCourse -> name) != 0)
						curCourse = curCourse -> courseNext;
	
					// Load Students to current Course					
					char dir_stu[501] = "C:\\Github\\CS162FinalProject\\Data\\";
					strcat(dir_stu, yearName);
					strcat(dir_stu, "\\Semester\\");
					strcat(dir_stu, semesterName);
					strcat(dir_stu, "\\");
					strcat(dir_stu, newCourse -> id);
					strcat(dir_stu, "\\Student.txt");

					ifstream fIn(dir_stu);
					char *studentID = new char[101];
					while (fIn >> studentID) {
	    				Student * curStudent = nullptr;
    					Class * curClass = curYear -> pClass;
    					while (curClass) {
    						curStudent = curClass -> pStudent;
    						while (curStudent) {
    							if (strcmp(curStudent -> studentID, studentID) == 0)
    								break;
    							curStudent = curStudent -> studentNext;
    						}
    						if (curStudent != nullptr) break;
    						curClass = curClass -> classNext;
    					}

    					enrollStudent(curSemester -> pCourse, curClass -> pStudent, newCourse -> id, studentID, yearName, semesterName, 0);
					}
					fIn.close();

					// Load Scoreboard of current Course
					char dir_sco[501] = "C:\\Github\\CS162FinalProject\\Data\\";
					strcat(dir_sco, yearName);
					strcat(dir_sco, "\\Semester\\");
					strcat(dir_sco, semesterName);
					strcat(dir_sco, "\\");
					strcat(dir_sco, newCourse -> id);
					strcat(dir_sco, "\\Scoreboard.txt");					

					fIn.open(dir_sco);
					char* s = new char[505];
					while (fIn.getline(s, 505)) {
                		Scoreboard *newScr = new Scoreboard;
                	    inputScoreboardCSV(newScr, s);
                		if (curCourse -> pScoreboard == nullptr)
                			curCourse -> pScoreboard = newScr;
                		else {
                			Scoreboard* pCur = curCourse -> pScoreboard;
                			while (pCur -> scoreboardNext != nullptr)
                				pCur = pCur -> scoreboardNext;
                			pCur -> scoreboardNext = newScr;
                		}						
					}
					delete[] s;
					fIn.close();
				}
			}
			courseIn.close();
		}
		semesterIn.close();			
	}
	yearIn.close();
}
