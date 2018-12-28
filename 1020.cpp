#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
struct mooncake
{
	double sum, price, ichi;
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
inline bool compare(mooncake x, mooncake y)
{
	return x.ichi > y.ichi;
}
int main(int argc, char const *argv[])
{
	memset(data, 0, sizeof(data));
	int n = getint();
	int need = getint();
	double answer = 0;
	for(int i = 1; i <= n; i++)
		scanf("%lf", &data[i].sum);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf", &data[i].price);
		data[i].ichi = data[i].price * 1.0 / data[i].sum;
	}
	sort(data + 1, data + n + 1, compare);
	for(int i = 1; i <= n; i++)
	{
		if(need >= data[i].sum)
		{
			need -= data[i].sum;
			answer += data[i].price;
		}
		else
		{
			answer += (need * 1.0 * (data[i].price * 1.0 / data[i].sum));
			need = 0;
		}
	}
	printf("%.2lf\n", answer);
	return 0;
}
