#include <iostream>
 #include <bits/stdc++.h>
 #include <Windows.h>
 #include <conio.h>
 using namespace std;
struct Time;
struct Date;
struct Student;
struct Scoreboard;
struct Class;
struct Year;
struct Semester;
struct dayPerformed;
struct Course;
struct cursorLocation;

struct Time {
	int hours;
	int mins;
};

struct Date {
	int day = -1;
	int month = -1;
	int year = -1;
};

struct Student
{
	char* studentID;
	char* Name;
	Date DOB;
	char* sClass;
	int gender; // 0 if male, 1 if female
	bool **enrolledSession;
	Course *pCourse = nullptr;
	Student *studentNext = nullptr;
};

struct Scoreboard {
	Student *stu;
	float midterm;
	float final;
	float bonus;
	float total;
	Scoreboard *scoreboardNext = nullptr;
};

struct Class {
	char *ClassName;
	Student *pStudent = nullptr;
	Class *classNext = nullptr; 
};

struct Year {
	char *YearName;
	Class *pClass = nullptr;
	Semester *pSemester = nullptr;
	Year *yearNext = nullptr;
};

struct Semester {
	char *SemesterName;
	Date startDate, endDate;
	Date startReg, endReg;
	Course *pCourse = nullptr;
	Semester *semesterNext = nullptr;
};

struct dayPerformed {
	char *d1; // day
	char *d2;
	char *s1; // shift
	char *s2;
};

struct Course {
	char *id;
	char *name;
	char *lecturerName;
	char *sSemester;
	int numberOfCredits;
	int maxStudent;
	dayPerformed date;
	Student* pStudent = nullptr;
	Course* courseNext = nullptr;
	Scoreboard* pScoreboard = nullptr;
};
struct cursorLocation
{
	int x;
	int y;
};

void createNewClass(Class*& pClass, char* yearName, char* className, int add);
void inputStudent(Student *&newStu);
void addStudent(Student*& pStudent, char* yearName, char* className, Student *& newStu, int add);

// Add student by CSV file

void inputStudentCSV(Student *&newStu, char *s);
void addStudentCSV(Student*& pStudent, char* CSV_Student_File, char* yearName, char* className, int add);

// Create year

void createNewYear(Year*& pYear, char* yearName, int add);

// Create Semester

void createNewSemester(Semester*& pSemester, char* semesterName, char* yearName, Date startDate, Date endDate, int add);

// Create Course registration session

void courseRegistration(Semester *& pSemester, Semester *totSemetser, char * yearName);

// Create Course

void addNewCourse(Course*& pCourse, char* semesterName, char* yearName, Course *& newCourse, int add);

//View list of all course available

void viewListOfCourse(Course * pCourse);

 // Delete Course

void deleteCourse (Year * pYear, Course*& pCourse, char* yearName, char* semesterName, char* courseID);

// Update Course

void updateCourse (Course*& pCourse, char* yearName, char* semesterName, char* courseID);

void viewListOfCLasses(Year* pYear);

void viewStudentInfo(Student student);
void viewListOfStudentsInClass(Year* pYear, char* className);
void viewScoreBoardOfClass(Student * pStudent, Semester * pSemester);

void viewListOfStudentsInCourse (Student *pStuInCourse, char *courseID);
void viewScoreboardOfCourse (Course *pCourse);

void inputScoreboardCSV(Scoreboard *& newScr , char *s);
void addScoreBoardCSV(Scoreboard *& pScore, char * yearName, char * semesterName, char * courseName);
void exportStudentToCsv(Student* pStuInCourse, char *courseID);
void updateScoreBoardStudent(Scoreboard *& pScr, char *yearName, char* semesterName, char *courseID, char* studentID);

void enrollStudent(Course *& pCourse, Student *& pStudent, char* CourseID, char* StudentID, char * yearName, char * semesterName, int add);
void removeCourseInEnrollList(Course *& pCourse, Student*& pStudnet, char *yearName, char *semesterName, char* CourseID, char *studentID);
void viewEnrollList(Course* pEnrollCourse, char * semesterName);

void viewScoreBoard(Course* pCourse, char* studentID); // task 26
void loadData(Year *& pYear);

int chooseRoleScreen();
bool LogIn(int t, char *& studentID);
void changePassword(int t, char * username);

int yearScreen();
void createYearScreen(Year*& pYear);

int classScreen(char* yearName);
void createClassScreen(Class *& pClass, char* yearName);

int studentScreen(Student * pStudent, char* yearName, char* className);
void createStudentScreen(Student *& pStudent, char* yearName, char* className);
void createStudentCSVScreen(Student *& pStudent, char* yearName, char* className);

int semesterScreen(Semester *& pSemester);
void createSemesterScreen(Semester *& pSemester, char* yearName);

int courseScreen(Course *& pCourse, char* semesterName);
void addCourseScreen(Course *& pCourse, char* yearName, char* semesterName);

int editCourseScreen(Course *& curCourse);

int enrollSemesterScreen(Year *& pYeawr, char * studentID);
int enrollCourseScreen(char *semesterName);
int chooseCourse(Course *& pCourse);

int viewAndDeleteCourseScreen(Course *& pCourse, char * semesterName);
void deleteCourseScreen(Course * pCourse, Student * pStudent, char * yearName, char * semesterName, char * studentID);

