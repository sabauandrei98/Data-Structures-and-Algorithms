#include "HashTable.h"


void HashTable::add(const int& weight) 
{
	int key = this->hashFunction(weight);
	this->elems[key].add(weight);
}

void HashTable::remove(const int& weight)
{
	int key = this->hashFunction(weight);
	this->elems[key].remove(weight);
}

bool HashTable::search(const int& weight)
{
	int key = this->hashFunction(weight);
	return this->elems[key].search(weight);
}

int HashTable::hashFunction(int weight)
{
	return weight % this->m;
}

void IteratorHT::next()
{
	this->index++;
	current = this->hashTable[this->index];
}

bool IteratorHT::valid()
{
	return this->hashTable.getCapacity() > this->index;
}

SinglyLinkedList* IteratorHT::getCurrent()
{
	return this->current;
}

void _testHT()
{
	cout << "HASH TABLE TESTS \n";

	bool seen[115]{ false };
	HashTable ht{ 10 };
	for (int i = 1; i <= 10; i++)
	{
		ht.add(i*i + i);
		seen[i*i + i] = true;
	}

	int iterations = 0;

	IteratorHT it{ ht };
	while (it.valid())
	{
		IteratorSLL itSll{ *it.getCurrent() };
		while(itSll.valid())
		{
			seen[itSll.getInfo()] = false;
			itSll.next();
			iterations++;
		}
		it.next();
	}
	
	for (int i = 1; i <= 110; i++)
		assert(!seen[i]);
	assert(iterations == 10);	
}
