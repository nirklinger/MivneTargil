﻿#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "UserInput.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ofstream;	//write
using std::ifstream;	//read
using std::ios_base;



int main() {
	bool shouldContinue = true;
	UserInput inputData;
	inputData.getInputFromUser();
	shouldContinue = inputData.isKeyboardDataValid();
	if (shouldContinue) {
		ifstream myInputFile(inputData.getInputFileName(), ios_base::in);
		ofstream myOutputFile(inputData.getOutputFileName(), ios_base::out);
		int* arr;
		arr = new int[inputData.getN()];
		inputData.fillArrFromFile(arr, myInputFile);
		shouldContinue = inputData.isFileDataValid();
		//if (!shouldContinue) {}
		//return 1;
		//inputData.emptyArrToFile(arr, inputData.getN(), myOutputFile);   PRINTING TO FILE
	}

	return 0;
}