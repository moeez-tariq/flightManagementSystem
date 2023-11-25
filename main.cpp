#include<sstream>
#include<fstream>

using namespace std;

#include "mylist.h"
#include "flightticket.h"
#include "flighthashtable.h"

//==========================================================
void listCommands()
{
	cout<<"\n----------------------------------"<<endl;
	cout<<"import <path>      	:Import flight-tickets from a CSV file"<<endl
		<<"export <path>      	:Export flight-tickets to a CSV file"<<endl
		<<"count_collisions   	:Print Number of Collisions"<<endl
		<<"add                	:Add a new flight-ticket"<<endl
		<<"delete <key>       	:Delete a flight-ticket"<<endl
		<<"find <key>         	:Find a flight-ticket's details"<<endl
		<<"allinday <date>    	:Display all flight-tickets in a day"<<endl
		<<"printASC <key>     	:Print flight-tickets in ascending order"<<endl
		<<"exit               	:Exit the program"<<endl;
}
//==========================================================
string toUpper(string input) //upper cases the parameter
{
	string upper = "";
	for (int i = 0; i < input.length(); i++) //go over the input using its length
	{
		upper += toupper(input[i]); //lower each character and concatenate with previous ones
	}
	return upper;
}
// to be completed with all the necessary method definitions

//==========================================================
int main(void)
{
	FlightHASHTABLE myFlightHASHTABLE;
	string user_input = "";
	string option = "";
	string argument = "";
	while(true)
	{
	listCommands();
	cout<<">";
	getline(cin, user_input);
		stringstream sstr(user_input); // parse userinput into command and parameter
		getline(sstr, option, ' ');
		getline(sstr, argument, '\n');

		if (option == "add")
		{
			string name, number, origin, destination, stop_over, flight_price, departure, arrival, date;
			cout << "Please enter the details of the flight-ticket:\n";
			cout << "Company Name: ";
			getline(cin, name);
			cout << "Flight Number: ";
			getline(cin, number);
			cout << "Country of Origin: ";
			getline(cin, origin);
			cout << "Country of Destination: ";
			getline(cin, destination);
			cout << "Stopover: ";
			getline(cin, stop_over);
			cout << "Price: ";
			getline(cin, flight_price);
			cout << "Time of Departure: ";
			getline(cin, departure);
			cout << "Time of Arrival: ";
			getline(cin, arrival);
			cout << "Date: ";
			getline(cin, date);

			//origin = "abc"; destination = "abc"; stop_over = "abc"; flight_price = "abc"; departure = "abc"; arrival = "abc"; date = "abc";
			name = toUpper(name);
			string key = name + " " + number;
			int int_number = stoi(number);

			Flight_Ticket* data = new Flight_Ticket(name, int_number, origin, destination, stop_over, flight_price, departure, arrival, date);
			int added = myFlightHASHTABLE.add(data);
			if (added == 1)
			{
				cout << "Flight " << key << " Successfully Added!\n";
			}
			else
			{
				cout << "Flight Addition Failed! Flight Already Exists!\n";
			}

		}
		else if (option == "find")
		{
			string para1, para2;
			stringstream sstr(argument); // parse userinput into command and parameter
			getline(sstr, para1, ','); //break argument into 2 parameters
			getline(sstr, para2);
			int int_para2 = stoi(para2);
			para1 = toUpper(para1);
			cout << endl;
			myFlightHASHTABLE.find(para1, int_para2);
		}
		else if (option == "delete")
		{
			string para1, para2;
			stringstream sstr(argument); // parse userinput into command and parameter
			getline(sstr, para1, ',');
			getline(sstr, para2);
			int int_para2 = stoi(para2);
			para1 = toUpper(para1);
			cout << endl;
			myFlightHASHTABLE.removeRecord(para1, int_para2);
		}
		else if (option == "import")
		{
			//string path = "";
			//path = "flight-ticket1k.csv";
			int count = myFlightHASHTABLE.importCSV(argument);
			if (count == -1)
			{
				cout << "Invalid Path Provided! Please Try Again!\n";
			}
			else
			{
				cout << count << " Imported!\n";

			}
		}
		else if (option == "export")
		{
			//string path = "";
			//path = "flight-ticket1k.csv";
			int count = myFlightHASHTABLE.exportCSV(argument);
			if (count == -1)
			{
				cout << "Invalid Path Provided! Please Try Again!\n";
			}
			else
			{
				cout << count << " Exported!\n";

			}
		}
		else if (option == "allinday")
		{
			cout << endl;
			myFlightHASHTABLE.allinday(argument);
		}
		else if (option == "count_collisions")
		{
			// int count2 = myFlightHASHTABLE.count_collisions2();
			// cout << "Collisions2: " << count2 << endl;

			int count = myFlightHASHTABLE.count_collisions();
			cout << "Collisions: " << count << endl;
		}
		else if (option == "printASC")
		{
			string para1, para2;
			stringstream sstr(argument); // parse userinput into command and parameter
			getline(sstr, para1, ',');
			getline(sstr, para2);
			int int_para2 = stoi(para2);
			para1 = toUpper(para1);
			cout << endl;
			myFlightHASHTABLE.printASC(para1, int_para2);
		}
		else if (option == "exit")
		{
			break;
		}
		else
		{
			cout << "Invalid Input! Try Again!\n";
		}

	}

	return 0;
}
