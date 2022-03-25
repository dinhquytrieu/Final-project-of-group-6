#include <string.h>
#include "Course.h"
#include "Header.h"
#include <iostream>

using namespace std;

void ViewListOfCLasses(Year* pYear) {
	while (pYear) {
		cout <<"Year:"<< pYear->nameYear << endl;
		while (pYear->pClassHead) {
			cout << pYear->pClassHead->nameClass << endl;
			pYear->pClassHead = pYear->pClassHead->pClassNext;
		}
		pYear = pYear->pYearNext;
	}
}
