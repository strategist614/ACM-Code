/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9') {if (c == '-')sgn = -1; c = getchar();}
	while (c >= '0' && c <= '9')x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0) {putchar('-'); x = -x;}
	if (x >= 10)out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int m;
ll f[1004];
const ll maxn = 1e12;
inline void find(ll a, ll b)
{
	if (a < b) swap(a, b);
	if (a == b)
	{
		printf("%lld\n", a);
		return ;
	}
	int c = lower_bound(f + 1, f + 60 + 1, a) - (f + 1);
	find(a - f[c], b);
}
int main ()
{
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= 60; i++) f[i] = f[i - 1] + f[i - 2];
	read(m);
	for (int i = 1; i <= m; i++)
	{
		ll a, b;
		read(a);
		read(b);
		find(a, b);
	}

	return 0 ;
}