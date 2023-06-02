#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Exceptions.h"

using namespace std;


class BinaryFile {
    static string address;
public:
    void writeNumber(int number);

    int* getAllNumbers(int* returnSize);

    void printAllNumbers();

    void clear();

    bool isInteger(const string& s);
};
