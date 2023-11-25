#include "flighthashtable.h"
#include <fstream>
#include <sstream>
#include <string>
#include<iostream>
#include<cstdlib>
#include <math.h>
#include <ctime>
using namespace std;

FlightHASHTABLE::FlightHASHTABLE() //constructor
{
	this->capacity = 125017;  //prime number greater than (100000*1.25)
	buckets = new MyList<HashNode> [this->capacity];
	this->size = 0;
}


FlightHASHTABLE::~FlightHASHTABLE() //destructor
{
	delete[] buckets;
}

long FlightHASHTABLE::hashCode(string key) //hashcode
{
	unsigned long hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash << 5) | (hash >> 27); //hashcode 1
	 	hash += (unsigned long)key[i]; 

		//hash += (unsigned long)key[i]; //hashcode 2

		//hash += (unsigned long)key[i] * pow(key.length(), i + 1); //hashcode 3
	}
	long hashed = hash % capacity; //use modulus to make sure in range
	return hashed;
}

int FlightHASHTABLE::count_collisions() //cont collisios
{
	int count = 0;
	int empty_buckets = 0;
	Node<HashNode>* current;
	for (int  i = 0; i < capacity; i++)
	{
		if (buckets[i].empty())
		{
			empty_buckets++;
		}
		else
		{6
			current = buckets[i].head;
			sort_by_key(i); //sort by key
			current = buckets[i].head;
			string current_key = current->elem.value.getCompanyName() + " " + to_string(current->elem.value.getFlightNumber()); //make new key
			string next_key;
			while (current != nullptr)
			{
				next_key = current->elem.value.getCompanyName() + " " + to_string(current->elem.value.getFlightNumber()); //key of next element
				if (current_key != next_key) //if different then count++
				{
					count++;
					current_key = next_key;
				}
				current = current->next;			
			}
		}
	}
	//cout << "Empty Buckets: " << empty_buckets << endl << endl;
	return count;
}

// int FlightHASHTABLE::count_collisions2() //another way of counting collisions
// {
// 	int count = 0;
// 	for (int  i = 0; i < capacity; i++)
// 	{
// 		if (buckets[i].empty() || buckets[i].size == 1)
// 		{
// 			continue;
// 		}
// 		else
// 		{
// 			count += buckets[i].size;
// 			count--;
// 		}
// 	}
// 	//cout << "Empty Buckets: " << empty_buckets << endl << endl;
// 	return count;
// }

int FlightHASHTABLE::add(Flight_Ticket* data) //add function
{
	string name = "";
	name = data->companyName;
	string number = to_string(data->flightNumber);
	string key = "";
	key = name + " " + number;
	long index = hashCode(key); //produce index using hashcode
	bool found = false;

	// if (buckets[index].empty()) //if the bucket is empty then no node exists and so can break
	// {
	// 	found = false;
	// }
	// else
	//{
	// 	Node<HashNode>* current = buckets[index].head;
	// 	while(current != nullptr) //check if all of the attributes same
	// 	{
	// 		string new_key = current->elem.value.companyName + " " + to_string(current->elem.value.flightNumber); 
	// 		//cout << new_key << " " << key;
	// 		if (new_key == key)
	// 		{
	// 			int counter = 0;
	// 			found = true;
	// 			if (data->companyName == current->elem.value.getCompanyName())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->flightNumber == current->elem.value.getFlightNumber())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->country_of_origin == current->elem.value.getOrigin())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->country_of_destination == current->elem.value.getDestination())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->stopOver == current->elem.value.getStopOver())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->price == current->elem.value.getPrice())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->time_of_departure == current->elem.value.getTimeDeparture())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->time_of_arrival == current->elem.value.getTimeArrival())
	// 			{
	// 				counter++;
	// 			}
	// 			if (data->date == current->elem.value.getDate())
	// 			{
	// 				counter++;
	// 			}

	// 			if (counter == 9)
	// 			{
	// 				return -1; //failed addition
	// 			}
	// 		}
	// 		current = current->next;
	// 	}
	// }

	HashNode* newnode = new HashNode(key, *data); //create a new node
	buckets[index].addFront(*newnode); //push back that new node in the found index
	size++; //increment size
	return 1;
}

