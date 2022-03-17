#include "header.h"

void describe_course(course *&courseHead, ofstream &fileout){
    course *pcur = courseHead;
    while(pcur->pCourseNext != nullptr){
        pcur = pcur->pCourseNext;
    }

    course *newCourse = new course;
    newCourse->pCourseNext = nullptr;

    
    cout << "\nEnter course id: ";
    cin.ignore();
    cin >> newCourse->IDcourse;
    cout << "\nEnter course name: ";
    cin.ignore();
    getline(cin, newCourse->NAMEcourse);
    cout << "\nEnter teacher'name: ";
    cin.ignore();
    getline(cin, newCourse->teacherName);
    cout << "\nEnter number of credits: ";
    cin >> newCourse->sumCredit;
    cout << "\nEnter the maximum number of student in thr course: ";
    cin >> newCourse->maxStudent;
    cout << "\nDay of performance in week: ";
    cin.ignore();
    getline(cin, newCourse->performDate.d1);
    cout << "\nTime of performance(hour-minute): ";
    cin >> newCourse->performDate.TIME1.hour;
    cin >> newCourse->performDate.TIME1.min;


    cout << "\nDay of performance in week: ";
    cin.ignore();
    getline(cin, newCourse->performDate.d2);
    cout << "\nTime of performance(hour-minute): ";
    cin >> newCourse->performDate.TIME2.hour;
    cin >> newCourse->performDate.TIME1.min;

    pcur->pCourseNext = newCourse;

    fileout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\description_courses.txt", ios_base::out);
    fileout << endl;
    fileout << newCourse->IDcourse << endl;
    fileout << newCourse->NAMEcourse << endl;
    fileout << newCourse->teacherName << endl;
    fileout << newCourse->sumCredit << endl;
    fileout << newCourse->maxStudent;
    fileout << newCourse->performDate.d1 << endl;
    fileout << newCourse->performDate.TIME1.hour << endl;
    fileout << newCourse->performDate.TIME1.min << endl;
    fileout << newCourse->performDate.d2<< endl;
    fileout << newCourse->performDate.TIME2.hour << endl;
    fileout << newCourse->performDate.TIME2.min << endl;

    fileout.close();

}
