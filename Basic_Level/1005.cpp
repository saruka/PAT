#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int callatz[maxn >> 2], answer[maxn >> 2];
bool vis[maxn];
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
inline bool compare(int x, int y)
{
	return x > y;
}
void check(int x)
{
	while(x != 1)
	{
		if(x % 2 == 0)
		{
			x >>= 1;
			vis[x] = true;
		}
		else
		{
			x = (x * 3 + 1) >> 1;
			vis[x] = true;
		}
	}
	return;
}
int main(int argc, char const *argv[])
{
	memset(vis, false, sizeof(vis));
	int n = getint();
	int now = 0;
	for(int i = 1; i <= n; i++)
	{
		callatz[i] = getint();
		check(callatz[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[callatz[i]])
			answer[++now] = callatz[i];
	}
	sort(answer + 1, answer + now + 1, compare);
	printf("%d", answer[1]);
	for(int i = 2; i <= now; i++)
		printf(" %d", answer[i]);
	putchar('\n');
	return 0;
}
