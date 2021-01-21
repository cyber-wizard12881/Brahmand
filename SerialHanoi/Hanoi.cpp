#include "pch.h"
#include "Hanoi.h"

Hanoi::Hanoi()
{
	this->N = 0;
	this->Discs = new queue<int>();
	this->Tower = "";
}

Hanoi::~Hanoi()
{
	this->N = 0;
	queue<int> discs;
	this->Discs->swap(discs);
	this->Tower.clear();
}

Hanoi::Hanoi(int N, queue<int>* Discs, string Tower)
{
	this->N = N;
	this->Discs = Discs;
	for (int disc = N; disc > 0; disc--) {
		this->Discs->push(disc);
	}
	this->Tower = Tower;
}
