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

class SHANOI_API Hanoi {
public:
	int N;
	queue<int>* Discs;
	string Tower;
	Hanoi();
	~Hanoi();
	Hanoi(int N, queue<int>* Discs, string Tower);
};