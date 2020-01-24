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

ll ksm(ll x, ll n)
{
	ll res = 1;
	while (n > 0)
	{
		if (n & 1) res = res * x;
		x = x * x ;
		n >>= 1;
	}
	return res;
}

const int N = 1e5 + 5;
ll prime[N], c[N];
int tot = 0;
void divid(ll n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		//cout<<1;
		if (n % i == 0)
		{
			prime[++tot] = i, c[tot] = 0;
			while (n % i == 0) n /= i, c[tot]++;
		}
	}
	if (n > 1) prime[++tot] = n, c[tot] = 1;
}

int main ()
{
	ll n;
	int flag = 0;
	while (scanf("%lld", &n) != EOF && n)
	{
		if (n == 1)
		{
			printf("Case %d: %d\n", ++flag, 2);
			continue;
		}
		tot = 0;
		divid(n);
		if (tot == 1)
		{
			ll ans = ksm(prime[tot], c[tot]);
			printf("Case %d: %lld\n", ++flag, ans + 1);
		}
		else
		{
			ll ans = 0;
			for (int i = 1; i <= tot; i++)
			{
				ans += ksm(prime[i], c[i]);
			}
			printf("Case %d: %lld\n", ++flag, ans);
		}
	}
	return 0 ;
}