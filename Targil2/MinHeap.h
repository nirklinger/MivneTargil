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
	T& deleteMin();
	const T& getMin();
	MinHeap(int capacity);
};

#endif