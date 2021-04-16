// Targil1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "Find.h"

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ios_base;
using std::setprecision;
using std::fixed;
using namespace std::chrono;

double* copyArray(const double numbers[], int size) {
    double* copy = new double[size];
    
    for (int i = 0; i < size; i++) {
        copy[i] = numbers[i];
    }

    return copy;
}

void reportTimes(const char functionName[], steady_clock::time_point start, steady_clock::time_point end, ofstream& myFile) {
    double time_taken =
        duration_cast<nanoseconds>(end - start).count();
    time_taken *= 1e-9;    
    myFile << "Time taken by function " << functionName << " is : " << fixed
        << time_taken << setprecision(9);
    myFile << " sec" << endl;
}

double* getNumbers(int size) {
    double* numbers = new double[size];

    for (int index = 0; index < size; index++) {
        cin >> numbers[index];

        if (!cin)
        {
            cout << "Wrong input";
            delete numbers;
            exit(1);
        }
    }

    return numbers;
}

int main()
{
    int size, index;
    cin >> size;
    cin >> index;

    cout << "numbers: " << size << " index: " << index << endl;

    double* numbers = getNumbers(size);

    ofstream myFile("Measure.txt"); // The name of the file

    double* copyNumbers = copyArray(numbers, size);
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    printf("%.4f\n", Find::getNumberSizeByIndexInsertion(index, size, copyNumbers));
    auto end = high_resolution_clock::now();        
    reportTimes("insertion sort", start, end, myFile);
    delete copyNumbers;

    copyNumbers = copyArray(numbers, size);
    start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    printf("%.4f\n", Find::getNumberSizeByIndexSelection(index, size, copyNumbers));
    end = high_resolution_clock::now();
    reportTimes("selection sort", start, end, myFile);
    delete copyNumbers;

    start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
	printf("%.4f\n", Find::getNumberSizeByIndexFifthAlgo(index, size, numbers));
    end = high_resolution_clock::now();
    reportTimes("selection sort", start, end, myFile);
    delete numbers;

    myFile.close();
}
