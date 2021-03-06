// Brahmand.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SerialHanoi.h"
#include "ParallelHanoi.h"
#include "Brahmand.h"
#include <chrono>
#include <omp.h>

//Number of Threads for Parallel Hanoi using OpenMP
#define NThreads 6

//fwd decl for Serial Hanoi Executor
void ExecuteSerialHanoi();
//fwd decl for Parallel Hanoi Executor
void ExecuteParallelHanoi();

//The main entry point for the application
int main()
{
    std::cout << "---------Entering Brahmand!!!----------\n";
    ExecuteParallelHanoi();
    ExecuteSerialHanoi();
    std::cout << "---------Exiting Brahmand!!!----------\n";
    return getchar();
}

//invoke the serial version of the Towers of Hanoi Algorithm using recursion 
void ExecuteSerialHanoi()
{
    cout << "...... Starting the Serial Hanoi Program ......" << endl;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    SerialHanoi* sHanoi = new SerialHanoi(3);
    start = std::chrono::steady_clock::now();
    sHanoi->move();
    end = std::chrono::steady_clock::now();
    cout << "Time to complete moves for Serial Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;
    
    start = std::chrono::steady_clock::now();
    sHanoi->print();
    end = std::chrono::steady_clock::now();
    cout << "Time to print moves for Serial Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;

    cout << "....... Ending the Serial Hanoi Program ......" << endl;
}

//invoke the parallel version of the Towers of Hanoi Algorithm using recursion with OpenMP
void ExecuteParallelHanoi()
{
    cout << "...... Starting the Parallel Hanoi Program ....." << endl;
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;

    //set the number of threads for execution in OpenMP
    omp_set_num_threads(NThreads);

    ParallelHanoi* pHanoi = new ParallelHanoi(3);
    start = std::chrono::steady_clock::now();
    pHanoi->move();
    end = std::chrono::steady_clock::now();
    cout << "Time to complete moves for Parallel Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;

    start = std::chrono::steady_clock::now();
    pHanoi->print();
    end = std::chrono::steady_clock::now();
    cout << "Time to print moves for Parallel Hanoi is " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds." << endl;

    cout << "....... Ending the Parallel Hanoi Program ......" << endl;
}
