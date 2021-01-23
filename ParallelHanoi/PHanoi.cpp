#include "pch.h"
#include "PHanoi.h"

PHanoi::PHanoi()
{
	this->N = 0;
	this->Discs = new queue<int>();
	this->Tower = "";
}

PHanoi::~PHanoi()
{
	this->N = 0;
	queue<int> discs;
	this->Discs->swap(discs);
	this->Tower.clear();
}

PHanoi::PHanoi(int N, queue<int>* Discs, string Tower)
{
	this->N = N;
	this->Discs = Discs;
	for (int disc = N; disc > 0; disc--) {
		this->Discs->push(disc);
	}
	this->Tower = Tower;
}
