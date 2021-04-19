#ifndef _FIND_H_
#define _FIND_H_

class Find {
	static void insertionSort(double numbers[], int size);
	static void bubbleSort(double numbers[], int indexStart, int indexEnd);
	static void swap(double* num1, double* num2);
	static void swap(int& num1, int& num2);
	static int partition(double numbers[], int left, int right);
	static int partition(double numbers[], int size);
	static int selection(double numbers[], int left, int right, int index);
public:
	static double getNumberSizeByIndexInsertion(int index, int size, double* numbers);
	static double getNumberSizeByIndexSelection(int index, int size, double* numbers);
	static double getNumberSizeByIndexFifthAlgo(int index, int size, double* numbers);
	static double getNumberSizeByIndexFifthAlgo(double* numbers, int left, int right, int index);
};
#endif
