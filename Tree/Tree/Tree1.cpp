#include"Tree1.h"
#include<iostream>
using namespace std;
Tree1::Tree1()
{
	m_pRoot = new Node();
}
Tree1::~Tree1() 
{
	m_pRoot->DeleteNode();
}
Node *Tree1::SearchNode(int NodeIndex)
{
    return	m_pRoot->SearchNode(NodeIndex);
}
bool Tree1::AddNode(int NodeIndex, int direction, Node *pNode)
{
	Node *temp = SearchNode(NodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	Node *node = new Node();
	if (node == NULL)
	{
		return false;
	}
	node->data = pNode->data;
	node->index = pNode->index;
	if (direction == 0)
	{
		temp->pLChild = node;
	}
	if (direction == 1)
	{
		temp->pRChild = node;
	}
	return true;
}
bool Tree1::DeleteNode(int NodeIndex, Node *pNode)
{
	Node *temp = SearchNode(NodeIndex);
	if (temp == NULL)
	{
		return false;
	}
	if(pNode!=NULL)
	{
	pNode->data = temp->data;
	}
	temp->DeleteNode();
	return true;
}
void Tree1::PreorderTraversal()
{
	m_pRoot->PreorderTraversal();
}
void Tree1::InorederTraversal()
{
	m_pRoot->InorederTraversal();
}
void Tree1::PostorderTraversal()
{
	m_pRoot->PostorderTraversal();
}