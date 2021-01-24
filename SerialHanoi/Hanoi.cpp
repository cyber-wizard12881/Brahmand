#include "pch.h"
#include "Hanoi.h"

//Default Constructor --> Initialize Defaults
Hanoi::Hanoi()
{
	this->N = 0;
	this->Discs = new queue<int>();
	this->Tower = "";
}

//Destructor --> Clean up stuff at the end
Hanoi::~Hanoi()
{
	this->N = 0;
	queue<int> discs;
	this->Discs->swap(discs);
	this->Tower.clear();
}

//Invoked Constructor --> With Number of Disks, its Configuration & the Name of the Tower
Hanoi::Hanoi(int N, queue<int>* Discs, string Tower)
{
	this->N = N;
	this->Discs = Discs;
	for (int disc = N; disc > 0; disc--) {
		this->Discs->push(disc);
	}
	this->Tower = Tower;
}
