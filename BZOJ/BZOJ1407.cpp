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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int n;
struct node
{
	ll c;
	ll p;
	ll l;
} a[20];
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) { x = 1, y = 0; return a; }
	int d = exgcd(b, a % b, x, y);
	int z = x; x = y; y = z - y * (a / b);
	return d;
}
ll x, y;
int solve(ll m)
{
	for (int i = 1; i <= n - 1; i++)
		for (int j = i + 1; j <= n; j++) {
			ll A = a[i].p - a[j].p, C = a[j].c - a[i].c, x, y, t = exgcd(A, m, x, y);
			if (C % t) continue;
			x = x * C / t;
			x = x % abs(m / t);
			if (x < 0) x += abs(m / t);
			if (x <= min(a[i].l, a[j].l)) return 0;
		}
	return 1;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	ll maxn = 0;
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(a[i].c);
		read(a[i].p);
		read(a[i].l);
		maxn = max(maxn, a[i].c);
	}
	for (ll i = maxn; i <= 1000000; i++)
	{
		if (solve(i)) {
			printf("%lld\n", i);
			return 0;
		}
	}
	return 0 ;
}