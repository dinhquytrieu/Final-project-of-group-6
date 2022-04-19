void changePassword(int t, char * userName) {
	ifstream fIn;
	if (t == 1)
		fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_admin.txt");
	else if (t == 2)
		fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_student.txt");
	char user[101], pass[101];
	while (fIn >> user && fIn >> pass) {
		if (strcmp(user, userName) == 0) {
			while(true) {	
				cout << "Please input your current password: ";
				char cur_pass[101]; cin >> cur_pass;
				if (strcmp(cur_pass, pass) != 0) {
					cout << "Wrong password, please try again later\n";
					system("pause");
					system("cls");
					break;
				}
				cout << "Please input your new password: ";
				char new_pass_1[101]; cin >> new_pass_1;
				cout << "Please input your new password again: ";
				char new_pass_2[101]; cin >> new_pass_2;
				if (strcmp(new_pass_1, new_pass_2) != 0) {
					cout << "The new passwords you just typed in doesn't match, please try again\n";
					system("pause");
					system("cls");
				}
				else {
					fIn.close();
					ofstream fOut;
					if (t == 1) {
						fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_admin.txt");
						fOut.open("C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt");
					}
					else if (t == 2) {
						fIn.open("C:\\Github\\Final-project-of-group-6\\DataProject\\Account_student.txt");
						fOut.open("C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt");					
					}	
					char userOut[101], passOut[101];
					while (fIn >> userOut && fIn >> passOut) {
						fOut << userOut << ' ';
						if (strcmp(pass, passOut) == 0 && strcmp(userName, userOut) == 0)
							fOut << new_pass_1 << '\n';							
						else
							fOut << passOut << '\n';
					}
					fIn.close();
					fOut.close();
					if (t == 1) {
						system("del C:\\Github\\Final-project-of-group-6\\DataProject\\Account_admin.txt");
						system("ren C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt Account_admin.txt");
					}
					else if (t == 2) {
						system("del C:\\Github\\Final-project-of-group-6\\DataProject\\Account_student.txt");
						system("ren C:\\Github\\Final-project-of-group-6\\DataProject\\tmp.txt Account_student.txt");
					}
					system("cls");
					cout << "Password changed successfully\n\n";
					break;           
				}
			}
			break;
		}
	}
}
