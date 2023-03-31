#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	int listSize = 0;
	Text* textList = requestTextAmount(listSize);
	requestData(textList, listSize);

	int length;
	string answer = "ні";

	do {
		cout << "Введіть довжину рядків які хочете порахувати: "; cin >> length; cout << endl;
		if (isStringPresent(textList, listSize, length)) {
			cout << "Текст із найбільшою кількістю рядків заданої довжини: " << endl;
			getTextWithMostStrings(textList, listSize, length).printText();
			cout << endl;
		}
		else {
			cout << "Текстів із рядками такої довжини не знайдено" << endl;
		}
		cout << "Хочете повторити пошук? так/ні" << endl; cin >> answer; cout << endl;
	} while (answer == "Так" or answer == "так");
}

