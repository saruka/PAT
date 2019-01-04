#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5;
vector <int> real_prime;
bool prime[maxn];
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
void initialization()
{
	memset(prime, true, sizeof(prime));
	real_prime.clear();
	return;
}
void Euler_Prime()
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
	Euler_Prime();
	int n = getint();
	int sum = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			if(j - i > 2) break;
			if(prime[i] && prime[j] && j - i == 2) sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}
