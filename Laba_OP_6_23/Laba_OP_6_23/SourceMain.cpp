#include "Header.h"
using namespace std;

void initiateInputLists(string& input,
	string& type,
	string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList) {
	cout << "Enter values of the same type or exit to stop: " << endl;
	while (true) {										// filling one of the lists
		getline(cin, input);
		if (input == "Exit" or input == "exit") {
			break;
		}
		type = getVariableType(input);

		if (sList.isEmpty() and iList.isEmpty() and fList.isEmpty()) {
			if (type == "int") {
				iList.push_back(stoi(input));
				mainType = "int";
			}
			else if (type == "float") {
				fList.push_back(stof(input));
				mainType = "float";
			}
			else {
				sList.push_back(input);
				mainType = "string";
			}
			continue;
		}

		if (mainType != type) {
			cout << "You entered variable of wrong type!\nYour type is " << mainType
				<< ", but you entered " << type
				<< ", element won't be added to the list." << endl;
			continue;
		}

		if (mainType == "string") {
			sList.push_back(input);
		}
		else if (mainType == "int") {
			iList.push_back(stoi(input));
		}
		else {
			fList.push_back(stof(input));
		}
	}
}

void printOneList(string &mainType,
	CircularLinkedList<string> &sList,
	CircularLinkedList<int> &iList,
	CircularLinkedList<float> &fList) {
	if (mainType == "int") {
		iList.printList();
	}
	else if (mainType == "float") {
		fList.printList();
	}
	else {
		sList.printList();
	}
}

void testDeletingElements(string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList) {
	int id;
	while (true) {
		cout << "Write id of element to delete or -1 to stop: ";
		cin >> id;
		if (id == -1) { break; }
		try {
			if (mainType == "int") {
				iList.deleteElement(id);
			}
			else if (mainType == "float") {
				fList.deleteElement(id);
			}
			else {
				sList.deleteElement(id);
			}

			cout << "Changed list: " << endl;
			printOneList(mainType, sList, iList, fList);
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
	}
}

void testDeletingList(string& mainType,
	CircularLinkedList<string>& sList,
	CircularLinkedList<int>& iList,
	CircularLinkedList<float>& fList) {
	if (mainType == "int") {
		iList.clear();
		iList.printList();
	}
	else if (mainType == "float") {
		fList.clear();
		fList.printList();
	}
	else {
		sList.clear();
		sList.printList();
	}
}


bool isInteger(const string& s) {
	istringstream iss(s);
	int value;
	iss >> noskipws >> value;
	return iss.eof() && !iss.fail();
}

bool isFloat(const string& s) {
	istringstream iss(s);
	float value;
	iss >> noskipws >> value;
	return iss.eof() && !iss.fail();
}


string getVariableType(const string& var) {
	if (isInteger(var)) {
		return "int";
	}
	else if (isFloat(var)) {
		return "float";
	}
	else {
		return "string";
	}
}
