#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
int score[maxn];
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
	memset(score, 0, sizeof(score));
	int n = getint();
	for(int i = 1; i <= n; i++)
	{
		int rank = getint();
		int temp = getint();
		score[rank] += temp;
	}
	int pos = max_element(score + 1, score + maxn + 1) - score;
	int sum = *max_element(score + 1, score + maxn + 1);
	printf("%d %d\n", pos, sum);
	return 0;
}
