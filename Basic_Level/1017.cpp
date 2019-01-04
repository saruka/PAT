#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
int quo = 0, divsion = 0;
bool flag = false;
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
	scanf("%s", str);
	int divsion = getint();
	for(int i = 0; i < strlen(str); i++)
	{
		quo = quo * 10 + str[i] - '0';
		if(quo >= divsion)
		{
			printf("%d", quo / divsion);
			flag = true;
		}
		else if(flag) putchar('0');
		quo %= divsion;
	}
	if(!flag) putchar('0');
	printf(" %d\n", quo);
	return 0;
}
