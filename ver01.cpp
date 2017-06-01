#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<graphics.h>
#include<iomanip>


using namespace std;

void ShowMap(int Map[21][21])
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (Map[i][j] == 0)
			{
				if (i == 0 && j == 0)
				{
					cout << "┏";
				}
				else if (i == 0 && j == 19)
				{
					cout << "┓";
				}
				else if (i == 19 && j == 0)
				{
					cout << "┗";
				}
				else if (i == 19 && j == 19)
				{
					cout << "┛";
				}
				else if (i == 0&&j<20)
				{
					cout << "┯";
				}
				else if (j == 0&&i<20)
				{
					cout << "┠";
				}
				else if (i == 19&&j<20)
				{
					cout << "┷";
				}
				else if (j == 19&&i<20)
				{
					cout << "┨";
				}
				else if (j == 20)
				{
					cout << setw(2)<<i+1;
				}
				else if (i == 20)
				{
					cout <<setw(2)<< j+1;
				}
				else
				{
					cout << "┼";
				}
			}
			else if (Map[i][j] == 1)
			{
				cout << "●";
			}
			else if (Map[i][j] == 2)
			{
				cout << "○";
			}
		}
		cout << endl;
	}
}

void SetPoint(int Map[21][21], bool &IsBlack)
{
	int i, j;
	cin >> i >> j;


	if (i < 1 || j < 1 || i>20 || j>20)
	{
		cout << "你所下的棋子超出棋盘" << endl;
		SetPoint(Map, IsBlack);
	}
	else if (Map[i - 1][j - 1])
	{
		cout << "你所下的位置已有棋子" << endl;
		SetPoint(Map, IsBlack);
	}
	else {
		if (IsBlack)Map[i - 1][j - 1] = 1;
		else 	
		{
			Map[i - 1][j - 1] = 2;
		}
		IsBlack = !IsBlack;
	}
}
int main()
{
	HWND hwnd = GetForegroundWindow();
	SetWindowTextA(hwnd, "五子棋 低配版");
	
	
	int Map[21][21] = { 0 };
	system("color 71");
	bool IsBlack = true;
	ShowMap(Map);
	POINT point = { 0, 0 };
	
	
	while (true)
	{
		SetPoint(Map,IsBlack);
		system("cls");
		ShowMap(Map);
		_sleep(1000);
	}

}