#pragma once
#include "BSTreeNode.h";
class BSTree
{


private:
	BSTreeNode* root;

	
public:
	BSTree() :root(NULL) {}
	~BSTree();
	BSTreeNode* Find(int id, int& numComp);
	void Insert(Person* item,int& numComp);
	void Delete(int id);
	Person Min();
	Person Max();
	void PrintTree();
	BSTreeNode* getroot();

};

