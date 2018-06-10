#include "LinkedList.h"


void SinglyLinkedList::add(const int& weight)
{
	if (this->first == nullptr)
	{
		Node* newNode = new Node;
		newNode->info = weight;
		newNode->nextNode = nullptr;
		this->first = newNode;
		len++;
	}
	else
	{
		Node* current = this->first;
		while (current->nextNode != nullptr)
			current = current->nextNode;
		Node*nw = new Node;
		nw->info = weight;
		nw->nextNode = current->nextNode;
		current->nextNode = nw;
		len++;
	}
}

bool SinglyLinkedList::search(const int& weight)
{
	IteratorSLL it{ *this };
	bool result = false;
	while (it.valid() && !result)
	{
		if (it.getInfo() == weight)
			return true;
			it.next();
	}
	return false;
}

void SinglyLinkedList::remove(const int& weight)
{
	Node* current = this->first;
	Node* prev = nullptr;
	while (current != nullptr && current->info != weight)
	{
		prev = current;
		current = current->nextNode;
	}
	if (prev == nullptr)
	{
		this->first = first->nextNode;
		len--;
	}
	else if (current != nullptr)
	{
		prev->nextNode = current->nextNode;
		current->nextNode = nullptr;
		len--;
	}

}

SinglyLinkedList::~SinglyLinkedList()
{
}

void SinglyLinkedList::printAll()
{
	IteratorSLL it{ *this };
	
	while (it.valid())
	{
		cout << "Element:" << it.getInfo() << '\n';
		it.next();
	}
}

void IteratorSLL::next()
{
	this->current = this->current->nextNode;
}

int IteratorSLL::getInfo()
{
	return this->current->info;
}

void IteratorSLL::getFirst()
{
	this->current = this->sll.getFirst();
}

bool IteratorSLL::valid()
{
	return (this->current != nullptr);
}


void _testSLL()
{
	cout << "SLL TESTS \n";

	SinglyLinkedList ls{};
	IteratorSLL it{ ls };
	int a1 = 0;
	int a2 = 2;
	int a3 = 4;

	it.getFirst();

	assert(ls.getSize() == 0);
	ls.add(a1);
	assert(ls.getSize() == 1);
	ls.add(a2);
	assert(ls.getSize() == 2);

	ls.add(a3);
	assert(ls.getSize() == 3);

	assert(ls.search(a1));

	int a5 = 7;
	assert(!(ls.search(a5)));

	ls.remove(a1);
	assert(ls.getSize() == 2);

	ls.remove(a5);
	assert(ls.getSize() == 2);

	ls.remove(a3);
	assert(ls.getSize() == 1);

	ls.printAll();

	ls.remove(a2);
	assert(ls.getSize() == 0);

}

