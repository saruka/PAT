#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int x, y;
bool ichi = false;
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
	while(scanf("%d %d", &x, &y) == 2)
	{
		if(y == 0) continue;
		if(!ichi)
		{
			printf("%d %d", x * y, y - 1);
			ichi = true;
		}
		else printf(" %d %d", x * y, y - 1);
	}
	if(!ichi) puts("0 0");
	else putchar('\n');
	return 0;
}
