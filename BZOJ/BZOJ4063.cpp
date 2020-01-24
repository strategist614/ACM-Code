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
map<int, int> mp;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--)
	{
		int n;
		read(n);
		ll ans = 0 ;
		for (int i = 1; i <= n; i++)
		{
			ll x, y;
			read(x);
			read(y);
			double tmp = sqrt((double)x * x + (double)y * y);
			if (tmp <= 20) ans += 10;
			else if (tmp > 20 && tmp <= 40) ans += 9;
			else if (tmp > 40 && tmp <= 60) ans += 8;
			else if (tmp > 60 && tmp <= 80) ans += 7;
			else if (tmp > 80 && tmp <= 100) ans += 6;
			else if (tmp > 100 && tmp <= 120) ans += 5;
			else if (tmp > 120 && tmp <= 140) ans += 4;
			else if (tmp > 140 && tmp <= 160) ans += 3;
			else if (tmp > 160 && tmp <= 180) ans += 2;
			else if (tmp > 160 && tmp <= 200) ans += 1;
		}
		printf("%lld\n", ans);
	}
	return 0 ;
}