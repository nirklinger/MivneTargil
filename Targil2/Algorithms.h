#ifndef AlgorithmsH
#define AlgorithmsH

#include <stdio.h>
#include "Node.h"
#include "MinHeap.h"

class Algorithms {
	static void swap(int& a, int& b);
	static int partition(int arr[], int low, int high);
	static void quickSort(int arr[], int low, int high);
	static int** splitToK(int arr[], const int size, const int k);
	static void freeSmallArrays(int** smallArrs, int k);
	static void heapMerge(int mergeArr[],int* smallArrs[], const int size, const int k);
public:
	static void kWayMerge(int arr[], const int size, const int k);
};

#endif