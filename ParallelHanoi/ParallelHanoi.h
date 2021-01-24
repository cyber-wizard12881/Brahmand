#pragma once
#include <vector>
#include <map>
#include <string>
#include <queue>
#include "PHanoi.h"
#include <concurrent_unordered_map.h>

#ifdef PHANOI_EXPORTS
#  define PHANOI_API __declspec(dllexport)
#else
#  define PHANOI_API __declspec(dllimport)
#endif

using namespace concurrency;
using namespace std;

//Parallel Version of the Towers of Hanoi Puzzle using OpenMP 
class PHANOI_API ParallelHanoi {
public:
	//Number of Disks
	int N;

	//Source Tower
	PHanoi* A;
	//Auxillary Tower
	PHanoi* B;
	//Destination Tower
	PHanoi* C;

	//Stores the results of the number of moves and its description
	map<int, string>* moves;

	//Keeps track on the number of Turn you are on
	int Turn;

	//Default Constructor
	ParallelHanoi();
	//Constructor accepting the Number of Disks
	ParallelHanoi(int N);
	//Destructor
	~ParallelHanoi();

	//Actual Recursive Algorithm with OpenMP Parallel Sections
	void move(int n, PHanoi* source, PHanoi* destination, PHanoi* auxillary, map<int, string>* moves);

	//The driver method to invoke the above move() method
	void move();

	//Print out the results to the console
	void print();
};