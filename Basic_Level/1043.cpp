#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e4 + 5;
char str[maxn], alphabet[10];
int sum[10];
inline int calc(char ch)
{
	static int temp = 0;
	switch(ch)
	{
		case 'P': sum[0]++; alphabet[0] = 'P'; temp++; break;
		case 'A': sum[1]++; alphabet[1] = 'A'; temp++; break;
		case 'T': sum[2]++; alphabet[2] = 'T'; temp++; break;
		case 'e': sum[3]++; alphabet[3] = 'e'; temp++; break;
		case 's': sum[4]++; alphabet[4] = 's'; temp++; break;
		case 't': sum[5]++; alphabet[5] = 't'; temp++; break;
		default : break;
	}
	return temp;
}
int main(int argc, char const *argv[])
{
	cin.getline(str, maxn);
	int now = 0, total = 0;
	for(int i = 0; i < strlen(str); i++) total = calc(str[i]);
	for(int i = 1; i <= maxn; i++)
	{
		if(sum[now] > 0)
		{
			putchar(alphabet[now]);
			sum[now]--;
		}
		now++;
		if(now > 5) now = 0;
	}
	putchar('\n');
	return 0;
}