void FlightHASHTABLE::find(string companyName, int flightNumber) //find
{
	float start_time = clock(); //for time
	string int_flightnumber = to_string(flightNumber);
	string key = companyName + " " + int_flightnumber;
	int count = 1;
	bool found = false;
	long index = hashCode(key); //get index
	//cout << index << endl;


	if (buckets[index].empty()) //if the bucket is empty then no node exists and so can break
	{
		found = false;
	}
	else
	{
		Node<HashNode>* current = buckets[index].head;
		while(current != nullptr)
		{
			string new_key = current->elem.value.companyName + " " + to_string(current->elem.value.flightNumber);
			//cout << new_key << " " << key;
			if (new_key == key) //if keys same then match found
			{
				found = true;
				cout << count << ". ";
				cout << "Company Name: " << current->elem.value.companyName << endl;
				cout << "Flight Number: " << current->elem.value.flightNumber << endl;
				cout << "Country of Origin: " << current->elem.value.country_of_origin << endl;
				cout << "Country of Destination: " << current->elem.value.country_of_destination << endl;
				cout << "Stopover: " << current->elem.value.stopOver << endl;
				cout << "Price: " << current->elem.value.price << endl;
				cout << "Time of Departure: " << current->elem.value.time_of_departure << endl;
				cout << "Time of Arrival: " << current->elem.value.time_of_arrival << endl;
				cout << "Date: " << current->elem.value.date << endl;
				cout << endl;
				count++;
			}
			current = current->next;
		}
	}

	if (found == false)
	{
		cout << "Key Not Found!\n";
	}

	float end_time = clock();
	//cout << end_time << endl;
	float time_taken = end_time - start_time; //time taken
	cout << "Milliseconds: " << time_taken/CLOCKS_PER_SEC*1000 << endl; //displayed in milisecond
}

void FlightHASHTABLE::allinday(string date) //find all in day
{
	int count = 1;
	bool found = false;
	for (int i = 0; i < capacity; i++)
	{
		if (!buckets[i].empty()) //if it is empty then it wont have a flight on the same day
		{
			Node<HashNode>* current = buckets[i].head;
			while (current != nullptr)
			{
				if (current->elem.value.getDate() == date) //go over all the buckets and nodes, then check their date.
				{
					found = true;
					cout << count << ". ";
					printLineTerminal(current); //if same then print
					count++;
				}
				current = current->next;
			}
		}
	}

	if (found == false)
	{
		cout << "No Flights on this Date!\n";
	}
}

int FlightHASHTABLE::importCSV(string path) //import file
{

	int count = 0;
	ifstream fin(path); //opens file
	//ifstream fin;
	//fin.open(path);
	string line;
	if (!fin.is_open()) //checks to see if the path provided is correct
	{
		return -1;
	}
	while (getline(fin, line)) 
	{
		string name, number, origin, destination, stop_over, flight_price, departure, arrival, date;
		int int_number = 0;
		int new_index = 0;
		int comma_count = 0;
		//cout << line << endl;
		while (line.length() != 0)
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ',') //if a comma is encountered means an individual value is present before it
				{
					comma_count++;
					new_index = i;
					break;
				}
			}

			if (comma_count == 1)
			{
				name = line.substr(0, new_index); //using the index of comma, get the right value
				string uppername = "";
				for (int i = 0; i < name.length(); i++) //go over the input using its length
				{
					uppername += toupper(name[i]); //lower each character and concatenate with previous ones
				}
				name = uppername;
				line = line.substr(new_index + 1, line.length() - new_index - 1); //remove that specific part from the input and the comma and now only the others remain
			}
			else if (comma_count == 2)
			{
				number = line.substr(0, new_index);
				line = line.substr(new_index + 1, line.length() - new_index - 1);
			}
			else if (comma_count == 3)
			{
				origin = line.substr(0, new_index);
				line = line.substr(new_index + 1, line.length() - new_index - 1);
			}
			else if (comma_count == 4)
			{
				destination = line.substr(0, new_index);
				line = line.substr(new_index + 1, line.length() - new_index - 1);
			}
			else if (comma_count == 5)
			{
				stop_over = line.substr(0, new_index);
				line = line.substr(new_index + 1, line.length() - new_index - 1);
			}
			else if (comma_count == 6)
			{
				flight_price = line.substr(0, new_index);
				line = line.substr(new_index + 1, line.length() - new_index - 1);
			}
			else if (comma_count == 7)
			{
				departure = line.substr(0, new_index);
				line = line.substr(new_index + 1, line.length() - new_index - 1);
			}
			else if (comma_count == 8)
			{
				arrival = line.substr(0, new_index);
				line = line.substr(new_index + 1, line.length() - new_index - 1);
				date = line.substr(0, line.length() - 1); //-1 to exclude "\n";
				line = "";
			}
		}

		// cout << "Name:" << name << endl;
		// cout << "Number:" << number << endl;
		// // cout << "Origin: " << origin << endl;
		// // cout << "Destination: " << destination << endl;
		// // cout << "Stop Over: " << stop_over << endl;
		// // cout << "Flight Price: " << flight_price << endl;
		// // cout << "Departure: " << departure << endl;
		// cout << "Arrival:" << arrival << endl;
		// cout << "Date:" << date << endl << date.length() << endl << endl;
		int_number = stoi(number);

		Flight_Ticket* data = new Flight_Ticket(name, int_number, origin, destination, stop_over, flight_price, departure, arrival, date); //make new flight ticket
		int added = add(data); //use add function to add to the table
		if (added == 1)
		{
			count++;
		}
	}
	fin.close(); //close file
	return count;
}

