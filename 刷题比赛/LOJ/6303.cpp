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
ll solve(ll x, ll y)
{
	if (y > x) return 0;
	return x / y + solve(x / y, y);
}
const int N = 5000009;
ll prime[N];
bool v[N];
int tot = 0;
ll c = 0;
void sieve()
{
	for (int i = 2; i <= 3400000; i++)
	{
		if (!v[i])
			prime[++tot] = i;
		for (int j = 1; j <= tot && i * prime[j] <= 3400000; j++)
		{
			v[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main ()
{
	sieve();
	ll n, k;
	while (~scanf("%lld %lld", &n, &k))
	{
		ll ans = 9e18;
		for (int i = 1; prime[i]*prime[i] <= k; i++)
		{
			if (k % prime[i] == 0)
			{
				c = 0;
				while (k % prime[i] == 0)
				{
					c ++;
					k /= prime[i];
				}
				ans = min(ans, solve(n, prime[i]) / c);
			}
		}
		if (k != 1) ans = min(ans, solve(n, k));
		cout << ans << endl;
	}
	return 0 ;
}