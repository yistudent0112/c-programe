#include<iostream>
using namespace std;
class Tree 
{
public:
	Tree(int size,int *pRoot);//创建树
	~Tree();//销毁树
	int *SearchNode(int NodeIndex);//根据索引寻找节点
	bool AddNode(int NodeIndex, int direction, int *pNode);//增加节点
	bool DeleteNode(int NodeIndex, int *pNode);//删除节点
	void TreeTraverse();//遍历树
private:
	int *m_pTree;
	int m_iSize;
};
