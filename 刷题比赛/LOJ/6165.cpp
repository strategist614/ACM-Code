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
const int N = 1e8 + 5;
const ll mod = 100000007;
bitset<N> v;
int prime[7000005];
ll ans = 1;
int tot = 0;
int n;
void sieve()
{
	v[0] = v[1] = 1;
	for (register int i = 2; i <= n; i++)
	{
		if (!v[i]) {
			prime[++tot] = i;
			for (register ll k = i; k <= n; k *= i)
			{
				ans = ans * 1ll * i % mod;
			}
		}
		for (register int j = 1; j <= tot && i * prime[j] <= N; j++)
		{
			v[i * prime[j]] = 1;
			if (i % prime[j] == 0)
				break;
		}
	}
}
int main ()
{
	cin >> n;
	sieve();
	cout << ans << endl;
	return 0 ;
}