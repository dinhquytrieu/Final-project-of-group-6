#include "header.h"

void enrollCourse(student *&studentHead, string studentID, string courseID, course *&courseHead, ofstream &fout){
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
			course *courseNew = pcourseCur;
            pcurStudent->pCourse = courseNew;
            courseNew->pCourseNext = nullptr;

        }
        else{
            course *pcourTem = pcurStudent->pCourse;
            while(pcourTem->pCourseNext != nullptr) pcourTem = pcourTem->pCourseNext;
			course *courseNew = pcourseCur;
            pcourTem->pCourseNext = courseNew;
            courseNew->pCourseNext = nullptr;
        }

        if(pcourseCur->pStuHead == nullptr){
			student *newStudent = pcurStudent;
            pcourseCur->pStuHead = newStudent;
            newStudent->pStudentNext = nullptr;
        }
        else{
            student *temp = pcourseCur->pStuHead;
            while(temp->pStudentNext != nullptr) temp = temp->pStudentNext;
			student *newStudent = pcurStudent;

            temp->pStudentNext = newStudent;
            newStudent->pStudentNext = nullptr;
        }
    }

    fout.open("C:\\GitHub\\Final-project-of-group-6\\datafile\\list_enrolledCourses.txt", ios_base::out | ios_base::app);
    
	
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