int FlightHASHTABLE::exportCSV(string path) //export everything
{
	fstream fout(path);
	if (!fout.is_open()) //check to see if the path is correct
	{
		return -1;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < capacity; i++)
		{
			if (!buckets[i].empty()) //if the bucket isnt empty
			{
				Node<HashNode>* current = buckets[i].head;
				while (current != nullptr)
				{
					printLineCSV(current,fout); //print the line in file 
					//printLineTerminal(current);
					count++; //to see how many exported
					current = current->next;
				}
			}
		}
		fout.close(); //close file
		return count;
	}
}

void FlightHASHTABLE::printLineCSV(Node<HashNode>* current, fstream& fout) //print line in file in the right format
{
	fout << current->elem.value.getCompanyName() << ","
	 << current->elem.value.getFlightNumber() << ","
	 << current->elem.value.getOrigin() << ","
	 << current->elem.value.getDestination() << ","
	 << current->elem.value.getStopOver() << ","
	 << current->elem.value.getPrice() << ","
	 << current->elem.value.getTimeDeparture() << ","
	 << current->elem.value.getTimeArrival() << ","
	<< current->elem.value.getDate() << endl;
}

void FlightHASHTABLE::printLineTerminal(Node<HashNode>* current) //print line in the terminal in the right format
{
	cout << current->elem.value.getCompanyName() << ", "
	 << current->elem.value.getFlightNumber() << ", "
	 << current->elem.value.getOrigin() << ", "
	 << current->elem.value.getDestination() << ", "
	 << current->elem.value.getStopOver() << ", "
	 << current->elem.value.getPrice() << ", "
	 << current->elem.value.getTimeDeparture() << ", "
	 << current->elem.value.getTimeArrival() << ", "
	<< current->elem.value.getDate() << endl;
}

