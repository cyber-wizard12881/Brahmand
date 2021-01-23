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

class PHANOI_API PHanoi {
public:
	int N;
	queue<int>* Discs;
	string Tower;
	PHanoi();
	~PHanoi();
	PHanoi(int N, queue<int>* Discs, string Tower);
};