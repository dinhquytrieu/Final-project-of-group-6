#include "course.h"
#include "header.h"

void view_listOfCourses(course *courseHead) {
	course * cur = courseHead;
	cout << "----------WELCOME!---------" << endl; 
	cout << "HERE IS THE LIST OF COURSES" << endl;
	cout << "---------------------------" << endl;
    while (cur != NULL) {
        cout << "Course ID: " << cur -> IDcourse << endl;
        cout << "Course Name: " << cur -> NAMEcourse << endl;
        cout << "Lecturer Name: " << cur -> teacherName << endl;
		cout << "Number of Credit: " << cur -> sumCredit << endl;
        cout << "Occur in: " << cur -> date.d1 << " " << cur -> date.TIME1 << " and " << cur -> date.d2 << " " << cur -> date.TIME2 << endl;
        int count = 0;
        student* pStuRegister = cur -> pStuHead;
        while (pStuRegister != NULL) {
        	count++;
        	pStuRegister = pStuRegister -> pStudentNext;
        }
		cout << "This course includes : " << count << " / " << cur -> maxStudent << " students." << endl;
		cout << endl;
        cur = cur -> pCourseNext;
    }
    system("pause");
    system("cls");
}

