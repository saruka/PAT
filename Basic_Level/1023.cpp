#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 15;
int data[maxn];
inline int getint()
{
	int r = 0, k = 1;
	char c = getchar();
	for(; c < '0' || c > '9'; c = getchar())
		if(c == '-') k = -1;
	for(; c >= '0' && c <= '9'; c = getchar())
		r = (r << 3) + (r << 1) + (c ^ 48);
	return r * k;
}
int main(int argc, char const *argv[])
{
	for(int i = 0; i <= 9; i++) data[i] = getint();
	for(int i = 1; i <= 9; i++)
	{
		if(data[i] != 0)
		{
			putchar(i + '0');
			data[i]--;
			break;
		}
	}
	for(int i = 0; i <= 9; i++)
	{
		for(int j = data[i]; j > 0; j--)
			putchar(i + '0');
	}
	putchar('\n');
	return 0;
}
