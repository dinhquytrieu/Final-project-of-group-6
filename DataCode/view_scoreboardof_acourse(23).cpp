#include "staff.h"
#include "header.h"
#include <iomanip>
#include <string.h>

void view_scoreBoardOf_acourse(course *pCurCourse) {
	cout << "------------------------------------------" << endl;
    scoreboard *cur;
    cur = pCurCourse -> pScoreHead;
    cout << setw(30) << left << "ID";    
	cout << "|";
    cout << setw(40) << left << "Name";
    cout << "|";
    cout << setw(30) << left << "Midterm's Mark";
    cout << "|";
    cout << setw(30) << left << "Final's Mark";
    cout << "|";
    cout << setw(30) << left << "Bonus's Mark";
    cout << "|";
    cout << setw(30) << left << "Total's Mark |" << '\n';
    cout << '\n';

    while (cur!=NULL) {
        cout << setw(30) << left << cur->stuHead->id;
        cout << setw(40) << left << cur->stuHead->name;
        cout << setw(30) << left << cur->Midterm;
        cout << setw(30) << left << cur->Final;
        cout << setw(30) << left << cur->bonus;
        cout << setw(30) << left << cur->total 
		cout << endl;
        cur = cur->pScoreboardNext;
    }
}
