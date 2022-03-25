#include <iostream>
#include "Course.h"
#include "Header.h"

using namespace std;

void viewListOfCourse (course *pCourseHead) {
	course * pCur = pCourseHead;
    while (pCur != nullptr) {
        cout << "Course ID: " << pCur -> IDcourse << '\n';
        cout << "Course Name: " << pCur -> NAMEcourse << '\n';
        cout << "Lecturer Name: " << pCur -> teacherName << '\n';
		    cout << "Number of Credit: " << pCur ->sumCredit << '\n';
        cout << "Occur in: " << pCur ->performDate.d1<< " at " << pCur ->performDate.TIME1.hour << ":" << pCur ->performDate.TIME1.min  
	<< " and " << pCur -> performDate.d2 << " at " << pCur->performDate.TIME2.hour << ":" << pCur ->performDate.TIME2.min << endl;
        int cnt = 0;
        student* stuInCourse = pCur -> pStuHead;
        while (stuInCourse != nullptr) {
        	cnt++;
        	stuInCourse = stuInCourse -> pStudentNext;
        }
		cout << "Number of students registered: " << cnt << " / " << pCur -> maxStudent << '\n';
		cout << '\n';
		cout <<endl;

        // move to next course
        pCur = pCur -> pCourseNext;
    }
    system("pause");
    system("cls");
}
