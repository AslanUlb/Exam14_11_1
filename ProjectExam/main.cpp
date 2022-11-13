#include<iostream>
#include "..\\classes\admins.h"
#include "..\\classes\user.h"
using namespace std;

int main() {
	string choise;
	do {
		system("cls");

		cout << "1 admin" << endl;
		cout << "2 operator" << endl;
		cout << "3 user" << endl;
		cout << "0 exit" << endl;


		cout << "#";
		cin >> choise;
		
		switch (choise[0])
		{
		case '1': system("..\\x64\\Debug\\admin.exe");  break;
		case '2': system("..\\x64\\Debug\\operator.exe"); break;
		case '3': system("..\\x64\\Debug\\user.exe"); break;
		}
		system("pause");
	} while (choise[0] != '0');
	return 0;
}
