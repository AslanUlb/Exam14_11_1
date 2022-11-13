#include "..\\classes\tickets.h"
#include "..\\classes\flights.h"
#include "..\\classes\user.h"
using namespace std;

Ticket::Ticket()
{
	downloadFlight();
	ifstream is("..\\db\\tickets.txt");
	string key;
	ticket* _ticket1;
	if (is) {
		while (!is.eof()) {

			_ticket1 = new ticket;
			ticket* temp_ticket;
			is >> key;
			if (!key.empty()) {
				_ticket1->numFlight = key;
				is >> _ticket1->pointSrc;
				is >> _ticket1->pointDst;

				is >> _ticket1->dateFlight.day;
				is >> _ticket1->dateFlight.month;
				is >> _ticket1->dateFlight.year;

				is >> _ticket1->timeUp.hour;
				is >> _ticket1->timeUp.min;
				is >> _ticket1->timeUp.sec;

				is >> _ticket1->timeDown.hour;
				is >> _ticket1->timeDown.min;
				is >> _ticket1->timeDown.sec;

				is >> _ticket1->numberTicket;

				temp_ticket = _ticket1;
				_tickets.insert(make_pair(key, *temp_ticket));
			}
		}
	}
	is.close();
}

Ticket::~Ticket()
{
	ofstream os("..\\db\\tickets.txt");

	for (auto it = _tickets.begin(); it != _tickets.end(); ++it) {
		os << it->second.numFlight << endl;
		os << it->second.pointSrc << endl;
		os << it->second.pointDst << endl;

		os << it->second.dateFlight.day << endl;
		os << it->second.dateFlight.month << endl;
		os << it->second.dateFlight.year << endl;

		os << it->second.timeUp.hour << endl;
		os << it->second.timeUp.min << endl;
		os << it->second.timeUp.sec << endl;

		os << it->second.timeDown.hour << endl;
		os << it->second.timeDown.min << endl;
		os << it->second.timeDown.sec << endl;

		os << it->second.numberTicket << endl;
	}
	os.close();
}

void Ticket::downloadFlight()
{
	Flight flight;//выгружаем все рейсы
	_flights = flight.get_flight();
}

void Ticket::listUpFlight()
{
	//downloadFlight();
	multimap<string, flight> temp_flightUp;
	string upCity;
	cout << "enter up city: ";
	cin >> upCity;
	for (auto it = _flights.begin(); it != _flights.end(); ++it) {
		if (it->second.pointSrc == upCity) {
			cout << it->second.numFlight << endl;
			cout << it->second.pointSrc << endl;
			cout << it->second.pointDst << endl;
			cout << it->second.dateFlight.day<<"."<< it->second.dateFlight.month<<"."<< it->second.dateFlight.year << endl;
			temp_flightUp.insert(make_pair(it->second.numFlight, it->second));
		}
	}

	multimap<string, flight> temp_flightUpDown;
	string downCity;
	cout << "enter down city: ";
	cin >> downCity;
	for (auto it = temp_flightUp.begin(); it != temp_flightUp.end(); ++it) {
		if (it->second.pointDst == downCity) {
			cout << it->second.numFlight << endl;
			cout << it->second.pointSrc << endl;
			cout << it->second.pointDst << endl;
			cout << it->second.dateFlight.day << "." << it->second.dateFlight.month << "." << it->second.dateFlight.year << endl;
			temp_flightUpDown.insert(make_pair(it->second.numFlight, it->second));
		}
	}

	char c;
	do {

		cout << "Do you whant to booking ticket? (Y\N): ";
		cin >> c;
		switch (c) {
		case 'Y':
			booking(temp_flightUpDown);
			break;
		}
	} while (c != 'N');
}

void Ticket::listDownFlight()
{
	//downloadFlight();
	multimap<string, flight> temp_flightDown;
	string downCity;
	cout << "enter up city: ";
	cin >> downCity;
	for (auto it = _flights.begin(); it != _flights.end(); ++it) {
		if (it->second.pointDst == downCity) {
			cout << it->second.numFlight << endl;
			cout << it->second.pointSrc << endl;
			cout << it->second.pointDst << endl;
			cout << it->second.dateFlight.day << "." << it->second.dateFlight.month << "." << it->second.dateFlight.year << endl;
			temp_flightDown.insert(make_pair(it->second.numFlight, it->second));
		}
	}

	multimap<string, flight> temp_flightUpDown;
	string upCity;
	cout << "enter down city: ";
	cin >> upCity;
	for (auto it = temp_flightDown.begin(); it != temp_flightDown.end(); ++it) {
		if (it->second.pointSrc == upCity) {
			cout << it->second.numFlight << endl;
			cout << it->second.pointSrc << endl;
			cout << it->second.pointDst << endl;
			cout << it->second.dateFlight.day << "." << it->second.dateFlight.month << "." << it->second.dateFlight.year << endl;
			temp_flightUpDown.insert(make_pair(it->second.numFlight, it->second));
		}
	}

	char c;
	do {

		cout << "Do you whant to booking ticket? (Y\N): ";
		cin >> c;
		switch (c) {
		case 'Y':
			booking(temp_flightUpDown);
			break;
		}
	} while (c != 'N');
}

