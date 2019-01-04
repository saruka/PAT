#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
char str[maxn];
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
	while(n--)
	{
		scanf("%s", str);
		bool gg = false;
		int pre = -1, post = 0, mid = 0;
		if(strlen(str) < 3) gg = true;
		for(int i = 0; i < strlen(str); i++)
		{
			if(gg) break;
			if(str[i] != 'P' && str[i] != 'A' && str[i] != 'T') gg = true;
			if(str[i] == 'P')
			{
				if(pre != -1) gg = true;
				pre = i;
				continue;
			}
			else if(str[i] == 'T')
			{
				mid = i - pre - 1;
				post = strlen(str) - i - 1;
			}
			if(pre * mid != post) gg = true;
		}
		if(!gg) puts("YES");
		else puts("NO");
	}
	return 0;
}
