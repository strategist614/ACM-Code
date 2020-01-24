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
const int mod = 100003;
ll ksm(ll a, ll b)
{
	ll ans = 1 % mod;
	while (b > 0)
	{
		if (b & 1) ans = (ans % mod) * (a % mod) % mod;
		b >>= 1;
		a = (a % mod) * (a % mod) % mod;
	}
	return ans % mod;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	ll n, m;
	cin >> m >> n;
	ll _ = ksm(m, n);
	ll __ = ksm(m - 1, n - 1);
	ll tmp = (m % mod * __ % mod) % mod;
	ll ans = ((_ - tmp) % mod + mod) % mod;
	cout << ans << endl;
	return 0 ;
}