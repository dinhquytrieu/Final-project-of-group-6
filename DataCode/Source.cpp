#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct account {
	string username;
	string password;
};

struct listOfAcc {
	account acc;
	listOfAcc* pNext;
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
void mainMenuConsole()
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
	gotoXY(x, y); cout << char(201);
	for (int i = 0; i < k; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	gotoXY(x, y+1); cout << char(186);
	for (int j = 0; j < k; j++)
	{
		cout << " ";
	}
	cout << char(186);
	gotoXY(x, y+2); cout << char(200);
	for (int i = 0; i < k; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	gotoXY(x + 7, y + 1); cout << "TEACHER";
	x = 70; y = 8;
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
	gotoXY(x + 7, y + 1); cout << "STUDENT";
	x = 39; y = 14;
	k = 51;
	gotoXY(x, y - 1); cout << "Username:";
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
	x = 39; y = 19;
	k = 51;
	gotoXY(x, y - 1); cout << "Password:";
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
	x = 55; y = 24;
	k = 19;
	
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
	textColor(14);
	gotoXY(x + 8, y + 1); cout << "LOGIN";
	/*for (int i = 8; i <= 30; i += 4)
	{
		gotoXY(60, i);
		cout << char(201);
		for (int i = 0; i < 10; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		gotoXY(60, i + 1);
		cout << char(186);
		for (int j = 0; j < 10; j++)
		{
			cout << " ";
		}
		cout << char(186);
		cout << endl;
		gotoXY(60, i + 2);
		cout << char(200);
		for (int i = 0; i < 10; i++)
		{
			cout << char(205);
		}
		cout << char(188);
	}*/
	gotoXY(1, 35);
}
int main()
{
	mainMenuConsole();

}