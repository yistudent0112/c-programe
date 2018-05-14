#include"Node.h"
#include<iostream>
using namespace std;
Node::Node()
{
	data = 0;
	index = 0;
	pLChild = NULL;
	pRChild = NULL;
	pParent = NULL;
}
Node *Node::SearchNode(int NodeIndex)
{
	if (this->index == NodeIndex)
	{
		return this;
	}
	if (this->pLChild != NULL)
	{
		if (this->pLChild->index == NodeIndex)
		{
			return this->pLChild;
		}
	}
	if (this->pRChild != NULL)
	{
		if (this->pRChild->index == NodeIndex)
		{
			return this->pRChild;
		}
	}
	return NULL;
}
void Node::DeleteNode()
{
	if (this->pLChild != NULL)
	{
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL)
	{
		this->pRChild->DeleteNode();
	}
	if(this->pParent!=NULL)
	{ 
	if (this->pParent->pLChild == this)
	{
		this->pParent->pLChild == NULL;
	}
	if (this->pParent->pRChild == this)
	{
		this->pParent->pRChild == NULL;
	}
	}
	delete this;
}
void Node::PreorderTraversal()
{
	cout << this->index << "   " << this->data << endl;

	if (this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();
	}

	if (this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}
}
void Node::InorederTraversal()
{
	
	if (this->pLChild != NULL)
	{
		this->pLChild->InorederTraversal();
	}
	cout << this->index << "   " << this->data << endl;

	if (this->pRChild != NULL)
	{
		this->pRChild->InorederTraversal();
	}
}
void Node::PostorderTraversal()
{
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();
	}
	
	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}

	cout << this->index << "   " << this->data << endl;
}