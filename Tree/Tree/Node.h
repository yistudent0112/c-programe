#ifndef NODE_H
#define NODE_H
class Node
{
public:
	Node();
	Node *SearchNode(int NodeIndex);
	void DeleteNode();
	void PreorderTraversal();
	void InorederTraversal();
	void PostorderTraversal();
	int data;
	int index;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;
};
#endif 
