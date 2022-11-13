
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
#include "..\\classes\flights.h"
#include "..\\classes\tickets.h"
#include "..\\classes\cities.h"
#include "..\\classes\user.h"


using namespace std;

void main_menu() {
		Flight f;
		bool exit = true;
		int press;

		do
		{
			cout << "select  0  -  exit : " << endl;
			cout << "select  1  -  add to flight : " << endl;
			cout << "select  2  -  eddit to flight : " << endl;
			cout << "select  3  -  delete to flight : " << endl;
			cout << "select  4  -  viuwer to list passager in flight : " << endl;

			while (!isdigit(char(cin.peek())))
			{
				system("cls");
				cin.ignore();
				cout << "select  0  -  exit : " << endl;
				cout << "select  1  -  add to flight : " << endl;
				cout << "select  2  -  eddit to flight : " << endl;
				cout << "select  3  -  delete to flight : " << endl;
				cout << "select  4  -  viuwer to list passager in flight : " << endl;
			}
			cin >> press;
			switch (press) {
			case 0:
				cout << "if you want to exit? -- press -- 0, if you continue = press -- 1 : ";;
				cin >> exit;
				break;
			case 1:

				f.addFlight();
				break;
			case 2:
				f.editFlight();
				break;
			case 3:
				f.delFlight();
				break;
			case 4:
				f.printPassanger();
				
				break;
			
			}
		} while (exit != 0);
}

bool auth() {
	string ulogin, upassw;
	cout << "login: ";
	cin >> ulogin;
	cout << "password: ";
	cin >> upassw;
	ifstream f("..\\db\\users.txt");
	string login, passw;
	bool isauth = false;
	while (!f.eof()) {
		f >> login;
		f >> passw;
		if (ulogin == login && upassw == passw)
			isauth = true;
	}
	f.close();
	return isauth;
}

int main() {
	if (auth())
		main_menu();
	return 0;
}