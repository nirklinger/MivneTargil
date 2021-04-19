#include "Find.h"

void Find::insertionSort(double numbers[], int size)
{
	double pivot;
	int i, j;
	for (i = 1; i < size; i++)
	{
		pivot = numbers[i];
		j = i - 1;

		while (j >= 0 && numbers[j] > pivot)
		{
			numbers[j + 1] = numbers[j];
			j = j - 1;
		}
		numbers[j + 1] = pivot;
	}
}

int Find::selection(double numbers[], int left, int right, int index) {
	int pivot, leftPart;
	pivot = partition(numbers, left, right);
	leftPart = pivot - left + 1;
	if (index == leftPart)
		return pivot;
	if (index < leftPart)
		return selection(numbers, left, pivot - 1, index);
	else return selection(numbers, pivot + 1, right, index - leftPart);
}

void Find::swap(double* num1, double* num2)
{
	double temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void Find::swap(int& num1, int& num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void Find::bubbleSort(double numbers[], int indexStart, int indexEnd)
{
	int i, j;
	for (i = 0; i < indexEnd-indexStart; i++)
		for (j = indexStart; j < indexEnd - i; j++)
			if (numbers[j] > numbers[j + 1])
				swap(&numbers[j], &numbers[j + 1]);
}

double Find::getNumberSizeByIndexInsertion(int index, int size, double* numbers) {
	insertionSort(numbers, size);
	return numbers[index-1];
}

double Find::getNumberSizeByIndexSelection(int index, int size, double* numbers) {
	int selected = selection(numbers, 0, size - 1, index);
	return numbers[selected];
}

double Find::getNumberSizeByIndexFifthAlgo(int index, int size, double* numbers) {
	if (size <= 5) {
		bubbleSort(numbers, 0, size - 1);
		return numbers[index];
	}

	int i, mediansSize = size / 5 + 1;
	double* medians = new double[mediansSize];

	for (i = 0; i < size / 5; i++) {
		bubbleSort(numbers, i * 5, i * 5 + 4);
		medians[i] = numbers[i * 5 + 2];
	}

	int sizeMod = size % 5;

	if (sizeMod != 0) {
		bubbleSort(numbers, i * 5, size - 1);
		medians[mediansSize - 1] = numbers[sizeMod / 2 + i * 5];
	}
	else mediansSize--;

	double pivot = getNumberSizeByIndexFifthAlgo(mediansSize / 2, mediansSize, medians);
	delete medians;
	int pivotIndex = 0;

	while (numbers[pivotIndex] != pivot) {
		pivotIndex++;
	}

	swap(&numbers[0], &numbers[pivotIndex]);
	pivotIndex = partition(numbers, size);

	if (index < pivotIndex) {
		return getNumberSizeByIndexFifthAlgo(index, pivotIndex, numbers);
	}
	else if (index > pivotIndex) {
		double* p = numbers + pivotIndex;
		return getNumberSizeByIndexFifthAlgo(index - pivotIndex, size - pivotIndex, p);
	}
	else return numbers[pivotIndex];
}

double Find::getNumberSizeByIndexFifthAlgo(double* numbers, int left, int right, int index) {
	const int size = right - left + 1;
	if (size <= 5) {
		bubbleSort(numbers, left, right);
		return numbers[index-1];
	}

	int i, mediansSize = size / 5 + 1;
	double* medians = new double[mediansSize];

	for (i = 0; i < size / 5; i++) {
		int batchIndex = left + i * 5;
		bubbleSort(numbers, batchIndex , batchIndex + 4);
		medians[i] = numbers[batchIndex + 2];
	}

	int sizeMod = size % 5;
	
	if (sizeMod != 0) {
		int batchIndex = left + i * 5;
		bubbleSort(numbers, batchIndex, right);
		medians[mediansSize - 1] = numbers[sizeMod / 2 + batchIndex];
	}
	else mediansSize--;

	double pivot = getNumberSizeByIndexFifthAlgo(medians, 0, mediansSize-1, mediansSize/2);
	delete medians;
	int pivotIndex = 0;
	
	while (numbers[left + pivotIndex] != pivot) {
		pivotIndex++;
	}

	swap(&numbers[left], &numbers[left + pivotIndex]);
	pivotIndex = partition(numbers, left, right) - left;
	
	if ((index-1) < pivotIndex) {
		return getNumberSizeByIndexFifthAlgo(numbers, left, left + pivotIndex - 1, index);
	}
	else if ((index-1) > pivotIndex) {
		return getNumberSizeByIndexFifthAlgo(numbers, left + pivotIndex + 1, right, index-pivotIndex);
	}
	else return numbers[left + pivotIndex];
}

int Find::partition(double numbers[], int left, int right) {
	int i, pointer = right, pivot = left;
	for (i = left; i <= right; i++) {
		if (numbers[pivot] > numbers[pointer] && pivot < pointer
			|| numbers[pivot] < numbers[pointer] && pivot > pointer)
		{
			swap(&numbers[pivot], &numbers[pointer]);
			swap(pivot, pointer);
		}
		if (pivot > pointer) {
			pointer++;
		}
		else if (pointer > pivot)
			pointer--;
		else return pivot;
	}
}

int Find::partition(double numbers[], int size) {
	int i, pointer = size - 1, pivot = 0;
	for (i = 0; i < size; i++) {
		if (numbers[pivot] > numbers[pointer] && pivot < pointer
			|| numbers[pivot] < numbers[pointer] && pivot > pointer)
		{
			swap(&numbers[pivot], &numbers[pointer]);
			swap(pivot, pointer);
		}
		if (pivot > pointer) {
			pointer++;
		}
		else if (pointer > pivot)
			pointer--;
		else return pivot;
	}
}