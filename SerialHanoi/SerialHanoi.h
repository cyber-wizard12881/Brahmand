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

//The Serial Version of the Towers Of Hanoi Puzzle
class SHANOI_API SerialHanoi {
public:
	//The Number of Disks
	int N;

	//The Source Tower
	Hanoi* A;
	//The Auxillary Tower
	Hanoi* B;
	//The Destination Tower
	Hanoi* C;

	//Stores the result as the number of the move & its description
	map<int, string>* moves;
	//Keeps track of the current number of move in the system
	int Turn;

	//Default Constructor
	SerialHanoi();
	//Invoked Constructor with the number of Disks
	SerialHanoi(int N);
	//Default Destructor
	~SerialHanoi();

	//The Serial recursive algorithm for the Towers of Hanoi Puzzle
	void move(int n, Hanoi* source, Hanoi* destination, Hanoi* auxillary, map<int, string>* moves);
	//The invoker of the serial recursive algorithm mentioned above
	void move();

	//Print out the resuts of computation onto the console (screen)
	void print();
};