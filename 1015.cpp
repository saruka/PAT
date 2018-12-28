#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
struct student
{
	int rank, morality, talent, type, sum;
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
	if(x.type != y.type) return x.type < y.type;
	else if(x.sum != y.sum) return x.sum > y.sum;
	else if(x.morality != y.morality) return x.morality > y.morality;
	return x.rank < y.rank;
}
int main(int argc, char const *argv[])
{
	memset(data, 0, sizeof(data));
	int n = getint();
	int line = getint();
	int excellent = getint();
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		data[i].rank = getint();
		data[i].morality = getint();
		data[i].talent = getint();
		data[i].sum = data[i].morality + data[i].talent;
		if(data[i].talent < line || data[i].morality < line)
		{
			data[i].type = 5;
			sum++;
		}
		else if(data[i].talent >= excellent && data[i].morality >= excellent)
			data[i].type = 1;
		else if(data[i].morality >= excellent && data[i].talent < excellent)
			data[i].type = 2;
		else if(data[i].talent < excellent && data[i].morality < excellent && data[i].talent <= data[i].morality)
			data[i].type = 3;
		else data[i].type = 4;
	}
	sort(data + 1, data + n + 1, compare);
	printf("%d\n", n - sum);
	for(int i = 1; i <= n; i++)
	{
		if(data[i].type != 5)
		{
			printf("%d", data[i].rank);
			printf(" %d", data[i].morality);
			printf(" %d\n", data[i].talent);
		}
	}
	return 0;
}
