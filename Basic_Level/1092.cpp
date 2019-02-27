#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
struct saruka
{
	int rank, sum;
} data[maxn];
inline bool compare(saruka x, saruka y)
{
	if(x.sum != y.sum) return x.sum > y.sum;
	return x.rank < y.rank;
}
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
	memset(data, 0, sizeof(data));
	int n = getint();
	int m = getint();
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int temp = getint();
			data[j].sum += temp;
		}
	}
	for(int i = 1; i <= n; i++) data[i].rank = i;
	sort(data + 1, data + 1 + n, compare);
	printf("%d\n", data[1].sum);
	int total = 1;
	for(int i = 2; i <= n; i++)
	{
		if(data[i].sum == data[i - 1].sum) total++;
		else break;
	}
	for(int i = 1; i <= total; i++)
	{
		if(i == 1) printf("%d", data[i].rank);
		else printf(" %d", data[i].rank);
	}
	putchar('\n');
	return 0;
}
