#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
const int maxn = 1e6 + 5;
bool gg = false;
bool vis[maxn];
map <int, vector <int> > saruka;
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
	for(int i = 0; i < n; i++)
	{
		int x = getint();
		int y = getint();
		saruka[x].push_back(y);
		saruka[y].push_back(x);
	}
	while(m--)
	{
		memset(vis, false, sizeof(vis));
		gg = false;
		int sum = getint();
		vector <int> vec(sum, 0);
		for(int i = 0; i < sum; i++)
		{
			vec[i] = getint();
			vis[vec[i]] = true;
		}
		for(int i = 0; i < vec.size(); i++)
		{
			for(int j = 0; j < saruka[vec[i]].size(); j++)
			{
				if(vis[saruka[vec[i]][j]])
				{
					gg = true;
					break;
				}
			}
		}
		if(gg) puts("No");
		else puts("Yes");
	}
	return 0;
}
