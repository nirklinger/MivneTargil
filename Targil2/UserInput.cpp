#include "UserInput.h"

void UserInput::getInputFromUser() {
	cout << "Enter the number n" << endl;
	cin >> n;
	cout << "Enter the number k" << endl;
	cin >> k;
	cout << "Enter the name of the input file" << endl;
	cin >> inputFile;
	cout << "Enter the name of the input file" << endl;
	cin >> outputFile;
}

bool UserInput::isKeyboardDataValid() {
	if ((k < 1) || (n < 1)) {
		cout << "wrong input" << endl;
		return false;
	}
}

void UserInput::fillArrFromFile(int* arrey, ifstream& myInputFile) {
	string lineFromFile;
	while (getline(myInputFile, lineFromFile)) {
		if (isNumber(lineFromFile)) {
			arrey[actualInts] = stoi(lineFromFile);
			actualInts++;
		}
		else break;
	}
	return;
}

void emptyArrToFile(int* arrey, const int& size, ofstream& myOutputFile) {
	for (int i = 0; i < size; ++i) {
		myOutputFile << arrey[i] << endl;
	}
}

bool UserInput::isNumber(const string& s) {
	for (int i = 0; i < s.length(); ++i) {
		if ((isDigit(s[i]) == false)) {
			if ((i == 0) && (s[0] != '-'))
				return false;
			else if (i != 0) return false;
		}
	}
	return true;
}

bool UserInput::isDigit(const char& ch) {
	if ((ch >= '0') && (ch <= '9'))
		return true;
	else return false;
}

bool UserInput::isFileDataValid() {
	if (n > actualInts)
		return false;
}

void UserInput::checkArr(int* arrey) {
	for (int i = 0; i < n; ++i) {
		cout << arrey[i] << endl;
	}
}

