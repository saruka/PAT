#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1005;
char str[maxn];
int sum[10];
int main(int argc, char const *argv[])
{
	scanf("%s", str);
	for(int i = 0; i < strlen(str); i++)
	{
		switch(str[i])
		{
			case '1': sum[1]++; break;
			case '2': sum[2]++; break;
			case '3': sum[3]++; break;
			case '4': sum[4]++; break;
			case '5': sum[5]++; break;
			case '6': sum[6]++; break;
			case '7': sum[7]++; break;
			case '8': sum[8]++; break;
			case '9': sum[9]++; break;
			case '0': sum[0]++; break;
		}
	}
	for(int i = 0; i <= 9; i++)
	{
		if(sum[i] != 0)
			printf("%d:%d\n", i, sum[i]);
	}
	return 0;
}
