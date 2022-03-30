#include "header.h"

void delete_enrolledCourse(student *pstudentHead, string studentID, string courseID, ofstream &fout){
    student *pstuCur = pstudentHead;
    while(pstuCur != nullptr && pstuCur->id != studentID){
        pstuCur = pstuCur->pStudentNext;
    }
    if(pstuCur->pCourse == nullptr) return;
    course *pCourseCur = pstuCur->pCourse;
    while(pCourseCur->pCourseNext != nullptr && pCourseCur->pCourseNext->IDcourse != courseID){
        pCourseCur = pCourseCur->pCourseNext;
    }

    if(pstuCur != nullptr && pCourseCur->pCourseNext != nullptr){
        course *courseDel = pCourseCur->pCourseNext;
        pCourseCur->pCourseNext = pCourseCur->pCourseNext->pCourseNext;
        delete courseDel;
    }

    fout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\list_enrolledCourses.txt", ios_base::out);
    student *ptem = pstudentHead;
    while(ptem != nullptr){
        fout << ptem->id << endl;
        course *pcourTem = ptem->pCourse;
        while(pcourTem != nullptr){
            fout << pcourTem->IDcourse << endl;
            pcourTem = pcourTem->pCourseNext;
        }

        fout << endl;
        ptem = ptem->pStudentNext;
    }

    fout.close();
}