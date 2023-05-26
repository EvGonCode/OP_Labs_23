#include "Header.h"
using namespace std;

int main()
{
	string input;
	string type;
	string mainType;
	CircularLinkedList<string> sList;		//
	CircularLinkedList<int> iList;			// used based on users choise
	CircularLinkedList<float> fList;		//
	try {

		initiateInputLists(input, type, mainType, sList, iList, fList);

		cout << "Generated list: " << endl;
		printOneList(mainType, sList, iList, fList);
		
		testChangingElements(mainType, sList, iList, fList);

		testDeletingElements(mainType, sList, iList, fList);

		cout << "Deleting list...\n";
		testDeletingList(mainType, sList, iList, fList);

	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}