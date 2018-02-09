/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  ================================================
*
*	Standard LinkedList API Implementation
*
*/

// Multiple Inclusion Guards
#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

#include "LinkedList.hpp"

// Default Constructor: initialize the head to nullptr 
template <class Type>
LinkedList<Type>::LinkedList() : head(nullptr) {}

// Default Destructor: if there are values in the list, delete them recursively
template <class Type>
LinkedList<Type>::~LinkedList() {
	clear();
	std::cout << "List destroyed!\n";
}

// Methods

// Insert at head of list
template <class Type>
void LinkedList<Type>::insertHead(Type key) {

	// Check if there are any elements. If not, insert at head
	if (head == nullptr) {
		head = new ListNode<Type>(key);
		return;
	}

	// Create new node and replace the head with it
	ListNode<Type> * temp = new ListNode<Type>(key);
	temp->next = head;
	head = temp;
}

// Insert at the end of the list
template <class Type>
void LinkedList<Type>::insertTail(Type key) {

	// Check if list is empty. If it is, insert at head
	if (head == nullptr) {
		head = new ListNode<Type>(key);
		return;
	}

	// Create a new node and iterate until the end to add it
	ListNode<Type> * temp = head;

	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = new ListNode<Type>(key);
}


// Remove head node of the list
template <class Type>
void LinkedList<Type>::popHead() {

	// If list is empty, nothing to remove
	if (head == nullptr) return;

	// If there is only one node, delete it 
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	
	// If there are more nodes, replace the head with the next node
	ListNode<Type> * temp = head;
	head = head->next;
	delete temp;
}

// Remove from the end of the list
template <class Type>
void LinkedList<Type>::popTail() {

	// Case: Empty list
	if (head == nullptr) return;

	// Case: List with one element
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}

	// Case: List with two or more elements
	// 1 -> 2 -> nullptr
	// t
	//     t (next-next is nullptr) !
	//     thus, we delete t->next 
	ListNode<Type> * h = head;
	ListNode<Type> * hn;

	while (h->next->next != nullptr) {
		h = h->next;
	}
	hn = h->next;
	h->next = nullptr;
	delete  hn;
}

// Empty list
template <class Type>
void LinkedList<Type>::clear() {
	if (head == nullptr) return;
	ListNode<Type> * temp = head;
	while (temp != nullptr) { // 1, 2, 3, 4, null
		temp = temp->next;
		delete head;
		head = temp;
	}
	head = nullptr;
}

// Print list
template <class Type>
void LinkedList<Type>::print() {

	// If list is empty, nothing to print
	if (head == nullptr) return;

	// Iterate and print all elements
	ListNode<Type> * temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}


// Print from the end to front
template <class Type>
void LinkedList<Type>::printReverse() {
	if (head == nullptr) return;
	// Call recursive function for this
	printRev(head);
	std::cout << "\n";
}

// Reverse LinkedList
// Input:  [1] -> [2] -> [3] -> NULL
// Output: NULL <- [1] <- [2] <- [3]
template <class Type>
void LinkedList<Type>::reverse() {

	// If list is empty or with one element, nothing to reverse
	if (head == nullptr || head->next == nullptr) return;

	ListNode<Type> * previous = nullptr;
	ListNode<Type> * current = head;
	ListNode<Type> * next = head->next;

	// Work with three pointers
	// NULL [1] -> [2] -> [3] -> NULL
	//  p    c      n
	//       p      c      n
	//              p      c      n
	while (next != nullptr) {
		current->next = previous;	// p <- c
		previous = current;		// p = c
		current = next;			// c = n
		next = next->next;		// n = n->next
	}

	// Connect last pair and set new head to current
	current->next = previous;
	head = current;
}

#endif // !LINKED_LIST_CPP
