#include "SortedList.h"



SortedList::SortedList()
{
}


SortedList::~SortedList()
{
}

void SortedList::add(const int & weight)
{
	this->ht.add(weight);
}

void SortedList::remove(int p)
{
	IteratorSL it{ *this };
	while (it.valid())
	{
		p--;
		if (p == 0)
			this->ht.remove(it.getInfo());
		it.next();
	}
}

bool SortedList::search(const int & weight)
{
	return this->ht.search(weight);
}

int SortedList::first()
{
	IteratorSL it{ *this };
	return it.getInfo();
}

int SortedList::last()
{
	IteratorSL it{ *this };
	int info;
	while (it.valid())
	{
		info = it.getInfo();
		it.next();
	}
	return info;
}

bool SortedList::valid(int p)
{
	IteratorSL it{ *this };
	while (it.valid())
	{
		p--;
		if (p == 0)
			return true;
		it.next();
	}
	return false;
}

bool SortedList::isEmpty()
{
	IteratorSL it{ *this };
	if (it.valid())
	{
		return false;
	}
	return true;
}

int SortedList::getElement(int p)
{
	IteratorSL it{ *this };
	while (it.valid())
	{
		p--;
		if (p == 0)
			return it.getInfo();
		it.next();
	}
	return -1;
}

int SortedList::position(int x)
{
	IteratorSL it{ *this };
	int p = 0;
	while (it.valid())
	{
		p++;
		if (x == it.getInfo())
			return p;
		it.next();
	}
	return -1;
}

int SortedList::size()
{
	IteratorSL it{ *this };
	int p = 0;
	while (it.valid())
	{
		p++;
		it.next();
	}
	return p;
}

IteratorSL::IteratorSL(SortedList& sl) : sortedList{ sl }
{
	int arr[150];
	int pos = 0;
	IteratorHT it{ this->sortedList.ht };
	while (it.valid())
	{
		IteratorSLL itSll{ *it.getCurrent() };
		while (itSll.valid())
		{
			pos++;
			arr[pos] = itSll.getInfo();
			itSll.next();
		}
		it.next();
	}

	for (int i = 1; i <= pos - 1; i++)
		for (int j = i + 1; j <= pos; j++)
			if (!this->sortedList.relation(arr[i], arr[j]))
				swap(arr[i], arr[j]);

	for (int i = 1; i <= pos; i++)
	{
		if (this->head == nullptr)
		{
			Node* newNode = new Node;
			newNode->info = arr[i];
			newNode->nextNode = nullptr;
			this->head = newNode;
		}
		else
		{
			Node* current = this->head;
			while (current->nextNode != nullptr)
				current = current->nextNode;
			Node*nw = new Node;
			nw->info = arr[i];
			nw->nextNode = current->nextNode;
			current->nextNode = nw;
		}
	}

	this->current = this->head;
}

void IteratorSL::next()
{
	this->current = this->current->nextNode;
}

int IteratorSL::getInfo()
{
	return this->current->info;
}

bool IteratorSL::valid()
{
	return (this->current != nullptr);
}

void _testSL()
{
	cout << "TEST SL\n";
	SortedList sl;
	
	assert(sl.isEmpty());

	for (int i = 10; i <= 50; i++)
		sl.add(i);
	
	assert(!sl.isEmpty());
	assert(sl.first() == 10);
	assert(sl.last() == 50);
	assert(sl.size() == 41);
	assert(!sl.search(51));
	sl.remove(4);
	assert(!sl.search(4));
	assert(sl.getElement(3) == 12);
	assert(sl.getElement(90) == -1);
	assert(sl.position(88) == -1);
	assert(sl.position(10) == 1);
	assert(sl.valid(10));
	assert(!sl.valid(80));
}
