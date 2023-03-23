#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;


struct PERSON {
    int day;
    int month;
    int year;
    string Name;
    string SName;
    string FName;
    string sex;
    string rank;
};

void printPERSON(PERSON person);
void printFile(string filename);
int getFileSize(ifstream* file);
string readString(ifstream* file);
void writeString(fstream* file, string str);
void writePERSONToFile(fstream* file, PERSON person);
void requestEnteringData(fstream* file);
void relocateOldToNewFile(string oldFilename, string newFileName, bool append);
bool isEmployeeOld(PERSON person);
bool isEmployeeNearOld(PERSON person);