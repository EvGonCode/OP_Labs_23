#include "Header.h"

using namespace std;

int main()
{
    string filename = "myFile";
    string newFilename = "newFile";
    string answer = "N";
    bool append = false;
    fstream file;
    do {
        if (answer == "Y") {
            append = true;
            file.open(filename, ios::binary | ios::out | ios::app);
        }
        else {
            file.open(filename, ios::binary | ios::out);
        }
        requestEnteringData(&file);
        file.close();

        cout << "Created file: " << endl;
        printFile(filename);

        relocateOldToNewFile(filename, newFilename, append);

        cout << "Changed created file: " << endl;
        printFile(filename);

        cout << "Created new file: " << endl;
        printFile(newFilename);
        cout << "Enter more data?(Y/N)"; cin >> answer;
        file.close();
    } while (answer == "Y");
}
