#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a, b, c;
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
inline LL getll()
{
	LL r = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar())
		if(c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar())
		r = r * 10 + c - '0';
	return r * k;
}
int main(int argc, char const *argv[])
{
	int T = getint();
	for(int i = 1; i <= T; i++)
	{
		a = getll();
		b = getll();
		c = getll();
		if(a + b > c) printf("Case #%d: true\n", i);
		else printf("Case #%d: false\n", i);
	}
	return 0;
}
