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
	int n = getint();
	int sum = 0;
	while(n != 1)
	{
		if(n % 2 == 0) n >>= 1;
		else n = (n * 3 + 1) >> 1;
		sum++;
	}
	printf("%d\n", sum);
	return 0;
}
