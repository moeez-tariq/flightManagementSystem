#include "flightticket.h"

//constructors
Flight_Ticket::Flight_Ticket(string companyName, int flightNumber, string country_of_origin, string country_of_destination, string stopOver, string price, string time_of_departure, string time_of_arrival, string date)
{
	this->companyName = companyName;
	this->flightNumber = flightNumber;
	this->country_of_origin = country_of_origin;
	this->country_of_destination = country_of_destination;
	this->stopOver = stopOver;
	this->price = price;
	this->time_of_departure = time_of_departure;
	this->time_of_arrival = time_of_arrival;
	this->date = date;
}
//getter and setter functions

string Flight_Ticket::getCompanyName() {return companyName;}
int Flight_Ticket::getFlightNumber() {return flightNumber;}
string Flight_Ticket::getOrigin() {return country_of_origin;}
string Flight_Ticket::getDestination() {return country_of_destination;}
string Flight_Ticket::getStopOver() {return stopOver;}
string Flight_Ticket::getPrice() {return price;}
string Flight_Ticket::getTimeDeparture() {return time_of_departure;}
string Flight_Ticket::getTimeArrival() {return time_of_arrival;}
string Flight_Ticket::getDate() {return date;}
void Flight_Ticket::setDestination(string destination)
{
	this->country_of_destination = destination;
}