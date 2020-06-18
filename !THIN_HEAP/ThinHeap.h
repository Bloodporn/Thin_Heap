#pragma once
#include"Node.h"
class ThinHeap
{
public:
	Node* first, * last;
	ThinHeap();
	void insert(int);
	void insert(Node*);
	void printRoots();
	int peekMin();
	static ThinHeap* merge(ThinHeap* h1, ThinHeap* h2);
	Node* extractMin();
	static void decreaseKey(ThinHeap* h ,Node* x,int);
	void deleteKey(Node* x);
};

