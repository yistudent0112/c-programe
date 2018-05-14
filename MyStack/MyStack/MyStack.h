#include<iostream>
using namespace std;
class MyStack{
public :
	MyStack(int size);
~MyStack();
bool StackEmpty();
bool StackFull();
void ClearStack();
int StackLength();
bool Push(char elem);
bool Pop(char &elem);
void StackTraverse(bool direction);
private:
	char *m_pBuffer;
	int m_iSize;
	int m_iTop;
};
