#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e4 + 5;
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
int main(int argc, char const *argv[])
{
	memset(vis, false, sizeof(vis));
	int n = getint();
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		int temp = (i / 2) + (i / 3) + (i / 5);
		vis[temp] = true;
	}
	for(int i = 1; i <= maxn; i++) if(vis[i]) sum++;
	printf("%d\n", sum + 1);
	return 0;
}
