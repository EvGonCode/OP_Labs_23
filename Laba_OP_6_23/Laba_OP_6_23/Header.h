#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;

template<typename T>
class CircularLinkedList;

template<typename T>
struct Node {
	CircularLinkedList<T>* parent;
	T data;
	Node<T>* next;
	Node<T>* prev;
	Node<T>(T value = T(), Node* pNext = nullptr, CircularLinkedList<T>* parent = nullptr) {
		data = value;
		next = pNext;
		this->parent = parent;
	}
};

template<typename T>
class Iterator {
	Node<T>* node;
public:
	Iterator() : node(NULL) {}
	Iterator(Node<T>* nod) : node(nod) {}
	void setBegining();
	Iterator operator++();
	Iterator operator--();
	Iterator operator++(int fake);
	Iterator operator--(int fake);
	Iterator& operator=(const Iterator& other);
	void setNode(Node<T>*);
	Node<T>* getNode();
	bool isEnd();
};

template<typename T>
class CircularLinkedList {

	Node<T>* head;
	Node<T>* tail;
public:
	friend class Iterator<T>;
	void push_back(T element);
	CircularLinkedList() : head(nullptr), tail(nullptr) {}
	bool isEmpty();
	void clear();
	T& operator[](int i);
	void deleteElement(int i);
	void printList();

	Node<T>* getTail() {
		return tail;
	}
};

															//CircularLinkedList methods
template<typename T>
void CircularLinkedList<T>::push_back(T element) {
	Node<T>* nod = new Node<T>(element);
	nod->parent = this;

	if (head == nullptr) {
		head = nod;
		tail = nod;
		head->prev = tail;
		head->next = tail;
		return;
	}
	else if (head == tail) {
		tail = nod;
		tail->prev = head;
		tail->next = head;
		head->prev = tail;
		head->next = tail;
		return;
	}
	else {
		tail->next = nod;
		nod->prev = tail;
		nod->next = head;
		tail = nod;
		head->prev = tail;
	}
}


template<typename T>
bool CircularLinkedList<T>::isEmpty() {
	return head == nullptr;
}

template<typename T>
void CircularLinkedList<T>::clear() {
	if (head == nullptr) {
		return;
	}

	Node<T>* current = head;
	Node<T>* nextNode;

	do {
		nextNode = current->next;
		delete current;
		current = nextNode;
	} while (current != head);

	head = nullptr;
	tail = nullptr;
}

template<typename T>
T& CircularLinkedList <T>::operator[](int i) {
	if (i == 0) {
		if (head != nullptr) {
			return head->data;
		}
		else {
			//cout << "List is empty!" << endl;
			throw out_of_range("List is empty exception!");
		}
	}
	Iterator<T> iter(head);
	while (iter.getNode() != tail and i > 0) {
		++iter;
		i--;
	}
	if (i != 0) {
		//cout << "Element not found!" << endl;
		throw out_of_range("Element not found exception!");
	}
	return iter.getNode()->data;
}

template<typename T>
void CircularLinkedList<T>::deleteElement(int i) {
	if (head == nullptr) { throw out_of_range("List is ampty!"); }
	if (i == 0 and head->next == head) {
		delete head;
	}
	else if (i == 0) {
		tail->next = head->next;
		head = head->next;
		delete head->prev;
		head->prev = tail;
		return;
	}

	Node<T>* nod = head;
	while (nod != tail and i > 0) {
		nod = nod->next;
		i--;
	}
	if (i != 0) {
		throw out_of_range("Element out of list size!");
	}
	if (nod == tail) {
		nod->prev->next = nod->next;
		nod->next->prev = nod->prev;
		tail = nod->next;
		delete nod;
		return;
	}
	nod->prev->next = nod->next;
	nod->next->prev = nod->prev;
	delete nod;
}


template<typename T>
void CircularLinkedList<T>::printList() {
	Iterator<T> i(this->tail);
	i.setBegining();
	if (i.getNode()) {
		while (!i.isEnd()) {
			cout << i.getNode()->data << " ";
			i++;
		}
		cout << i.getNode()->data << endl;
	}
}



														//Iterator methods



template<typename T>
void Iterator<T>::setBegining() {
	if (node == nullptr) {
		cout << "Empty list!" << endl;
		return;
	}

	node = node->parent->head;
}

template<typename T>
Iterator<T> Iterator<T>::operator++() {
	node = node->next;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator--() {
	node = node->prev;
	return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator++(int fake) {
	Iterator<T> tmp(node);
	node = node->next;
	return tmp;
}

template<typename T>
Iterator<T> Iterator<T>::operator--(int fake) {
	Iterator<T> tmp(node);
	node = node->prev;
	return tmp;
}


template<typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& other) {
	node = other.node;
	return *this;
}

template<typename T>
void Iterator<T>::setNode(Node<T>* nod) {
	node = nod;
}

template<typename T>
Node<T>* Iterator<T>::getNode() {
	return node;
}
template<typename T>
bool Iterator<T>::isEnd() {
	return node == node->parent->tail;
}
															//Functions for main
bool isInteger(const string& s);
bool isFloat(const string& s);
string getVariableType(const string& var);

void initiateInputLists(string& input,
	string& type,
	string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList);

void printOneList(string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList);

void testDeletingElements(string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList);

void testDeletingList(string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList);


void testChangingElements(string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList);
