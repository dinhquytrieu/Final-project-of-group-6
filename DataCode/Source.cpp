#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <fstream>
using namespace std;

struct account {
	string username;
	string password;
};

struct listOfAcc {
	account acc;
	listOfAcc* pNext = nullptr;
};
struct cursorLocation
{
	int x;
	int y;
};
bool checkWord(string s1, string s2)
{
	int a = s1.length();
	int b = s2.length();
	if (a != b)
		return false;
	else
	{
		for (int i = 0; i < a; i++)
		{
			if (s1[i] != s2[i])
				return false;
		}
	}
	return true;
}
bool checkPassword(account x, listOfAcc* pHead)
{
	listOfAcc* pCur = pHead;
	while (pCur)
	{
		if (checkWord(pCur->acc.username, x.username))
		{
			if (checkWord(pCur->acc.password, x.password))
				return true;
			else
				return false;
		}
		else
			pCur = pCur->pNext;
	}
	return false;
}
listOfAcc* createNode(account x)
{
	listOfAcc* p = new listOfAcc;
	p->acc = x;
	p->pNext = nullptr;
	return p;
}
void readFile(ifstream& accFile, listOfAcc*& pHead)
{
	pHead = NULL;
	account x;
	getline(accFile, x.username);
	getline(accFile, x.password);
	if (accFile.eof())
		return;
	listOfAcc* p = createNode(x);
	pHead = p;
	listOfAcc* pCur = pHead;
	while (!accFile.eof())
	{
		getline(accFile, x.username);
		getline(accFile, x.password);
		p = createNode(x);
		pCur->pNext = p;
		pCur = pCur->pNext;
	}
}

