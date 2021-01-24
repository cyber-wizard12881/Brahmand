#pragma once
#pragma once
#include <vector>
#include <map>
#include <string>
#include <ppl.h>
#include <queue>

#ifdef PHANOI_EXPORTS
#  define PHANOI_API __declspec(dllexport)
#else
#  define PHANOI_API __declspec(dllimport)
#endif

using namespace std;

//Backing Data Store for the Parallel Version of the Towers of Hanoi Puzzle
class PHANOI_API PHanoi {
public:
	//Number of Disks
	int N;

	//The Disks stacked on each other for this Tower
	queue<int>* Discs;
	//Name of the Tower
	string Tower;

	//Default Constructor
	PHanoi();
	//The Destructor
	~PHanoi();
	//Overloaded actually invoked Constructor
	PHanoi(int N, queue<int>* Discs, string Tower);
};