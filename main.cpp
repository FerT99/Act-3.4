// =================================================================
//
// File: main.cpp
// Author: Fernanda Michelle Torres Aguilar
// Date: 28/11/2022
//
// =================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "header.h"
#include "heapFile.h"

using namespace std;

int main(int argc, char* argv[]) {
	
	
	ifstream inputFile;
	ofstream outputFile;

	inputFile.open(argv[1]);
	if (inputFile.fail()){
		cout << "Error: cannot open file" << endl;
		return 1;
	}

	outputFile.open(argv[2]);
	if (outputFile.fail()){
		cout << "Error: cannot open file" << endl;
		return 1;
	}

	int n;
	
	inputFile >> n;
	
	Heap<int> Heap(n);
		for (int i = 0; i < n; i++){
			int number;
			inputFile >> number;
			Heap.add(number);
		}

	for(int i = 0; i < n; i++){
		Heap.pushDown(i);
	}

	int sum = 0, m = 0;

	for(int i = 0; i < n && Heap.length() > 1; i++){
		sum = Heap.remove() + Heap.remove();
		Heap.toString();
		Heap.add(sum);
		m += sum - 1;
	}
	
	outputFile << m << endl;
	
	return 0;
}