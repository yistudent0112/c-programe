#include"Node.h"
#ifndef TREE1_H
#define TREE1_H
class Tree1
{
public :
	Tree1();//������
	~Tree1();//������
	Node *SearchNode(int NodeIndex);//���ؽڵ�
	bool AddNode(int NodeIndex, int direction, Node *pNode);//��ӽڵ�
	bool DeleteNode(int NodeIndex, Node *pNode);//ɾ���ڵ�
	void PreorderTraversal();//ǰ�����
	void InorederTraversal();//�������
	void PostorderTraversal();//�������
private :
	Node *m_pRoot;
};
#endif