void viewOrAddScoreBoard(Course *curCourse, char * yearName, char * semesterName);
void gotoXY(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void setConsoleWindow(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, w, h, TRUE);
}
void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void textColor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
void invisibleCursor()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void visibleCursor()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void drawBox(int x, int y, int k)
{
	gotoXY(x, y); cout << char(201);
	for (int i = 0; i < k; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoXY(x, y + 1); cout << char(186);
	for (int j = 0; j < k; j++)
	{
		cout << " ";
	}
	cout << char(186);
	gotoXY(x, y + 2); cout << char(200);
	for (int i = 0; i < k; i++)
	{
		cout << char(205);
	}
	cout << char(188);
}
void moveLeft(int &func)
{
	invisibleCursor();
	if (func == 1)
		func = 0;
	else if (func == 2)
		func = 1;
	else if (func == 0)
		func = 2;
	if (func==1)
	{
		textColor(14);
		int x = 32;int y = 8;
		int k = 20;
		drawBox(x, y, k);
		textColor(7);
		gotoXY(x + 8, y + 1); cout << "STAFF";
		x = 55; y = 8;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
		x = 78; y = 8;
		k = 20;
		drawBox(x, y, k);
		gotoXY(x + 9, y + 1); cout << "QUIT";
	}
	else if(func==2)
	{
		textColor(7);
		int x = 32;int y = 8;
		int k = 20;
		drawBox(x, y, k);
		gotoXY(x + 8, y + 1); cout << "STAFF";
		x = 55; y = 8;
		textColor(14);
		drawBox(x, y, k);
		textColor(7);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
		x = 78; y = 8;
		k = 20;
		drawBox(x, y, k);
		gotoXY(x + 9, y + 1); cout << "QUIT";
	}
	else if (func == 0)
	{
		textColor(7);
		int x = 32;int y = 8;
		int k = 20;
		drawBox(x, y, k);
		gotoXY(x + 8, y + 1); cout << "STAFF";
		x = 55; y = 8;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
		x = 78; y = 8;
		k = 20;
		textColor(14);
		drawBox(x, y, k);
		textColor(7);
		gotoXY(x + 9, y + 1); cout << "QUIT";
	}
}
void moveRight(int& func)
{
	invisibleCursor();
	if (func == 1)
		func = 2;
	else if (func == 2)
		func = 0;
	else if (func == 0)
		func = 1;
	if (func == 1)
	{
		textColor(14);
		int x = 32;int y = 8;
		int k = 20;
		drawBox(x, y, k);
		textColor(7);
		gotoXY(x + 8, y + 1); cout << "STAFF";
		x = 55; y = 8;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
		x = 78; y = 8;
		k = 20;
		drawBox(x, y, k);
		gotoXY(x + 9, y + 1); cout << "QUIT";
	}
	else if (func == 2)
	{
		textColor(7);
		int x = 32;int y = 8;
		int k = 20;
		drawBox(x, y, k);
		gotoXY(x + 8, y + 1); cout << "STAFF";
		x = 55; y = 8;
		textColor(14);
		drawBox(x, y, k);
		textColor(7);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
		x = 78; y = 8;
		k = 20;
		drawBox(x, y, k);
		gotoXY(x + 9, y + 1); cout << "QUIT";
	}
	else if (func == 0)
	{
		textColor(7);
		int x = 32;int y = 8;
		int k = 20;
		drawBox(x, y, k);
		gotoXY(x + 8, y + 1); cout << "STAFF";
		x = 55; y = 8;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
		x = 78; y = 8;
		k = 20;
		textColor(14);
		drawBox(x, y, k);
		textColor(7);
		gotoXY(x + 9, y + 1); cout << "QUIT";
	}
}
void moveUp(cursorLocation& pos)
{
	invisibleCursor();
	if (pos.y == 15)
	{
		pos.x = 54;
		pos.y = 28;
	}
	else if (pos.y == 20)
	{
		pos.x = 38;
		pos.y = 15;
	}
	else if (pos.y == 25)
	{
		pos.x = 38;
		pos.y = 20;
	}
	else if (pos.y == 28)
	{
		pos.x = 54;
		pos.y = 25;
	}
	gotoXY(pos.x, pos.y);
	cout << char(26);
}
void moveDown(cursorLocation& pos)
{
	invisibleCursor();
	 if (pos.y == 15)
	{
		pos.x = 38;
		pos.y = 20;
	}
	else if (pos.y == 20)
	{
		pos.x = 54;
		pos.y = 25;
	}
	else if (pos.y == 25)
	{
		pos.x = 54;
		pos.y = 28;
	}
	else if (pos.y == 28)
	{
		pos.x = 38;
		pos.y = 15;
	}
	gotoXY(pos.x, pos.y);
	cout << char(26);
}
void deleteArrow(cursorLocation pos)
{
	gotoXY(pos.x, pos.y);
	cout << " ";
}
int main() {
	//Input interface

	Year* pYear = nullptr;
	loadData(pYear);
	system("cls");
	time_t cur_t = time(0);
	tm* now = localtime(&cur_t);

	while(true) { // Basic screen, choose which role to login
		int respondRole = chooseRoleScreen();
		if (respondRole == 0) 
			break;
		else if (respondRole == 1) {
			char * userName;
			if (LogIn(1, userName)) { // Login as a Staff
				while(true) { // Edit Year screen
					int respondYear = yearScreen();
					if (respondYear == 0) // Logout 
						return 0;
					else if (respondYear == 1) { // Change password
						changePassword(1, userName);
					}	
					else if (respondYear == 2) { // Create a School Year
						createYearScreen(pYear);	
					}
					else {
						// Access that year
						Year* curYear = pYear;
						int cntYear = 3;
						while (curYear != nullptr && cntYear < respondYear) {
							curYear = curYear -> yearNext;
							cntYear++;
						}
						if (curYear == nullptr || cntYear < respondYear) {
							textColor(4);
							gotoXY(32,1);cout << "Invalid, please try again";
							textColor(7);
							continue;
						}	

						while(true) { // Edit Class screen
							int respondClass = classScreen(curYear -> YearName);
							if (respondClass == 0)
								break;       
							else if (respondClass == 1) { 
								while (true) { // Check all semesters
									int respondSemester = semesterScreen(curYear -> pSemester);
									
									if (respondSemester == 0)
										break;
									else if (respondSemester == 1) { // Create a new Semester in this year
										createSemesterScreen(curYear -> pSemester, curYear -> YearName);	
									}
									else {
     									// Access that semester
     									Semester* curSemester = curYear -> pSemester;
     									int cntSemester = 2;
     									while (curSemester != nullptr && cntSemester < respondSemester) {
     										curSemester = curSemester -> semesterNext;
     										cntSemester++;
     									}
     									if (curSemester == nullptr || cntSemester < respondSemester) {
     										textColor(4);
											gotoXY(32,1);cout << "Invalid, please try again";
											textColor(7);
     										continue; 
     									}

     									while (true) { // Edit Course screen  
     										int respondCourse = courseScreen(curSemester -> pCourse, curSemester -> SemesterName);

     										if (respondCourse == 0)
     											break;
     										else if (respondCourse == 1) { // Create a course registration session
												courseRegistration(curSemester, curYear -> pSemester, curYear -> YearName);												     											
     										}	
     										else if (respondCourse == 2) { // Add a course to this semester
     											addCourseScreen(curSemester -> pCourse, curYear -> YearName, curSemester -> SemesterName);
     										}
     										else if (respondCourse == 3) {	// View the details of all the courses
     											viewListOfCourse(curSemester -> pCourse);
     										}
											else {
												// Access that Course
												
												int cntCourse = 4;
												Course *curCourse = curSemester -> pCourse;
												while (curCourse != nullptr && cntCourse < respondCourse) {
													curCourse = curCourse -> courseNext;
													cntCourse++;
												}
												if (curCourse == nullptr || cntCourse < respondCourse) {
     												cout << "Invalid, please try again\n\n";
		     										continue;
												}

     											while (true) { // Edit the current course
	     											int respondEditCourse = editCourseScreen(curCourse);
	     											if (respondEditCourse == 0) {
    	 												break;
	     											}
	     											else if (respondEditCourse == 1) { // Update course information
														updateCourse(curSemester -> pCourse, curYear -> YearName, curSemester -> SemesterName, curCourse -> id);
	     											}
	     											else if (respondEditCourse == 2) { // View list of students in this course
	     												viewListOfStudentsInCourse(curCourse -> pStudent, curCourse -> id);
	     											}
	     											else if (respondEditCourse == 3) { // View the scoreboard of this course
	     												viewOrAddScoreBoard(curCourse , curYear -> YearName, curSemester -> SemesterName);	
	     											}
	     											else if (respondEditCourse == 4) { // Delete the current course
														deleteCourse(curYear, curSemester -> pCourse, curYear -> YearName, curSemester -> SemesterName, curCourse -> id);
														break;
	     											}
	     											else 
	     												cout << "Invalid, please try again\n\n";
												}
											}
     									}
     								}
								}
							}
							else if (respondClass == 2) { // Create a Class in this year
								createClassScreen(curYear -> pClass, curYear -> YearName);
							}                         
							else {           
								//Access that class
								Class* curClass = curYear -> pClass;
								int cntClass = 3;
								while (curClass != nullptr && cntClass < respondClass) {
									curClass = curClass -> classNext;
									cntClass++;
								}
								if (curClass == nullptr || cntClass < respondClass) {
									textColor(4);
						gotoXY(45,1);cout << "Invalid, please try again\n\n";
						textColor(7);
									continue;
								}

								while (true) { // Edit Student Screen
									int respondStudent = studentScreen(curClass -> pStudent, curYear -> YearName, curClass -> ClassName);
									if (respondStudent == 0)
										break;
									else if (respondStudent == 1) { // Create a new student in this class
										createStudentScreen(curClass -> pStudent, curYear -> YearName, curClass -> ClassName);
									}	
									else if (respondStudent == 2) { // Add students through .csv file
										createStudentCSVScreen(curClass -> pStudent, curYear -> YearName, curClass -> ClassName);										
									}
									else if (respondStudent == 3) {	// View scoreboard of a class
										viewScoreBoardOfClass(curClass -> pStudent, curYear -> pSemester);
									}
									else
										cout << "Invalid, please try again\n\n";
								}
							}
						}	
					}
				}	
			}
		}
		else if (respondRole == 2) {
			char * studentID;
			if (LogIn(2, studentID)) { // Login as a Student

   				char * yearName = new char[51];
   				int tmp = (studentID[0] - '0') * 10 + studentID[1] - '0';
   				char tmp_c[40] = "";
   				strcat(yearName, "20");
   				strcat(yearName, itoa(tmp, tmp_c, 10));
   				strcat(yearName, "-20");
   				strcat(yearName, itoa(tmp + 1, tmp_c, 10));

   				Year * curYear = pYear;
   				while (curYear && strcmp(curYear -> YearName, yearName) != 0)
   					curYear = curYear -> yearNext;

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

   				Date RegisterDate;
   				RegisterDate.day = now -> tm_mday;
   				RegisterDate.month = now -> tm_mon + 1;
   				RegisterDate.year = now -> tm_year + 1900;

				while (true) {  // Choose a semester to enroll

    				int respondSemester = enrollSemesterScreen(curYear, studentID);
    				if (respondSemester == 0) // Logout
    					return 0;
    				else if (respondSemester == 1) {// Change password
    					changePassword(2, studentID);
    				}						
    				else {
         				// Access that semester
       					Semester* curSemester = curYear -> pSemester;
       					int cntSemester = 2;
       					while (curSemester != nullptr && cntSemester < respondSemester) {
       						curSemester = curSemester -> semesterNext;
       						cntSemester++;
       					}
       					if (curSemester == nullptr || cntSemester < respondSemester) {
       						cout << "Invalid, please try again\n\n";
       						continue; 
       					}


       					while (true) {
       						int respondCourse = enrollCourseScreen(curSemester -> SemesterName);
       						if (respondCourse == 0)
       							break;
       						else if (respondCourse == 1) { // Choose a course to enroll

       							bool ok_s = false, ok_l = false;
       							if (curSemester -> startReg.year < RegisterDate.year) ok_s = true;
       							if (curSemester -> startReg.year == RegisterDate.year && curSemester -> startReg.month < RegisterDate.month) ok_s = true;
       							if (curSemester -> startReg.year == RegisterDate.year && curSemester -> startReg.month == RegisterDate.month && curSemester -> startReg.day < RegisterDate.day) ok_s = true;
       							if (RegisterDate.year < curSemester -> endReg.year) ok_l = true;
       							if (RegisterDate.year == curSemester -> endReg.year && RegisterDate.month < curSemester -> endReg.month) ok_l = true;
       							if (RegisterDate.year == curSemester -> endReg.year && RegisterDate.month == curSemester -> endReg.month && RegisterDate.day < curSemester -> endReg.day) ok_l = true;

								if (!ok_s || !ok_l) {
                            		cout << "The registration phase has expired or not exist, cannot enrolled\n\n";
                            		continue;
								}

								while (true) { // List of course to choose screen
									int respondChooseCourse = chooseCourse(curSemester -> pCourse);

									if (respondChooseCourse == 0)
										break;
									else {
										int cntCourse = 1;
										Course * curCourse = curSemester -> pCourse;
										while(curCourse && cntCourse < respondChooseCourse) {
											cntCourse++;
											curCourse = curCourse -> courseNext;
										}
										if (curCourse == nullptr || cntCourse < respondChooseCourse) {
											cout << "Invalid, please try again\n\n";
											continue;
										}
										enrollStudent(curSemester -> pCourse, curClass -> pStudent, curCourse -> id, curStudent -> studentID, curYear -> YearName, curSemester -> SemesterName, 1);
									}
								}
       						}	
       						else if (respondCourse == 2) { // View list of enrolled course
       							while(1) {
	       							int respondViewAndDelete = viewAndDeleteCourseScreen(curStudent -> pCourse, curSemester -> SemesterName);
	       							if (respondViewAndDelete == 0) 
	       								break;
									else
										deleteCourseScreen(curSemester -> pCourse, curStudent, curYear -> YearName, curSemester -> SemesterName, curStudent -> studentID);
								}
       						}
       						else if (respondCourse == 3) { // View scoreboard in this semester
       							viewScoreBoard(curSemester -> pCourse, curStudent -> studentID);
       						}
       						else
       							cout << "Invalid, please try again\n\n";
       					}
    				}
				}
			}
		}
		else
			cout << "Invalid, please try again\n\n";
	}
	
	yearScreen();
}






void addNewCourse(Course*& pCourse, char* semesterName, char* yearName, Course *& newCourse, int add) {
   	Course * pCur = pCourse;
   	while (pCur != nullptr) {
   		if (strcmp(pCur -> id, newCourse -> id) == 0) {
			cout << "Failed to add a new course!!\n";
			cout << "The course you are about to add has already existed!!\n";
			system("pause");
			system("cls");
			return;
   		}
   		pCur = pCur -> courseNext;
   	}
    char dirD[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
    char c[505] = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);

	char mkdir[505] = "mkdir ";
	strcat(mkdir, c);
	strcat(mkdir, "\\");
	strcat(mkdir, newCourse -> id);
	system(mkdir);

    strcat(c, "\\Course.txt");

    ofstream fout;

    if (add == 1)
	    fout.open(c);

   	pCur = pCourse;

    if (!pCourse) {
        pCourse = newCourse;
        pCur = pCourse;
    }
    else {
        while (pCur -> courseNext) {
            pCur = pCur -> courseNext;
        }
        pCur -> courseNext = newCourse;
        pCur = pCur -> courseNext;
    }

    if (add == 1) {
    	pCur = pCourse;
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
 	}

    if (add == 1)
	    fout.close();
}

void inputScoreboardCSV(Scoreboard *& newScr , char *s) {
	int t = 0, n = strlen(s);
	char *cur = new char[505]; 
	int pos = 0;
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] == ',') {
			if (i == n - 1)
				cur[pos++] = s[i];
			cur[pos] = '\0';
			if (t == 0) {
				newScr -> stu = new Student;
			}
			else if (t == 1) {
				newScr -> stu -> studentID = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newScr -> stu -> studentID[j] = cur[j];
				newScr -> stu -> studentID[pos] = '\0';					
			} 
			else if (t == 2) {
				newScr -> stu -> Name = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newScr -> stu -> Name[j] = cur[j];
				newScr -> stu -> Name[pos] = '\0';
			}
			else if (t == 3) {
				newScr -> midterm = atof(cur);
			}
			else if (t == 4) {
				newScr -> final = atof(cur); 
			}
			else if (t == 5) {
				newScr -> bonus = atof(cur); 
			}else if(t == 6) {
				newScr -> total = atof(cur);
			}
			t++;
			pos = 0;
		}
		else 
			cur[pos++] = s[i];
	} 
	delete[] cur;
}


