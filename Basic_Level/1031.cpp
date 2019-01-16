#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
const char bits[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
char str[maxn][20];
bool not_dits = false;
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
char calc(int now)
{
	int temp = 0;
	not_dits = false;
	for(int i = 0; i <= strlen(str[now]) - 2; i++)
	{
		if(str[now][i] < '0' || str[now][i] > '9') not_dits = true;
		int num = 0;
		num = num * 10 + str[now][i] - '0';
		temp += (num * weight[i]);
	}
	temp %= 11;
	return bits[temp];
}
inline bool check(int now)
{
	if(calc(now) != str[now][strlen(str[now]) - 1]) return false;
	return true;
}
int main(int argc, char const *argv[])
{
	int n = getint();
	bool gg = false;
	for(int i = 1; i <= n; i++)
		scanf("%s", str[i]);
	for(int i = 1; i <= n; i++)
	{
		bool result = check(i);
		if(not_dits)
		{
			puts(str[i]);
			gg = true;
			continue;
		}
		if(!result)
		{
			puts(str[i]);
			gg = true;
		}
	}
	if(!gg) puts("All passed");
	return 0;
}
