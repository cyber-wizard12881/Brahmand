#include "pch.h"
#include "SerialHanoi.h"
#include <iostream>

using namespace std;

SerialHanoi::SerialHanoi()
{
	this->Turn = 0;
	this->N = 0;
	this->A = new Hanoi();
	this->B = new Hanoi();
	this->C = new Hanoi();
	this->moves = new map<int, string>();
}

SerialHanoi::~SerialHanoi()
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

void SerialHanoi::move(int n, Hanoi* source, Hanoi* destination, Hanoi* auxillary, map<int, string>* moves)
{
	if (n > 0) {
		move(n - 1, source, auxillary, destination, moves);

		destination->Discs->push(source->Discs->front());
		source->Discs->pop();

		string action = "Move " + std::to_string(n) + " From " + source->Tower + " To " + destination->Tower + " .... \n";
		moves->insert(make_pair(this->Turn, action));
		this->Turn++;

		move(n - 1, auxillary, destination, source, moves);
	}
}

void SerialHanoi::move()
{
	this->move(this->N, this->A, this->C, this->B, this->moves);
}

void SerialHanoi::print()
{
	for (int turn = 0; turn < this->moves->size(); turn++) {
		cout << "Turn-" << turn << ":" << this->moves->find(turn)->second << endl;
	}
}

SerialHanoi::SerialHanoi(int N)
{
	this->Turn = 0;
	this->N = N;
	this->A = new Hanoi(N, new queue<int>(), "A");
	this->B = new Hanoi(0, new queue<int>(), "B");
	this->C = new Hanoi(0, new queue<int>(), "C");
	this->moves = new map<int, string>();
}
