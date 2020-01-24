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
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int a[N];
int cnt[N];
int pre[N];
ll f[N];
int main ()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) read(a[i]);
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i]]++;
		mx = max(mx, a[i]);
	}
	pre[0] = 1;
	for (int i = 1 ; i <= mx; i++)
		pre[i] = pre[i - 1] * 2 % mod;
	ll ans = 0;
	for (int i = mx; i > 1; i--)
	{
		int k = 0, tmp = i;
		while (tmp <= mx) k += cnt[tmp], tmp += i;
		if(k == 0) continue;
		f[i] = (1ll * k * pre[k - 1]) % mod;
		for (int j = i + i; j <= mx; j += i)
			f[i] = (f[i] - f[j] + mod) % mod;
		ans = (ans + 1ll * i * f[i]) % mod;
	}
	printf("%lld\n", ans);
	return 0 ;
}