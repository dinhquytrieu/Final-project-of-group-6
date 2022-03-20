#include "header.h"

void add_semester(semester *&psemHead, ofstream &fileout){
    
        system("cls");

        semester *psemNew = new semester;
        
        cout << "Course'name: ";
        cin.ignore();
        getline(cin, psemNew->nameSemester);
        cout << "\nStart date(dd/mm/yyyy): ";
        cin >> psemNew->startDate.day >> psemNew->startDate.month >> psemNew->startDate.year;
        cout << "\nEnd date (dd/mm/yyyy): ";
        cin >> psemNew->endDate.day >> psemNew->endDate.month >> psemNew->endDate.year;

        if(psemHead == nullptr){
            psemHead = psemNew;
            psemNew->pSemNext = nullptr;
        }
        else{
            semester *psemcur = psemHead;
            while(psemcur->pSemNext != nullptr){
                psemcur = psemcur->pSemNext;
            }

            psemcur->pSemNext = psemNew;
            psemNew->pSemNext = nullptr;
        }
        
    

    fileout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\time_ofSemester.txt", ios_base::out | ios_base::app);
    fileout << endl;
    fileout << psemNew->nameSemester << endl;
    fileout << psemNew->startDate.day << " " << psemNew->startDate.month << " " << psemNew->startDate.year << endl;
    fileout << psemNew->endDate.day << " " << psemNew->endDate.month << " " << psemNew->endDate.year;

    fileout.close();

}