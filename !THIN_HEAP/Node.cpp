#include "Node.h"
bool Node::isThin() {
	if (rank == 0)
		return child;
	return rank != child->rank + 1;
}

Node::Node(int x) {
	key = x;
	rank = 0;
	child = right = left = nullptr;
}

