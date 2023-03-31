#include <iostream>
#include "Header.h"

using namespace std;

Text::~Text() {
	delete[] text;
}

Text::Text(const Text& obj) {
	text = new string[MAX_SIZE];

	textSize = obj.textSize;
	for (int i = 0; i < textSize; i++) {
		text[i] = obj.text[i];
	}
}

void Text::addString() { 
	if (textSize >= MAX_SIZE) {
		cout << "У цьому тексті не залишилося місця для нових рядків";
		return;
	}

	string str;
	cout << "Введіть рядок" << endl;
	cin.ignore();
	getline(cin, str);

	text[textSize] = str;
	++textSize;
}

const void Text::printText() {
	if (textSize == 0) return;

	for (int i = 0; i < textSize-1; i++) {
		cout << text[i] << endl;
	}
	cout << text[textSize - 1];
}

const int  Text::getSize() {
	return textSize;
}

const int  Text::countStringWithSize(int size) {
	if (textSize == 0) return 0;
	int counter = 0;

	for (int i = 0; i < textSize; i++) {
		if (text[i].size() == size) {
			++counter;
		}
	}

	return counter;
}

Text* requestTextAmount(int& listSize) {
	int i;
	cout << "Введіть кількість текстів: "; cin >> i; cout << endl;
	Text* txts = new Text[i];
	listSize = i;
	return txts;
}

void requestData(Text* list, int size) {
	string str;
	string answer;
	for (int i = 0; i < size; i++) {
		cout << "Введення рядків у текст номер: " << (i + 1) << endl;
		while (1) {
			list[i].addString();
			cout << "Продовжити введення? (так/ні): ";
			cin >> answer; cout << endl;
			if (answer == "ні" or answer == "Ні") break;
		}
	}
}

Text getTextWithMostStrings(Text* list, int size, int length) {
	int answer = -1;
	for (int i = 0; i < size; i++) {
		int counter = list[i].countStringWithSize(length);
		if (counter != 0) {
			if (answer == -1) {
				answer = i;
			}
			else {
				if (list[answer].countStringWithSize(length) < counter) {
					answer = i;
				}
			}
		}
	}

	return list[answer];
}

bool isStringPresent(Text* list, int size, int length) {
	for (int i = 0; i < size; i++) {
		if (list[i].countStringWithSize(length) != 0) {
			return true;
		}
	}
	return false;
}