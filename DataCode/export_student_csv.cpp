#include "header.h"
#include "staff.h"
#include <iostream>
#include <fstream>
#include <string.h>

void export_student_toCsv(student* pStuRegister, char *IDcourse) {
	char csvfile[] = "C:\\Github\\Final-project-of-group-6\\datafile\\csvfile\\csv_studentincourse\\";
	char csv[505];
	strcat(csv, IDcourse);
	strcat(csv, ".csv");
	ofstream fileout;
	fileout.open(csv);
	if (fileout.is_open()) {
		int count = 0;
		while (pStuRegister != NULL) {
			fileout << ++count << "," << pStuRegister->id << "," << pStuRegister->name << "," << pStuRegister->dob.day << "-" << pStuRegister -> dob.month << "-" << 
			pStuRegister -> dob.year << "," << pStuRegister->Class << "," << pStuRegister->gender;
			fileout << end;
			
			pStuRegister = pStuRegister->pStudentNext;
		}
		cout << "...Done! The list of students has been exported." << endl;
		cout << "If you want to find the location, please open " << endl;
		cout << "Final-project-of-group-6\\datafile\\csvfile\\csv_studentincourse" << IDcourse << ".csv\n\n";
		system("pause");
		system("cls");
	}
	fileout.close();
}

//tui tao 1 thu muc csv_studentincourse de chua hoc sinh cua moi course. id thi tam thoi dat la course1, course2, course 3
