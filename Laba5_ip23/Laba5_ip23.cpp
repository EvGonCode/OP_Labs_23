#include "Header.h"

using namespace std;


int main()
{
	int n = -1;
	while (1) {
		cout << "Enter amount of iterations or 0 to stop: "; cin >> n;
		if (n < 0 or n == 0) break;
		generateAndCalculate(n);
	}
}
