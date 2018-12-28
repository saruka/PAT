#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int odd_sum, cross_sum, sum, max_val = -23333, aver_sum;
double average;
bool vis[10];
inline int getint()
{
	int r = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar())
		if(c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar())
		r = r * 10 + c - '0';
	return r * k;
}
int main(int argc, char const *argv[])
{
	memset(vis, false, sizeof(vis));
	int temp = 0;
	int n = getint();
	for(int i = 1; i <= n; i++)
	{
		int data = getint();
		if(data % 2 == 0 && data % 5 == 0)
		{
			odd_sum += data;
			vis[1] = true;
		}
		if(data % 5 == 1)
		{
			cross_sum += (data * pow(-1, temp));
			temp++;
			vis[2] = true;
		}
		if(data % 5 == 2)
		{
			sum++;
			vis[3] = true;
		}
		if(data % 5 == 3)
		{
			average += data;
			aver_sum++;
			vis[4] = true;
		}
		if(data % 5 == 4)
		{
			max_val = max(max_val, data);
			vis[5] = true;
		}
	}
	if(vis[1])
		printf("%d", odd_sum);
	else
		putchar('N');
	if(vis[2])
		printf(" %d", cross_sum);
	else
		printf(" N");
	if(vis[3])
		printf(" %d", sum);
	else
		printf(" N");
	if(vis[4])
		printf(" %.1lf", average * 1.0 / aver_sum);
	else
		printf(" N");
	if(vis[5])
		printf(" %d\n", max_val);
	else
		puts(" N");
	return 0;
}
