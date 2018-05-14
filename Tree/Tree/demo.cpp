#include"Tree.h"
/***************************************/
/*
二叉树：数组实现
要插入的树
                 3(0)
        5(1)                8(2)
2(3)          6(4)    9(5)          7(6)
*/
/***************************************/
#include"Tree1.h"
/***************************************/
/*
二叉树：链表实现
要插入的树
                   (0)
         5(1)                8(2)
2(3)          6(4)    9(5)          7(6)
*/
/***************************************/
void main() {
	int x;
	/*
	int  root = 3;
	int node1 = 5;
	int node2 = 8;
	int node3 = 2;
	int node4 = 6;
	int node5 = 9;
	int node6 = 7;
	Tree *pTree = new Tree(10, &root);

	pTree->AddNode(0, 0, &node1);
	pTree->AddNode(0, 1, &node2);

	pTree->AddNode(1, 0, &node3);
	pTree->AddNode(1, 1, &node4);

	pTree->AddNode(2, 0, &node5);
	pTree->AddNode(2, 1, &node6);

	int *number = pTree->SearchNode(4);
	cout << "第四个节点的值为："<<*number << endl;
	if(pTree->DeleteNode(2, &x))
	cout << "第二个节点的值为：" << x << endl;
	pTree->TreeTraverse();
	delete pTree;
	*/
	Tree1 *tree1 =new Tree1();

	Node *node1 = new Node();
	node1->data = 5;
	node1->index = 1;

	Node *node2 = new Node();
	node2->data = 8;
	node2->index = 2;

	Node *node3 = new Node();
	node3->data = 2;
	node3->index = 3;

	Node *node4 = new Node();
	node4->data = 6;
	node4->index = 4;

	Node *node5 = new Node();
	node5->data = 9;
	node5->index = 5;

	Node *node6 = new Node();
	node6->data = 7;
	node6->index = 6;

	tree1->AddNode(0, 0, node1);
	tree1->AddNode(0, 1, node2);

	tree1->AddNode(1, 0, node3);
	tree1->AddNode(1, 1, node4);

	tree1->AddNode(2, 0, node5);
	tree1->AddNode(2, 1, node6);

	cout << "前序遍历"<< endl;
	tree1->PreorderTraversal();

	cout << "中序遍历" << endl;
	tree1->InorederTraversal();

	cout << "后序遍历" << endl;
	tree1->PostorderTraversal();
	
	delete tree1;
	cin >> x;
}