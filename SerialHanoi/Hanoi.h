#pragma once
#pragma once
#include <vector>
#include <map>
#include <string>
#include <queue>

#ifdef SHANOI_EXPORTS
#  define SHANOI_API __declspec(dllexport)
#else
#  define SHANOI_API __declspec(dllimport)
#endif

using namespace std;

//Backing Store for the Serial Towers of Hanoi Algorithm Puzzle
class SHANOI_API Hanoi {
public:
	//The Number of Disks
	int N;

	//Number of Disks on the tower with its configuration
	queue<int>* Discs;
	//Name of the Tower
	string Tower;

	//Default Constructor
	Hanoi();
	//The Destructor
	~Hanoi();
	//Invoked Constructor with Disks & name of the Tower
	Hanoi(int N, queue<int>* Discs, string Tower);
};