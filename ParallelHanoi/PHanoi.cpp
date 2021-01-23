#include "pch.h"
#include "PHanoi.h"

PHanoi::PHanoi()
{
	this->N = 0;
	this->Discs = new concurrent_queue<int>();
	this->Tower = "";
}

PHanoi::~PHanoi()
{
	this->N = 0;
	concurrent_queue<int> discs;
	this->Discs->clear();
	this->Tower.clear();
}

PHanoi::PHanoi(int N, concurrent_queue<int>* Discs, string Tower)
{
	this->N = N;
	this->Discs = Discs;
	for (int disc = N; disc > 0; disc--) {
		this->Discs->push(disc);
	}
	this->Tower = Tower;
}
