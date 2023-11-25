#ifndef FlightHASHTABLE_H
#define FlightHASHTABLE_H

#include<iostream>
#include <fstream>
#include "flightticket.h"
#include "mylist.h"
// include additional header files if needed

using namespace std;

class HashNode
{
	private:
		string key; // key = companyName+flightNumber
		Flight_Ticket value;
	public:
		HashNode(string key, Flight_Ticket value)
		{
			this->key = key;
			this->value = value;
		}
		Flight_Ticket getValue()
		{
			return this->value;
		}
		friend class FlightHASHTABLE;
};

//=============================================================================
class FlightHASHTABLE
{
	private:
		MyList<HashNode> *buckets;				//List of Buckets, Please create your own List Class called MyList
		int size;					    //Current Size of HashTable
		int capacity; //Total capacity of hashTable
	public:
		FlightHASHTABLE();						//constructor
		~FlightHASHTABLE();						//destructor
		long hashCode(string key); 						//implement and test different hash functions 
		int importCSV(string path); 			//Load all the flight-tickets from the CSV file to the HashTable
		int exportCSV(string path); 			//Export all the flight-tickets from the HashTable to a CSV file in an ascending order		
		//int count_collisions2();	
		int count_collisions();					//return the number of collisions on the HashTable
		int add(Flight_Ticket* data);			//add new flight to the HashTable
		void removeRecord (string companyName, int flightNumber);	//Delete a record with key from the hashtable
		void printLineCSV(Node<HashNode>* current, fstream& fout);
		void find(string companyName, int flightNumber);		//Find and Display records with same key entered 
		void printLineTerminal(Node<HashNode>* current); //Prints flight in a line on terminal
		void sort_by_key(int index); //sorts all nodes in a singly linked list by key
		void sort(string key); //sorts all nodes in a singly linked list by destination
		void allinday(string date); 					//Find and Display records with same day entered
		void printASC(string companyName, int flightNumber);  		//display the collisions for the entered key in an ascending order 
};

#endif