void FlightHASHTABLE::removeRecord(string companyName, int flightNumber) //removes record
{
	int count = 0;
	string key = companyName + " " + to_string(flightNumber);
	int index = hashCode(key);
	sort_by_key(index);
	Node<HashNode>* current = buckets[index].head;
	while (current != nullptr) //prints all the similar records with same keys
	{
		if (key == current->elem.value.getCompanyName() + " " + to_string(current->elem.value.getFlightNumber()))
		{
			cout << count + 1 << ". ";
			printLineTerminal(current);
			count++;
		}
		current = current->next;
	}

	if (count == 0)
	{
		cout << "Key Not Found!\n";
		return;
	}

	string user_input = "";
	bool correct = true;

	while (true)
	{
		cout << endl << "Please select the record you want to delete: ";
		getline(cin, user_input);
		for (int i = 0; i < user_input.length(); i++)
		{
			if (!isdigit(user_input[i])) //input validation
			{
				correct = false;
			}
		}

		if (correct == false)
		{
			cout << "Please Enter A Valid Number\n";
			cout << endl;
		}
		else if (stoi(user_input) > 0 && stoi(user_input) < count + 1) //make sure its in the range
		{
			break;
		}
		else
		{
			cout << "Please Enter A Valid Number\n";
			cout << endl;
		}
	}

	int input = stoi(user_input);
	current = buckets[index].head;
	while (current != nullptr)
	{
		string new_key;
		if (current->next == nullptr) //last node in the chain or the very first
		{
			new_key = key;
		}
		else
		{
			new_key = current->next->elem.value.getCompanyName() + " " + to_string(current->next->elem.value.getFlightNumber());
		}

		if (key == new_key)
		{
			if (input == 1) //dont need to update current if first node needs to be removed
			{
				break;
			}
			for (int i = 0; i < input - 1; i++) //find the key and do next for the right amount of times
			{
				current = current->next;
			}
			break;
		}
		current = current->next;
	}
	if (buckets[index].size == count && input == 1) //special case
	{
		buckets[index].head = current->next;
	}
	else
	{
		Node<HashNode>* temp = current->next; //simple deletion of a node in a singly linked list
		current->next = current->next->next;
		delete temp;
	}
	buckets[index].size--; //decrease bucket size
	cout << "The flight-ticket has been successfully deleted!\n";
}

void FlightHASHTABLE::printASC(string companyName, int flightNumber) //prints by ascending order of destination
{
	bool found = false;
	string key = companyName + " " + to_string(flightNumber);
	sort(key); //sort function sorts by destination all of the nodes in the link
	int index = hashCode(key);
	Node<HashNode>* current = buckets[index].head;
	while (current != nullptr)
	{
		string new_key = current->elem.value.getCompanyName() + " " + to_string(current->elem.value.getFlightNumber());
		if (key == new_key)
		{
			found = true;
			printLineTerminal(current); //only print those that match the key
		}
		current = current->next;
	}

	if (found == false)
	{
		cout << "Key Not Found!\n";
	}
}

void FlightHASHTABLE::sort(string key) //sort function to sort a singly linked list 
{
	long index = hashCode(key);
	Node<HashNode>* current = buckets[index].head;
	Flight_Ticket temp;
	int count = 0;
	bool flag = false;

	//checks for the number of nodes in the list
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	for (int i = 0; i < count; i++) //since max time complexity can be O(N^2)
	{
		flag = false; //reinitialize flag to false
		current = buckets[index].head;
		while (current->next != NULL)
		{
			if (current->elem.value.getDestination() > current->next->elem.value.getDestination()) //check if the next element is smaller than the current one
			{
				flag = true; //even if a single switch is made, loop it again
				temp = current->elem.value; //stores the element of current node in a temporary variable
				current->elem.value = current->next->elem.value;
				current->next->elem.value = temp;
			}
			current = current->next; //next node becomes the current node
		}
		if (flag == false)
		{
			break; //if not even a single switch is done, then the list is already sorted
		}
	}
}


void FlightHASHTABLE::sort_by_key(int index) //sorts the singly linked list based on keys
{
	Node<HashNode>* current = buckets[index].head;
	Flight_Ticket temp;
	int count = 0;
	bool flag = false;

	//checks for the number of nodes in the list
	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	for (int i = 0; i < count; i++) //since max time complexity can be O(N^2)
	{
		flag = false; //reinitialize flag to false
		current = buckets[index].head;
		while (current->next != NULL)
		{
			string key1 = current->elem.value.getCompanyName() + " " + to_string(current->elem.value.getFlightNumber());
			string key2 = current->next->elem.value.getCompanyName() + " " + to_string(current->next->elem.value.getFlightNumber());
			if (key1 > key2) //check if the next element is smaller than the current one
			{
				flag = true; //even if a single switch is made, loop it again
				temp = current->elem.value; //stores the element of current node in a temporary variable
				current->elem.value = current->next->elem.value;
				current->next->elem.value = temp;
			}
			current = current->next; //next node becomes the current node
		}
		if (flag == false)
		{
			break; //if not even a single switch is done, then the list is already sorted
		}
	}
}