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

class PHANOI_API ParallelHanoi {
public:
	int N;
	PHanoi* A;
	PHanoi* B;
	PHanoi* C;
	concurrent_unordered_map<int, string>* moves;
	int Turn;
	ParallelHanoi();
	ParallelHanoi(int N);
	~ParallelHanoi();
	void move(int n, PHanoi* source, PHanoi* destination, PHanoi* auxillary, concurrent_unordered_map<int, string>* moves);
	void move();
	void print();
};