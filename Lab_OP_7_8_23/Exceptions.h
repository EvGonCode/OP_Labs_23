#include <iostream>

using namespace std;

class WrongInputException: public exception{
public:
    const char *what() {
        return "Wrong data entered, only Integer allowed";
    }
};

class FailedOpenFileException: public exception{
public:
    const char *what() {
        return "Can't open file";
    }
};

class PositiveNotFoundException: public exception{
public:
    const char *what() {
        return "No positiv data";
    }
};
