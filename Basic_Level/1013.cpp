#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e7 + 5;
bool prime[maxn];
vector <int> real_prime;
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
inline void initialization()
{
	memset(prime, true, sizeof(prime));
	real_prime.clear();
	return;
}
void Euler_prime()
{
	prime[1] = false;
	for(int i = 2; i <= maxn; i++)
	{
		if(prime[i]) real_prime.push_back(i);
		for(int j = 0; j < real_prime.size() && real_prime[j] * i <= maxn; j++)
		{
			prime[real_prime[j] * i] = false;
			if(i % real_prime[j] == 0) break;
		}
	}
	return;
}
int main(int argc, char const *argv[])
{
	initialization();
	Euler_prime();
	int m = getint();
	int n = getint();
	real_prime.clear();
	int now = 1;
	for(int i = 2; i <= maxn; i++)
		if(prime[i]) real_prime.push_back(i);
	for(int i = m - 1; i <= n - 1; i++)
	{
		if(now == 1) printf("%d", real_prime[i]);
		else printf(" %d", real_prime[i]);
		now++;
		if(now == 11)
		{
			putchar('\n');
			now = 1;
		}
		if(i == n - 1 && now != 1) putchar('\n');
	}
	return 0;
}
