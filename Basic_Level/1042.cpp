#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;
char str[maxn];
struct data
{
	int rank, sum;
} saruka[maxn];
inline bool compare(data x, data y)
{
	if(x.sum != y.sum) return x.sum > y.sum;
	return x.rank < y.rank;
}
int main(int argc, char const *argv[])
{
	memset(saruka, 0, sizeof(saruka));
	cin.getline(str, maxn);
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			saruka[str[i]].rank = str[i];
			saruka[str[i]].sum++;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			saruka[str[i] + 32].rank = str[i] + 32;
			saruka[str[i] + 32].sum++;
		}
	}
	sort(saruka, saruka + 128, compare);
	printf("%c %d\n", saruka[0].rank, saruka[0].sum);
	return 0;
}
