#pragma once
#include <iostream>

template<class T>
struct Node {
	T value;
	Node<T>* prev;
	Node<T>* next;

	// construct node
	Node(T v, Node<T>* p = nullptr, Node<T>* n = nullptr) {
		this->value = v;
		this->prev = p;
		this->next = n;
	}
};

template<class T>
// construct linked list
class LinkedList {
private:
	// pointer to the head of the linked list
	Node<T>* head;
	// pointer to the end of the linked list
	Node<T>* tail;

public:
	LinkedList() {
		// initialize head and tail pointers as null
		this->head = nullptr;
		this->tail = nullptr;
	}

	~LinkedList() {
		// delete the memory that has been allocated
		Node<T>* current = this->tail;

		// loop until the end of the list 
		while (current != nullptr) {
			// if this is not the last node
			if (current->next != nullptr) {
				// set current to the next node
				current = current->next;

				// delete the previous node
				delete current->prev;
			}
			else {
				// if it is the last node, delete it and set current to nullptr
				delete current;
				current = nullptr;
			}
		}
	}

	// add a value to the C++
	Node<T>* add(T value) {
		// check if the list is empty
		if (this->head == nullptr) {
			// create new node
			Node<T>* new_node = new Node<T>(value);

			// set the head and the tail to the new node
			this->head = new_node;
			this->tail = new_node;

			return new_node;
		}
		else {
			// create new node
			Node<T>* new_node = new Node<T>(value, this->head);

			// point the head node to the new node
			this->head->next = new_node;

			// set the new node as the head node
			this->head = new_node;

			return new_node;
		}
	}

	// find the pointer of a node in the list given its value
	Node<T>* find(T value) {
		// initalize the current tracker with the tail node
		Node<T>* current = this->tail;

		// loop until the end of the linked lista
		while (current != nullptr) {
			// if the current node matches the value being searched for , return the nodes pointer
			if (current->value == value) {
				return current;
			}

			// go to the next node in the list
			current = current->next;
		}

		// if no value is found return nullptr
		return nullptr;
	}

	// remove a value from the list
	bool remove(Node<T>* node) {
		if (node == nullptr) {
			return false;
		}

		// store the next and prev value of the node which is being deleted
		Node<T>* del_prev = node->prev;
		Node<T>* del_next = node->next;

		// delete the node
		delete node;

		// check if the node was the only node in the list
		if (del_prev == nullptr && del_next == nullptr) {
			// set the head and tail to null
			this->head = nullptr;
			this->tail = nullptr;
		}
		// if the node is the tail
		else if (del_prev == nullptr && del_next != nullptr) {
			// set the next node as the tail
			this->tail = del_next;

			// set the new tail node's previous node to nullptr
			this->tail->prev = nullptr;
		}
		// if the node is the head
		else if (del_prev != nullptr && del_next == nullptr) {
			// set the prev node as the head
			this->head = del_prev;

			// set the new head node's next node to nullptr
			this->head->next = nullptr;
		}
		else {
			// point the prev node to the next node
			del_prev->next = del_next;

			// point the next node to the prev node
			del_next->prev = del_prev;
		}

		// return true
		return true;
	}

	// get the pointer to the node containing the max value of the list
	Node<T>* max() {
		// keep track of the max value
		Node<T>* max = this->tail;

		// keep track of the current node
		Node<T>* current = this->tail;

		// loop until end of list
		while (current != nullptr) {
			// if the current nodes value is larger than the current max, set it as the new max
			if (current->value > max->value) {
				max = current;
			}

			// continue to the next node
			current = current->next;
		}
		// return the node with the max value
		return max;
	}

	// get the pointer to the node containing the min value of the list
	Node<T>* min() {
		// keep track of the min value
		Node<T>* min = this->tail;

		// keep track of the current node
		Node<T>* current = this->tail;

		// loop until end of list
		while (current != nullptr) {
			// if the current nodes value is smaller than the current min, set it as the new min
			if (current->value < min->value) {
				min = current;
			}

			// continue to the next node
			current = current->next;
		}
		// return the node with the min value
		return min;
	}

	// print the LinkedList
	void print(std::ostream& out) {
		out << "Tail - ";

		// keep track of the current node, start at the tail
		Node<T>* current = this->tail;

		// loop until the end of the list
		while (current != nullptr) {
			// output the value of the node
			out << "[" << current->value << "] ";

			// go to the next node
			current = current->next;
		}

		out << "- Head";
	}

};




