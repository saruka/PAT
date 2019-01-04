#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
string str, answer;
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
	cin >> str;
	LL sum = 0;
	for(int i = 0; i < str.length(); i++)
	{
		int temp = 0;
		temp = temp * 10 + str[i] - '0';
		sum += temp;
	}
	answer = to_string(sum);
	for(int i = 0; i < answer.length(); i++)
	{
		switch(answer[i])
		{
			case '0': printf("ling"); break;
			case '1': printf("yi"); break;
			case '2': printf("er"); break;
			case '3': printf("san"); break;
			case '4': printf("si"); break;
			case '5': printf("wu"); break;
			case '6': printf("liu"); break;
			case '7': printf("qi"); break;
			case '8': printf("ba"); break;
			case '9': printf("jiu"); break;
		}
		if(i != answer.length() - 1) putchar(' ');
	}
	putchar('\n');
	return 0;
}
