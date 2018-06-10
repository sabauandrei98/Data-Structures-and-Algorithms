#pragma once

#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node* nextNode;
};

class SinglyLinkedList
{
private:
	Node* first;
	int len;
public:
	SinglyLinkedList() :first{ nullptr } {}
	void add(const int& weight);
	void remove(const int& weight);
	bool search(const int& weight);

	int getSize()  { return this->len; } ;
	Node* getFirst() { return this->first; };
	void printAll();
	~SinglyLinkedList();
};

class IteratorSLL
{
private:
    SinglyLinkedList& sll;
	Node* current;
public:
	IteratorSLL(SinglyLinkedList& sl) : sll{ sl }, current{ sll.getFirst() } {}
	void getFirst();
	bool valid();
	void next();
	int getInfo();
	~IteratorSLL() {};
};

void _testSLL();
