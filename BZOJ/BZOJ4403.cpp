/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
	x = 0;
	char c = getchar();
	int sgn = 1;
	while (c < '0' || c > '9')
	{
		if (c == '-')
			sgn = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	x *= sgn;
}
template <typename T>
void out(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x >= 10)
		out(x / 10);
	putchar(x % 10 + '0');
}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
const int p = 1e6 + 3;
int n;

ll ksm(ll a, ll b)
{
	ll ans = 1;
	a %= p;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return ans % p;
}
ll C(ll a, ll b)
{
	ll ans1 = 1, ans2 = 1;
	if (b > a)
		return 0;
	if (a == b)
		return 1;
	for (ll i = 1; i <= b; i++)
	{
		ans1 = ans1 * (a - i + 1) % p;
		ans2 = ans2 * i % p;
	}
	return ans1 * ksm(ans2, p - 2) % p;
}
ll lucas(ll a, ll b)
{
	if (b == 0)
		return 1;
	return C(a % p, b % p) * lucas(a / p, b / p) % p;
}
int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--)
	{
		int l, r;
		scanf("%d %d %d", &n, &l, &r);
		int _ = r - l + 1;
		int __ = n + r - l + 1;
		ll ans = lucas(__,_);
		ans = (ans - 1+ p) % p;
		printf("%lld\n", ans);
	}
	return 0;
}