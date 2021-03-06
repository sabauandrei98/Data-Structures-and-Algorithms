// main.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include "LinkedList.h"
#include "HashTable.h"
#include "SortedList.h"
#include <stdlib.h>
#include <time.h> 

void runTests()
{
	_testSL();
	_testSLL();
	_testHT();
}

void Solve()
{
	cout << "\n\nProblem solving: \n\n";

	srand(time(NULL));
	SortedList sl;
	for (int i = 1; i <= 30; i++)
		sl.add(rand() % 100 + 1);

	cout << "Raport/Day ingreasingly: \n";
	IteratorSL it{ sl };
	int sum = 0;
	while (it.valid())
	{
		cout << it.getInfo() << " ";
		sum += it.getInfo();
		it.next();
	}

	cout << "\nThe total: " << sum << '\n';

	cout << "Best and worst days:\n";
	cout << sl.last() << " / " << sl.first() << '\n';
}


int main()
{
	runTests();
	//Solve();

	system("pause");
    return 0;
}

