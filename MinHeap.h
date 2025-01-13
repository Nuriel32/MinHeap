#pragma once
#include "functions.h"
#include "Person.h"
class MinHeap {
private:
	Person** data;
	int maxSize;
	int heapSize;
	int allocated;
	
	static int Left(int node) {return node * 2 + 1; }
	static int Right(int  node){ return node * 2 + 2; }
	static int Parent(int i) { return (i - 1) / 2; }
public:
	int comp = 0;
	MinHeap(int max);
	MinHeap(Person** person, int n);
	void FixHeap(int node);
	~MinHeap();
	Person& Min();
	Person* DeleteMin();
	Person* DeleteMax();
	void Insert(Person* item);
	Person* Max();
	void Swap(int a, int b);
};