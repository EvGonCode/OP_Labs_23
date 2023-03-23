#include "Header.h"

using namespace std;

void writePERSONToFile(fstream* file, PERSON person) {
	
	writeString(file, person.Name);
	writeString(file, person.SName);
	writeString(file, person.FName);
	writeString(file, person.sex);
	writeString(file, person.rank);
	file->write((char*)&(person.day), sizeof(person.day));
	file->write((char*)&(person.month), sizeof(person.month));
	file->write((char*)&(person.year), sizeof(person.year));
}

void printPERSON(PERSON person) {
	cout << person.Name << " " << person.SName << " " << person.FName <<
		" " << person.sex << " " << person.rank << " " << person.day << "." << person.month << "."
		<< person.year << endl;
}

void printFile(string filename){
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Can't open file\n";
        return;
    }
	int size = getFileSize(&file);
	while (file.tellg() < size) {
		PERSON person;
		person.Name = readString(&file);
		person.SName = readString(&file);
		person.FName = readString(&file);
		person.sex = readString(&file);
		person.rank = readString(&file);
		file.read((char*)&(person.day), sizeof(person.day));
		file.read((char*)&(person.month), sizeof(person.month));
		file.read((char*)&(person.year), sizeof(person.year));
		printPERSON(person);
	}
	file.close();
}

int getFileSize(ifstream* file) {
	int current_ptr = file->tellg();
	file->seekg(0, ios::end);
	int size = file->tellg();
	file->seekg(current_ptr, ios::beg);
	return size;
}

string readString(ifstream* file) {
	int size;
	file->read((char*)&size, sizeof(size));
	char* buf = new char[size + 1];
	buf[size] = '\0';
	file->read(buf, size);
	string str = buf;
	delete[] buf;
	return str;
}

void writeString(fstream* file, string str) {
	int size = str.size();
	file->write((char*)&size, sizeof(size));
	file->write(str.c_str(), size);
}

void requestEnteringData(fstream* file) {
	time_t now = time(nullptr);
	tm* local_time = localtime(&now);
	int year = local_time->tm_year + 1900;
	cout << "Enter employee data or Stop to stop" << endl << endl; 
	while (1) {
		PERSON person;
		cout << "Enter Name: "; cin >> person.Name;
		if (person.Name == "Stop" or person.Name == "stop") {
			break;
		}
		cout << "Enter Second Name: "; cin >> person.SName;
		cout << "Enter Father Name: "; cin >> person.FName;
		cout << "Enter sex(male/female): "; cin >> person.sex;
		cout << "Enter rank: "; cin >> person.rank;
		while (true) {
			cout << "Enter year of birth: "; cin >> person.year;
			if (person.year > year) {
				cout << "Enter proper year" << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "Enter month of birth: "; cin >> person.month;
			if (person.month > 12) {
				cout << "Enter proper month" << endl;
			}
			else {
				break;
			}
		}
		while (true) {
			cout << "Enter day of birth: "; cin >> person.day;
			if (person.day > 31 or (person.month == 2 and person.day > 28)) {
				cout << "Enter proper day" << endl;
			}
			else {
				break;
			}
		}
		writePERSONToFile(file, person);
		cout << "Saved employee: "; printPERSON(person); cout << endl;
	}
}

void relocateOldToNewFile(string oldFilename, string newFileName, bool append) {
	ifstream oldFile(oldFilename, ios::binary);
	fstream newFile(newFileName, ios::binary | ios::out);
	vector<PERSON> strongEmpoyees;
	int size = getFileSize(&oldFile);
	while (oldFile.tellg() < size) {
		PERSON person;
		person.Name = readString(&oldFile);
		person.SName = readString(&oldFile);
		person.FName = readString(&oldFile);
		person.sex = readString(&oldFile);
		person.rank = readString(&oldFile);
		oldFile.read((char*)&(person.day), sizeof(person.day));
		oldFile.read((char*)&(person.month), sizeof(person.month));
		oldFile.read((char*)&(person.year), sizeof(person.year));
		if (isEmployeeOld(person)) {
			writePERSONToFile(&newFile, person);
		}
		else if (isEmployeeNearOld(person)) {
			writePERSONToFile(&newFile, person);
			strongEmpoyees.push_back(person);
		}
		else {
			strongEmpoyees.push_back(person);
		}
	}
	oldFile.close();
	newFile.close();
	fstream oldFileWriter(oldFilename, ios::binary | ios::out);
	for (int i = 0; i < strongEmpoyees.size(); i++) {
		writePERSONToFile(&oldFileWriter, strongEmpoyees[i]);
	}
	oldFileWriter.close();
}

bool isEmployeeOld(PERSON person) {
	time_t now = time(nullptr);
	tm* local_time = localtime(&now);
	int day = local_time->tm_mday;
	int month = local_time->tm_mon + 1;
	int year = local_time->tm_year + 1900;

	if (person.sex == "male") {
		if (year > person.year + 70) {
			return true;
		}
		else if (year == (person.year + 70) and month > person.month) {
			return true;
		}
		else if (year == (person.year + 70) and month == person.month and day >= person.day) {
			return true;
		}
		else {
			return false;
		}
	}else if (person.sex == "female") {
		if (year > person.year + 65) {
			return true;
		}
		else if (year == (person.year + 65) and month > person.month) {
			return true;
		}
		else if (year == (person.year + 65) and month == person.month and day >= person.day) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool isEmployeeNearOld(PERSON person) {
	time_t now = time(nullptr);
	tm* local_time = localtime(&now);
	int year = local_time->tm_year + 1900;
	if (person.sex == "male") {
		if (year == person.year + 70) {
			return true;
		}
	}else if (person.sex == "female") {
		if (year == person.year + 65) {
			return true;
		}
	}

	return false;
}
