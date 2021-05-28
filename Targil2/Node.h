#ifndef _NODE_H_
#define _NODE_H_
class Node {
	int size;
	int currentIndex;
	int* arr;	
public: 
	Node(int* _arr, int _size);
	Node();
	bool operator <(const Node& other) const;
	bool operator >(const Node& other) const;
	bool operator <=(const Node& other) const;
	int getKey() const { return arr[currentIndex]; }
	bool canAdvance();
	void advance();
};

#endif