#include"header.h"
#include"course.h"

using namespace std;

void deleteCourse(Year * pYear, course *&courseHead, string IDcourse) {
	while(1) {
		cout << "Are you sure you want to delete this course?\n\n";
		cout << "0: No\n";
		cout << "1: Yes\n\n";

   		cout << "Answer: ";
   		char *respond = new char[101]; 
		cin >> respond;
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

    if (strcmp(courseHead->IDcourse, IDcourse) == 0) {
        course* pDel = courseHead;
        courseHead = courseHead -> pCourseNext;
        delete pDel;
    }
    else {
        course* pCur = courseHead;
        while (pCur -> pCourseNext && strcmp(pCur -> pCourseNext -> IDcourse, IDcourse) != 0) {
            pCur = pCur -> courseNext;
        }
        if (pCur -> pCourseNext) {
            course* pDel = pCur -> pCourseNext;
            pCur -> pCourseNext = pDel -> pCourseNext;
            delete pDel;
        }
    }
    
    ofstream fout("C:\\Github\\Final-project-of-group-6\\datafile\\description_courses.txt");

    course * pCur = courseHead;
    while (pCur != NULL) {
        fout << pCur -> IDcourse << '\n';
        fout << pCur -> NAMEcourse << '\n';
        fout << pCur -> teacherName << '\n';
        fout << pCur -> sumCredit << '\n';
        fout << pCur -> maxStudent << '\n';
        fout << pCur -> date.d1 << '\n' << pCur->date.TIME1 << '\n';
	    fout << pCur -> date.d2 << '\n' << pCur->date.TIME2 << '\n';
    	pCur = pCur -> pCourseNext;
 	}
 	fout.close();
}

