#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	short h, m, s;
	requestTime(h, m, s);
	Time T1(h,m,s);
	Time T2 = Time();
	Time T3(T1);
	cout << "T1: "; T1.printTime(); cout << endl;
	cout << "T2: "; T2.printTime(); cout << endl;
	cout << "T3: "; T3.printTime(); cout << endl; cout << endl;


	T1 += 17;
	T2 += 34;
	Time T4 = T1 - T2;
	cout << "T1: "; T1.printTime(); cout << endl;
	cout << "T2: "; T2.printTime(); cout << endl;
	cout << "Time between T1 and T2: ";
	T4.printTime(); cout << endl;
	cout << "Time till midnight from T3:";
	Time T5 = T3.getTimeTillMidnight();
	T5.printTime();
}
