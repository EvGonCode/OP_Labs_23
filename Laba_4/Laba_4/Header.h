#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Time{
	short h;
	short m;
	short s;

public:
	Time(short hours, short mins, short sec): h(hours), m(mins), s(sec) {}
	Time() :h(0), m(0), s(0) {}
	Time(const Time& t);
	const short getH();
	const short getM();
	const short getS();
	const Time getTimeTillMidnight();
	const void printTime();
	Time operator+=(short min);
	Time operator-(Time t);
};

void requestTime(short& hours, short& mins, short& secs);