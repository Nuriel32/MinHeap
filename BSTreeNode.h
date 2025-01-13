#pragma once
#include "Person.h"

class BSTreeNode
{
		Person* value;
		BSTreeNode* Left, * Right;
		void DestroyRecursive();
public :
	BSTreeNode();
	BSTreeNode(Person* item, BSTreeNode* left, BSTreeNode* right);
	~BSTreeNode();
	void Inorder();
	void Preorder();
	void Postorder();
	BSTreeNode* getLeft();
	BSTreeNode* getright();
	Person* getvalue();
	friend class BSTree;
};

