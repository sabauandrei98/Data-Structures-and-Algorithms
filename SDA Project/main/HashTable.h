#pragma once

#include "LinkedList.h"
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

class HashTable
{
private:
	int hashFunction(int weight);
	SinglyLinkedList* elems = nullptr;
	int capacity;
	int m = 7;

public:
	HashTable(int cap) : elems{ new SinglyLinkedList[cap] }, capacity{ cap } {}
	~HashTable() {}

	void add(const int& weight);
	void remove(const int& weight);
	bool search(const int& weight);

	SinglyLinkedList* operator[](int x) {return &elems[x];}
	int getCapacity() { return this->capacity; }
};

class IteratorHT 
{
private:
	int index = 0;
	SinglyLinkedList* current;
	HashTable& hashTable;

public:
	IteratorHT(HashTable& hashT) : hashTable{ hashT } { this->current = this->hashTable[this->index]; }
	~IteratorHT() {}

	void next();
	bool valid();
	SinglyLinkedList* getCurrent();
};

void _testHT();

