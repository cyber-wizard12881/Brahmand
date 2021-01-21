#pragma once
#include <vector>
#include <map>
#include <string>
#include <queue>
#include "Hanoi.h"

#ifdef SHANOI_EXPORTS
#  define SHANOI_API __declspec(dllexport)
#else
#  define SHANOI_API __declspec(dllimport)
#endif

using namespace std;

class SHANOI_API SerialHanoi {
public:
	int N;
	Hanoi* A;
	Hanoi* B;
	Hanoi* C;
	map<int, string>* moves;
	int Turn;
	SerialHanoi();
	SerialHanoi(int N);
	~SerialHanoi();
	void move(int n, Hanoi* source, Hanoi* destination, Hanoi* auxillary, map<int, string>* moves);
	void move();
	void print();
};