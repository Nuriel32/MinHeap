#include "Tree.h"
BSTreeNode* BSTree::getroot()
{
	return this->root;
}

BSTree::~BSTree()
{
	root->~BSTreeNode();
}

void BSTree::PrintTree()
{
	if (root != NULL)
		root->Inorder();
}


Person BSTree::Min()
{
	
	BSTreeNode* curr = this->root;
	while (curr->Left != NULL)
	{
		curr = curr->Left;

	}
	return *(curr->value);

}

Person BSTree::Max()
{

	BSTreeNode* curr = this->root;
	while (curr->Right != NULL)
	{
		curr = curr->Right;

	}
	return *(curr->value);

}

void BSTree::Insert(Person* item,int& numComp)
{
	if (Find(item->getid(),numComp) != NULL)
	{
		cout << "the key is exist" << endl;
		return;
	}
	BSTreeNode* temp = root;
	BSTreeNode* parent = NULL;
	BSTreeNode* newNode;
	while (temp != NULL)
	{
		parent = temp;
		if (item->getid() < temp->value->getid())
		{
			numComp++;
			temp = temp->Left;
		}
		else
			temp = temp->Right;
	}
	newNode = new BSTreeNode(item, NULL, NULL);
	if (parent == NULL)
	{
	root = newNode;
	numComp++;
	}
	else if (item->getid() < parent->value->getid())
	{
		numComp++;
		parent->Left = newNode;
	}
		
	else
		parent->Right = newNode;




}



BSTreeNode* BSTree::Find(int id, int& numComp)
{
	BSTreeNode* temp = this->root;
	while (temp != NULL)
	{
		if (temp->value->getid() == id)
		{
			numComp++;
			return temp;
		}

		
		if (temp->value->getid() < id)
		{
			numComp++;
			temp = temp->Right;
		}
		else temp = temp->Left;
		

	}
	return NULL;
}



void BSTree::Delete(int id)
{
	int k;

	if (Find(id,k) == NULL)
	{
		cout << "There is no key" << endl;
		return;
	}

	BSTreeNode* temp = root;
	BSTreeNode* parent = NULL;
	BSTreeNode* todelete;
	BSTreeNode* newroot;
	bool right = false;
	bool isroot = false;
	if (temp->value->getid() == id)
	{
		todelete = temp;
		if (temp->Right == NULL)
		{
			root = temp->Left;
		}
		else
		{
			temp = temp->Right;
			while (temp->Left != NULL)
			{
				temp = temp->Left;
			}
			temp->Left = root->Left;
		}
	}
	else {
		while (temp->value->getid() != id)
		{
			parent = temp;
			if (temp->value->getid() < id)
			{
				right = false;
				temp = temp->Left;

			}
			else
			{
				right = true;
				temp = temp->Right;
			}

		}
		todelete = temp;
		if (temp->Right == NULL || temp->Left == NULL)
		{

			if (right)
			{
				if (temp->Right != NULL)
				{

					parent->Right = temp->Right;
				}
				else parent->Right = temp->Left;

			}
			else
			{
				if (temp->Right != NULL)
				{

					parent->Left = temp->Right;
				}
				else
					parent->Left = temp->Left;
			}
		}

		else
		{
			if (right)
			{
				temp = temp->Left;
				while (temp->Right != NULL)
				{
					temp = temp->Right;
				}
				parent->Right = temp;
				while (temp->Left != NULL)
				{
					temp = temp->Left;
				}
				temp->Left = todelete->Left;
			}
			else
			{
				temp = temp->Left;
				while (temp->Right != NULL)
				{
					temp = temp->Right;
				}
				parent->Left = temp;
				while (temp->Left != NULL)
				{
					temp = temp->Left;
				}
				temp->Left = todelete->Left;
			}
		}
	}
	delete(todelete);

}