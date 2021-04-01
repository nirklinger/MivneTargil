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

void reportTimes(steady_clock::time_point start, steady_clock::time_point end, ofstream& myFile) {
    double time_taken =
        duration_cast<nanoseconds>(end - start).count();
    time_taken *= 1e-9;    
    myFile << "Time taken by function <name-of-fun> is : " << fixed
        << time_taken << setprecision(9);
    myFile << " sec" << endl;
}

int* getNumbers(int size) {
    int* numbers = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> numbers[i];

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
    int n, i;
    cin >> n;
    cin >> i;

    cout << "numbers: " << n << " index: " << i << endl;

    int* numbers = getNumbers(n);

    ofstream myFile("Measure.txt"); // The name of the file

    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cout << Find::getNumberSizeByIndexInsertion(i, n, numbers);
    auto end = high_resolution_clock::now();        
    reportTimes(start, end, myFile);

    start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cout << Find::getNumberSizeByIndexSelection(i, n, numbers);
    end = high_resolution_clock::now();
    
    myFile.close();
}