void addScoreBoardCSV(Scoreboard *& pScore, char* yearName, char* semesterName, char* courseName) {
	char dirOut[] = { "C:\\Github\\Final-project-of-group-6\\DataProject\\" };

	/* The course has already been chosen in courseName so we don't need this part
	char d[505] = "";
	strcat(d, dirOut);
	strcat(d, yearName);
	strcat(d, "\\Semester\\");
	strcat(d, semesterName);
	strcat(d, "\\");
	strcat(d, "Course.txt");

	ifstream fin;
	
	fin.open(d);
	if(!fin.is_open()){
		cout << "Error at open Course.txt" << endl;
		return;
	}else{
		system("cls");
		cout << ">>Course: " << endl;
		int n;
		fin >> n;
		for(int i = 0; i < n; i++){
			char tcourse[20];
			fin.ignore(100, '\n');
			fin.get(tcourse, 20, '\n');
			cout << "[" << i+1 << "] " << tcourse << endl;
		}
		cout << "Please input a course: ";
		char mycourse[20];
		cin.ignore(100, '\n');
		cin.get(mycourse, 20, '\n'); 
	}
	fin.close();
	*/
	
	char dc[201] = "";
	strcat(dc, courseName);
	strcat(dc, ".txt");
	
	char ddd[505] = "";
	strcat(ddd, dirOut);
	strcat(ddd, yearName);
	strcat(ddd, "\\Semester\\");
	strcat(ddd, semesterName);
	strcat(ddd, "\\");
	strcat(ddd, courseName);
	strcat(ddd, "\\");
	strcat(ddd, "Scoreboard.txt");

	ofstream fOut(ddd);

	char dirIn[] = { "C:\\Github\\Final-project-of-group-6\\DataProject\\Scoreboard_csv\\" };
	char dd[505] = "";
	strcat(dd, dirIn);
	strcat(dd, courseName);
	strcat(dd, ".csv");


	ifstream fIn(dd);

	if (!fIn.is_open()) {
		cout << "Cannot locate the file\n";
		system("pause");
		system("cls");
		return;
	}

	char* s = new char[505];
	while (fIn.getline(s, 505)) {
		Scoreboard *newScr = new Scoreboard;
	    inputScoreboardCSV(newScr, s);
	
		if (pScore == nullptr)
			pScore = newScr;
		else {
			Scoreboard* pCur = pScore;
			while (pCur -> scoreboardNext != nullptr)
				pCur = pCur -> scoreboardNext;
			pCur -> scoreboardNext = newScr;
		}
	}

	Scoreboard *pCur = pScore;
	int cnt = 0;
	while (pCur != nullptr) {
		fOut << ++cnt << ',' << pCur -> stu -> studentID << ',' << pCur -> stu -> Name << ',' << pCur -> midterm << ',' << pCur -> final << ',' << pCur -> bonus << ',' << pCur -> total << '\n';
		pCur = pCur -> scoreboardNext;
	}
	fOut.close();
	delete[] s;
}
void inputStudent(Student *&newStu) {
	cin.get();

	cout << "Input the student's ID: ";
	newStu -> studentID = new char[51];
	cin.getline(newStu -> studentID, 50);

	cout << "Input the student's name: ";
	newStu -> Name = new char[51];
	cin.getline(newStu -> Name, 50);

	cout << "Input the student's date of birth.\n";
	cout << "Year? ";
	cin >> newStu -> DOB.year;
	cout << "Month? ";
	cin >> newStu -> DOB.month;
	cout << "Day? ";
	cin >> newStu -> DOB.day;
	cin.get();

	cout << "Input the student's gender (type 0 if male, 1 if female): ";
	cin >> newStu -> gender;
	cin.get();
	system("cls");
}

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
	char d[505] = "";
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	strcat(d, "\\");
	strcat(d, "Student.txt");

	ofstream fOut;                  	
	if (add)
		fOut.open(d);

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
			fOut << pStudent -> studentID << ',' << pStudent -> Name << ',' << pStudent -> DOB.year << "-" << pStudent -> DOB.month << "-" << pStudent -> DOB.day << ',' << pStudent -> gender << '\n';
	}
	else {
		Student* pCur = pStudent;
		while (pCur -> studentNext != nullptr) {
			pCur = pCur -> studentNext;
			if (add)
				fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
		}
		if (add)
			fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
		pCur -> studentNext = newStu;
		pCur = pCur -> studentNext;
		if (add)
			fOut << pCur -> studentID << ',' << pCur -> Name << ',' << pCur -> DOB.year << "-" << pCur -> DOB.month << "-" << pCur -> DOB.day << ',' << pCur -> gender << '\n';
	}
	if (add)
		fOut.close();
}
void inputStudentCSV(Student *&newStu, char *s) {
	int t = 0, n = strlen(s);
	int pos = 0;
	char *cur = new char[505];
	for (int i = 0; i < n; i++) {
		if (i == n - 1 || s[i] == ',') {
			if (t == 0) {
				// Doing nothing
			}
			else if (t == 1) {
				newStu -> studentID = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newStu -> studentID[j] = cur[j];
				newStu -> studentID[pos] = '\0';					
			} 
			else if (t == 2) {
				newStu -> Name = new char[pos + 10];
				for (int j = 0 ; j < pos; j++)
					newStu -> Name[j] = cur[j];
				newStu -> Name[pos] = '\0';
			}
			else if (t == 3) {
				newStu -> DOB.year = (cur[0] - '0') * 1000 + (cur[1] - '0') * 100 + (cur[2] - '0') * 10 + (cur[3] - '0');
				newStu -> DOB.month = (cur[5] - '0') * 10 + (cur[6] - '0');
				newStu -> DOB.day = (cur[8] - '0') * 10 + (cur[9] - '0');
			}
			else if (t == 4) {
				// Doing nothing		
			}
			else if (t == 5) {
				newStu -> gender = s[i] - '0';
			}
			t++;
			pos = 0;
		}
		else 
			cur[pos++] = s[i];
	} 
	delete[] cur;
}

void addStudentCSV(Student*& pStudent, char* CSV_Student_File, char* yearName, char* className, int add) {
	char dirOut[] = { "C:\\Github\\Final-project-of-group-6\\DataProject\\" };
	char d[505] = "";
	strcat(d, dirOut);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	strcat(d, "\\");
	strcat(d, "Student.txt");

	ofstream fOut(d);

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
		pCur = pCur -> studentNext;
	}
	if (add)
		fOut.close();
	delete[] s;
}

