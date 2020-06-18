#include "ThinHeap.h"
#include<iostream>
const int MAX_RANK = 32;
ThinHeap::ThinHeap() {
	first = nullptr;
	last = nullptr;
	
}
void ThinHeap::insert(int x) {
	Node* temp = new Node(x);
	if (first == nullptr) {
		first = temp;
		last = temp;
	}
	else {
		if (x < first->key) {
			temp->right = first;
			first = temp;
		}
		else {
			last->right = temp;
			last = temp;
		}
	}
}
void ThinHeap::insert(Node* temp)
{
	if (first == nullptr) {
		first = temp;
		last = temp;
	}
	else {
		if (temp->key < first->key) {
			temp->right = first;
			first = temp;
		}
		else {
			last->right = temp;
			last = temp;
		}
	}
}
void ThinHeap::printRoots() {
	Node* temp = first;
	while (temp != nullptr){
		std::cout << temp->key << " ";
		temp = temp->right;
	} 
}
int ThinHeap::peekMin() {
	return first->key;
}

ThinHeap* ThinHeap::merge(ThinHeap* h1,ThinHeap* h2) {
	if (!h1) {
		return h2;
	}
	if (!h2) {
		return h1;
	}
	if (h1->first->key < h2->first->key) {
		h1->last->right = h2->first;
		h1->last = h2->last;
		return h1;
	}
	else {
		h2->last->right = h1->first;
		h2->last = h1->last;
		return h2;
	}
}


Node* ThinHeap::extractMin() {
	Node* temp;
	temp = first;
	first = first->right;
	if (!first) {
		last = nullptr;
	}
	Node* x = temp->child;
	Node* next=nullptr;
	while (x) {
		if (x->isThin()) {
			x->rank -= 1;
		}
		next = x->right;
		x->left = nullptr;
		x->right = nullptr;
		insert(x);
		x = next;
	}
	int max = -1;
	x = first;
	Node** comb = new Node*[MAX_RANK];
	for (int i = 0; i < MAX_RANK; i++) {
		comb[i] = nullptr;
	}
		
	Node* stakan;
	while (x) {
		next = x->right;
		while (comb[x->rank]!=nullptr) {
			
			if (comb[x->rank]->key < x->key) {
				stakan = comb[x->rank];
				comb[x->rank] = x;
				x = stakan;
			}
			comb[x->rank]->right = x->child;

			if(x->child)
				x->child->left = comb[x->rank];

			comb[x->rank]->left = x;
			x->child = comb[x->rank];
			comb[x->rank] = nullptr;
			x->rank++;
		}
		x->right = nullptr;
		comb[x->rank] = x;
		
		if (x->rank > max)
			max = x->rank;
		x = next;
	}
	first =  nullptr;
	last = nullptr;
	for (int i = 0; i < max+1; i++) {
		if (comb[i])
			insert(comb[i]);
	}
	return temp;
}

void ThinHeap::decreaseKey(ThinHeap* h, Node* x, int delta)
{	
	x->key -= delta;
	if (!x->left) {
		
		if (x->key < h->first->key) {
			h->first->right = h->last;
			h->last = x->right;
			x->right = nullptr;
			h->first = x;
		}
		return;
	}
	Node* y = x->left;
	if (y->child == x) {
		
		y->child = x->right;
		if(x->right)
			x->right->left = y;
	}
	else {
		
		y->right = x->right;
		if (x->right)
			x->right->left = y;
	}
	x->right = x->left = nullptr;
	if (x->isThin()) {
		x->rank -= 1;
	}
	h->insert(x);
	Node* cur;
	Node* z;
	int suc = 0;
	while (suc!=2) {
		suc = 0;

		if ((y->rank == 1 && !y->right) || (y->rank - y->right->rank >= 2) ) {
			if (!y->isThin()) {
				cur = y->child;
				y->child = y->child->right;
				if (y->right)
					y->child->left = y;

				cur->left = y;
				cur->right = y->right;
				if (y->right)
					y->right->left = cur;
				y->right = cur;
				return;
			}
			else {
				y->rank--;
				y = y->left;
			}

		}
		else suc++;
		if ((y->rank == 2 && !y->child)) {
			y->rank -= 2;
		}
		else {
			if (y->child) {
				if (((y->rank - y->child->rank) == 3) || (!y->left)) {
					if (!y->left) {
						y->rank -= 1;
						return;
					}
					z = y->left;
					if (z->child == y) {
						z->child = y->right;
						y->right->left = z;
					}
					else {
						z->right = y->right;
						y->right->left = z;
					}
					y->right = y->left = nullptr;
					h->insert(y);
					y = z;
				}
				else suc++;
			}
			else suc++;
			
		}
		

	}
}

void ThinHeap::deleteKey(Node* x) {
	ThinHeap::decreaseKey(this,x,999999);
	extractMin();
}


