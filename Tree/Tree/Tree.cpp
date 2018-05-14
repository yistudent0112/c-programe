#include"Tree.h"

Tree::Tree(int size, int *pRoot)
{
	m_iSize = size;
	m_pTree = new int[size];
	for (int i = 0; i < m_iSize; i++)
	{
		m_pTree[i] = 0;
	}
	m_pTree[0] = *pRoot;
}

Tree::~Tree() 
{
	delete[]m_pTree;
	m_pTree = NULL;
}

int *Tree::SearchNode(int NodeIndex)
{
	if (NodeIndex < 0 || NodeIndex >= m_iSize) 
	{
		return NULL;
	}
	if(m_pTree[NodeIndex]==0)
	{
		return NULL;
	}
	return &m_pTree[NodeIndex];
}

bool Tree::AddNode(int NodeIndex, int direction, int *pNode)
{
	if (NodeIndex < 0 || NodeIndex >= m_iSize)
	{
		return false;
	}
	if (m_pTree[NodeIndex] == 0)
	{
		return false;
	}
	if (direction == 0) 
	{
		if ( (NodeIndex*2+1) >= m_iSize)
		{
			return false;
		}
		if (m_pTree[(NodeIndex * 2 + 1)] != 0)
		{
			return false;
		}
		m_pTree[(NodeIndex * 2 + 1)] = *pNode;
	}
	if (direction == 1)
	{
		if ((NodeIndex * 2 + 2) >= m_iSize)
		{
			return false;
		}
		if (m_pTree[(NodeIndex * 2 + 2)] != 0)
		{
			return false;
		}
		m_pTree[(NodeIndex * 2 + 2)] = *pNode;
	}
	return true;
}

bool Tree::DeleteNode(int NodeIndex, int *pNode)
{
	if (NodeIndex < 0 || NodeIndex >= m_iSize)
	{
		return false;
	}
	if (m_pTree[NodeIndex] == 0)
	{
		return false;
	}
	*pNode = m_pTree[NodeIndex];
	m_pTree[NodeIndex] = 0;
	return true;
}

void Tree::TreeTraverse()
{
	for (int i = 0; i < m_iSize; i++)
	{
		cout << m_pTree[i] << endl;
	}
}