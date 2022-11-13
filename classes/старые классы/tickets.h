#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>
using namespace std;

struct passanger {
	string fio;
	string birthday;
};
struct ticket {
	passanger pass;
	string numFlight;
	string pointSrc;
	string pointDst;
	date dateFlight;
	times timeUp;
	times timeDown;
	string numberTicket;
};

class Ticket {
	map<string, flight> _flights;
	multimap<string, ticket> _tickets;
	int number = 0;
public:
	Ticket();
	~Ticket();
	void downloadFlight();
	void listUpFlight();
	void listDownFlight();
	void listUpDownFlighy();
	void booking(multimap<string, flight> fud);
	void print();
};