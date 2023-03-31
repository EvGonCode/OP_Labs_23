#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <cstring>
using namespace std;

class Text {
	const static int MAX_SIZE = 255;
	int textSize;
	string *text;
public:
	Text(): textSize(0) {
		text = new string[MAX_SIZE];
	}
	Text(const Text& obj);
	~Text();
	void addString();
	const void printText();
	const int  getSize();
	const int  countStringWithSize(int size);
};

Text* requestTextAmount(int &listSize);
void requestData(Text* list, int size);
bool isStringPresent(Text* list, int size, int length);
Text getTextWithMostStrings(Text* list, int size, int length);