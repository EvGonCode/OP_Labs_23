#include <iostream>
#include "Header.h"

using namespace std;

Time::Time(const Time& t) {
	h = t.h;
	m = t.m;
	s = t.s;
}

const short  Time::getH() {
	return h;
}

const short  Time::getM() {
	return m;
}

const short  Time::getS() {
	return s;
}

const Time Time::getTimeTillMidnight() {
	Time time(23 - h, 59 - m, 60 - s);
		return time;
}

const void Time::printTime() {
	printf("%2d:%2d:%2d", h,m,s);
}

Time Time::operator+=(short min) {
	if (min >= 60) {
		h += min / 60;
		min = min % 60;
	}
	m += min;
	if (m >= 60) {
		++h;
		m -= 60;
	}
	h = h % 24;
	return *this;
}

Time Time::operator-(Time t) {
	int sec1 = h * 60 * 60 + m * 60 + s;
	int sec2 = t.h * 60 * 60 + t.m * 60 + t.s;
	if (sec1 > sec2) sec1 -= sec2;
	else { sec1 = sec2 - sec1; }
	short sec;
	short min;
	short hour;
	hour = sec1 / 60 / 60;
	sec1 -= hour * 60 * 60;
	min = sec1 / 60;
	sec = sec1 % 60;
	Time time(hour, min, sec);
	return time;
}

void requestTime(short& hours, short& mins, short& secs) {
	while (1) {
		cout << "Enter hours: "; cin >> hours;
		if (hours <= 23) {
			break;
		}
		cout << "Enter proper data!" << endl;
	}
	while (1) {
		cout << "Enter minutes: "; cin >> mins;
		if (mins <= 59) {
			break;
		}
		cout << "Enter proper data!" << endl;
	}
	while (1) {
		cout << "Enter seconds: "; cin >> secs;
		if (secs <= 59) {
			break;
		}
		cout << "Enter proper data!" << endl;
	}
	cout << endl;
}