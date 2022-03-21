
#ifndef _HEADER_H_
#define _HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct date;
struct student;
struct CLASS;
struct course;
struct perform;
struct scoreboard;
struct semester;
struct year;

struct time{
    int hour, min;
};

struct date{
    int day, month, year;
};

struct student{
    string id;
    string name;
    string Class;
    int gender; // 0 is female, 1 is male
    date dob;
    course *pCourse = nullptr;
    student *pStudentNext = nullptr;
};

struct scoreboard{
    student *stuHead;
    double Midterm, Final, bonus, total;
    scoreboard *pScoreboardNext = nullptr;
};

struct CLASS{
    string nameClass;
    student *pStudentHead = nullptr;
    CLASS *pClassNext = nullptr;
};

struct Year{
    string nameYear;
    CLASS *pClassHead = nullptr;
    semester *psemHead = nullptr;
    Year *pYearNext = nullptr;
};

struct semester{
    string nameSemester;
    date startDate, endDate;
    date regStart, regEnd; // date of registration
    course *pCourseHead = nullptr;
    semester *pSemNext = nullptr;
};

struct perform{
    //day
    string d1;
    string d2;
    //time
    time TIME1;
    time TIME2;
    
};

struct course{
    string IDcourse;
    string teacherName;
    string NAMEcourse;
    string courseSemester;
    int maxStudent;
    int sumCredit;
    perform performDate;
    student *pStuHead = nullptr;
    scoreboard *pScoreHead = nullptr;
    course *pCourseNext = nullptr;
};

void register_course(semester *&semesterNew, ofstream &fileout);

#endif
