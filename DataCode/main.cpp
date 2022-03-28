#include "header.h"
#include "registerCourse_time.cpp"
#include "addSemester.cpp"
#include "addCourse.cpp"
#include "delete_course.cpp"
#include "View_list_of_Courses.cpp"
#include "enroll_course.cpp"

void load_data(semester *&pSemHead, course *&pcourseHead, ifstream &filein){
    filein.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\time_ofSemester.txt", ios_base::in);
    while(filein.eof() == 0){
        semester *psemNew = new semester;

      //  filein.ignore(1, '\n');
        filein >> psemNew->nameSemester;
        filein >> psemNew->startDate.day >> psemNew->startDate.month >> psemNew->startDate.year;  
        filein >> psemNew->endDate.day >> psemNew->endDate.month >> psemNew->endDate.year;  

        if(pSemHead == nullptr){
            pSemHead = psemNew;
            psemNew->pSemNext = nullptr;
        }
        else{
            semester *psemcur = pSemHead;
            while(psemcur->pSemNext != nullptr){
                psemcur = psemcur->pSemNext;
            }

            psemcur->pSemNext = psemNew;
            psemNew->pSemNext = nullptr;
        }
    }

    filein.close();

    
}

void loadData2(semester *&psemHead, ifstream &filein){
    filein.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\time_registration.txt", ios_base::in);
    if(psemHead == nullptr) return;
    semester *psemcur = psemHead;
    while(psemcur != nullptr){
        filein >> psemcur->regStart.year >> psemcur->regStart.month >>  psemcur->regStart.day;

        psemcur = psemcur->pSemNext;
    }

    filein.close();
}

void loadData3(course *&pcourHead, ifstream &filein){
    filein.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\description_courses.txt", ios_base::in);
    
    while(filein.eof() == 0){
        course *courseNew = new course;
        filein.ignore();
        getline(filein, courseNew->IDcourse);
        // cout << courseNew->IDcourse;
      

     
        getline(filein, courseNew->NAMEcourse);
        // cout << courseNew->NAMEcourse;

        getline(filein, courseNew->teacherName);
        // cout << courseNew->teacherName;


        filein >> courseNew->sumCredit;
                // cout << courseNew->sumCredit;

        filein >> courseNew->maxStudent;
            //    cout << courseNew->maxStudent;

        filein.ignore();
        getline(filein, courseNew->performDate.d1);
        filein >> courseNew->performDate.TIME1.hour;
        filein >> courseNew->performDate.TIME1.min;
        filein.ignore();
        getline(filein, courseNew->performDate.d2);

        filein >> courseNew->performDate.TIME2.hour;
        filein >> courseNew->performDate.TIME2.min;

        if(pcourHead == nullptr){
            pcourHead = courseNew;
            courseNew->pCourseNext = nullptr;
        }
        else{
            course *pcur = pcourHead;
            while(pcur->pCourseNext != nullptr){
                pcur = pcur->pCourseNext;
            }

            pcur->pCourseNext = courseNew;
            courseNew->pCourseNext = nullptr;
        }


    }
    filein.close();
}

void output(semester *psemHead){
    system("cls");
    semester *psemcur = psemHead;
    while(psemcur != nullptr){
        cout << psemcur->nameSemester << endl;
        cout << psemcur->startDate.day << "/" << psemcur->startDate.month << "/" << psemcur->startDate.year << endl;
        cout << psemcur->endDate.day << "/" << psemcur->endDate.month << "/" << psemcur->endDate.year << endl;
        cout << psemcur->regStart.day << "/" << psemcur->regStart.month << "/" << psemcur->regStart.year << endl;
        psemcur = psemcur->pSemNext;
    }
}

void output_descriptionCourse(course *pcourHead){
    system("cls");
    course *pcur = pcourHead;
    while(pcur != nullptr){
        cout << pcur->IDcourse << " ";
        cout << pcur->NAMEcourse << " ";
        cout << pcur->teacherName << " ";
        cout << pcur->sumCredit << " ";
        cout << pcur->maxStudent << " ";
        cout << pcur->performDate.d1 << " ";
        cout << pcur->performDate.TIME1.hour << " ";
        cout << pcur->performDate.TIME1.min << " ";
        cout << pcur->performDate.d2 << " ";
        cout << pcur->performDate.TIME2.hour << " ";
        cout << pcur->performDate.TIME2.min << " ";

        cout << endl;
        pcur = pcur->pCourseNext;
    }
}

void output_studentID(student *pstudent){
    if(pstudent == nullptr) return;
    student *pcur = pstudent;
    while(pcur != nullptr){
        cout << pcur->id << endl;
        pcur = pcur->pStudentNext;
    }
}

void menu(semester *&pSemHead, course *&pcourseHead, ofstream &fileout, student *&pstudent, ofstream &fout){
    while(true){
        system("cls");
        cout << "1. add courses" << endl;
        cout << "2. add courses'description: " << endl;
        cout << "3. output" << endl;
        cout << "4. Enroll courses: " << endl;
        cout << "5. add student: " << endl;
        cout << "6. cout list students: " << endl;
        cout << "7. Output description courses: " << endl;


        cout << "0. Exit" << endl;

        int choice;
        cin >> choice;
        if(choice == 0) return;
        else if(choice == 1){
            add_semester(pSemHead, fileout);
        }
        else if(choice == 2){
            describe_course(pcourseHead, fileout);
        }
        else if(choice == 3) output_descriptionCourse(pcourseHead);
        else if(choice == 4){
            system("cls");
            cout << "Enter student'id: ";
            string id;
            cin.ignore();
            getline(cin, id);
            cout << "\nWhich course do you want to enroll: ";
            string nameCourse;
            cin.ignore();
            getline(cin, nameCourse);
            enrollCourse(pstudent, id, nameCourse, pcourseHead, fout);
        }
        else if( choice == 5){
            student *pnew = new student;
            cout << "\nInput student'ID: ";
            cin.ignore();
            getline(cin, pnew->id);
            if(pstudent == nullptr){
                pstudent = pnew;
                pnew->pStudentNext = nullptr;
            }
            else{
                student *pcur = pstudent;
                while(pcur->pStudentNext != nullptr){
                    pcur = pcur->pStudentNext;
                }

                pcur->pStudentNext = pnew;
                pnew->pStudentNext = nullptr;
            }
        }

        else if(choice == 6){
            output_studentID(pstudent);
            system("pause");
        } 
        else if(choice == 7){
            output_descriptionCourse(pcourseHead);
            system("pause");
        }      

    }
}

int main(){
    semester *pSemHead = nullptr;
    course *pcourseHead = nullptr;
    student *pstudent = nullptr;
    ifstream filein;
    ofstream fileout;
    ofstream fout;

   // register_course(pSemHead, fileout);
   // add_semester(pSemHead, fileout);
    loadData3(pcourseHead, filein);

    menu(pSemHead, pcourseHead, fileout, pstudent, fout);
 //  load_data(pSemHead, pcourseHead, filein);
  // loadData2(pSemHead, filein);
  // output(pSemHead);

  //  viewListOfCourse(pcourseHead);
    // deleteCourse(pcourseHead, "cs10002", fileout);


    return 0;
}
