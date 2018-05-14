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

你的代码将被嵌在这里 

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

int s[31]; // 存放划分结果
int top = -1; // 数组指针
int countn = 0; // 统计输出的次数
int sum = 0; // 拆分项累加和

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
} // 输出部分
if (sum > N) {
return;
}
for (int j=i; j<=N; j++) {
s[++top] = j;
sum += j;
division (j);
sum -= j;
top --;
} // 算法主体
}