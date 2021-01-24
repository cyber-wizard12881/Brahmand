#include "pch.h"
#include "PHanoi.h"

//Default Constructor --> Initialize defaults here
PHanoi::PHanoi()
{
	this->N = 0;
	this->Discs = new queue<int>();
	this->Tower = "";
}

//The Destructor --> Clean up stuff at the end
PHanoi::~PHanoi()
{
	this->N = 0;
	queue<int> discs;
	this->Discs->swap(discs);
	this->Tower.clear();
}

//Constructor that is invoked --> Initialize the disks on the tower
PHanoi::PHanoi(int N, queue<int>* Discs, string Tower)
{
	this->N = N;
	this->Discs = Discs;
	for (int disc = N; disc > 0; disc--) {
		this->Discs->push(disc);
	}
	this->Tower = Tower;
}
