#include "..\\classes\flights.h"
#include "..\\classes\tickets.h"
#include "..\\classes\cities.h"

using namespace std;

int main() {
	Ticket tk;
	int n;
	do
	{
		system("cls");
		cout << "\thello chel" << endl;
		cout << "you can select number: " << endl;
		cout << "1 - enter up city" << endl;
		cout << "2 - enter down city" << endl;
		cout << "3 - enter up and down city" << endl;
		cout << "0 - exit" << endl;
		cout << ">>>>>>>";
		cin >> n;
		switch (n)
		{
		case 1:
			tk.listUpFlight();
			break;
		case 2:
			tk.listDownFlight();
			break;
		case 3:
			tk.listUpDownFlighy();
			break;
		}
	} while (n != 0);

	system("cls");
	tk.print();

	return 0;
}