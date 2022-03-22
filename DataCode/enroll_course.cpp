#include "header.h"

void enrollCourse(student *&studentHead, string studentID, string courseID, course *courseHead){
    student *pcurStudent = studentHead;
    while(pcurStudent != nullptr && pcurStudent->id != studentID){
        pcurStudent = pcurStudent->pStudentNext;
    }

    course *pcourseCur = courseHead;
    while(pcourseCur != nullptr && pcourseCur->IDcourse != courseID){
        pcourseCur = pcourseCur->pCourseNext;
    }

    if(pcurStudent != nullptr && pcourseCur != nullptr){
        pcurStudent->pCourse = pcourseCur;
    }

    
}