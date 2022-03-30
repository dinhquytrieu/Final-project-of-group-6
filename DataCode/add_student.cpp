#include <iostream>
#include <fstream>
#include <string.h>
#include "header.h"
#include "class.h"
using namespace std;

void input_student(student *&new_student) {
	cin.get();
	
	cout << "Please input the information of student!" << endl;
	cout << "Enter the student's name: ";
	cin.ignore();
	getline(cin, new_student -> name);
	
	cout << "Enter the student's ID number ";
	cin.ignore();
	getline(cin, new_student -> id);

	cout << "Enter the student's date of birth.\n";
	cout << "Enter year: ";
	cin >> new_student -> dob.year;
	cout << "Enter month: ";
	cin >> new_student -> dob.month;
	cout << "Enter day: ";
	cin >> new_student -> dob.day;
	cin.get();

	cout << "Enter the student's gender.\n";
	cout << "//Press 0 if the student is female or 1 if the student is male!//"
	cin >> new_student -> gender;
	cin.get();
	system("cls");
}

void add_NewStudent(student *&pStu, string* yearName, string* className, student *&new_student, int add) {
	Student *pcur = pStu;
	while (pcur != nullptr) {
		if  (strcmp(pcur -> id, new_student -> id) == 0) {
			cout << "Invalid input!" << endl;
			cout << "The student you are about to add has already existed!!" << endl;
			system("pause");
			system("cls");
			return;
		}
		pcur = pcur -> pStudentNext;
	}
	
	string locate[] = "C:\\Github\\Final-project-of-group-6\\datafile\\";
	string l[505] = "";
	strcat(l, locate);
	strcat(l, yearName);
	strcat(l, "\\");
	strcat(l, className);
	strcat(l, "\\");
	strcat(l, "student_infor.txt");
	// tao file student_infor.txt
	ofstream fileout;                  	
	if (add)
		fileout.open(l);
	
    new_student -> Class = className;
	new_student -> enrolledSession = new bool* [8];
	for (int i = 0; i < 7; i++) {
		new_student -> enrolledSession[i] = new bool[5];
		for (int j = 0; j < 4; j++)
			new_student -> enrolledSession[i][j] = false;
	}

	if (pStu == nullptr) {
		pStu = new_student;
		if (add != 0)
			fileout << pStu -> id << ',' << pStu -> name << ',' << pStu -> dob.year << "-" << pStu -> dob.month << "-" << pStu -> dob.day << ',' << pStu -> gender << '\n';
	}
	else {
		student* pcur = pStu;
		while (pcur -> pStudentNext != nullptr) {
			pcur = pcur -> pStudentNext;
			if (add)
				fileout << pcur -> id << ',' << pcur -> name << ',' << pcur -> dob.year << "-" << pcur -> dob.month << "-" << pcur -> dob.day << ',' << pcur -> gender << '\n';
		}
		if (add)
			fileout << pcur -> id << ',' << pcur -> name << ',' << pcur -> dob.year << "-" << pcur -> dob.month << "-" << pcur -> dob.day << ',' << pcur -> gender << '\n';
		pcur -> pStudentNext = new_student;
		pcur = pcur -> pStudentNext;
		if (add)
			fileout << pcur -> id << ',' << pcur -> name << ',' << pcur -> dob.year << "-" << pcur -> dob.month << "-" << pcur -> dob.day << ',' << pcur -> gender << '\n';
	}
	if (add)
		fileout.close();
}
