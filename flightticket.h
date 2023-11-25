#ifndef FLIGHT_TICKET_H
#define FLIGHT_TICKET_H

#include<iostream>
using namespace std;

class Flight_Ticket
{
	private:
		string companyName;
		int flightNumber;
		string country_of_origin;
		string country_of_destination;
		string stopOver;
		string price;
		string time_of_departure;
		string time_of_arrival;
		string date;

	public:
		Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date);
		Flight_Ticket() {};
		string getCompanyName();
		int getFlightNumber();
		string getOrigin();
		string getDestination();
		string getStopOver();
		string getPrice();
		string getTimeDeparture();
		string getTimeArrival();
		string getDate();
		void setDestination(string destination);
		friend class FlightHASHTABLE;
};

#endif
