#include <string.h>
#include "course.h"
#include "header.h"

void view_listof_classes(Year* yearHead) {
	cout << "Here is the list of classes in "
	while (yearHead != NULL) {
		cout << "Here is the list of classes in ";
		cout << yearHead -> nameYear << endl;
		while (yearHead -> pClassHead != NULL) {
			cout << yearHead -> pClassHead -> nameClass << endl;
			yearHead -> pClassHead = yearHead -> pClassHead -> pClassNext;
		}
		yearHead = yearHead -> pYearNext;
	}
}
