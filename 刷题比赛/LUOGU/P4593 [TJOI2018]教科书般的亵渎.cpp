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
const int mod = 1e9 + 7;
const int N = 55;
ll a[55];
ll f[55];
ll fac[55] = {1};
ll n, m;
ll ksm(ll x, ll y) {
	ll re = 1;
	while (y) {
		if (y & 1) re = re * x % mod;
		x = x * x % mod; y >>= 1;
	} return re % mod;
}
ll lagrange(ll n, ll k) {
	ll pro = 1, num = 0;
	if (n <= k) return f[n];
	for (ll i = 1; i <= k; i++)
		pro = pro * (n - i) % mod;
	for (ll i = 1; i <= k; i++) {
		ll inv1 = ksm(n - i, mod - 2);
		ll inv2 = ksm((fac[i - 1] % mod * fac[k - i]) % mod, mod - 2);
		ll sign = (k - i) & 1 ? -1 : 1;
		num = (num + sign * inv1 * inv2 % mod * f[i] % mod * pro % mod) % mod;
	} return (num + mod) % mod;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	for (ll i = 1; i <= 55; i++) {
		fac[i] = fac[i - 1] * (ll)i % mod;
		//fac[i] %= mod;
	}
	ll t;
	read(t);
	while (t--) {
		read(n);
		read(m);
		for (ll i = 1; i <= m + 3; i++)
			f[i] = (f[i - 1] + ksm(i, m + 1)) % mod;
		for (ll i = 1; i <= m; i++) read(a[i]);
		sort(a + 1, a + m + 1);
		ll ans = 0;
		for (ll i = 0; i <= m; i++) {
			ans = (ans + lagrange(n - a[i], m + 3)) % mod;
			for (ll j = i + 1; j <= m; j++) ans = (ans + mod - ksm(a[j] - a[i], m + 1)) % mod;
		} 
	    printf("%lld\n", (ans + mod) % mod);
	}
	return 0;
}