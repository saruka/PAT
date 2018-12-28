#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
const int maxn = 85;
stack <char> st;
char str[maxn];
int main(int argc, char const *argv[])
{
	cin.getline(str, 100);
	for(int i = strlen(str) - 1; i >= 0; i--)
	{
		if(str[i] == ' ' || i == 0)
		{
			if(i == 0) st.push(str[0]);
			while(!st.empty())
			{
				putchar(st.top());
				st.pop();
			}
			if(i != 0) putchar(' ');
		}
		else st.push(str[i]);
	}
	putchar('\n');
	return 0;
}
