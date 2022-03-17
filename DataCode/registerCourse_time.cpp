#include "header.h"

void register_course(semester *&semesterNew, ofstream &fileout){
   
    cout << "\t\tEnter start date of registration of the course: " << endl;
    cout << "YEAR: ";
    cin >> semesterNew->regStart.year;
    cout << " month: ";
    cin >> semesterNew->regStart.month;
    cout << " day: ";
    cin >> semesterNew->regStart.day;

    fileout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\time_registration.txt", ios_base::out);
 //   fileout << endl;
    fileout << semesterNew->regStart.year << " ";
    fileout << semesterNew->regStart.month << " ";
    fileout << semesterNew->regStart.day << " ";

    fileout.close();
}