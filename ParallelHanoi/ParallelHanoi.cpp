#include "pch.h"
#include "ParallelHanoi.h"
#include <iostream>
#include <ppl.h>
#include <omp.h>

using namespace concurrency;
using namespace std;

ParallelHanoi::ParallelHanoi()
{
	this->Turn = 0;
	this->N = 0;
	this->A = new PHanoi();
	this->B = new PHanoi();
	this->C = new PHanoi();
	this->moves = new concurrent_unordered_map<int, string>();
}

ParallelHanoi::~ParallelHanoi()
{
	this->Turn = 0;
	this->N = 0;
	delete this->A;
	this->A = NULL;
	delete this->B;
	this->B = NULL;
	delete this->C;
	this->C = NULL;
	this->moves->clear();
}

void ParallelHanoi::move(int n, PHanoi* source, PHanoi* destination, PHanoi* auxillary, concurrent_unordered_map<int, string>* moves)
{

	if (n > 0) {
#pragma omp parallel sections
#pragma omp section
		move(n - 1, source, auxillary, destination, moves);

	int srcDisc;
	source->Discs->try_pop(srcDisc);
	destination->Discs->push(srcDisc);

	string action = "Move " + std::to_string(n) + " From " + source->Tower + " To " + destination->Tower + " .... \n";
	moves->insert(make_pair(this->Turn, action));
	this->Turn++;
#pragma omp section
	move(n - 1, auxillary, destination, source, moves);
	
	}
}

void ParallelHanoi::move()
{
	this->move(this->N, this->A, this->C, this->B, this->moves);
}

void ParallelHanoi::print()
{
	for (int turn = 0; turn < this->moves->size(); turn++) {
		cout << "Turn-" << turn << ":" << this->moves->find(turn)->second << endl;
	}
}

ParallelHanoi::ParallelHanoi(int N)
{
	this->Turn = 0;
	this->N = N;
	this->A = new PHanoi(N, new concurrent_queue<int>(), "A");
	this->B = new PHanoi(0, new concurrent_queue<int>(), "B");
	this->C = new PHanoi(0, new concurrent_queue<int>(), "C");
	this->moves = new concurrent_unordered_map<int, string>();
}
