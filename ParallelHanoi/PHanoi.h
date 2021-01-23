#pragma once
#pragma once
#include <vector>
#include <map>
#include <string>
#include <ppl.h>
#include <concurrent_queue.h>

#ifdef PHANOI_EXPORTS
#  define PHANOI_API __declspec(dllexport)
#else
#  define PHANOI_API __declspec(dllimport)
#endif

using namespace concurrency;
using namespace std;

class PHANOI_API PHanoi {
public:
	int N;
	concurrent_queue<int>* Discs;
	string Tower;
	PHanoi();
	~PHanoi();
	PHanoi(int N, concurrent_queue<int>* Discs, string Tower);
};