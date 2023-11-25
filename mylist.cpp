#include "mylist.h"
#include "flighthashtable.h"
#include <iostream>
using namespace std;

template <typename E> MyList<E>::MyList ()
{
	this->head = NULL;
	size = 0;
}
//====================================
// destructor to clean up all nodes
template <typename E> MyList<E>::~MyList () 
{
	while(!empty())
	{
		removeFront(); //keep removing front till the list is empty
	}
}
//====================================
// Check if the list is empty or not
template <typename E> bool MyList<E>::empty() const 
{
	if (head == NULL) //if head points towards NULL then the list is empty
	{
		return true;
	}
	else
	{
		return false;
	}
}
//====================================
// add a node at the front of the list
template <typename E> void MyList<E>::addFront(E elem)
{
	size++;
	Node<E>* newnode = new Node<E>(elem);
	newnode->next = head; //points to where the head was pointing at
	head = newnode; //head now points to this new node

}
//====================================
// remove the first node from the list
template <typename E> void MyList<E>::removeFront()
{
	if (!empty()) //ensuring the list has nodes before removing
	{
		Node<E>* current = head;
		head = current->next;
		delete current; //deletes the node
	}
	else
	{
		cout << "Cannot remove front. The list is empty.\n"; //outputs error if list is empty
	}
}
//====================================
template <typename E> void MyList<E>::display() const
{
	cout << "Head -> ";
	Node<E>* current = this->head;
	//E element;
	while (true)
	{	
		if (current == NULL)
		{
			break; //if the list is empty then break the loop and only print head and tail
		}
		//element = current->elem;
		cout << current->elem.getValue().getCompanyName() << " " << current->elem.getValue().getFlightNumber() << " -> ";
		current = current->next;

	}
	cout << "Tail" << endl;
}

template class MyList<HashNode>;