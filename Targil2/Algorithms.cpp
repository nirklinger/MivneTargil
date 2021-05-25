#include "Algorithms.h"

void Algorithms::swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int Algorithms::partition(int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void Algorithms::quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int** Algorithms::splitToK(int arr[], const int size, const int k) {
    int arrSize = size / k;
    
    int** arrs = new int*[k];
    int leftOver = size % k;

    for (int i = 0; i < k; i++) {        
        int currArrSize = arrSize;

        if (i < leftOver) {
            currArrSize++;
        }

        arrs[i] = new int[currArrSize]();
    }

    for (int i = 0; i < size; i++) {
        int arrayNumber = i % k;
        int arrayIndex = i / k;
        arrs[arrayNumber][arrayIndex] = arr[i];
    }

    return arrs;
}

void Algorithms::kWayMerge(int arr[], const int size, const int k) {
    if (size <= k) {
        quickSort(arr, 0, size);
        return;
    }

    int** smallArrs = splitToK(arr, size, k);

    int leftOver = size % k;

    for (int i = 0; i < k; i++) {
        int currArrSize = size/k;

        if (i < leftOver) {
            currArrSize++;
        }
        kWayMerge(smallArrs[i], currArrSize, k);
    }

    heapMerge(arr, smallArrs, size, k);
    freeSmallArrays(smallArrs, k);
}

void Algorithms::heapMerge(int mergedArr[], int* smallArrs[], const int size, const int k) {
    MinHeap<Node> minHeap(k);    
    int leftOver = size % k;

    for (int i = 0; i < k; i++) {
        int currArrSize = size / k;

        if (i < leftOver) {
            currArrSize++;
        }

        minHeap.insert(Node(smallArrs[i], currArrSize));
    }

    for (int i = 0; i < size; i++) {
        Node* currMin = minHeap.getMin();
        mergedArr[i] = currMin->getKey();
        bool hasNext = currMin->advance();
        
        if (hasNext) {
            minHeap.heapifyDown(0);            
        }
        else {
            minHeap.deleteMin();
        }
    }
}

void Algorithms::freeSmallArrays(int** smallArrs, int size) {
    for (int i = 0; i < size; i++) {
        delete[] smallArrs[i];
    }

    delete[] smallArrs;
}