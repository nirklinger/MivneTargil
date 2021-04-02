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

        for (int j = i+1; j < size; j++) {
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

double Find::getNumberSizeByIndexInsertion(int index, int size, double* numbers) {
    insertionSort(numbers, size);
    return numbers[index];
}

double Find::getNumberSizeByIndexSelection(int index, int size, double* numbers) {
    selectionSort(numbers, size);
    return numbers[index];
}