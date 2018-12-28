#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
list <int> link;
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
	for(int i = 1; i <= n; i++)
	{
		int data = getint();
		link.push_back(data);
	}
	list <int>::iterator it = link.end();
	for(int i = 1; i <= m; i++)
	{
		link.push_front(*it);
		link.pop_back();
		it--;
	}
	for(list <int>::iterator it = link.begin(); it != link.end(); it++)
	{
		if(it == link.begin()) printf("%d", *it);
		else printf(" %d", *it);
	}
	putchar('\n');
	return 0;
}
