#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
struct link_list
{
	int pre, nxt, rank, data;
} link[maxn];
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
	int n = getint();
	int m = getint();
	m %= n;
	int head = 1;
	for(int i = 1; i <= n; i++)
	{
		link[i].data = getint();
		link[i].rank = i;
	}
	link[1].pre = -1;
	link[1].nxt	= link[2].rank;
	link[n].pre = link[n - 1].rank;
	link[n].nxt = -1;
	for(int i = 2; i <= n - 1; i++)
	{
		link[i].pre = link[i - 1].rank;
		link[i].nxt = link[i + 1].rank;
	}
	for(int i = n; i >= n - m + 1; i--)
	{
		link[i].pre = link[head].pre;
		link[i - 1].nxt = link[i].nxt;
		link[head].pre = link[i].rank;
		link[i].nxt = link[head].rank;
		head = i;
	}
	printf("%d", link[head].data);
	while(link[head].nxt != -1)
	{
		head = link[head].nxt;
		printf(" %d", link[head].data);
	}
	putchar('\n');
	return 0;
}
