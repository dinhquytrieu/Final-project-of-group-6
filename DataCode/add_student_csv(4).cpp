#include <iostream>
#include <fstream>
#include <string.h>
#include "header.h"
#include "class.h"

student *create(int number, string name, string id, date dob, int gender) {
	student *pnew = new student;
	pnew -> number = number;
	pnew -> name = name;
	pnew -> id = id;
	pnew -> dob = dob;
	pnew -> gender = gender;
	pnew -> pStudentNext = NULL;
	return pnew;
}

void delete_wholelist(student *&pStu) {
	student *cur = pStu;
	while(cur != NULL) {
		pStu = pStu -> pStudentNext;
		delete cur;
		cur = pStu;	
	}	
} 

student *add_student_csv(student *&pStu, char* yearName, char* className) {
	ifstream filein("C:\\Github\\Final-project-of-group-6\\datafile\\csvfile\\csv_student_file\\studentcsv.csv");
	student *pcur = NULL;
	
	int number;
	string name;
	string id;
	date dob;
	int gender;
	char temp;
	
	while(!filein.eof()){
		filein >> number;
		filein >> temp; //read ,
		getline(filein, name, ',');
		getline(filein, id, ',');
		filein >> dob.day >> temp >> dob.month >> temp >> dob.year >> temp;
		filein >> gender;
		if (number == 0) break;
		if (pStu == NULL) {
			pStu = create(number, name, id, dob, gender);
			pcur = pStu;
		} else {
			pcur -> pStudentNext = create(number, name, id, dob, gender);
			pcur = pcur-> pStudentNext;
		}
	}
	filein.close();

	const char locate[] = "C:\\Github\\Final-project-of-group-6\\datafile\\";
	char l[505] = "";
	strcat(l, locate);
	strcat(l, yearName);
	strcat(l, "\\");
	strcat(l, className);
	strcat(l, "\\");
	strcat(l, "student_infor.txt");
	// tao file student_infor.txt
	ofstream fileout(l);             

	pcur = pStu;
	while(pcur != NULL) {
		fileout << pcur -> number << " ";
		fileout << pcur -> name << " ";
		fileout << pcur -> id << " ";
		fileout << pcur -> dob.day << "/" << pcur -> dob.month << "/" << pcur -> dob.year << " ";
		fileout << pcur -> gender;
		fileout << endl;
		pcur = pcur -> pStudentNext;
	}
	fileout.close();
	return pStu;
}

//int main() {
//	student *pStu;
//	pStu = NULL;
//	add_student_csv(pStu, "yearName", "className");
//	
//	delete_wholelist(pStu);
//	return 0;
//}
