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
ll mod;
ll n;
ll a[10000];
ll ksm(ll a, ll b, ll mod) {
	ll ans = 1;
	while (b > 0) {
		if (b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans % mod;
}
ll phi(ll n) {
	ll ans = n;
	for (ll i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}
ll solve(ll cur, ll p)
{
	if (cur == n) return a[cur] % p;
	ll tmp = phi(p);
	ll c = solve(cur + 1, tmp) + tmp;
	return ksm(a[cur], c, p);
}
int main ()
{
	int flag = 0;
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	char str[100000];
	while (scanf("%s", str) == 1 && strcmp(str, "#"))
	{
		ll p;
		sscanf(str, "%lld", &p);
		scanf("%lld", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		ll ans = 0;
		if (n == 1)
		{
			ans = a[1] % p;
		}
		else ans = solve(1, p);
		printf("Case #%d: %lld\n", ++flag, ans);
	}
	return 0 ;
}