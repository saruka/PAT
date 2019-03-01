#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;
char str[maxn];
long long sum = 0;
int total_one = 0, total_zero = 0;
int main(int argc, char const *argv[])
{
	cin.getline(str, maxn);
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z') sum += (str[i] - 'A' + 1);
		else if(str[i] >= 'a' && str[i] <= 'z') sum += (str[i] - 'a' + 1);
	}
	while(sum != 0)
	{
		if(sum % 2) total_one++;
		else total_zero++;
		sum >>= 1;
	}
	printf("%d %d\n", total_zero, total_one);
	return 0;
}
