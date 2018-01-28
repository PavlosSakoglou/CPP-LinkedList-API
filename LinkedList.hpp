/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  =================================================
*
*	Standard LinkedList API Definition
*
*/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

// Node class
template <class Type>
struct ListNode {
	ListNode * next;
	Type data;
	ListNode(Type d = 0) : data(d), next(nullptr) {}
};

// LinkedList 
template <class Type>
class LinkedList {
public:
	// Default Constructor/Destructor
	LinkedList();
	~LinkedList();

	// Insert methods
	void insertHead(Type key);
	void insertTail(Type key);

	// Remove methods
	void popHead();
	void popTail();
	void clear();

	// Traverse methods
	void print();
	void printReverse();

	// Reverse method
	void reverse();

private:
	// Private recursive methods

	// Print reverse recursive
	void printRev(ListNode<Type> * h) {

		// If you reach the end, pop from recursion stack
		if (h == nullptr) return;

		// Go until the end of list
		printRev(h->next);

		// Print last element
		std::cout << h->data << " ";
	}

	ListNode<Type> * head;
};

#ifndef LINKED_LIST_CPP
#include "LinkedList.cpp"
#endif

#endif // !LINKED_LIST_HPP
