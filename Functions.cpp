#include "functions.h"
using namespace std;
/*
* each iteration of the function Partition will place the nummbers that smaller then the random pivot to the left and the bigger numbers to the right 
* if the pivot is equal to k-1 then it means k- minimal number at the "right place"
* else
*		if pivot  bigger then k-1 the k minimal number will be at the right part of the array to the pivot.
*		else if pivot  smaller then k-1 the k minimal number will be at the left part of the array to the pivot.
* so each time we save unnecessary iterations.<3
*/
const Person& RandSelection(Person arr[], int n, int k, int& NumComp)
{
	if (n <=1)
		return arr[0];

	int pivot = Partition(arr,0,n-1,NumComp);

	if (pivot == k-1)
	{
		return arr[k-1];
		NumComp++;
	}
	else
	{
		if (k-1 < pivot)
		{
			NumComp++;
			RandSelection(arr, pivot, k, NumComp);
		}
		
		else
		{
			RandSelection(arr+ pivot+1,n-pivot-1 , k-pivot-1, NumComp);
		}

	}
	return arr[k-1];//check
}

int Partition(Person arr[], int start, int end ,int& NumComp)
{
	bool left = true;
	int pivot = rand() % (end - start+1);
	if(pivot!=0)
	{ 
	swap(arr, 0, pivot);
	NumComp++;
	}
	int res = arr[0].getid();
	
	while (start!=end)
	{
		if (left)
		{
			if (arr[start].getid() <= arr[end].getid())
			{
				NumComp++;
				end--;
			}
			else
			{
				swap(arr, start, end);
				start++;
				left = false;
			}
		}
		else
		{
			if ((arr[end].getid() > arr[start].getid()))
			{
				NumComp++;
				start++;
			}
			else
			{
				swap(arr, start, end);
				end--;
				left = true;
			}
		}
	
	}

	return end;
}
	

void swap(Person ppl[], int a, int b)
{
	Person temp;
	temp = ppl[b];
	ppl[b] = ppl[a];
	ppl[a] = temp;

}


const Person& selectHeap(Person* ppl, int n, int k, int& NumComp)
{
	Person** PtoPPL = new Person* [n];
	for (int i = 0; i < n; i++)
	{
		PtoPPL[i] = &(ppl[i]);
	}
	MinHeap heap(PtoPPL, n);
	int i = 1;
	while (i < k)
	{
		heap.DeleteMin();
		i++;
	}
	NumComp = heap.comp;
	Person& a = *heap.DeleteMin();
	delete(PtoPPL);
	return a;
	
}


const Person& BST(Person ppl[], int n, int k, int& NumComp)
{
	
	BSTree tree;
	Person** a=new Person*;
	
	for (int i = 0; i < n; i++)
	{
		tree.Insert(&(ppl[i]),NumComp);
	}	
	 RecursiveBST(tree.getroot(),k,NumComp,a);

	 Person& b = **a;
	 delete(a);
	 return b;
}


void RecursiveBST(BSTreeNode* root, int& k, int& NumComp, Person** returnvalue)
{
	
	if (root == NULL)
	{
		NumComp++;
		return;
	}
	RecursiveBST(root->getLeft(), k, NumComp, returnvalue);
	k--;
	if (k == 0)
	{
		NumComp++;
		*returnvalue= (root->getvalue());
	}
	else
	{
	
	 RecursiveBST(root->getright(), k, NumComp, returnvalue);
	}

}

bool isValidN(int n) {
	return n > 0;
}

bool sameID(Person* persons, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (persons[i].getid() == persons[j].getid()) {
				return true;
			}
		}
	}
	return false;
}

bool isValidK(int k, int n) {
	return k > 0 && k <= n;
}

void program(Person* persons, int n, int k) {
	Person person;
	int NumComp = 0;

	Person* copy = new Person[n];
	copyArray(persons, copy, n);
	person = RandSelection(copy, n, k, NumComp);
	cout << "RandSelection: " << person.getid() << " " << person.getname() << " " << NumComp << " comparisons" << endl;
	copyArray(persons, copy, n);
	NumComp = 0;
	person = selectHeap(copy, n, k, NumComp);
	cout << "selectHeap: " << person.getid() << " " << person.getname() << " " << NumComp << " comparisons" << endl;

	copyArray(persons, copy, n);
	NumComp = 0;
	person = BST(copy, n, k, NumComp);
	cout << "BST: " << person.getid() << " " << person.getname() << " " << NumComp << " comparisons" << endl;

}

void copyArray(Person* src, Person* dest, int size)
{

	for (int i = 0; i < size; i++)
	{
		dest[i] = src[i];
	}
}