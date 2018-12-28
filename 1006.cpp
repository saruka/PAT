#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
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
	int data = getint();
	int pre = data / 100;
	int mid = data / 10 % 10;
	int post = data % 10;
	for(int i = 1; i <= pre; i++)
		putchar('B');
	for(int i = 1; i <= mid; i++)
		putchar('S');
	for(int i = 1; i <= post; i++)
		printf("%d", i);
	putchar('\n');
	return 0;
}
