#ifndef _STAFF_H_
#define _STAFF_H_

#include "header.h"

//void viewListOfCLasses(Year* pYear);
void ViewListOfCLasses(Year* pYear);
//void viewStudentInfo(Student student);
//void viewListOfStudentsInClass(Year* pYear, char* className);
//void viewScoreBoardOfClass(Student * pStudent, Semester * pSemester);

void view_listOfStudents_inCourse(Student *pStu, char *IDcourse);
void view_scoreBoardOf_acourse(course *pCurCourse);
//void inputScoreboardCSV(Scoreboard *& newScr , char *s);
//void addScoreBoardCSV(Scoreboard *& pScore, char * yearName, char * semesterName, char * courseName);
void export_student_toCsv(student* pStuRegister, char *IDcourse);
//void updateScoreBoardStudent(Scoreboard *& pScr, char *yearName, char* semesterName, char *courseID, char* studentID);

#endif
