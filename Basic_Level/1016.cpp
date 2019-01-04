#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long LL;
string a, b, da, db;
LL pa = 0, pb = 0;
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
	cin >> a >> da >> b >> db;
	for(int i = 0; i < a.length(); i++)
	{
		if(a[i] == da[0])
			pa = pa * 10 + da[0] - '0';
	}
	for(int i = 0; i < b.length(); i++)
	{
		if(b[i] == db[0])
			pb = pb * 10 + db[0] - '0';
	}
	printf("%lld\n", pa + pb);
	return 0;
}
