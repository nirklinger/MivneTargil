#include "Find.h"

void Find::insertionSort(int arr[], int n)
{
    int pivot, i, j;
    for (i = 1; i < n; i++)
    {
        pivot = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > pivot)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = pivot;
    }
}

int Find::getNumberSizeByIndexInsertion(int i, int size, int* numbers) {
    insertionSort(numbers, size);
    return numbers[i];
}

int getNumberSizeByIndexSelection(int index, int size, int* numbers) {
    
}