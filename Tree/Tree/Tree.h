#include<iostream>
using namespace std;
class Tree 
{
public:
	Tree(int size,int *pRoot);//������
	~Tree();//������
	int *SearchNode(int NodeIndex);//��������Ѱ�ҽڵ�
	bool AddNode(int NodeIndex, int direction, int *pNode);//���ӽڵ�
	bool DeleteNode(int NodeIndex, int *pNode);//ɾ���ڵ�
	void TreeTraverse();//������
private:
	int *m_pTree;
	int m_iSize;
};
