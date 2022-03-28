#include <iostream>
#include <fstream>
#include <string.h>

#include "Header.h"
#include "Course.h"

using namespace std;
void updateCourse(course*& pCourse, string nameYear, string nameSemester, string courseID) {
    course* pCur = pCourse;
    while (pCur && pCur->IDcourse !=courseID) ) {
        pCur = pCur->pCourseNext;
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
        cin.get(pCur->IDcourse, 101, '\n');
    }
    else if (x == 2) {
        cout << "New course's name: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->NAMEcourse, 101, '\n');
    }
    else if (x == 3) {
        cout << "New lecturer's name: ";
        cin.ignore(1001, '\n');
        cin.get(pCur->teacherName, 101, '\n');
    }
    else if (x == 4) {
        cout << "New number of credits: ";
        cin >> pCur->sumCredit;
    }
    else if (x == 5) {
        cout << "New max students: ";
        cin >> pCur->maxStudent;
    }
    else {
        cout << "New day 1 and time: ";
	cin.ignore()
	getline(cin, pCur->performDate.d1);
	cout << "Time of day 1(hour-minute): "<<endl;
        cin >> pCur->performDate.TIME1.hour >> pCur->performDate.TIME1.min;
        cout << "New day 2 and time: ";
	cin.ignore()
	getline(cin, pCur->performDate.d2);
	cout << "Time of day 2(hour-minute): "<<endl;
        cin >> pCur->performDate.TIME2.hour >> pCur->performDate.TIME2.min;
    }
    cout << "Update successfully!!\n";
    system("pause");
    system("cls");

    char dirD[] = "C:\\GitHub\\Final-project-of-group-6\\datafile\\";
    char c[500] = "";
    strcat(c, dirD);
    strcat(c, yearName);
    strcat(c, "\\Semester\\");
    strcat(c, semesterName);
    strcat(c, "\\Course.txt");

    ofstream fileout(c);

    pCur = pCourse;
    while (pCur != nullptr) {
        fileout << pCur ->IDcourse<< '\n';
        fileout << pCur ->NAMEcourse << '\n';
        fileout << pCur ->teacherName << '\n';
        fileout << pCur -> sumCredit << '\n';
        fileout << pCur -> maxStudent << '\n';
        fileout << pCur ->performDate.d1 << endl;
	fileout << pCur->performDate.TIME1.hour << endl;
    	fileout << pCur->performDate.TIME1.min << endl;
    	fileout << pCur->performDate.d2<< endl;
    	fileout << pCur->performDate.TIME2.hour << endl;
    	fileout << pCur->performDate.TIME2.min;
    
    	pCur = pCur -> pCourseNext;
	}
	fileout.close();
}
