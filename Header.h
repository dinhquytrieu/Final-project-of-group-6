#ifndef _HEADER_H_
#define _HEADER_H_



#include <iostream>
 #include <bits/stdc++.h>
 
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

























#endif // !_HEADER_H_
