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
	string answer = "��";

	do {
		cout << "������ ������� ����� �� ������ ����������: "; cin >> length; cout << endl;
		if (isStringPresent(textList, listSize, length)) {
			cout << "����� �� ��������� ������� ����� ������ �������: " << endl;
			getTextWithMostStrings(textList, listSize, length).printText();
			cout << endl;
		}
		else {
			cout << "������ �� ������� ���� ������� �� ��������" << endl;
		}
		cout << "������ ��������� �����? ���/��" << endl; cin >> answer; cout << endl;
	} while (answer == "���" or answer == "���");
}

