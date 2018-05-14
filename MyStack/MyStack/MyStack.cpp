#include"MyStack.h"

MyStack::MyStack(int size){
	m_iSize = size;
	m_pBuffer= new char[size];
	m_iTop = 0;
}
MyStack::~MyStack() {
	delete []m_pBuffer;
	m_pBuffer = NULL;
}
bool MyStack::StackEmpty() {
	bool temp = false;
	if (m_iTop == 0)
		temp = true;
	return temp;
}
bool MyStack::StackFull() {
	bool temp = false;
	if (m_iTop == m_iSize)
		temp = true;
	return temp;
}
void MyStack::ClearStack() {
	//delete[]m_pBuffer;
	m_iTop = 0;
}
int MyStack::StackLength() {
	return m_iTop;
}
bool MyStack::Push(char elem) {
	bool temp = false;
	if (!StackFull()) {
		m_pBuffer[m_iTop] = elem;
		m_iTop++;
		temp = true;
	}
	return temp;
}
bool MyStack::Pop(char &elem) {
	bool temp = false;
	if (!StackEmpty()) {
		elem = m_pBuffer[m_iTop-1];
		m_iTop--;
		temp = true;
	}
	return temp;
}
void MyStack::StackTraverse(bool direction) {
	if (!StackEmpty()) {
		if (direction) {
			for (int i = 0; i < m_iTop; i++) {
				cout << m_pBuffer[i] << "," << endl;
			}
		}
		else {
			for (int i = m_iTop - 1; i > -1; i--) {
				cout << m_pBuffer[i] << "," << endl;
			}
		}

	}
}