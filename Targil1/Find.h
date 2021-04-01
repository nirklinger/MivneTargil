#ifndef _FIND_H_
#define _FIND_H_

class Find {
	static void insertionSort(int arr[], int n);
public:
	static int getNumberSizeByIndexInsertion(int index, int size, int* numbers);
	static int getNumberSizeByIndexSelection(int index, int size, int* numbers);
};
#endif
