#include"MyStack.h"
/*******************************/
/*
Õ»Àà£º
ÒªÇó£º
MyStack(int n);
~MyStack();
bool StackEmpty();
bool StackFull();
void ClearStack();
int StackLength();
void Push(char elem);
char Pop(char &elem);
void StackTraverse();

2018/1/23   yi
*/
/******************************/
int main(void) {
	 MyStack *m=new MyStack(10);
	 m->Push('a');
	 m->Push('b');
	 m->Push('c');
	 m->Push('d');
	 m->Push('e');
	 char a;
	 m->Pop( a);
	 m->StackTraverse(false);
	 delete m;
	 int n;
	 cin >> n;
	 return 0;
}
