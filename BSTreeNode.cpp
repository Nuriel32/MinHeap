#include "BSTreeNode.h"

BSTreeNode::BSTreeNode(Person* item, BSTreeNode* left, BSTreeNode* right)
{
	this->value = item;
	this->Left = left;
	this->Right = right;
}

void BSTreeNode::Inorder()
{
	if (this == NULL)
	{
		return;
	}
	this->Left->Inorder();
	cout << this->value->getid() << " " << this->value->getname() << endl;

	this->Right->Inorder();

}


void BSTreeNode::Preorder()
{
	if (this == NULL)
	{
		return;
	}
	cout << this->value->getid() << " " << this->value->getname() << endl;
	this->Left->Inorder();
	

	this->Right->Inorder();

}


void BSTreeNode::Postorder()
{
	if (this == NULL)
	{
		return;
	}
	
	this->Left->Inorder();
	this->Right->Inorder();
	cout << this->value->getid() << " " << this->value->getname() << endl;

}
BSTreeNode::~BSTreeNode()
{
	//this->DestroyRecursive();
	if (Left)
		delete(Left);
	if (Right)
		delete(Right);
}

void BSTreeNode::DestroyRecursive()
{
	if (this)
	{
		this->Left->DestroyRecursive();
		this->Right->DestroyRecursive();
		delete this;
	}
}



BSTreeNode* BSTreeNode::getLeft()
{
	return this->Left;
}
BSTreeNode* BSTreeNode::getright() 
{
	return this->Right;
}



Person* BSTreeNode::getvalue()
{
	return this->value;
	
}