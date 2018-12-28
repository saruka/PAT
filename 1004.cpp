#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
struct student
{
	int score;
	char name[15], rank[15];
} data[maxn];
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
inline bool compare(student x, student y)
{
	return x.score < y.score;
}
int main(int argc, char const *argv[])
{
	memset(data, 0, sizeof(data));
	int n = getint();
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", data[i].name);
		scanf("%s", data[i].rank);
		data[i].score = getint();
	}
	int maxx = max_element(data + 1, data + n + 1, compare) - data;
	int minn = min_element(data + 1, data + n + 1, compare) - data;
	printf("%s %s\n", data[maxx].name, data[maxx].rank);
	printf("%s %s\n", data[minn].name, data[minn].rank);
	return 0;
}
