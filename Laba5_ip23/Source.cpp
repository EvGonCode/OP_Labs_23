#include "Header.h"

using namespace std;

void TPair::incrementA() {
	++a;
}
void TPair::decrementA() {
	--a;
}
void TPair::incrementB() {
	++b;
}
void TPair::decrementB() {
	--b;
}
int TPair::getA() {
	return a;
}
int TPair::getB() {
	return b;
}

void TTime::printIt() {
	cout << "time: " << setw(2) << getA() << ":" << setw(2) << getB();
}

void TMoney::printIt() {
	cout << "money: " << setw(3) << getA() << " UAH " << setw(2) << getB() << " Cents";
}


void generateAndCalculate(int n) {
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		TTime time(rand() % 8 + 1,
				   rand() % 59 + 0); //����������� ������� ���� �� ��������� 8 ����� 59 ������
		TMoney money(rand() % 161 + 40,
					 rand() % 100 + 0); // ̳�������� �������� ����� � ������ ������ �� 2023 �� 40���/���
		time.printIt(); cout << "  X  ";
		money.printIt(); cout << "  =  ";
		printPayment(&time, &money); cout << " Payment" << endl;
	}
}

void printPayment(TPair* time, TPair* money) {
	double payment =time->getA() * money->getA() +
		(time->getA() * money->getB() / (double)100) +
		(time->getB() * money->getA() / (double)60) +
		((time->getB() * money->getB() / (double)60) / (double)100);
	printf("%6.2f UAH", payment);
}