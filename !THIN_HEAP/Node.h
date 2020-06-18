#pragma once
class Node
{
public:
	int key;
	int rank;
	Node* child;
	Node* right;
	Node* left;

	Node(int);
	bool isThin();

};

