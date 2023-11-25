#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>

using namespace std;
template <typename E> class MyList;


template <typename E> 
class Node
{
	private:
		E elem; //data element 
		Node<E>* next; //Link (pointer) to the next Node
		
	public:
		Node(E elem) : elem(elem), next(NULL)
		{}
		friend class MyList<E>;
		friend class FlightHASHTABLE;
};

template <typename E> 
class MyList
{
	private:
		Node<E>* head; // pointer to the head of list
		int size;
	public:
		MyList (); // empty list constructor
		~MyList (); // destructor to clean up all nodes
		bool empty() const; // is list empty?
		void addFront(E elem); // add a new Node at the front of the list
		void removeFront(); // remove front Node from the list
		// unsigned int countElem(E elem); //count frequency of an element in the list
		// int getIndexOf(E elem); //returns first index of an element in the list, -1 if the element is not present
		void display() const;
		friend class FlightHASHTABLE;
};

#endif