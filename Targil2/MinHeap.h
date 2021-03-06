#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_
template<class T>
class MinHeap {
	T* heapArr; // pointer to array of elements in heap
	int capacity; // maximum possible size of min heap
	int size; // Current number of elements in min heap
	int left(const int index) const;
	int right(const int index) const;
	int parent(const int index) const;
	void heapifyUp(const int index);
	bool isLeaf(const int index) const;
public: 
	void heapifyDown(const int index);
	void insert(T element);
	T* deleteMin();
	T* getMin();
	MinHeap(int capacity);
	MinHeap();
	~MinHeap();
};

template<class T>
void swap(T& t1, T& t2) {
	T temp = t2;
	t2 = t1;
	t1 = temp;
}

template<class T>
MinHeap<T>::MinHeap(int cap) {
	capacity = cap;
	heapArr = new T[cap];
	size = 0;
}

template<class T>
MinHeap<T>::MinHeap() {
	capacity = 0;
	heapArr = nullptr;
	size = 0;
}

template <class T>
MinHeap<T>::~MinHeap() {
	delete[] heapArr;
}

template<class T>
int MinHeap<T>::left(const int index) const {
	return index * 2 + 1;
}

template<class T>
int MinHeap<T>::right(const int index) const {
	return index * 2 + 2;
}

template<class T>
int MinHeap<T>::parent(const int index) const {
	return (index - 1) / 2;
}

template<class T>
bool MinHeap<T>::isLeaf(const int index) const {
	return (index >= size / 2 && index <= size - 1);
}

template<class T>
void MinHeap<T>::heapifyUp(int i) {
	while (i != 0 && heapArr[parent(i)] > heapArr[i])
	{
		swap(heapArr[i], heapArr[parent(i)]);
		i = parent(i);
	}
}

template<class T>
void MinHeap<T>::heapifyDown(const int index) {

	// if the node at index has children
	if (!isLeaf(index)) {

		// get indices of children
		int leftChildIndex = left(index);
		int rightChildIndex = right(index);
		int smallestIndex = index; // start out smallest index at parent index

		// if the left child > parent
		if (leftChildIndex < size && heapArr[leftChildIndex] < heapArr[smallestIndex]) {
			// reassign smallest index to left child index
			smallestIndex = leftChildIndex;
		}

		// if the right child > element at smallest index (either parent or left child)
		if (rightChildIndex < size && heapArr[rightChildIndex] <= heapArr[smallestIndex]) {
			// reassign smallest index to right child index
			smallestIndex = rightChildIndex;
		}

		// if the smallest index is not the parent index
		if (smallestIndex != index) {
			// swap
			swap(heapArr[index], heapArr[smallestIndex]);
			// recursively move down the heap
			heapifyDown(smallestIndex);
		}
	}
}

template<class T>
void MinHeap<T>::insert(T element) {
	if (size >= capacity) {
		return;
	}

	heapArr[size] = element;
	heapifyUp(size);
	size++;
}

template<class T>
T* MinHeap<T>::deleteMin() {
	if (size < 1) return nullptr;

	// get min and last element
	T& min = heapArr[0];	
	// reassign first element to the last element
	size--;
	if (size) {
		T& end = heapArr[size];
		heapArr[0] = end;
		// heapify down until element is back in its correct position
		heapifyDown(0);
	}

	// return the min
	return &min;
}

template<class T>
T* MinHeap<T>::getMin() {
	if (size < 1)
		return nullptr;

	return &(heapArr[0]);
}

#endif