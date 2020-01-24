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
const int MAX_N = 1e6 + 6;
int v[MAX_N], prime[MAX_N], phi[MAX_N];
const int mod = 1000000007;
int  m;
void euler(int n) {
	memset(v, 0, sizeof(v));
	m = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (v[i] == 0) {
			v[i] = i, prime[++m] = i;
			phi[i] = i - 1;
		}
		for (int j = 1; j <= m; j++) {
			if (prime[j] > v[i] || prime[j] > n / i) break;
			v[i * prime[j]] = prime[j];
			phi[i * prime[j]] = phi[i] * (i % prime[j] ? prime[j] - 1 : prime[j]);
		}
	}
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	euler(n);
	ll ans = 1;
	for (int i = 1; i <= n; i++) {
		ans = ans * phi[i] % mod;
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0 ;
}