void Ticket::listUpDownFlighy()
{
	//downloadFlight();
	multimap<string, flight> temp_flightUpDown;
	string upCity;
	cout << "enter up city: ";
	cin >> upCity;
	string downCity;
	cout << "enter up city: ";
	cin >> downCity;
	
	for (auto it = _flights.begin(); it != _flights.end(); ++it) {
		if (it->second.pointDst == upCity && it->second.pointSrc == downCity) {
			cout << it->second.numFlight << endl;
			cout << it->second.pointSrc << endl;
			cout << it->second.pointDst << endl;
			cout << it->second.dateFlight.day << "." << it->second.dateFlight.month << "." << it->second.dateFlight.year << endl;
			temp_flightUpDown.insert(make_pair(it->second.numFlight, it->second));
		}
	}

	char c;
	do {

		cout << "Do you whant to booking ticket? (Y\N): ";
		cin >> c;
		switch (c) {
		case 'Y':
			booking(temp_flightUpDown);
			break;
		}
	} while (c != 'N');
}

void Ticket::booking(multimap<string, flight> fud)
{
	//downloadFlight();
	string pass_name, pass_bithday, pass_flightnumber;
	ticket temp_ticket;
	cout << "enter fio: ";
	cin >> pass_name;
	cout << "enter bithday(dd.mm.yy): ";
	cin >> pass_bithday;
	cout << "enter flight number for booking: ";
	cin >> pass_flightnumber;
	for (auto it = fud.begin(); it != fud.end(); ++it) {
		if (it->second.numFlight == pass_flightnumber) {
			temp_ticket.numFlight = it->second.numFlight;
			temp_ticket.dateFlight = it->second.dateFlight;
			temp_ticket.pointDst = it->second.pointDst;
			temp_ticket.pointSrc = it->second.pointSrc;
			temp_ticket.timeDown = it->second.timeDown;
			temp_ticket.timeUp = it->second.timeUp;

			temp_ticket.pass.fio = pass_name;
			temp_ticket.pass.birthday = pass_bithday;

			
			auto temp_str = to_string(number);
			temp_ticket.numberTicket = it->second.numFlight + '_' + temp_str;
			number++;
			_tickets.insert(make_pair(temp_ticket.numFlight, temp_ticket));
		}
	}
	//auto it = _tickets.begin();
	//if (it->first.empty())
	
	

	cout << "\tYour ticket!" << endl;
	cout << temp_ticket.numFlight << endl;
	cout << temp_ticket.dateFlight.day<<"."<< temp_ticket.dateFlight.month<<"."<< temp_ticket.dateFlight.year << endl;
	cout << temp_ticket.pointDst << endl;
	cout << temp_ticket.pointSrc << endl;
	cout << temp_ticket.timeDown.hour<<":"<< temp_ticket.timeDown.min<<":"<< temp_ticket.timeDown.sec << endl;
	cout << temp_ticket.timeUp.hour << ":" << temp_ticket.timeUp.min << ":" << temp_ticket.timeUp.sec << endl;

	cout << temp_ticket.pass.fio << endl;
	cout << temp_ticket.pass.birthday << endl;
}

void Ticket::print()
{
	for (auto it = _tickets.begin(); it != _tickets.end(); ++it) {
		cout << "#######################################################" << endl;
		cout << it->second.numFlight << endl;
		cout << it->second.dateFlight.day << "." << it->second.dateFlight.month << "." << it->second.dateFlight.year << endl;
		cout << it->second.pointDst << endl;
		cout << it->second.pointSrc << endl;
		cout << it->second.timeDown.hour << ":" << it->second.timeDown.min << ":" << it->second.timeDown.sec << endl;
		cout << it->second.timeUp.hour << ":" << it->second.timeUp.min << ":" << it->second.timeUp.sec << endl;
		cout << it->second.pass.fio << endl;
		cout << it->second.pass.birthday << endl;
		cout << "#######################################################" << endl;
	}
}


multimap<string, ticket> Ticket::getTicketS() {
	return _tickets;
}