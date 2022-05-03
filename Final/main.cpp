#include "header.h"
int main() {
	//Input interface

	Year* pYear = nullptr;
	loadData(pYear);
	system("cls");
	time_t cur_t = time(0);
	tm* now = localtime(&cur_t);

	while (true) { // Basic screen, choose which role to login
		int respondRole = chooseRoleScreen();
		if (respondRole == 0)
			break;
		else if (respondRole == 1) {
			char* userName;
			if (LogIn(1, userName)) { // Login as a Staff
				setConsoleWindow(1400, 700);
				fixConsoleWindow();
				while (true) { // Edit Year screen
					int respondYear = yearScreen();
					if (respondYear == 0) // Logout 
						return 0;
					else if (respondYear == 1) { // Change password
						changePassword(1, userName);
					}
					else if (respondYear == 2) { // Create a School Year
						Menu_createYear(pYear);
					}
					else {
						// Access that year
						Year* curYear = pYear;
						int cntYear = 3;
						while (curYear != nullptr && cntYear < respondYear) {
							curYear = curYear->yearNext;
							cntYear++;
						}
						if (curYear == nullptr || cntYear < respondYear) {
							textColor(4);
							gotoXY(32, 1); cout << "Invalid, try again";
							textColor(7);
							continue;
						}

						while (true) { // Edit Class screen
							int respondClass = classScreen(curYear->YearName);
							if (respondClass == 0)
								break;
							else if (respondClass == 1) {
								while (true) { // Check all semesters
									int respondSemester = semesterScreen(curYear->pSemester);

									if (respondSemester == 0)
										break;
									else if (respondSemester == 1) { // Create a new Semester in this year
										Menu_createSemester(curYear->pSemester, curYear->YearName);
									}
									else {
										// Access that semester
										Semester* curSemester = curYear->pSemester;
										int cntSemester = 2;
										while (curSemester != nullptr && cntSemester < respondSemester) {
											curSemester = curSemester->semesterNext;
											cntSemester++;
										}
										if (curSemester == nullptr || cntSemester < respondSemester) {
											textColor(4);
											gotoXY(32, 1); cout << "Invalid, try again";
											textColor(7);
											continue;
										}

										while (true) { // Edit Course screen  
											int respondCourse = courseScreen(curSemester->pCourse, curSemester->SemesterName);

											if (respondCourse == 0)
												break;
											else if (respondCourse == 1) { // Create a course registration session
												courseRegistration(curSemester, curYear->pSemester, curYear->YearName);
											}
											else if (respondCourse == 2) { // Add a course to this semester
												Menu_addCourse(curSemester->pCourse, curYear->YearName, curSemester->SemesterName);
											}
											else if (respondCourse == 3) {	// View the details of all the courses
												viewListOfCourse(curSemester->pCourse);
											}
											else {
												// Access that Course

												int cntCourse = 4;
												Course* curCourse = curSemester->pCourse;
												while (curCourse != nullptr && cntCourse < respondCourse) {
													curCourse = curCourse->courseNext;
													cntCourse++;
												}
												if (curCourse == nullptr || cntCourse < respondCourse) {
													textColor(4);
													gotoXY(40, 1);
													cout << "Invalid, try again\n\n";
													textColor(7);
													continue;
												}

												while (true) { // Edit the current course
													int respondEditCourse = editCourseScreen(curCourse);
													if (respondEditCourse == 0) {
														break;
													}
													else if (respondEditCourse == 1) { // Update course information
														updateCourse(curSemester->pCourse, curYear->YearName, curSemester->SemesterName, curCourse->id);
													}
													else if (respondEditCourse == 2) { // View list of students in this course
														viewListOfStudentsInCourse(curCourse->pStudent, curCourse->id);
													}
													else if (respondEditCourse == 3) { // View the scoreboard of this course
														viewOrAddScoreBoard(curCourse, curYear->YearName, curSemester->SemesterName);
													}
													else if (respondEditCourse == 4) { // Delete the current course
														deleteCourse(curYear, curSemester->pCourse, curYear->YearName, curSemester->SemesterName, curCourse->id);
														break;
													}
													else
													{
														gotoXY(62, 1);
														textColor(4);
														cout << "Invalid, try again\n\n";
														textColor(7);
													}
												}
											}
										}
									}
								}
							}
							else if (respondClass == 2) { // Create a Class in this year
								Menu_createClass(curYear->pClass, curYear->YearName);
							}
							else {
								//Access that class
								Class* curClass = curYear->pClass;
								int cntClass = 3;
								while (curClass != nullptr && cntClass < respondClass) {
									curClass = curClass->classNext;
									cntClass++;
								}
								if (curClass == nullptr || cntClass < respondClass) {
									textColor(4);
									gotoXY(45, 1); cout << "Invalid, try again\n\n";
									textColor(7);
									continue;
								}

								while (true) { // Edit Student Screen
									int respondStudent = studentScreen(curClass->pStudent, curYear->YearName, curClass->ClassName);
									if (respondStudent == 0)
										break;
									else if (respondStudent == 1) { // Create a new student in this class
										Menu_createStudent(curClass->pStudent, curYear->YearName, curClass->ClassName);
									}
									else if (respondStudent == 2) { // Add students through .csv file
										Menu_createStudent_toCSV(curClass->pStudent, curYear->YearName, curClass->ClassName);
									}
									else if (respondStudent == 3) {	// View scoreboard of a class
										viewScoreBoardOfClass(curClass->pStudent, curYear->pSemester);
									}
									else
									{
										gotoXY(37, 1);
										textColor(4);
										cout << "Invalid, try again\n\n";
										textColor(7);
									}
								}
							}
						}
					}
				}
			}
		}
		else if (respondRole == 2) {
			char* studentID;
			if (LogIn(2, studentID)) { // Login as a Student
				setConsoleWindow(1400, 700);
				fixConsoleWindow();
				char* yearName = new char[51];
				int tmp = (studentID[0] - '0') * 10 + studentID[1] - '0';
				char tmp_c[40] = "";
				strcat(yearName, "20");
				strcat(yearName, itoa(tmp, tmp_c, 10));
				strcat(yearName, "-20");
				strcat(yearName, itoa(tmp + 1, tmp_c, 10));

				Year* curYear = pYear;
				while (curYear && strcmp(curYear->YearName, yearName) != 0)
					curYear = curYear->yearNext;

				Student* curStudent = nullptr;
				Class* curClass = curYear->pClass;
				while (curClass) {
					curStudent = curClass->pStudent;
					while (curStudent) {
						if (strcmp(curStudent->studentID, studentID) == 0)
							break;
						curStudent = curStudent->studentNext;
					}
					if (curStudent != nullptr) break;
					curClass = curClass->classNext;
				}

				Date RegisterDate;
				RegisterDate.day = now->tm_mday;
				RegisterDate.month = now->tm_mon + 1;
				RegisterDate.year = now->tm_year + 1900;

				while (true) {  // Choose a semester to enroll

					int respondSemester = enrollSemesterScreen(curYear, studentID);
					if (respondSemester == 0) // Logout
						return 0;
					else if (respondSemester == 1) {// Change password
						changePassword(2, studentID);
					}
					else {
						// Access that semester
						Semester* curSemester = curYear->pSemester;
						int cntSemester = 2;
						while (curSemester != nullptr && cntSemester < respondSemester) {
							curSemester = curSemester->semesterNext;
							cntSemester++;
						}
						if (curSemester == nullptr || cntSemester < respondSemester) {
							gotoXY(62, 1);
							textColor(4);
							cout << "Invalid, try again";
							textColor(7);
							continue;
						}


						while (true) {
							int respondCourse = enrollCourseScreen(curSemester->SemesterName);
							if (respondCourse == 0)
								break;
							else if (respondCourse == 1) { // Choose a course to enroll

								bool ok_s = false, ok_l = false;
								if (curSemester->startReg.year < RegisterDate.year) ok_s = true;
								if (curSemester->startReg.year == RegisterDate.year && curSemester->startReg.month < RegisterDate.month) ok_s = true;
								if (curSemester->startReg.year == RegisterDate.year && curSemester->startReg.month == RegisterDate.month && curSemester->startReg.day < RegisterDate.day) ok_s = true;
								if (RegisterDate.year < curSemester->endReg.year) ok_l = true;
								if (RegisterDate.year == curSemester->endReg.year && RegisterDate.month < curSemester->endReg.month) ok_l = true;
								if (RegisterDate.year == curSemester->endReg.year && RegisterDate.month == curSemester->endReg.month && RegisterDate.day < curSemester->endReg.day) ok_l = true;

								if (!ok_s || !ok_l) {
									gotoXY(35, 1);
									textColor(4);
									cout << "The registration phase has expired or not exist, please enroll later";
									textColor(7);
									continue;
								}

								while (true) { // List of course to choose screen
									int respondChooseCourse = chooseCourse(curSemester->pCourse);

									if (respondChooseCourse == 0)
										break;
									else {
										int cntCourse = 1;
										Course* curCourse = curSemester->pCourse;
										while (curCourse && cntCourse < respondChooseCourse) {
											cntCourse++;
											curCourse = curCourse->courseNext;
										}
										if (curCourse == nullptr || cntCourse < respondChooseCourse) {
											gotoXY(62, 2);
											textColor(4);
											cout << "Invalid, try again";
											textColor(7);
											continue;
										}
										enrollStudent(curSemester->pCourse, curClass->pStudent, curCourse->id, curStudent->studentID, curYear->YearName, curSemester->SemesterName, 1);
									}
								}
							}
							else if (respondCourse == 2) { // View list of enrolled course
								while (1) {
									int respondViewAndDelete = viewAndDeleteCourseScreen(curStudent->pCourse, curSemester->SemesterName);
									if (respondViewAndDelete == 0)
										break;
									else
										deleteCourseScreen(curSemester->pCourse, curStudent, curYear->YearName, curSemester->SemesterName, curStudent->studentID);
								}
							}
							else if (respondCourse == 3) { // View scoreboard in this semester
								viewScoreBoard(curSemester->pCourse, curStudent->studentID);
							}
							else
							{

								gotoXY(34, 1);
								textColor(4);
								cout << "Invalid, try again";
								textColor(7);
							}
						}
					}
				}
			}
		}
	}

}






