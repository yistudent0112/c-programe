#include<iostream>
using namespace std;
#define MAXN 10


#include <stdio.h>
/*
int Count_Digit(int N, int D);

int main()
{
	int N, D;

	cin >> N;
	cin >> D;
	printf("%d\n", Count_Digit(N, D));
	system("pause");
	return 0;
}

��Ĵ��뽫��Ƕ������ 

int Count_Digit(int N, int D)
{
	int a[2] = { 0 };
	int C;

	while (N >= 10)
	{
		C = N % 10;
		if (C == D)
			a[0] = a[0] + 1;
		N = N / 10;
	}
	return a[0];
}
*/
int N;

int s[31]; // ��Ż��ֽ��
int top = -1; // ����ָ��
int countn = 0; // ͳ������Ĵ���
int sum = 0; // ������ۼӺ�

void division (int i);

int main ()
{
scanf_s ("%d", &N);

division (1);
system("pause");
return 0;
}

void division (int i) {
if (sum == N) {
countn++;
printf("%d=", N);
int k;
for (k=0; k<top; k++) {
printf("%d+", s[k]);
}
if (countn%4 == 0 || s[top] == N) {
printf("%d\n", s[top]);
} else {
printf("%d;", s[top]);
}
return;
} // �������
if (sum > N) {
return;
}
for (int j=i; j<=N; j++) {
s[++top] = j;
sum += j;
division (j);
sum -= j;
top --;
} // �㷨����
}