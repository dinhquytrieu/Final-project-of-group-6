#ifndef _HEADER_H_
#define _HEADER_H_
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
	bool** enrolledSession;
	Course* pCourse = nullptr;
	Student* studentNext = nullptr;
};

struct Scoreboard {
	Student* stu;
	float midterm;
	float final;
	float bonus;
	float total;
	Scoreboard* scoreboardNext = nullptr;
};

struct Class {
	char* ClassName;
	Student* pStudent = nullptr;
	Class* classNext = nullptr;
};

struct Year {
	char* YearName;
	Class* pClass = nullptr;
	Semester* pSemester = nullptr;
	Year* yearNext = nullptr;
};

struct Semester {
	char* SemesterName;
	Date startDate, endDate;
	Date startReg, endReg;
	Course* pCourse = nullptr;
	Semester* semesterNext = nullptr;
};

struct dayPerformed {
	char* d1; // day
	char* d2;
	char* s1; // shift
	char* s2;
};

struct Course {
	char* id;
	char* name;
	char* lecturerName;
	char* sSemester;
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

void create_class(Class*& pClass, char* yearName, char* className, int add);
void input_stu(Student*& newStu);
void addStudent(Student*& pStudent, char* yearName, char* className, Student*& newStu, int add);

void inputStudent_toCSV(Student*& newStu, char* s);
void addStudentCSV(Student*& pStudent, char* CSV_Student_File, char* yearName, char* className, int add);

void create_year(Year*& pYear, char* yearName, int add);

void createSemester(Semester*& pSemester, char* semesterName, char* yearName, Date startDate, Date endDate, int add);


void courseRegistration(Semester*& pSemester, Semester* totSemetser, char* yearName);



void addNewCourse(Course*& pCourse, char* semesterName, char* yearName, Course*& newCourse, int add);


void viewListOfCourse(Course* pCourse);


void deleteCourse(Year* pYear, Course*& pCourse, char* yearName, char* semesterName, char* courseID);


void updateCourse(Course*& pCourse, char* yearName, char* semesterName, char* courseID);

void viewListOfCLasses(Year* pYear);

void viewStudentInfo(Student student);
void viewListOfStudentsInClass(Year* pYear, char* className);
void viewScoreBoardOfClass(Student* pStudent, Semester* pSemester);

void viewListOfStudentsInCourse(Student* pStuInCourse, char* courseID);
void viewScoreboardOfCourse(Course* pCourse);

void inputScoreboardCSV(Scoreboard*& newScr, char* s);
void addScoreBoardCSV(Scoreboard*& pScore, char* yearName, char* semesterName, char* courseName);
void exportStudentToCsv(Student* pStuInCourse, char* courseID);
void updateScoreBoardStudent(Scoreboard*& pScr, char* yearName, char* semesterName, char* courseID, char* studentID);

void enrollStudent(Course*& pCourse, Student*& pStudent, char* CourseID, char* StudentID, char* yearName, char* semesterName, int add);
void removeCourseInEnrollList(Course*& pCourse, Student*& pStudnet, char* yearName, char* semesterName, char* CourseID, char* studentID);
void viewEnrollList(Course* pEnrollCourse, char* semesterName);

void viewScoreBoard(Course* pCourse, char* studentID); // task 26
void loadData(Year*& pYear);

int chooseRoleScreen();
bool LogIn(int t, char*& studentID);
void changePassword(int t, char* username);

int yearScreen();
void Menu_createYear(Year*& pYear);

int classScreen(char* yearName);
void Menu_createClass(Class*& pClass, char* yearName);

int studentScreen(Student* pStudent, char* yearName, char* className);
void Menu_createStudent(Student*& pStudent, char* yearName, char* className);
void Menu_createStudent_toCSV(Student*& pStudent, char* yearName, char* className);

int semesterScreen(Semester*& pSemester);
void Menu_createSemester(Semester*& pSemester, char* yearName);

int courseScreen(Course*& pCourse, char* semesterName);
void Menu_addCourse(Course*& pCourse, char* yearName, char* semesterName);

int editCourseScreen(Course*& curCourse);

int enrollSemesterScreen(Year*& pYeawr, char* studentID);
int enrollCourseScreen(char* semesterName);
int chooseCourse(Course*& pCourse);

int viewAndDeleteCourseScreen(Course*& pCourse, char* semesterName);
void deleteCourseScreen(Course* pCourse, Student* pStudent, char* yearName, char* semesterName, char* studentID);

void viewOrAddScoreBoard(Course* curCourse, char* yearName, char* semesterName);
void gotoXY(SHORT posX, SHORT posY);
void setConsoleWindow(int w, int h);
void fixConsoleWindow();
void textColor(int color);
void invisibleCursor();
void visibleCursor();
void drawBox(int x, int y, int k);
void drawBox(int x, int y, int k, int n);
void moveLeft(int& func);
void moveRight(int& func);
void moveUp(cursorLocation& pos);
void moveDown(cursorLocation& pos);
void deleteArrow(cursorLocation pos);

#endif
