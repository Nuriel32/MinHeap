#include "MinHeap.h"

MinHeap::MinHeap(Person** A, int n)
{
	heapSize = maxSize = n;
	data = A;
	
	allocated = 0;
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		FixHeap(i);
	}
		
}
void MinHeap::FixHeap(int node)
{
	

	int min = node;
	int left = Left(node);
	int right = Right(node);
	if ((left < heapSize))
	{
		if ((data[left]->getid()) < data[node]->getid())
		{
			min = left;
			comp++;
		}

	}
	else { min = node; }

	if (right < heapSize)
	{
		if ((data[right]->getid()) < data[min]->getid())
		{
			min = right;
			comp++;
		}

	}
	comp++;
	if (min != node)
	{
		Swap(node, min);
		FixHeap(min);
	}



}




MinHeap::MinHeap(int max)
{
	data = new Person*[max];
	maxSize = max;
	heapSize = 0;
	allocated = 1;
}
MinHeap::~MinHeap()
{
	if (allocated)
		delete data;
	data = NULL;
}
Person& MinHeap::Min()
{
	return *data[0];
}
Person* MinHeap::Max()
{
	Person* max = data[0];
	for(int i = heapSize / 2;i< heapSize;i++)//leaves are at the second half.
	{
		if (max->getid() < data[i]->getid())
			max = data[i];
	}
	return max;
	
}
Person* MinHeap::DeleteMin()
{
	if(heapSize < 1)
	{//erorr
	}

	Person* min = data[0];
	heapSize--;
	data[0] = data[heapSize];
	FixHeap(0);
	return min;

}
Person* MinHeap::DeleteMax()
{

	int maxindex = 0;
	Person* max = data[0];
	for (int i = heapSize / 2; i < heapSize; i++)//leaves are at the second half.
	{
		if (data[i]->getid() > max->getid())
		{
			max = data[i];
			maxindex = i;
		}
			
	}
	heapSize--;
	data[maxindex] = data[heapSize];
	FixHeap(0);
	return max;
	
}
void MinHeap::Insert(Person* item) 
{
	if (heapSize == maxSize)
	{
		cout << "erorr" << endl;
		return;
	}
	int i = heapSize;
	heapSize++;
	while ((i > 0) && (data[Parent(i)]->getid() > item->getid()))
	{
	
		data[i] = data[Parent(i)];
		i = Parent(i);

	}
	data[i] = item;
}




void MinHeap::Swap(int a, int b)
{
	Person* temp = data[a];
	data[a] = data[b];
	data[b] = temp;
}