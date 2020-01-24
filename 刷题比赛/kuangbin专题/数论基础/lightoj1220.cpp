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
const int N = 1e6 + 5;
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}

int c[N], tot = 0;
void divid(ll x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)
		{
			c[++tot] = 0;
			while (x % i == 0) x /= i, c[tot]++;
		}
	}
	if (x > 1) c[++tot] = 1;
}
int main ()
{
	int t;
	cin >> t;
	int flag = 0;
	while (t--)
	{
		memset(c, 0, sizeof(c));
		ll x;
		cin >> x;
		tot = 0;
		if (x < 0)
		{
			x = 0 - x;
			divid(x);
			int ans =  0;
			for (int i = 1; i <= tot; i++)
				ans = gcd(ans, c[i]);
			while (ans % 2 == 0) ans >>= 1;
			printf("Case %d: %d\n", ++flag, ans);
		}
		else
		{
			divid(x);
			int ans = 0;
			for (int i = 1; i <= tot; i++)
				ans = gcd(ans, c[i]);
			printf("Case %d: %d\n", ++flag, ans);
		}
	}
	return 0 ;
}