#include"Node.h"
#ifndef TREE1_H
#define TREE1_H
class Tree1
{
public :
	Tree1();//创建树
	~Tree1();//销毁树
	Node *SearchNode(int NodeIndex);//搜素节点
	bool AddNode(int NodeIndex, int direction, Node *pNode);//添加节点
	bool DeleteNode(int NodeIndex, Node *pNode);//删除节点
	void PreorderTraversal();//前序遍历
	void InorederTraversal();//中序遍历
	void PostorderTraversal();//后序遍历
private :
	Node *m_pRoot;
};
#endif