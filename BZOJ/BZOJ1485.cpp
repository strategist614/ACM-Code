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
const int N = 2e6 + 6;
int v[N], prime[N];
int m;
int c[N];
void primes(int n) {
	memset(v, 0, sizeof(v));
	m = 0;
	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			v[i] = i;
			prime[++m] = i;
		}
		for (int j = 1; j <= m; j++) {
			if (prime[j] > v[i] || prime[j] > n / i) break;
			v[i * prime[j]] = prime[j];
		}
	}
}
void divid(int x, int d)
{
	for (int i = 1; i <= m && prime[i] * prime[i] <= x; i++)
	{
		if (x % prime[i] == 0)
		{
			while (x % prime[i] == 0)
			{
				c[prime[i]] += d;
				x /= prime[i];
			}
		}
	}
	if (x > 1) c[x] += d;
}
ll ksm(ll a, ll b, ll mod)
{
	ll ans = 1 % mod;
	while (b > 0)
	{
		if (b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans % mod;
}
int main()
{
	int n, p;
	read(n);
	read(p);
	primes(n << 1);
	for (int i = n + 2; i <= (n << 1); i++) divid(i, 1);
	for (int i = 1; i <= n; i++) divid(i, -1);
	ll ans = 1;
	for (int i = 1; i <= m; i++)
	{
		if (c[prime[i]]) {
			ans = ans * ksm(prime[i], c[prime[i]], p);
			ans %= p;
		}
	}
	cout << ans << endl;
	return 0 ;
}