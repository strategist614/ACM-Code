/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define N 6000005
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
bool vis[N];
int mu[N], sum1[N], phi[N];
long long sum2[N];
int cnt, prim[N];
tr1::unordered_map<int, ll>w1;
tr1::unordered_map<int, int>w;
inline void get(int maxn)
{
	phi[1] = mu[1] = 1;
	for (int i = 2; i <= maxn; i++)
	{
		if (!vis[i])
		{
			prim[++cnt] = i;
			mu[i] = -1; phi[i] = i - 1;
		}
		for (int j = 1; j <= cnt && prim[j]*i <= maxn; j++)
		{
			vis[i * prim[j]] = 1;
			if (i % prim[j] == 0)
			{
				phi[i * prim[j]] = phi[i] * prim[j];
				break;
			}
			else mu[i * prim[j]] = -mu[i], phi[i * prim[j]] = phi[i] * (prim[j] - 1);
		}
	}
	for (int i = 1; i <= maxn; i++)sum1[i] = sum1[i - 1] + mu[i], sum2[i] = sum2[i - 1] + phi[i];
}
inline int djsmu(int x)
{
	if (x <= 6000000) return sum1[x];
	if (w[x]) return w[x];
	int ans = 1;
	for (int l = 2, r; l <= x; l = r + 1)
	{
		r = x / (x / l);
		ans -= (r - l + 1) * djsmu(x / l);
	}
	return w[x] = ans;
}
inline ll djsphi(int x)
{
	if (x <= 6000000) return sum2[x];
	if (w1[x]) return w1[x];
	ll ans = 1ll * x * (1 + 1ll * x) / 2;
	for (int l = 2, r; l <= x; l = r + 1)
	{
		r = x / (x / l);
		ans -= 1ll*(r - l + 1) * djsphi(x / l);
	}
	return w1[x] = ans;
}
int main ()
{
	int t;
	read(t);
	get(6000000);
	while (t--)
	{
		int n;
		read(n);
		printf("%lld %d\n", djsphi(n), djsmu(n));
	}
	return 0 ;
}