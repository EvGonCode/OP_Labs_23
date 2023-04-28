#pragma once
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;

class TPair {
protected:
	int a;
	int b;
public:
	void incrementA();
	void decrementA();
	void incrementB();
	void decrementB();
	virtual void printIt() = 0;
	int getA();
	int getB();
};

class TTime : public TPair {
public:
	void printIt() override;
	TTime(int a, int b) {
		this->a = a;
		this->b = b;
	}
};

class TMoney : public TPair {
public:
	void printIt() override;
	TMoney(int a, int b) {
		this->a = a;
		this->b = b;
	}
};

void generateAndCalculate(int n);
void printPayment(TPair* time, TPair* money);