#pragma once
#include "Person.h"
#include "MinHeap.h"
#include "Tree.h"
using namespace std;
void swap(Person ppl[], int a, int b);
int Partition(Person arr[], int start, int end, int& NumComp);
const Person& RandSelection(Person arr[], int n, int k, int& NumComp);
const Person& selectHeap(Person* ppl, int n, int k, int& NumComp);
const Person& BST(Person ppl[], int n, int k, int& NumComp);
void  RecursiveBST(BSTreeNode* root, int& k, int& NumComp, Person** returnvalue);
bool isValidN(int n); 
bool sameID(Person* persons, int n); 
bool isValidK(int k, int n); 
void program(Person* persons, int n, int k);
void copyArray(Person* src, Person* dest, int size);