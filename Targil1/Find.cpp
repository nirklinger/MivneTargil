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

void Find::selectionSort(double numbers[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;

		for (int j = i + 1; j < size; j++) {
			if (numbers[j] < numbers[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			numbers[i] += numbers[minIndex];
			numbers[minIndex] = numbers[i] - numbers[minIndex];
			numbers[i] = numbers[i] - numbers[minIndex];
		}
	}
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
	return numbers[index];
}

double Find::getNumberSizeByIndexSelection(int index, int size, double* numbers) {
	selectionSort(numbers, size);
	return numbers[index];
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
		double* p = numbers + pivotIndex + 1;
		return getNumberSizeByIndexFifthAlgo(index - pivotIndex, size - pivotIndex - 1, p);
	}
	else return numbers[pivotIndex];
}

int Find::partition(double numbers[], int size) {
	int i, pointer = size - 1, pivot = 0;
	for (i = 0; i < size; i++) {
		if (numbers[pivot] > numbers[pointer])
		{
			swap(&numbers[pivot], &numbers[pointer]);
			swap(pivot, pointer);
		}
		if (pivot > pointer) {
			pointer++;
		}
		else {
			if (pointer < pivot)
				pointer--;
			else return pivot;
		}
	}
}

int Find::findHatzion(double numbers[], int size) {
	if (size == 1)
		return numbers[size - 1];


}