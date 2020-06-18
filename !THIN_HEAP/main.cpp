#include"ThinHeap.h"
#include<iostream>
#include<chrono>
#include<queue>
using namespace std;
int main() {
	/*ThinHeap* x = new ThinHeap();
	Node** a = new Node * [9];

	for (int i = 0; i < 9; i++) {
		a[i] = new Node(i);
		x->insert(a[i]);
	}
	x->extractMin();
	


	


	for (int i = 1; i < 9; i++) {
		cout << "deliting: " << i << "\n";
		x->deleteKey(a[i]);
		cout << "Cur roots: ";
		x->printRoots();
		cout << endl;
	}

	
	system("pause");*/
			
	cout << "C++ queue lib" << endl;
	cout << "Insert 0 - 999999. time is ";
	std::priority_queue<int> q;
	auto start = chrono::high_resolution_clock::now();
	auto end = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		q.push(i);
	}
	end = chrono::high_resolution_clock::now();
	chrono::duration<float> dur5 = end - start;
	cout << dur5.count() << endl;

	start = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		q.pop();
	}
	cout << "Extract all. time is ";
	end = chrono::high_resolution_clock::now();
	chrono::duration<float> dur6 = end - start;
	cout << dur6.count() << endl << endl ;











	cout << "ThinHeap" << endl;
	ThinHeap* speedTest = new ThinHeap();
	cout << "Insert 0 - 999999. time is ";

	start = chrono::high_resolution_clock::now();
	end = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		speedTest->insert(i);
	}
	end = chrono::high_resolution_clock::now();
	chrono::duration<float> dur = end - start;
	cout << dur.count() << endl;

	cout << "Extract all. time is ";
	auto xxstart = chrono::high_resolution_clock::now();
	auto xxend = chrono::high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		speedTest->extractMin();
	}
	xxend = chrono::high_resolution_clock::now();
	chrono::duration<float> dur2 = xxend - xxstart;
	cout << dur2.count() << endl;
	





}