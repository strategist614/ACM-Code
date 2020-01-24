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
const ll mod = 20101009;
const int N = 1e7 + 5;
ll mu[N];
bool vis[N];
int prime[N];
int tot;
ll sum[N];

ll ksm(ll a, ll b)
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

void getmu(int n)
{
	mu[1] = 1;
	for (register int i = 2; i <= n; i++)
	{
		if (!vis[i]) {mu[i] = -1; prime[++tot] = i;}
		for (register int j = 1; j <= tot && prime[j]*i <= n; j++)
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)break;
			else mu[prime[j]*i] = -mu[i];
		}
	}
	for (register int i = 1; i <= n; i++)
		(sum[i] = sum[i - 1] + 1ll * mu[i] * 1ll * i % mod * 1ll * i % mod ) %= mod;
}

int main ()
{
	int n, m;
	read(n);
	read(m);
	long long inv2 = (mod + 1ll) / 2ll;
	int max_rep = min(n, m);
	getmu(max_rep);
	ll ans = 0;
	ll summ = 0;
	for (register ll i = 1, jj; i <= max_rep; i = jj + 1)
	{
		jj = min(n / (n / i), m / (m / i));
		int maxx = n / i;
		int maxy = m / i;
		summ = 0ll;
		int minn = min(maxx, maxy);
		for (register ll l = 1, r; l <= minn; l = r + 1ll)
		{
			r = min(maxx / (maxx / l), maxy / (maxy / l));
			summ += (sum[r] - sum[l - 1]) % mod * ((1ll + maxx / l) % mod * 1ll * (maxx / l) % mod * inv2 % mod) % mod * ((1ll + maxy / l) % mod * 1ll * (maxy / l) % mod * inv2 % mod) % mod;
			summ %= mod;
		}
		ans += (((i+jj)*(jj-i+1)/2)%mod*summ)%mod;
		ans %= mod;
	}
	out((ans % mod + mod) % mod);
	puts("");
	return 0 ;
}