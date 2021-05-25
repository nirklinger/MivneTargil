//
#ifndef UserInputH
#define UserInputH

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;


class UserInput {
	//Data members
	int n, k, actualInts = 0;
	std::string inputFile, outputFile;


public:
	const int& getN() { return n; }
	const int& getK() { return k; }
	const string& getInputFileName() { return inputFile; }
	const string& getOutputFileName() { return outputFile; }
	void getInputFromUser();
	bool isKeyboardDataValid();
	void fillArrFromFile(int* arrey, ifstream& myInputFile);
	void emptyArrToFile(int* arrey, const int& size, ofstream& myOutputFile);
	bool isNumber(const string& s);
	bool isDigit(const char& ch);
	bool isFileDataValid();
	void checkArr(int* arrey);


	//void printInputForTest();
};

#endif