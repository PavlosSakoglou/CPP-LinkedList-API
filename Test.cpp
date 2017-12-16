/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  ================================================
*
*	Standard LinkedList API Test program
*
*/

#include <iostream>

#include "LinkedList.hpp"

template <class K>
struct Object {
	K satellite;
	Object(K k = 0) : satellite(k) {}
};

int main() {

	
	// Create LinkedList of int
	LinkedList<int> list;

	// Insert at end
	list.insertTail(10);
	list.insertTail(20);
	list.insertTail(30);
	list.insertTail(40);
	list.insertTail(50);

	// Insert at front
	list.insertHead(500);
	list.insertHead(400);
	list.insertHead(300);
	list.insertHead(200);
	list.insertHead(100);

	// Print list
	std::cout << "List:\n";
	list.print();

	std::cout << "\nReversed List:\n";
	list.reverse();
	list.print();

	// Remove head
	std::cout << "\nRemoved head:\n";
	list.popHead();
	list.print();

	// Remove tail
	std::cout << "\nRemoved tail:\n";
	list.popTail();
	list.print();

	// Clear list
	std::cout << "\nEmptying list...\n";
	list.clear();	

	return 0;
}