bool changePass(account x, listOfAcc* pHead)
{
	listOfAcc* pCur = pHead;
	while (pCur)
	{
		if (checkWord(pCur->acc.username, x.username))
		{
			do
			{
				string pass;
				cout << "Enter current password: ";
				getline(cin, pass);
				if (checkWord(pass, x.password))
				{
					break;
				}
			} while (true);
			cout << "Enter your new password: ";
			string newPass;
			getline(cin, newPass);
			pCur->acc.password = newPass;
		}
		else
			pCur = pCur->pNext;
	}
	return false;
}
void gotoXY(SHORT posX, SHORT posY)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = posX;
	Position.Y = posY;

	SetConsoleCursorPosition(hStdout, Position);
}
void setConsoleWindow(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, w, h, TRUE);
}
void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void textColor(int color)
{
	HANDLE hConsoleColor;
	hConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleColor, color);
}
void invisibleCursor()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void visibleCursor()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void drawBox(int x, int y, int k)
{
	gotoXY(x, y); cout << char(201);
	for (int i = 0; i < k; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoXY(x, y + 1); cout << char(186);
	for (int j = 0; j < k; j++)
	{
		cout << " ";
	}
	cout << char(186);
	gotoXY(x, y + 2); cout << char(200);
	for (int i = 0; i < k; i++)
	{
		cout << char(205);
	}
	cout << char(188);
}
void loginConsole()
{
	setConsoleWindow(1000, 600);
	fixConsoleWindow();
	gotoXY(30, 0);
	cout << char(201);
	for (int i = 0; i < 70; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	for (int i = 1; i <= 5; i++)
	{
		gotoXY(30, i);
		cout << char(186);
		for (int j = 0; j < 70; j++)
		{
			cout << " ";
		}
		cout << char(186);
		cout << endl;
	}
	gotoXY(30, 6);
	cout << char(200);
	for (int i = 0; i < 70; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	int x = 41, y = 1;
	textColor(4);
	gotoXY(x, y);   cout << "oooooo";
	gotoXY(x, y+1); cout << "o     o";
	gotoXY(x, y+2); cout << "oooooo ";
	gotoXY(x, y+3); cout << "o      ";
	gotoXY(x, y+4); cout << "o      ";
	textColor(6);
	gotoXY(x+9, y);     cout << " ooooo";
	gotoXY(x+9, y + 1); cout << "o     o";
	gotoXY(x+9, y + 2); cout << "o     o ";
	gotoXY(x+9, y + 3); cout << "o     o ";
	gotoXY(x+9, y + 4); cout << " ooooo  ";
	textColor(14);
	gotoXY(x + 18, y);     cout << "oooooo";
	gotoXY(x + 18, y + 1); cout << "o     o";
	gotoXY(x + 18, y + 2); cout << "oooooo ";
	gotoXY(x + 18, y + 3); cout << "o    o ";
	gotoXY(x + 18, y + 4); cout << "o     o";
	textColor(9);
	gotoXY(x+27, y);     cout << "ooooooo";
	gotoXY(x+27, y + 1); cout << "   o   ";
	gotoXY(x+27, y + 2); cout << "   o   ";
	gotoXY(x+27, y + 3); cout << "   o   ";
	gotoXY(x+27, y + 4); cout << "   o   ";
	textColor(10);
	gotoXY(x + 36, y);      cout << " ooooo ";
	gotoXY(x + 36, y+1);    cout << "o     o";
	gotoXY(x + 36, y+2);    cout << "ooooooo";
	gotoXY(x + 36, y+3);    cout << "o     o";
	gotoXY(x + 36, y+4);    cout << "o     o";
	textColor(11);
	gotoXY(x + 45, y);        cout << "o      ";
	gotoXY(x + 45, y + 1);    cout << "o      ";
	gotoXY(x + 45, y + 2);    cout << "o      ";
	gotoXY(x + 45, y + 3);    cout << "o      ";
	gotoXY(x + 45, y + 4);    cout << "ooooooo";
	textColor(7);
	x = 40; y = 8;
	int k = 19;
	drawBox(x, y, k);
	gotoXY(x + 7, y + 1); cout << "TEACHER";
	x = 70; y = 8;
	drawBox(x, y, k);
	gotoXY(x + 7, y + 1); cout << "STUDENT";
	x = 39; y = 14;
	k = 51;
	gotoXY(x, y - 1); cout << "Username:";
	drawBox(x, y, k);
	x = 39; y = 19;
	k = 51;
	gotoXY(x, y - 1); cout << "Password:";
	drawBox(x, y, k);
	x = 55; y = 24;
	k = 19;
	drawBox(x, y, k);
	textColor(14);
	gotoXY(x + 8, y + 1); cout << "LOGIN";
	textColor(7);
	x = 55; y = 27;
	k = 19;
	drawBox(x, y, k);
	textColor(14);
	gotoXY(x + 8, y + 1); cout << "QUIT";
	gotoXY(1, 35);

}
void deleteArrow(cursorLocation pos)
{
	gotoXY(pos.x, pos.y);
	cout << " ";
}
void moveUp(cursorLocation& pos)
{
	invisibleCursor();
	if (pos.y == 15)
	{
		pos.x = 54;
		pos.y = 28;
	}
	else if (pos.y == 20)
	{
		pos.x = 38;
		pos.y = 15;
	}
	else if (pos.y == 25)
	{
		pos.x = 38;
		pos.y = 20;
	}
	else if (pos.y == 28)
	{
		pos.x = 54;
		pos.y = 25;
	}
	gotoXY(pos.x, pos.y);
	cout << char(26);
}
void moveDown(cursorLocation& pos)
{
	invisibleCursor();
	 if (pos.y == 15)
	{
		pos.x = 38;
		pos.y = 20;
	}
	else if (pos.y == 20)
	{
		pos.x = 54;
		pos.y = 25;
	}
	else if (pos.y == 25)
	{
		pos.x = 54;
		pos.y = 28;
	}
	else if (pos.y == 28)
	{
		pos.x = 38;
		pos.y = 15;
	}
	gotoXY(pos.x, pos.y);
	cout << char(26);
}
void moveLeftRight(bool &func)
{
	if (func)
		func = 0;
	else func = 1;
	if (func)
	{
		textColor(14);
		int x = 40, y = 8;
		int k = 19;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "TEACHER";
		textColor(7);
		x = 70, y = 8;
		k = 19;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
	}
	else
	{
		textColor(14);
		int x = 70, y = 8;
		int k = 19;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "STUDENT";
		textColor(7);
		x = 40, y = 8;
		k = 19;
		drawBox(x, y, k);
		gotoXY(x + 7, y + 1); cout << "TEACHER";
	}
}

void loginSystem()
{
	bool func = 1;
	cursorLocation pos;
	pos.x = 38;
	pos.y = 15;
	loginConsole();
	char ch;
	do
	{
		ch = _getch();
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 75)
			{
				moveLeftRight(func);
			}
			else if (ch == 77)
			{
				moveLeftRight(func);
			}
			else if (ch == 72)
			{
				deleteArrow(pos);
				moveUp(pos);
			}
			else if (ch == 80)
			{
				deleteArrow(pos);
				moveDown(pos);
			}
		}

	} while (ch != 27);
}
void box()
{
	fixConsoleWindow();
	int x = 0, y = 25, k = 118;
	gotoXY(x, y); cout << char(201);
	for (int i = 0; i < k; i++)
	{
		if (i == 43 || i == 58 || i == 73 || i == 88 || i == 103)
			cout << char(203);
		else
			cout << char(205);
	}
	cout << char(187);
	gotoXY(x, y + 1); cout << char(186);
	for (int i = 0; i < k; i++)
	{
		if (i == 43 || i == 58 || i == 73 || i == 88 || i == 103)
			cout << char(186);
		else
			cout << " ";
	}
	cout << char(186);
	gotoXY(x, y + 2); cout << char(186);
	for (int i = 0; i < k; i++)
	{
		if (i == 43 || i == 58 || i == 73 || i == 88 || i == 103)
			cout << char(186);
		else
			cout << " ";
	}
	cout << char(186);
	gotoXY(x, y + 3); cout << char(186);
	for (int i = 0; i < k; i++)
	{
		if (i == 43 || i == 58 || i == 73 || i == 88 || i == 103)
			cout << char(186);
		else
			cout << " ";
	}
	cout << char(186);
	gotoXY(x, y + 4); cout << char(200);
	for (int i = 0; i < k; i++)
	{
		if (i == 43 || i == 58 || i == 73 || i == 88 || i == 103)
			cout << char(202);
		else
			cout << char(205);
	}
	cout << char(188);
}
void mainMenuScreen()
{
	box();
	textColor(14);
	gotoXY(50, 26);
	cout << "MAIN";
	gotoXY(50, 27);
	cout << "MENU";
	textColor(7);
	gotoXY(65, 27);
	cout << "YEAR";
	gotoXY(79, 26);
	cout << "CHANGE";
	gotoXY(78, 27);
	cout << "PASSWORD";
	gotoXY(94, 27);
	cout << "LOGOUT";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
}
void yearScreen()//truyen year vao
{
	box();
	textColor(14);
	gotoXY(50, 27);
	cout << "YEAR";
	textColor(7);
	gotoXY(65, 27);
	cout << "NEW";
	gotoXY(79, 26);
	cout << "ACCESS";
	gotoXY(80, 27);
	cout << "YEAR";
	gotoXY(95, 27);
	cout << "BACK";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
}
void accessYearScreen()
{
	box();
	textColor(14);
	gotoXY(50, 26);
	cout << "YEAR";
	gotoXY(47, 27);
	cout << "2021-2022";
	textColor(7);
	gotoXY(64, 27);
	cout << "CLASS";
	gotoXY(78, 27);
	cout << "SEMESTER";
	gotoXY(95, 27);
	cout << "BACK";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
}
void classScreen()
{
	box();
	textColor(14);
	gotoXY(50, 27);
	cout << "CLASS";
	textColor(7);
	gotoXY(65, 27);
	cout << "NEW";
	gotoXY(79, 26);
	cout << "ACCESS";
	gotoXY(80, 27);
	cout << "CLASS";
	gotoXY(95, 27);
	cout << "BACK";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
}
void accessClassScreen()//truyen 1 class vao
{
	box();
	textColor(14);
	gotoXY(50, 26);
	cout << "CLASS";
	gotoXY(47, 27);
	cout << "21CLC10";//fix
	textColor(7);
	gotoXY(65, 27);
	cout << "ADD";
	gotoXY(63, 27);
	cout << "STUDENT";
	gotoXY(79, 26);
	cout << "SCORE";
	gotoXY(79, 27);
	cout << "BOARD";
	gotoXY(95, 27);
	cout << "BACK";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
}
void accessSemesterScreen()
{
	box();
	textColor(14);
	gotoXY(48, 26);
	cout << "SEMESTER";
	gotoXY(51, 27);
	cout << "1";
	textColor(7);
	gotoXY(61, 26);
	cout << "REGISTRATION";
	gotoXY(63, 27);
	cout << "SESSION";
	gotoXY(78, 27);
	cout << "COURSES";
	gotoXY(95, 27);
	cout << "BACK";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
}
void semesterScreen() 
{
	box();
	textColor(14);
	gotoXY(48, 27);
	cout << "SEMESTER";
	textColor(7);
	gotoXY(65, 27);
	cout << "NEW";
	gotoXY(79, 26);
	cout << "ACCESS";
	gotoXY(78, 27);
	cout << "SEMESTER";
	gotoXY(95, 27);
	cout << "BACK";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
}
void coursesScreen()
{
	box();
	textColor(14);
	gotoXY(48, 27);
	cout << "COURSES";
	textColor(7);
	gotoXY(64, 26);
	cout << "ACCESS";
	gotoXY(64, 27);
	cout << "COURSES";
	gotoXY(81, 27);
	cout << "ADD";
	gotoXY(95, 27);
	cout << "VIEW";
	gotoXY(110, 27);
	cout << "BACK";
	char ch = _getch();
}
void accessCoursesScreen()
{
	box();
	textColor(14);
	gotoXY(48, 26);
	cout << "COURSES";
	gotoXY(49, 27);//fix
	cout << "CS162";
	textColor(7);
	gotoXY(64, 27);
	cout << "UPDATE";
	gotoXY(80, 27);
	cout << "INFO";
	gotoXY(94, 27);
	cout << "DELETE";
	gotoXY(110, 27);
	cout << "BACK";
	char ch = _getch();
}
void infoScreen()
{
	box();
	textColor(14);
	gotoXY(50, 27);
	cout << "INFO";
	textColor(7);
	gotoXY(63, 27);
	cout << "STUDENT";
	gotoXY(79, 26);
	cout << "SCORE";
	gotoXY(79, 27);
	cout << "BOARD";
	gotoXY(95, 27);
	cout << "BACK";
	gotoXY(107, 27);
	cout << "----------";
	char ch = _getch();
	
}
void move_left(int range, int &cur)
{
	if (cur == 0)
	{
		cur = range - 1;
	}
	else
		cur--;
	if (cur == 0)
	{
		gotoXY(61, 28);
		cout << "------------";
		gotoXY(76, 28);
		cout << "            ";        
	}
	else if (cur == 1)
	{
		gotoXY(76, 28);
		cout << "------------";
		gotoXY(91, 28);
		cout << "            ";
	}
	else if (cur == 2)
	{
		gotoXY(91, 28);
		cout << "------------";
		if (range == 3)
		{
			gotoXY(106, 28);
			cout << "            ";
		}
		if (range == 2)
		{
			gotoXY(61, 28);
			cout << "            ";
		}
	}
	else if (cur == 3)
	{
		gotoXY(106, 28);
		cout << "------------";
		gotoXY(61, 28);
		cout << "            ";
	}
}
void move_right(int range, int &cur)
{
	if (cur == range)
	{
		cur = 0;
	}
	else
		cur++;
	if (cur == 0)
	{
		gotoXY(61, 28);
		cout << "------------";
		if (range == 3)
		{
			gotoXY(106, 28);
			cout << "            ";
		}
		if (range == 2)
		{
			gotoXY(91, 28);
			cout << "            ";
		}
	}
	else if (cur == 1)
	{
		gotoXY(76, 28);
		cout << "------------";
		gotoXY(61, 28);
		cout << "            ";
	}
	else if (cur == 2)
	{
		gotoXY(91, 28);
		cout << "------------";
		gotoXY(76, 28);
		cout << "            ";
	}
	else if (cur == 3)
	{
		gotoXY(106, 28);
		cout << "------------";
		gotoXY(91, 28);
		cout << "            ";
	}
}
int main()
{
	account x;
	listOfAcc* pHead = nullptr;
	ifstream accFile;
	accFile.open("acc.txt", ios::in);
	readFile(accFile, pHead);
	cout << "Username: ";
	getline(cin, x.username);
	cout << "Password: ";
	getline(cin, x.password);
	listOfAcc* pCur = pHead;
	while (pCur->pNext)
	{
		cout << pCur->acc.username << endl;
		cout << pCur->acc.password << endl;
		pCur = pCur->pNext;
	}
	if (checkPassword(x, pHead))
		cout << "Success";
	else
		cout << "Try again";
}