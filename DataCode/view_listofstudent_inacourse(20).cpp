#include <iostream>
#include <iomanip>
#include <string.h>
#include "staff.h"
#include "header.h"

using namespace std;

void view_listOfStudents_inCourse (Student *pStu, char *IDcourse) {
	while (1) {
		student *pStuRegister = pStu;
	    while (pStuRegister != NULL) {
	        cout << setw(12) << left << pStuRegister -> id;
	        cout << setw(20) << left << pStuRegister->name;
	        cout << setw(10) << left << pStuRegister->Class;
	        cout << setw(8) << left << ((pStuRegister->gender == 0) ? "MALE" : "FEMALE");
	        cout << pStuRegister->dob.day << "/" << pStuRegister->dob.month << "/" << pStuRegister->dob.year << endl;
	        pStuRegister = pStuRegister -> pStudentNext;
    	}
    	cout << endl;
		cout << "HERE IS THE LIST OF STUDENT IN - ID: " << IDcourse << endl;
    	cout << "Would you like to export the list of students to a CSV file?\n";
    	cout << "0: No\n";
    	cout << "1: Yes\n\n";
    	
		cout << "Answer: ";
		char *res = new char[101]; 
		cin >> res;
		
		system("cls");
		
		if (strlen(res) > 1 || (res[0] < '0' || '1' < res[0])) {
			cout << "Invalid, please try again\n\n";
			continue;
		}
		if (res[0] - '0') 
			exportStudentToCsv(pStudent, courseID);
		return;
	}
}
