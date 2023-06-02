#include <iostream>
#include <fstream>
#include "BinaryFile.h"

using namespace std;
string BinaryFile::address = "storage_file";


void BinaryFile::writeNumber(int number) {
    ofstream file(address, ios::binary | ios::app);
    if(!file.is_open()){
        throw FailedOpenFileException();
    }
    file.write((char*)&number, sizeof(number));
    file.close();
}

int* BinaryFile::getAllNumbers(int* returnSize){
    int size = 0;
    int buf = 0;
    ifstream file(address, ios::binary);
    if(!file.is_open()){
        throw FailedOpenFileException();
    }
    while(!file.eof()){
        file.read((char*)&buf, sizeof(buf));
        if(file.eof()) break;
        size++;
    }
    file.clear();
    file.seekg(0);

    *returnSize = size;
    int* arr = new int[size];
    size = 0;
    while(!file.eof()){
        file.read((char*)&buf, sizeof(buf));
        if(file.eof()) break;
        arr[size] = buf;
        size++;
    }
    file.close();
    return arr;
}

void BinaryFile::printAllNumbers() {
    ifstream file(address, ios::binary);
    if(!file.is_open()){
        throw FailedOpenFileException();
    }
    int buf = 0;
    while (!file.eof()) {
        file.read((char*)&buf, sizeof(buf));
        if (file.eof()) {
            break;
        }
        cout << left << setw(5) << buf << "\t";
    }
    file.close();
}

void BinaryFile::clear() {
    ofstream file(address, ios::binary);
    if(!file.is_open()){
        throw FailedOpenFileException();
    }
    file.close();
}

bool BinaryFile::isInteger(const string& s) {
    istringstream iss(s);
    int value;
    iss >> noskipws >> value;
    return iss.eof() && !iss.fail();
}


