#include "Node.h"

Node::Node(int* _arr, int _size) {
	size = _size;
	arr = _arr;
	currentIndex = 0;
}

Node::Node() {
	size = 0;
	arr = nullptr;
	currentIndex = 0;
}

bool Node::operator <(const Node& other) const{
	return getKey() < other.getKey();
}

bool Node::operator >(const Node& other) const {
	return getKey() > other.getKey();
}

bool Node::operator <=(const Node& other) const{
	return getKey() <= other.getKey();
}

bool Node::canAdvance() {
	if (currentIndex >= size-1) {
		return false;
	}

	return true;
}

void Node::advance() {
	currentIndex++;
}