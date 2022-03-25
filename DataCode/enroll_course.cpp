#include "header.h"

void enrollCourse(student *&studentHead, string studentID, string courseID, course *&courseHead){
    student *pcurStudent = studentHead;
    while(pcurStudent != nullptr && pcurStudent->id != studentID){
        pcurStudent = pcurStudent->pStudentNext;
    }

    course *pcourseCur = courseHead;
    while(pcourseCur != nullptr && pcourseCur->IDcourse != courseID){
        pcourseCur = pcourseCur->pCourseNext;
    }

    if(pcurStudent != nullptr && pcourseCur != nullptr){
        if(pcurStudent->pCourse == nullptr){
            pcurStudent->pCourse = pcourseCur;
            pcurStudent->pCourse->pCourseNext = nullptr;

        }
        else{
            course *pcourTem = pcurStudent->pCourse;
            while(pcourTem->pCourseNext != nullptr) pcourTem = pcourTem->pCourseNext;
            pcourTem->pCourseNext = pcourseCur;
            pcourTem->pCourseNext->pCourseNext = nullptr;
        }

        if(pcourseCur->pStuHead == nullptr){
            pcourseCur->pStuHead = pcurStudent;
            pcourseCur->pStuHead->pStudentNext = nullptr;
        }
        else{
            student *temp = pcourseCur->pStuHead;
            while(temp->pStudentNext != nullptr) temp = temp->pStudentNext;
            temp->pStudentNext = pcurStudent;
            temp->pStudentNext->pStudentNext = nullptr;
        }
    }

    ofstream fout("C:\\GitHub\\Final-project-of-group-6\\datafile\\list_enrolledCourses.txt", ios_base::out | ios_base::app);
    
    if(pcurStudent->pCourse->pCourseNext == nullptr){
        fout << pcurStudent->id << endl;
        fout << pcurStudent->pCourse->NAMEcourse << endl;
    }
    else{
        course *ptem = pcurStudent->pCourse;
        while(ptem->pCourseNext != nullptr){
            ptem = ptem->pCourseNext;
        }
        fout << ptem->NAMEcourse << endl;

    }

    fout.close();
}