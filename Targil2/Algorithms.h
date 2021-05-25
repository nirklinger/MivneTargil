#ifndef AlgorithmsH
#define AlgorithmsH

#include <stdio.h>

class Algorithms {
	//

public:
	void swap(int& a, int& b);
	int partition(int arr[], int low, int high);
	void quickSort(int arr[], int low, int high);

};

#endif