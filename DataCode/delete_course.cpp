#include"header.h"
#include"course.h"

using namespace std;

void deleteCourse(course *&courseHead, string IDcourse) {
	// while(1) {
	// 	cout << "Are you sure you want to delete this course?\n\n";
	// 	cout << "0: No\n";
	// 	cout << "1: Yes\n\n";

   	// 	cout << "Answer: ";
   	// 	char *respond = new char[101]; 
	// 	cin >> respond;
   	// 	system("cls");
   	// 	if (strlen(respond) > 1 || (respond[0] < '0' || '1' < respond[0])) {
   	// 		cout << "Invalid, please try again\n\n";
   	// 		continue;
   	// 	}
   	// 	int x = respond[0] - '0';
   	// 	delete[] respond;
   	// 	if (!x)
   	// 		return;
   	// 	break;		
	// }
 	// Then we simply delete this course

    if (strcmp(courseHead->IDcourse.c_str(), IDcourse.c_str()) == 0) {
        course* pDel = courseHead;
        courseHead = courseHead -> pCourseNext;
        delete pDel;
    }
    else {
        course* pCur = courseHead;
        while (pCur -> pCourseNext && strcmp(pCur -> pCourseNext -> IDcourse.c_str(), IDcourse.c_str()) != 0) {
            pCur = pCur -> pCourseNext;
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
        fout << pCur -> performDate.d1 << '\n' << pCur->performDate.TIME1.hour << endl <<  pCur->performDate.TIME1.min << '\n';
	    fout << pCur -> performDate.d2 << '\n' <<  pCur->performDate.TIME2.hour << endl <<  pCur->performDate.TIME2.min <<'\n';
    	pCur = pCur -> pCourseNext;
 	}
 	fout.close();
}

