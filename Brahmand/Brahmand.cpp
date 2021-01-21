// Brahmand.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SerialHanoi.h"
#include "Brahmand.h"

void ExecuteSerialHanoi();

int main()
{
    std::cout << "---------Entering Brahmand!!!----------\n";
    ExecuteSerialHanoi();
    std::cout << "---------Exiting Brahmand!!!----------\n";
    return getchar();
}

void ExecuteSerialHanoi()
{
    SerialHanoi* sHanoi = new SerialHanoi(4);
    sHanoi->move();
    sHanoi->print();
}
