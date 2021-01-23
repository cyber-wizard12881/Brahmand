// Brahmand.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SerialHanoi.h"
#include "ParallelHanoi.h"
#include "Brahmand.h"
#include <chrono>
#include <omp.h>

#define NThreads 6

void ExecuteSerialHanoi();
void ExecuteParallelHanoi();

int main()
{
    std::cout << "---------Entering Brahmand!!!----------\n";
    ExecuteParallelHanoi();
    ExecuteSerialHanoi();
    std::cout << "---------Exiting Brahmand!!!----------\n";
    return getchar();
}

void ExecuteSerialHanoi()
{
    cout << "...... Starting the Serial Hanoi Program ......" << endl;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    start = std::chrono::steady_clock::now();
    SerialHanoi* sHanoi = new SerialHanoi(3);
    sHanoi->move();
    end = std::chrono::steady_clock::now();
    cout << "Time to complete moves for Serial Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;
    
    start = std::chrono::steady_clock::now();
    sHanoi->print();
    end = std::chrono::steady_clock::now();
    cout << "Time to print moves for Serial Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;

    cout << "....... Ending the Serial Hanoi Program ......" << endl;
}

void ExecuteParallelHanoi()
{
    cout << "...... Starting the Parallel Hanoi Program ....." << endl;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    omp_set_num_threads(NThreads);

    start = std::chrono::steady_clock::now();
    ParallelHanoi* pHanoi = new ParallelHanoi(3);
    pHanoi->move();
    end = std::chrono::steady_clock::now();
    cout << "Time to complete moves for Parallel Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;

    start = std::chrono::steady_clock::now();
    pHanoi->print();
    end = std::chrono::steady_clock::now();
    cout << "Time to print moves for Parallel Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;

    cout << "....... Ending the Parallel Hanoi Program ......" << endl;
}
