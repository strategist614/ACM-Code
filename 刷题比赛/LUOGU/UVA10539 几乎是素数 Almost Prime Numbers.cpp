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
const int N = 1300000;
const ll INF = 1e12;
int p = 0;
int prime[N];
bool is_prime[N];
std::vector<ll> v;
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
void sieve() {
	for (int i = 0; i <= N; i++)is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i]) {
			prime[++p] = i;
			for (int j = 2 * i; j <= N; j += i)is_prime[j] = false;
		}
	}
}
void pre_work()
{
	sieve();
	for (int i = 1; i <= p; i++)
	{
		ll _ = 0;
		for (int j = 2;; j++)
		{
			if (_ > INF) break;
			_ = ksm(prime[i], j);
			v.push_back(_);
		}
	}
}
int main ()
{
	pre_work();
	sort(v.begin(), v.end());
	int t;
	cin >> t;
	while (t--)
	{
		ll l, r;
		read(l);
		read(r);
		int _ = lower_bound(v.begin(), v.end(), l) - v.begin();
		int __ = upper_bound(v.begin(), v.end(), r) - v.begin();
		cout << __ - _ << endl;
	}
	return 0 ;
}
