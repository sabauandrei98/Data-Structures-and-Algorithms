#pragma once

#include "HashTable.h"
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

class SortedList
{
public:
	SortedList();
	~SortedList();

	HashTable ht{ 20 };
	bool relation(int i, int j) { return i < j; };

	void add(const int& weight);
	void remove(int p);
	bool search(const int& weight);
	int first();
	int last();
	bool valid(int p);
	int getElement(int p);
	int position(int x);
	int size();
	bool isEmpty();
};

class IteratorSL
{
private:
	int index = 0;
	Node* head = nullptr;
	Node* current = nullptr;
	SortedList& sortedList;
public:
	IteratorSL(SortedList& sl);
	~IteratorSL() {};

	void next();
	bool valid();
	int getInfo();
};

void _testSL();