void courseRegistration(Semester *& pSemester, Semester * totSemester, char * yearName) {
	if (pSemester -> startReg.year != -1) {
		while(true) {
			cout << "WARNING!! There's already a course registration session in this semester.\n"; 
			cout << "The registration session for this semester is from " << pSemester -> startReg.year << '/' << pSemester -> startReg.month << '/' << pSemester -> startReg.day << " to "
			<< pSemester -> endReg.year << '/' << pSemester -> endReg.month << '/' << pSemester -> endReg.day << "\n\n";
			cout << "Do you want to overwrite it?\n";
			cout << "1: Yes\n";
			cout << "0: No\n";
			
			cout << "Your input: ";
			char *respond = new char[101]; cin >> respond;
			system("cls");
			if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
				cout << "Invalid, please try again\n\n";
				continue;
			}
			system("cls");
			int x = respond[0] - '0';
			delete[] respond;
			if (x == 0) return;
			else break;
		}
	}
	 
	cout << "Please input the start date of the registration session: \n";
	cout << "Year: "; cin >> pSemester -> startReg.year;
	cout << "Month: "; cin >> pSemester -> startReg.month;
	cout << "Day: "; cin >> pSemester -> startReg.day;
	cout << "Please input the end date of the registration session: \n";	
	cout << "Year: "; cin >> pSemester -> endReg.year;
	cout << "Month: "; cin >> pSemester -> endReg.month;
	cout << "Day: "; cin >> pSemester -> endReg.day;
	cout << "Finish, The registration session for this semester is from " << pSemester -> startReg.year << '/' << pSemester -> startReg.month << '/' << pSemester -> startReg.day << " to "
			<< pSemester -> endReg.year << '/' << pSemester -> endReg.month << '/' << pSemester -> endReg.day << '\n';
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
void changePassword(int t, char * userName) {
	ifstream fIn;
	if (t == 1)
		fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_admin.txt");
	else if (t == 2)
		fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_student.txt");
	char user[101], pass[101];
	while (fIn >> user && fIn >> pass) {
		if (strcmp(user, userName) == 0) {
			while(true) {	
				cout << "Please input your current password: ";
				char cur_pass[101]; cin >> cur_pass;
				if (strcmp(cur_pass, pass) != 0) {
					cout << "Wrong password, please try again later\n";
					system("pause");
					system("cls");
					break;
				}
				cout << "Please input your new password: ";
				char new_pass_1[101]; cin >> new_pass_1;
				cout << "Please input your new password again: ";
				char new_pass_2[101]; cin >> new_pass_2;
				if (strcmp(new_pass_1, new_pass_2) != 0) {
					cout << "The new passwords you just typed in doesn't match, please try again\n";
					system("pause");
					system("cls");
				}
				else {
					fIn.close();
					ofstream fOut;
					if (t == 1) {
						fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_admin.txt");
						fOut.open("C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt");
					}
					else if (t == 2) {
						fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_student.txt");
						fOut.open("C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt");					
					}	
					char userOut[101], passOut[101];
					while (fIn >> userOut && fIn >> passOut) {
						fOut << userOut << ' ';
						if (strcmp(pass, passOut) == 0)
							fOut << new_pass_1 << '\n';							
						else
							fOut << passOut << '\n';
					}
					fIn.close();
					fOut.close();
					if (t == 1) {
						system("del C:\\Github\\Final-project-of-group-6\\DataProject\\Account_admin.txt");
						system("ren C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt Account_admin.txt");
					}
					else if (t == 2) {
						system("del C:\\Github\\Final-project-of-group-6\\DataProject\\Account_student.txt");
						system("ren C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt Account_student.txt");
					}
					system("cls");
					cout << "Password changed successfully\n\n";
					break;           
				}
			}
			break;
		}
	}
}
void deleteCourse(Year * pYear, Course*& pCourse, char* yearName, char* semesterName, char* courseID) {
	while(1) {
		cout << "Are you sure you want to delete this course?\n\n";
		cout << "0: No\n";
		cout << "1: Yes\n\n";

   		cout << "Your input: ";
   		char *respond = new char[101]; cin >> respond;
   		system("cls");
   		if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
   			cout << "Invalid, please try again\n\n";
   			continue;
   		}
   		int x = respond[0] - '0';
   		delete[] respond;
   		if (!x)
   			return;
   		break;		
	}

 	// Then we simply delete this course

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
	char dirD[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
    char c[500] = "";
    strcat(c, dirD);
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
void exportStudentToCsv(Student* pStuInCourse, char *courseID) {
	char dirD[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\Student_csv\\";
	char c[505];
	strcat(c, dirD);
	strcat(c, courseID);
	strcat(c, ".csv");
	ofstream fout;
	fout.open(c);
	if (fout.is_open()) {
		int cnt = 0;
		while (pStuInCourse) {
			fout << ++cnt << "," << pStuInCourse->studentID << "," << pStuInCourse->Name << "," << pStuInCourse->DOB.year << "-" << pStuInCourse -> DOB.month << "-" << 
			pStuInCourse -> DOB.day << "," << pStuInCourse->sClass << "," << pStuInCourse->gender;
			fout << '\n';
			pStuInCourse = pStuInCourse->studentNext;
		}
		cout << "Done! The list of students has been exported into the file Final-project-of-group-6\\DataProject\\Student_csv\\" << courseID << ".csv\n\n";
		system("pause");
		system("cls");
	}
	fout.close();
}

void loadData(Year *& pYear) {
	ifstream yearIn("C:\\Github\\Final-project-of-group-6\\DataProject\\Year.txt");
	char *yearStr = new char[51];
	while (yearIn >> yearStr) { // Load Years
		char *yearName = new char[51];
		strcpy(yearName, yearStr);
		createNewYear(pYear, yearName, 0);

		Year* curYear = pYear;
		while(strcmp(curYear -> YearName, yearName) != 0) {
			curYear = curYear -> yearNext;
		}

		char dir_c[501] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
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
					    	    
			char dir[501] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
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

		char dir_s[501] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
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

			char dir[501] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
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
					char dir_stu[501] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
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
					char dir_sco[501] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
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
bool LogIn(int t, char *& UN)
{
	
	char ad[200] = "";
	bool login = false;
	bool StillLog = true;

	if (t == 1)
		strcat(ad, "C:\\Github\\Final-project-of-group-6\\DataProject\\Account_admin.txt");
	else if (t == 2)
		strcat(ad, "C:\\Github\\Final-project-of-group-6\\DataProject\\Account_student.txt");
			char Username[101]; char Password[101];
		while(!login)
		{
		
			gotoXY(30, 0);
	cout << char(201);
	for (int i = 0; i < 70; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	for (int i = 1; i <= 5; i++)
	{
		gotoXY(30, i);
		cout << char(186);
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
		cout << char(186);
		cout << endl;
	}
	gotoXY(30, 6);
	cout << char(200);
	for (int i = 0; i < 70; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	int x = 41, y = 1;
	textColor(4);
	gotoXY(x, y);   cout << "oooooo";
	gotoXY(x, y+1); cout << "o     o";
	gotoXY(x, y+2); cout << "oooooo ";
	gotoXY(x, y+3); cout << "o      ";
	gotoXY(x, y+4); cout << "o      ";
	textColor(6);
	gotoXY(x+9, y);     cout << " ooooo";
	gotoXY(x+9, y + 1); cout << "o     o";
	gotoXY(x+9, y + 2); cout << "o     o ";
	gotoXY(x+9, y + 3); cout << "o     o ";
	gotoXY(x+9, y + 4); cout << " ooooo  ";
	textColor(14);
	gotoXY(x + 18, y);     cout << "oooooo";
	gotoXY(x + 18, y + 1); cout << "o     o";
	gotoXY(x + 18, y + 2); cout << "oooooo ";
	gotoXY(x + 18, y + 3); cout << "o    o ";
	gotoXY(x + 18, y + 4); cout << "o     o";
	textColor(9);
	gotoXY(x+27, y);     cout << "ooooooo";
	gotoXY(x+27, y + 1); cout << "   o   ";
	gotoXY(x+27, y + 2); cout << "   o   ";
	gotoXY(x+27, y + 3); cout << "   o   ";
	gotoXY(x+27, y + 4); cout << "   o   ";
	textColor(10);
	gotoXY(x + 36, y);      cout << " ooooo ";
	gotoXY(x + 36, y+1);    cout << "o     o";
	gotoXY(x + 36, y+2);    cout << "ooooooo";
	gotoXY(x + 36, y+3);    cout << "o     o";
	gotoXY(x + 36, y+4);    cout << "o     o";
	textColor(11);
	gotoXY(x + 45, y);        cout << "o      ";
	gotoXY(x + 45, y + 1);    cout << "o      ";
	gotoXY(x + 45, y + 2);    cout << "o      ";
	gotoXY(x + 45, y + 3);    cout << "o      ";
	gotoXY(x + 45, y + 4);    cout << "ooooooo";
	textColor(7);
	x = 55; y = 8;
	int k = 20;
	drawBox(x, y, k);
	if(t==1){
	
	gotoXY(x + 8, y + 1); cout << "STAFF";
	}
	else if(t==2)
	{
			gotoXY(x + 7, y + 1); cout << "STUDENT";
	}
	x = 39; y = 14;
	k = 51;
	gotoXY(x, y - 1); cout << "Username:";
	drawBox(x, y, k);
	x = 39; y = 19;
	k = 51;
	gotoXY(x, y - 1); cout << "Password:";
	drawBox(x, y, k);
	x = 55; y = 24;
	k = 19;
	drawBox(x, y, k);
	gotoXY(x + 8, y + 1); cout << "LOGIN";
	x = 55; y = 27;
	k = 19;
	drawBox(x, y, k);
	gotoXY(x + 8, y + 1); cout << "BACK";
	cursorLocation pos;
	pos.x = 38;
	pos.y = 15;
		char ch;
	do
	{
		ch = getch();
		if (ch == -32)
		{
			ch = getch();
		
		if (ch == 72)
			{
				deleteArrow(pos);
				moveUp(pos);
			}
			else if (ch == 80)
			{
				deleteArrow(pos);
				moveDown(pos);
			}
		}
		if (ch == 13)
		{
			if (pos.y == 15)
			{
				//enter username
				visibleCursor();
				gotoXY(40, 15);
				cin>>Username;
				invisibleCursor();
				continue;
			}
			else if (pos.y == 20)
			{
				//enter password
				visibleCursor();
				gotoXY(40, 20);
			cin>>Password;
				invisibleCursor();
				continue;
			}
			else if (pos.y == 25)
			{
			ifstream fin(ad);
		char name[101], pass[101];
		while(fin >> name && fin >> pass){
			if(strcmp(name,Username) == 0 && strcmp(pass, Password) == 0){
				UN = new char[101];
				strcpy(UN, name);
				system("cls");
				login = true;
				break;
			}
		}
		if (login)
			break;
		system("cls");
		textColor(4);
		gotoXY(44,22);
		cout << "Wrong username or password, please try again.";
		textColor(7);
		break;
			}
			else if (pos.y == 28)
			{
				system("cls");
			return login;
			}
		}

	} while (ch != 27);
	}
	return login;
}

void createNewClass(Class*& pClass, char* yearName, char* className, int add) {
	Class* cur = pClass;

	while (cur != nullptr) {
		if (strcmp(cur -> ClassName, className) == 0) {
			cout << "Failed to create a new class!!\n";
			cout << "The class you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		cur = cur -> classNext;
	}

	char dirD[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\Class.txt");

	ofstream fout;
	if (add)
		fout.open(c);

	cur = pClass;

	if (pClass == nullptr) {
		pClass = new Class;
		pClass -> ClassName = className;
		if (add)
			fout << pClass -> ClassName;
	}
	else {
		while (cur -> classNext != nullptr) {
			if (add)
				fout << cur -> ClassName << '\n';
			cur = cur -> classNext;
		}
		if (add)
			fout << cur -> ClassName << '\n';
		cur -> classNext = new Class;
		cur = cur -> classNext;
		cur -> ClassName = className;
		if (add)
			fout << cur -> ClassName;
	}
	if (add)
		fout.close();

	char d[500] = "";
	strcat(d,  "mkdir ");
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\");
	strcat(d, className);
	system(d);
}
void createNewYear(Year*& pYear, char* yearName, int add) {
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
		fout.open("C:\\GitHub\\Final-project-of-group-6\\DataProject\\Year.txt");

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

	char dirD[] = "C:\\GitHub\\Final-project-of-group-6\\DataProject\\";
	char c[500] = "";
	strcat(c, "mkdir ");
	strcat(c, dirD);
	strcat(c, yearName);
	system(c);
}
void createNewSemester(Semester*& pSemester, char* semesterName, char* yearName, Date startDate, Date endDate, int add) {
	Semester* cur = pSemester;

	while (cur != nullptr) {
		if (strcmp(cur -> SemesterName, semesterName) == 0) {
			cout << "Failed to create a new semester!!\n";
			cout << "The semester you are about to create has already existed!!\n";
			system("pause");
			system("cls");
			return;
		}
		cur = cur -> semesterNext;
	}

	char dirD[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
	char c[500] = "";
	strcat(c, dirD);
	strcat(c, yearName);
	strcat(c, "\\Semester");
	strcat(c, "\\Semester.txt");

	ofstream fOut;
	if (add)
		fOut.open(c);

	cur = pSemester;

	if (pSemester == nullptr) {
		pSemester = new Semester;
		pSemester -> SemesterName = semesterName;
		pSemester -> startDate = startDate;
		pSemester -> endDate = endDate;
	}
	else {
		while (cur -> semesterNext != nullptr) {
			cur = cur -> semesterNext;
		}

		cur -> semesterNext = new Semester;
		cur = cur -> semesterNext;
		cur -> SemesterName = semesterName;
		cur -> startDate = startDate;
		cur -> endDate = endDate;
	}

	if (add) {
		cur = pSemester;
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

	char d[500] = "";
	strcat(d, "mkdir ");
	strcat(d, dirD);
	strcat(d, yearName);
	strcat(d, "\\Semester\\");
	strcat(d, semesterName);
	system(d);
}
void removeCourseInEnrollList(Course*& pCourse, Student*& pStudent, char *yearName, char *semesterName, char* CourseID, char* studentID) {
	while(1) {
		cout << "Are you sure you want to unenroll from this course?\n\n";
		cout << "0: No\n";
		cout << "1: Yes\n";
		cout << '\n';

   		cout << "Your input: ";
   		char *respond = new char[101]; cin >> respond;
   		system("cls");
   		if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
   			cout << "Invalid, please try again\n\n";
   			continue;
   		}
   		int x = respond[0] - '0';
   		delete[] respond;
   		if (!x)
   			return;
   		break;		
	}

	int d1, d2, s1, s2;

	if (strcmp(pCourse -> date.d1, "MON") == 0) d1 = 2;
	else if (strcmp(pCourse -> date.d1, "TUE") == 0) d1 = 3;
	else if (strcmp(pCourse -> date.d1, "WED") == 0) d1 = 4;
	else if (strcmp(pCourse -> date.d1, "THU") == 0) d1 = 5;
	else if (strcmp(pCourse -> date.d1, "FRI") == 0) d1 = 6;
	else if (strcmp(pCourse -> date.d1, "SAT") == 0) d1 = 7;
	s1 = (pCourse -> date.s1)[1] - '0';

	if (strcmp(pCourse -> date.d2, "MON") == 0) d2 = 2;
	else if (strcmp(pCourse -> date.d2, "TUE") == 0) d2 = 3;
	else if (strcmp(pCourse -> date.d2, "WED") == 0) d2 = 4;
	else if (strcmp(pCourse -> date.d2, "THU") == 0) d2 = 5;
	else if (strcmp(pCourse -> date.d2, "FRI") == 0) d2 = 6;
	else if (strcmp(pCourse -> date.d2, "SAT") == 0) d2 = 7;
	s2 = (pCourse -> date.s2)[1] - '0';

	pStudent -> enrolledSession[d1][s1] = false;
	pStudent -> enrolledSession[d2][s2] = false;

	Course *& pEnrollCourse = pStudent -> pCourse;
	Student *& pStuInCourse = pCourse -> pStudent;

    if (strcmp(pEnrollCourse -> id, CourseID) == 0) {
    	Course* pDel = pEnrollCourse;
    	pEnrollCourse = pEnrollCourse -> courseNext;
    	delete pDel;
    }
    else {
    	Course * pCur = pEnrollCourse;
		while(pCur -> courseNext != nullptr && strcmp(pCur -> courseNext -> id, CourseID) != 0)
			pCur = pCur -> courseNext;
		Course* pDel = pCur -> courseNext;
		pCur -> courseNext = pDel -> courseNext;
		delete pDel;
	}

    if (strcmp(pStuInCourse -> studentID, studentID) == 0) {
    	Student* pDel = pStuInCourse;
    	pStuInCourse = pStuInCourse -> studentNext;
    	delete pDel;
    }
    else {
    	Student *pCurStudent = pStuInCourse;
		while(pCurStudent -> studentNext != nullptr && strcmp(pCurStudent -> studentNext -> studentID, studentID) != 0)
			pCurStudent = pCurStudent -> studentNext;
		Student* pDel = pCurStudent -> studentNext;
		pCurStudent -> studentNext = pDel -> studentNext;
		delete pDel;
	}

	char dir[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
	char c[505] = "";
	strcat(c, dir);
	strcat(c, yearName);
	strcat(c, "\\Semester\\");
	strcat(c, semesterName);
	strcat(c, "\\");
	strcat(c, CourseID);
	strcat(c, "\\Student.txt");
	ofstream fOut(c);


	Student *curStudent = pStuInCourse;
	while (curStudent) {
		fOut << curStudent -> studentID << '\n';
		curStudent = curStudent -> studentNext;
	}

	fOut.close();
}
int chooseRoleScreen() {
	int choose=0; 
	 setConsoleWindow(1000, 600);
	fixConsoleWindow();
	gotoXY(30, 0);
	cout << char(201);
	for (int i = 0; i < 70; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	for (int i = 1; i <= 5; i++)
	{
		gotoXY(30, i);
		cout << char(186);
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
		cout << char(186);
		cout << endl;
	}
	gotoXY(30, 6);
	cout << char(200);
	for (int i = 0; i < 70; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	int x = 41, y = 1;
	textColor(4);
	gotoXY(x, y);   cout << "oooooo";
	gotoXY(x, y+1); cout << "o     o";
	gotoXY(x, y+2); cout << "oooooo ";
	gotoXY(x, y+3); cout << "o      ";
	gotoXY(x, y+4); cout << "o      ";
	textColor(6);
	gotoXY(x+9, y);     cout << " ooooo";
	gotoXY(x+9, y + 1); cout << "o     o";
	gotoXY(x+9, y + 2); cout << "o     o ";
	gotoXY(x+9, y + 3); cout << "o     o ";
	gotoXY(x+9, y + 4); cout << " ooooo  ";
	textColor(14);
	gotoXY(x + 18, y);     cout << "oooooo";
	gotoXY(x + 18, y + 1); cout << "o     o";
	gotoXY(x + 18, y + 2); cout << "oooooo ";
	gotoXY(x + 18, y + 3); cout << "o    o ";
	gotoXY(x + 18, y + 4); cout << "o     o";
	textColor(9);
	gotoXY(x+27, y);     cout << "ooooooo";
	gotoXY(x+27, y + 1); cout << "   o   ";
	gotoXY(x+27, y + 2); cout << "   o   ";
	gotoXY(x+27, y + 3); cout << "   o   ";
	gotoXY(x+27, y + 4); cout << "   o   ";
	textColor(10);
	gotoXY(x + 36, y);      cout << " ooooo ";
	gotoXY(x + 36, y+1);    cout << "o     o";
	gotoXY(x + 36, y+2);    cout << "ooooooo";
	gotoXY(x + 36, y+3);    cout << "o     o";
	gotoXY(x + 36, y+4);    cout << "o     o";
	textColor(11);
	gotoXY(x + 45, y);        cout << "o      ";
	gotoXY(x + 45, y + 1);    cout << "o      ";
	gotoXY(x + 45, y + 2);    cout << "o      ";
	gotoXY(x + 45, y + 3);    cout << "o      ";
	gotoXY(x + 45, y + 4);    cout << "ooooooo";
	textColor(7);
	x = 32; y = 8;
	int k = 20;
	drawBox(x, y, k);
	gotoXY(x + 8, y + 1); cout << "STAFF";
	x = 55; y = 8;
	drawBox(x, y, k);
	gotoXY(x + 7, y + 1); cout << "STUDENT";
	x = 78; y = 8;
	k = 20;
	drawBox(x, y, k);
	gotoXY(x + 9, y + 1); cout << "QUIT";
	gotoXY(1, 35);
	char ch;
	do
	{
		ch = getch();
		if (ch == -32)
		{
			ch = getch();
			if (ch == 75)
			{
				moveLeft(choose);
			}
			else if (ch == 77)
			{
				moveRight(choose);
			}
		
		}
		if (ch == 13)
		{
			system("cls");
			return choose; 
		}
	} while (ch != 27);
	return 0; 
}

int yearScreen() {
visibleCursor();
	while(1) {
		drawBox(0,0,5);
		textColor(14);
		gotoXY(1,1);cout<<"STAFF"<<endl<<endl;
		textColor(3);
		cout<<" MENU";
		textColor(7);
		drawBox(0,5,2);
		gotoXY(1,6);cout<<"0";
		gotoXY(5,6);cout<<"Logout"<<endl<<endl;
		drawBox(0,8,2);
		gotoXY(1,9);cout<<"1";
		gotoXY(5,9);cout<<"Change Password"<<endl<<endl;
		drawBox(0,11,2);
		gotoXY(1,12);cout<<"2";
		gotoXY(5,12);cout<<"New school year"<<endl<<endl;
		textColor(3);
		cout<<" ACCESS YEAR"<<endl<<endl;
		textColor(7);
		char *s = new char[51];
		int cnt = 3;
		ifstream fIn("C:\\Github\\Final-project-of-group-6\\DataProject\\Year.txt");
		int xb=0,yb=16;
		while(fIn >> s)
		{
			drawBox(xb,yb,2);
			gotoXY(xb+1,yb+1);cout<<cnt++;
			gotoXY(xb+5,yb+1);cout<<s<<endl;
		yb+=3;
		}
		delete[] s;
	cout<<endl;
		gotoXY(12,1);cout << "Your input: ";
		char *respond = new char[101];gotoXY(24,1) ;cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			textColor(4);
			gotoXY(32,1);cout << "Invalid, please try again";
			textColor(7);
			continue;
		}
		int x;
		
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}

	
}

void createYearScreen(Year *& pYear) {
	cout << "Please input the new school year name: \n";
	char *yearName = new char[101];
	cin >> yearName;
	createNewYear(pYear, yearName, 1);
	system("cls");
}

int classScreen(char* yearName) {
	visibleCursor();
	char dir[101] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
	strcat(dir, yearName);
	strcat(dir, "\\Class.txt");
	while(1) {
		drawBox(0,0,15);
		gotoXY(1,1);
		textColor(14);
		cout << "YEAR: " << yearName << "\n\n";
		textColor(3);
		cout<<" MENU";
		textColor(7);
		drawBox(0,5,2);
		gotoXY(1,6);cout<<"0";
		gotoXY(5,6);cout<<"Back"<<endl<<endl;
		drawBox(0,8,2);
		gotoXY(1,9);cout<<"1";
		gotoXY(5,9);cout<<"Semester"<<endl<<endl;
		drawBox(0,11,2);
		gotoXY(1,12);cout<<"2";
		gotoXY(5,12);cout<<"New class"<<endl<<endl;
		textColor(3);
		cout<<" ACCESS CLASS"<<endl<<endl;
		textColor(7);
		char *s = new char[51];
		int cnt = 3;
		ifstream fIn(dir);
		int xb=0,yb=16;
		while(fIn >> s)
			//cout << cnt++ << ": Access class " << s << '\n';
			drawBox(xb,yb,2);
			gotoXY(xb+1,yb+1);cout<<cnt++;
			gotoXY(xb+5,yb+1);cout<<s<<endl;
		yb+=3;
		delete[] s;
	
		gotoXY(25,1);cout << "Your input: ";
		char *respond = new char[101]; gotoXY(37,1);cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			textColor(4);
						gotoXY(45,1);cout << "Invalid, please try again\n\n";
						textColor(7);
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

void createClassScreen(Class *& pClass, char * yearName) {
	cout << "Input the new class name: \n";
	char *className = new char[101];
	cin >> className;
	createNewClass(pClass, yearName, className, 1);
	system("cls");
}

int studentScreen(Student * pStudent, char* yearName, char* className) {
	while(1) {
		char *s = new char[51];
		cout << "Class: " << className << "\n\n";

		Student * curStudent = pStudent;
		while (curStudent != nullptr) {
	        cout << setw(12) << left << curStudent->studentID;
	        cout << setw(25) << left << curStudent->Name;
	        cout << setw(8) << left << ((curStudent->gender) ? "FEMALE" : "MALE");
	        cout << curStudent->DOB.day << "/" << curStudent->DOB.month << "/"  << curStudent->DOB.year << '\n';
			curStudent = curStudent -> studentNext;
		}	

		cout << '\n';

		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Create a new student\n";
		cout << "2: Add students through .csv file\n";
		cout << "3: View scoreboard of the class\n";
	
		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

void createStudentScreen(Student *& pStudent, char* yearName, char* className) {
	Student *newStu = new Student;
	inputStudent(newStu);
	addStudent(pStudent, yearName, className, newStu, 1);
}

void createStudentCSVScreen(Student *& pStudent, char* yearName, char* className) {
	cout << "Please drag the .csv file you wish to import into the directory Final-project-of-group-6\\DataProject\\Class_csv\n";
	cout << "Also, please input the name of the file (with the file name extension too, for example: 20CTT1_Student.csv): ";
	char *csvFile = new char[101];
	cin >> csvFile;
	system("cls");
	addStudentCSV(pStudent, csvFile, yearName, className, 1);
}

int semesterScreen(Semester *& pSemester) {
	visibleCursor();
	while(1) {
		drawBox(0,0,8);
		gotoXY(1,1);
		textColor(14);
		cout << "SEMESTER" << "\n\n";
		textColor(3);
		cout<<" MENU";
		textColor(7);
		drawBox(0,5,2);
		gotoXY(1,6);cout<<"0";
		gotoXY(5,6);cout<<"Back"<<endl<<endl;
		drawBox(0,8,2);
		gotoXY(1,9);cout<<"1";
		gotoXY(5,9);cout<<"New Semester"<<endl<<endl;
		textColor(3);
		cout<<"ACCESS SEMESTER"<<endl<<endl;
		textColor(7);
		int cnt = 2;
		int xb=0,yb=12;
		
		Semester * pCur = pSemester;
		while (pCur != nullptr) {
			drawBox(xb,yb,2);
			gotoXY(xb+1,yb+1);cout<<cnt++;
			gotoXY(xb+5,yb+1);cout <<"Semester "<< pCur -> SemesterName << " (From " << pCur->startDate.month << '/' << pCur->startDate.day << '/' << pCur->startDate.year <<
				" to " << pCur->endDate.month << '/' << pCur->endDate.day << '/' << pCur->endDate.year << ")" << '\n';
			pCur = pCur -> semesterNext;
					yb+=3;
		}
cout<<endl;
		gotoXY(12,1);cout << "Your input: ";
		char *respond = new char[101]; gotoXY(24,1);cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
		textColor(4);
		gotoXY(32,1);	cout << "Invalid, please try again\n\n";
		textColor(7);
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}                     

void createSemesterScreen(Semester *& pSemester, char *yearName) {
	cout << "Please input the new semester name: \n";
	char *semesterName = new char[51];
	cin >> semesterName;

	cout << "Please input the start date of the semester: \n";
	Date startDate;
	cout << "Year?: "; cin >> startDate.year;
	cout << "Month: "; cin >> startDate.month;
	cout << "Day?: "; cin >> startDate.day;

	cout << "Please input the end date of the semester: \n";
	Date endDate;
	cout << "Year?: "; cin >> endDate.year;
	cout << "Month: "; cin >> endDate.month;
	cout << "Day?: "; cin >> endDate.day;

	createNewSemester(pSemester, semesterName, yearName, startDate, endDate, 1);
	system("cls");
}

int courseScreen(Course *& pCourse, char * semesterName) {
	while(1) {
		cout << "Semester: " << semesterName << "\n\n";

		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Create a course registration session\n";
		cout << "2: Add a new course\n";
		cout << "3: View list of courses\n\n";

		int cnt = 4;
		Course * pCur = pCourse;
		while (pCur != nullptr) {
			cout << cnt++ << ": Access course " << pCur -> id << '\n';
			pCur = pCur -> courseNext;
		}

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}	
}

void addCourseScreen(Course *& pCourse, char* yearName, char* semesterName) {
	Course * newCourse = new Course;
	                   
	cin.get();
    cout << "Please input the course ID: ";
    newCourse -> id = new char[101];
	cin.getline(newCourse -> id, 50);
    
    cout << "Please input the course name: ";
    newCourse -> name = new char[101];
	cin.getline(newCourse -> name, 50);

    cout << "Please input the course lecturer's name: ";
    newCourse -> lecturerName = new char[101];
	cin.getline(newCourse -> lecturerName, 50);

    cout << "Please input the number of credits: ";
    cin >> newCourse->numberOfCredits;

    cout << "Please input the maximal student: ";
    cin >> newCourse->maxStudent;
    cin.get();

    cout << "The session that the course will be performed (MON / TUE / WED / THU / FRI / SAT)" << endl;
    cout << "and shift S1 (07:30), S2 (09:30), S3(13:30) and S4 (15:30))" << endl;
    cout << "Please input 2 sessions :" << endl;
    newCourse -> date.d1 = new char[5];
    newCourse -> date.s1 = new char[5];
    newCourse -> date.d2 = new char[5];
    newCourse -> date.s2 = new char[5];
    cout << "Day 1: ";
	cin.getline(newCourse -> date.d1, 5);
    cout << "Shift 1: "; newCourse->date.s1;
	cin.getline(newCourse -> date.s1, 5);
    cout << "Day 2: ";
	cin.getline(newCourse -> date.d2, 5);
    cout << "Shift 2: "; newCourse->date.s1;
	cin.getline(newCourse -> date.s2, 5);
	addNewCourse(pCourse, semesterName, yearName, newCourse, 1);
	system("cls");
}

int editCourseScreen(Course *& curCourse) {
	while (true) {
		cout << "Course ID: " << curCourse -> id << '\n';
	    cout << "Course Name: " << curCourse -> name << '\n';
	    cout << "Lecturer Name: " << curCourse -> lecturerName << '\n';
		cout << "Number of Credit: " << curCourse -> numberOfCredits << '\n';
	    cout << "Occur in: " << curCourse -> date.d1 << " " << curCourse -> date.s1 << " and " << curCourse -> date.d2 << " " << curCourse -> date.s2 << '\n';
	    int cnt = 0;
	    Student* stuInCourse = curCourse -> pStudent;
	    while (stuInCourse != nullptr) {
	    	cnt++;
	    	stuInCourse = stuInCourse -> studentNext;
	    }
		cout << "Number of students registered: " << cnt << " / " << curCourse -> maxStudent << '\n';
  		cout << '\n';

  		cout << "Please input your choice: \n\n";
  		cout << "0: Go back\n\n";

  		cout << "1: Update this course information\n";
  		cout << "2: View list of students in this course\n";
  		cout << "3: View the scoreboard of this course\n\n";

  		cout << "4: Delete this course\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

int enrollSemesterScreen(Year *& pYear, char * studentID) {
	Student *curStudent = nullptr;
	Class * curClass = pYear -> pClass; 
	while (curStudent == nullptr && curClass != nullptr) {
		curStudent = curClass -> pStudent;
		while (curStudent != nullptr) {
			if (strcmp(curStudent -> studentID, studentID) == 0)
				break;
			curStudent = curStudent -> studentNext;
		}
		curClass = curClass -> classNext;
	}                                      


	while(1) {
		cout << "Student's ID: " << curStudent -> studentID << '\n';
		cout << "Student's Name: " << curStudent -> Name << '\n';
		cout << "Student's Gender: " << ((curStudent -> gender) ? "Female" : "Male") << '\n';
		cout << "Student's Day of Birth: " << curStudent -> DOB.month << '/' << curStudent -> DOB.day << '/' << curStudent -> DOB.year << "\n\n";

		cout << "Please input your choice: \n\n";

		cout << "0: Logout\n";   
		cout << "1: Change password\n\n";
		int cnt = 2;
		Semester * pCur = pYear -> pSemester;
		while (pCur != nullptr) {
			cout << cnt++ << ": Access semester " << pCur -> SemesterName << " (From " << pCur->startDate.month << '/' << pCur->startDate.day << '/' << pCur->startDate.year <<
				" to " << pCur->endDate.month << '/' << pCur->endDate.day << '/' << pCur->endDate.year << ")" << '\n';
			pCur = pCur -> semesterNext;
		}

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}				
}

int enrollCourseScreen(char *semesterName) {
	while(1) {
		cout << "Semester: " << semesterName << "\n\n";

		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Enroll in a course\n";
		cout << "2: View list of your enrolled courses in this semester\n";
		cout << "3: View your scoreboard in this semester\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

int chooseCourse(Course *& pCourse) {
	while (1) {
		Course * pCur = pCourse;
	    while (pCur != nullptr) {
	        cout << "Course ID: " << pCur -> id << '\n';
	        cout << "Course Name: " << pCur -> name << '\n';
	        cout << "Lecturer Name: " << pCur -> lecturerName << '\n';
			cout << "Number of Credit: " << pCur -> numberOfCredits << '\n';
	        cout << "Occur in: " << pCur -> date.d1 << " " << pCur -> date.s1 << " and " << pCur -> date.d2 << " " << pCur -> date.s2 << '\n';
	        int cnt = 0;
	        Student* stuInCourse = pCur -> pStudent;
	        while (stuInCourse != nullptr) {
	        	cnt++;
	        	stuInCourse = stuInCourse -> studentNext;
	        }
			cout << "Number of students registered: " << cnt << " / " << pCur -> maxStudent << '\n';
			cout << '\n';
	
	        // move to next course
	        pCur = pCur -> courseNext;
	    }

	    cout << "Please input your choice: \n\n";
	    cout << "0: Go back\n\n";

	    int cnt = 1;
	    pCur = pCourse;
	    while (pCur != nullptr) {
	    	cout << cnt++ << ": Enroll in course " << pCur -> id << '\n';
	    	pCur = pCur -> courseNext;
	    }

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

int viewAndDeleteCourseScreen(Course *& pCourse, char *semesterName) {
    while(1) {
		viewEnrollList(pCourse, semesterName);
		
		cout << "Please input your choice: \n\n";
		cout << "0: Go back\n\n";
		cout << "1: Unenroll a course\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		int x;
		if (strlen(respond) == 1)
			x = respond[0] - '0';
		else
			x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;
		return x;	
	}
}

void deleteCourseScreen(Course * pCourse, Student * pStudent, char * yearName, char * semesterName, char * studentID) {
	cout << "Please input the ID of the course you want to unenroll: ";
	char * courseID = new char[101];
	cin >> courseID;
	cout << '\n';
	Course * tmpCourse = pCourse;
	while (tmpCourse) {
		if (strcmp(tmpCourse -> id, courseID) == 0)
			break;
		tmpCourse = tmpCourse -> courseNext;	
	}

	if (tmpCourse == nullptr) {
		cout << "There are no courses that match the course ID you just input!\n";
		system("pause");
		system("cls");
		return;
	}

	while (strcmp(pCourse -> id, courseID) != 0)
		pCourse = pCourse -> courseNext;

	
	removeCourseInEnrollList(pCourse, pStudent, yearName, semesterName, courseID, studentID);
}

void viewOrAddScoreBoard(Course *curCourse, char * yearName, char * semesterName) {
   	if (!curCourse -> pScoreboard) {
   		while (1) {
   			cout << "There is no scoreboard in this course yet.\n";
   			cout << "Do you want to import a scoreboard into this semester?\n\n";

   			cout << "Please input your choice: \n\n";

   			cout << "0: No\n";
   			cout << "1: Yes\n";

      		cout << "Your input: ";
      		char *respond = new char[101]; cin >> respond;
      		system("cls");
      		if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
      			cout << "Invalid, please try again\n\n";
      			continue;
      		}

      		int x;
      		if (strlen(respond) == 1)
      			x = respond[0] - '0';
      		else
      			x = (respond[0] - '0') * 10 + (respond[1] - '0');
			delete[] respond;
      		if (x != 0 && x != 1) {
      			cout << "Invalid, please try again\n\n";
      			continue;
      		}	
      		if (x == 0) return;
			cout << "Please drag the scoreboard of the course in the format " << curCourse -> id << ".csv file into the folder C:\\Github\\Final-project-of-group-6\\DataProject\\Scoreboard_csv\\ \n\n";
			system("pause");
			system("cls");
   			addScoreBoardCSV(curCourse -> pScoreboard, yearName, semesterName, curCourse -> id);
   			break;
  		}
  	}
  	while (1) {
		viewScoreboardOfCourse(curCourse);

		cout << "Please input your choice: \n\n";

		cout << "0: Go back\n";
		cout << "1: Update a student result\n";
		cout << "Your input: ";
      	char *respond = new char[101]; cin >> respond;
      	system("cls");
      	if (strlen(respond) > 2 || (respond[0] < '0' || '9' < respond[0]) || (strlen(respond) == 2 && (respond[1] < '0' || '9' < respond[1]))) {
      		cout << "Invalid, please try again\n\n";
      		continue;
      	}

      	int x;
      	if (strlen(respond) == 1)
      		x = respond[0] - '0';
      	else
      		x = (respond[0] - '0') * 10 + (respond[1] - '0');
		delete[] respond;

		if (x != 0 && x != 1) {
			cout << "Invalid, please try again\n\n";
			continue;
		}

		if (x == 0)
			break;
		else if (x == 1) {
			char *studentID = new char[51]; 
			cout << "Please input the Student's ID: ";
			cin >> studentID;
			updateScoreBoardStudent(curCourse -> pScoreboard, yearName, semesterName, curCourse -> id, studentID);
			delete[] studentID;
		}	
	}
}
void enrollStudent(Course *& pCourse, Student *& pStudent, char* CourseID, char* StudentID, char * yearName, char * semesterName, int add) { 
	Course *curCourse = pCourse;
	while (curCourse && strcmp(curCourse -> id, CourseID) != 0) {
		curCourse = curCourse -> courseNext;
	}

	Student *curStudent = pStudent;
	while (curStudent && strcmp(curStudent -> studentID, StudentID) != 0) {
		curStudent = curStudent -> studentNext;
	}

	Course * tmpCourse = curStudent -> pCourse;
	while (tmpCourse) {
		if (strcmp(tmpCourse -> id, CourseID) == 0) {
			cout << "The student has already enrolled in this course, cannot enrolled!\n\n";
			return;
		}
		tmpCourse = tmpCourse -> courseNext;
	}

	int d1, d2, s1, s2;

	if (strcmp(curCourse -> date.d1, "MON") == 0) d1 = 2;
	else if (strcmp(curCourse -> date.d1, "TUE") == 0) d1 = 3;
	else if (strcmp(curCourse -> date.d1, "WED") == 0) d1 = 4;
	else if (strcmp(curCourse -> date.d1, "THU") == 0) d1 = 5;
	else if (strcmp(curCourse -> date.d1, "FRI") == 0) d1 = 6;
	else if (strcmp(curCourse -> date.d1, "SAT") == 0) d1 = 7;
	s1 = (curCourse -> date.s1)[1] - '0';

	if (strcmp(curCourse -> date.d2, "MON") == 0) d2 = 2;
	else if (strcmp(curCourse -> date.d2, "TUE") == 0) d2 = 3;
	else if (strcmp(curCourse -> date.d2, "WED") == 0) d2 = 4;
	else if (strcmp(curCourse -> date.d2, "THU") == 0) d2 = 5;
	else if (strcmp(curCourse -> date.d2, "FRI") == 0) d2 = 6;
	else if (strcmp(curCourse -> date.d2, "SAT") == 0) d2 = 7;
	s2 = (curCourse -> date.s2)[1] - '0';

	if (curStudent -> enrolledSession[d1][s1] || curStudent -> enrolledSession[d2][s2]) {
		cout << "The current course has sessions that are conflict with existing enrolled course sessions, cannot enrolled!\n\n";
		return;
	}

	int sz_enroll = 0;
	Course* enrollCourse = curStudent -> pCourse;
	while (enrollCourse) {
		sz_enroll++;
		enrollCourse = enrollCourse -> courseNext;
	}
	if (sz_enroll >= 5) {
		cout << "The student has already enrolled in 5 courses, cannot enrolled!\n\n";
		return;
	}

	int sz_student = 0;
	Student* stuInCourse = curCourse -> pStudent;
	while(stuInCourse) {
		sz_student++;
		stuInCourse = stuInCourse -> studentNext;
	}
	if (sz_student >= curCourse -> maxStudent) {
		cout << "The course is already full, cannot enrolled!\n\n";
		return;
	}

		
	curStudent -> enrolledSession[d1][s1] = true;
	curStudent -> enrolledSession[d2][s2] = true;

	enrollCourse = curStudent -> pCourse;
	if (enrollCourse == nullptr) {
		curStudent -> pCourse = new Course;
		enrollCourse = curStudent -> pCourse;
	}
	else {
		while (enrollCourse -> courseNext)
			enrollCourse = enrollCourse -> courseNext;
		enrollCourse -> courseNext = new Course;
		enrollCourse = enrollCourse -> courseNext;
	}

	enrollCourse -> id = new char[51];
	strcpy(enrollCourse -> id, curCourse -> id);
	enrollCourse -> name = new char[51];
	strcpy(enrollCourse -> name, curCourse -> name);
	enrollCourse -> lecturerName = new char[51];
	strcpy(enrollCourse -> lecturerName, curCourse -> lecturerName);
	enrollCourse -> numberOfCredits = curCourse -> 	numberOfCredits;
	enrollCourse -> maxStudent = curCourse -> maxStudent;
	enrollCourse -> date.d1 = new char[51]; 
	strcpy(enrollCourse -> date.d1, curCourse -> date.d1);
	enrollCourse -> date.s1 = new char[51]; 
	strcpy(enrollCourse -> date.s1, curCourse -> date.s1);
	enrollCourse -> date.d2 = new char[51]; 
	strcpy(enrollCourse -> date.d2, curCourse -> date.d2);
	enrollCourse -> date.s2 = new char[51]; 
	strcpy(enrollCourse -> date.s2, curCourse -> date.s2);
	enrollCourse -> sSemester = new char[51];
	strcpy(enrollCourse -> sSemester, semesterName);

	stuInCourse = curCourse -> pStudent;
	if (stuInCourse == nullptr) {
		curCourse -> pStudent = new Student;
		stuInCourse = curCourse -> pStudent;
	}
	else {
		while(stuInCourse -> studentNext)
			stuInCourse = stuInCourse -> studentNext;
		stuInCourse -> studentNext = new Student;
		stuInCourse = stuInCourse -> studentNext;
	}

	stuInCourse -> studentID = new char[51];
	strcpy(stuInCourse -> studentID, curStudent -> studentID);
	stuInCourse -> Name = new char[51];
	strcpy(stuInCourse -> Name, curStudent -> Name);
	stuInCourse -> DOB = curStudent -> DOB;
	stuInCourse -> sClass = new char[51];
	strcpy(stuInCourse -> sClass, curStudent -> sClass);
	stuInCourse -> gender = curStudent -> gender;


	cout << "Enroll successfully!\n\n";

	if (add == 1) {
		char dir[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
		char c[505] = "";
		strcat(c, dir);
		strcat(c, yearName);
		strcat(c, "\\Semester\\");
		strcat(c, semesterName);
		strcat(c, "\\");
		strcat(c, CourseID);
		strcat(c, "\\Student.txt");
		ofstream fOut(c);

		stuInCourse = curCourse -> pStudent;
		while (stuInCourse) {
			fOut << stuInCourse -> studentID << '\n';
			stuInCourse = stuInCourse -> studentNext;
		}

		fOut.close();
	}
}
void updateCourse(Course*& pCourse, char* yearName, char* semesterName, char* courseID) {
    Course* pCur = pCourse;
    while (pCur && strcmp(pCur->id, courseID) != 0) {
        pCur = pCur->courseNext;
    }
    
    int x;
    while(1) {
    	cout << "0: Go back\n\n";

	    cout << "Choose 1 of these functions:\n";
	    cout << "1: Course's ID" << endl;
	    cout << "2: Course's name" << endl;
	    cout << "3: Lecturer's name" << endl;
	    cout << "4: Number of credits" << endl;
	    cout << "5: Max students" << endl;
	    cout << "6: Session and Shifts" << endl;
	    cout << "Which information do you want to update?" << "\n\n";

   		cout << "Your input: ";
   		char *respond = new char[101]; cin >> respond;
   		system("cls");
   		if (strlen(respond) > 1 || (respond[0] < '0' || '9' < respond[0])) {
   			cout << "Invalid, please try again\n\n";
   			continue;
   		}
   		x = respond[0] - '0';
   		break;
	}

	if (x == 0)
		return;

    if (x == 1) {
        cout << "New course's ID: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->id, 101, '\n');
    }
    else if (x == 2) {
        cout << "New course's name: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->name, 101, '\n');
    }
    else if (x == 3) {
        cout << "New lecturer's name: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->lecturerName, 101, '\n');
    }
    else if (x == 4) {
        cout << "New number of credits: ";
        cin >> pCur->numberOfCredits;
    }
    else if (x == 5) {
        cout << "New max students: ";
        cin >> pCur->maxStudent;
    }
    else {
        cout << "New day 1 and shift 1: ";
        cin >> pCur->date.d1 >> pCur->date.s1;
        cout << "New day 2 and shift 2: ";
        cin >> pCur->date.d2 >> pCur->date.s2;
    }
    cout << "Update successfully!!\n";
    system("pause");
    system("cls");

    char dirD[] = "C:\\Github\\Final-project-of-group-6\\DataProject\\";
    char c[500] = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);
    strcat(c, "\\Course.txt");

    ofstream fout(c);

    pCur = pCourse;
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
void updateScoreBoardStudent(Scoreboard *& pScr, char *yearName, char * semesterName, char *courseID, char* studentID) {
	Scoreboard * pCur = pScr;
	while(pCur != nullptr && strcmp(pCur->stu->studentID, studentID) != 0){
		pCur = pCur-> scoreboardNext;
	}	
	
	if(pCur != nullptr){
		cout << "Update Score of student " << studentID << ": " << endl;
		cout << "Midterm's mark: "; cin >> pCur->midterm;
		cout << "Final's mark: "; cin >> pCur->final;
		cout << "Bonus's mark: "; cin >> pCur->bonus;
		cout << "Total's mark: "; cin >> pCur->total;
		cout << "Update successfully!!\n";
	} else {
		cout << "Student ID not found." << '\n';
	}
	system("pause");
	system("cls");

	char dirOut[] = { "C:\\Github\\Final-project-of-group-6\\DataProject\\" };
	char ddd[505] = "";
	strcat(ddd, dirOut);
	strcat(ddd, yearName);
	strcat(ddd, "\\Semester\\");
	strcat(ddd, semesterName);
	strcat(ddd, "\\");
	strcat(ddd, courseID);
	strcat(ddd, "\\");
	strcat(ddd, "Scoreboard.txt");

	ofstream fOut(ddd);

	pCur = pScr;
	int cnt = 0;
	while (pCur != nullptr) {
		fOut << ++cnt << ',' << pCur -> stu -> studentID << ',' << pCur -> stu -> Name << ',' << pCur -> midterm << ',' << pCur -> final << ',' << pCur -> bonus << ',' << pCur -> total << '\n';
		pCur = pCur -> scoreboardNext;
	}
	fOut.close();
}
void viewEnrollList(Course* pEnrollCourse, char *semesterName){
	Course * pCur = pEnrollCourse;
	while(pCur != nullptr){
		if (strcmp(semesterName, pCur -> sSemester) == 0) {
		    cout << "Course ID: " << pCur -> id << '\n';
		    cout << "Course Name: " << pCur -> name << '\n';
		    cout << "Lecturer Name: " << pCur -> lecturerName << '\n';
			cout << "Number of Credit: " << pCur -> numberOfCredits << '\n';
		    cout << "Occur in: " << pCur -> date.d1 << " " << pCur -> date.s1 << " and " << pCur -> date.d2 << " " << pCur -> date.s2 << '\n';
			cout << '\n';        
		}	
		pCur = pCur -> courseNext;
	}
}
void viewListOfCLasses(Year* pYear) {
	while (pYear) {
		cout <<"Year:"<< pYear->YearName << endl;
		while (pYear->pClass) {
			cout << pYear->pClass->ClassName << endl;
			pYear->pClass = pYear->pClass->classNext;
		}
		pYear = pYear->yearNext;
	}
}
void viewListOfCourse (Course *pCourse) {
	Course * pCur = pCourse;
    while (pCur != nullptr) {
        cout << "Course ID: " << pCur -> id << '\n';
        cout << "Course Name: " << pCur -> name << '\n';
        cout << "Lecturer Name: " << pCur -> lecturerName << '\n';
		cout << "Number of Credit: " << pCur -> numberOfCredits << '\n';
        cout << "Occur in: " << pCur -> date.d1 << " " << pCur -> date.s1 << " and " << pCur -> date.d2 << " " << pCur -> date.s2 << '\n';
        int cnt = 0;
        Student* stuInCourse = pCur -> pStudent;
        while (stuInCourse != nullptr) {
        	cnt++;
        	stuInCourse = stuInCourse -> studentNext;
        }
		cout << "Number of students registered: " << cnt << " / " << pCur -> maxStudent << '\n';
		cout << '\n';

        // move to next course
        pCur = pCur -> courseNext;
    }
    system("pause");
    system("cls");
}
void viewListOfStudentsInCourse (Student *pStudent, char *courseID) {
	while (1) {
		Student *pStuInCourse = pStudent;
	    while (pStuInCourse) {
	        cout << setw(12) << left << pStuInCourse->studentID;
	        cout << setw(30) << left << pStuInCourse->Name;
	        cout << setw(10) << left << pStuInCourse->sClass;
	        cout << setw(8) << left << ((pStuInCourse->gender) ? "FEMALE" : "MALE");
	        cout << pStuInCourse->DOB.day << "/" << pStuInCourse->DOB.month << "/" << pStuInCourse->DOB.year << '\n';
	        pStuInCourse = pStuInCourse -> studentNext;
    	}
    	cout << '\n';

    	cout << "Do you want to export the list of students to a CSV file?\n";
    	cout << "0: No\n";
    	cout << "1: Yes\n\n";

		cout << "Your input: ";
		char *respond = new char[101]; cin >> respond;
		system("cls");
		if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		if (respond[0] - '0')
			exportStudentToCsv(pStudent, courseID);
		return;
	}
}
void viewScoreBoard(Course* pCourse, char* studentID) {
	cout << setw(15) << left << "Course";
	cout << setw(20) << left << "Midterm's Mark";
	cout << setw(20) << left << "Final's Mark";
	cout << setw(20) << left << "Bonus's Mark";
	cout << setw(20) << left << "Total's Mark" << '\n';
	cout << '\n';

	while (pCourse != nullptr) {
		Scoreboard *pCur = pCourse -> pScoreboard; 
		while (pCur != nullptr) {
			if (strcmp(pCur -> stu -> studentID, studentID) == 0) {
				cout << setw(15) << left << pCourse -> id;
				cout << setw(20) << left << pCur -> midterm;
				cout << setw(20) << left << pCur -> final;
				cout << setw(20) << left << pCur -> bonus;
				cout << setw(20) << left << pCur -> total << '\n';
				break;
			}
			pCur = pCur -> scoreboardNext;
		}
		pCourse = pCourse -> courseNext;
	}

	system("pause");
	system("cls");
}
void viewScoreBoardOfClass(Student * pStudent, Semester * pSemester) {
	char * semesterName = new char[11];
	while (1) {
		cout << "Please input the name of the semester you want to see the scoreboard: ";
		cin >> semesterName;
		if (strlen(semesterName) > 1 || semesterName[0] < '0' || '3' < semesterName[0]) {
			system("cls");
			cout << "Invalid, please try again\n\n";
			continue;
		}
		break;
	}
	system("cls");
    cout << setw(18) << left << "Student's ID";
    cout << setw(30) << left << "Student's Name";

    Semester *curSem = pSemester;
    while (curSem) {
    	if (strcmp(curSem -> SemesterName, semesterName) == 0) {
    		Course *curCourse = curSem -> pCourse;
    		while (curCourse) {
    			cout << setw(10) << left << curCourse -> id;
    			curCourse = curCourse -> courseNext;
    		}
    	}
    	curSem = curSem -> semesterNext;
    }

    cout << setw(20) << left << "GPA this semester";
    cout << setw(20) << left << "GPA overall" << '\n';
    cout << '\n';

    Student *curStu = pStudent;
	while (curStu) {
	    cout << setw(18) << left << curStu -> studentID;
	    cout << setw(30) << left << curStu -> Name; 
		curSem = pSemester;
			
		int cntCourseSem = 0;
		double totMarkSem = 0;
		int cntCourse = 0;
		double totCourse = 0;

		while (curSem) {
	    	Course *curCourse = curSem -> pCourse;
	    	while (curCourse) {
	    		Scoreboard *curScr = curCourse -> pScoreboard;
	    		while (curScr) {
	    			if (strcmp(curScr -> stu -> studentID, curStu -> studentID) == 0) { 
						if (strcmp(curSem -> SemesterName, semesterName) == 0) {
			    			cout << setw(10) << left << curScr -> total;
			    			cntCourseSem++;
			    			totMarkSem += curScr -> total;
						}
						cntCourse++;
						totCourse += curScr -> total;
					}
					curScr = curScr -> scoreboardNext;
				}
			    curCourse = curCourse -> courseNext;
	    	}
	    	curSem = curSem -> semesterNext;
		}

  	  	cout << setw(20) << left << totMarkSem / cntCourseSem;
	    cout << setw(20) << left << totCourse / cntCourse << '\n';

		curStu = curStu -> studentNext;
	}

	system("pause");
	system("cls");
 	delete[] semesterName;
}
void viewScoreboardOfCourse (Course *curCourse) {
    Scoreboard *pCur;
    pCur = curCourse -> pScoreboard;
    cout << setw(30) << left << "Name";
    cout << setw(20) << left << "ID";
    cout << setw(20) << left << "Midterm's Mark";
    cout << setw(20) << left << "Final's Mark";
    cout << setw(20) << left << "Bonus's Mark";
    cout << setw(20) << left << "Total's Mark" << '\n';
    cout << '\n';

    while (pCur) {
        cout << setw(30) << left << pCur->stu->Name;
        cout << setw(20) << left << pCur->stu->studentID;
        cout << setw(20) << left << pCur->midterm;
        cout << setw(20) << left << pCur->final;
        cout << setw(20) << left << pCur->bonus;
        cout << setw(20) << left << pCur->total << '\n';
        pCur = pCur->scoreboardNext;
    }
}
