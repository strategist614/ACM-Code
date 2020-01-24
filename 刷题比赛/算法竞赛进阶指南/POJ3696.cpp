/*
独立思考
*/
#include <math.h>
#include <cstdio>
#include <iostream>
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
ll d, k, p, s, L;
ll phi(ll n) {
	ll ans = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}

ll gcd(ll x, ll y) {
	return y ? gcd(y, x % y) : x;
}


ll ksc(ll a, ll b, ll c) {
	ll ans = 0;
	while (b) {
		if (b & 1) ans = (ans + a) % c;
		a = a * 2 % c;
		b >>= 1;
	}
	return ans;
}

ll ksm(ll a, ll b, ll c) {
	ll ans = 1 % c;
	a %= c;
	while (b) {
		if (b & 1) ans = ksc(ans, a, c);
		a = ksc(a, a, c);
		b >>= 1;
	}
	return ans;
}

ll number() {
	d = gcd(L, 8ll);
	k = 9 * L / d;
	if (gcd(k, 10ll) != 1) return 0;
	p = phi(k);
	s = sqrt(p);
	for (int i = 1; i <= s; i++)
		if (p % i == 0 && ksm(10ll, i, k) == 1)
			return i;
	for (int i = s - 1; i; i--)
		if (p % i == 0 && ksm(10ll, p / i, k) == 1)
			return p / i;
	return 0;
}


int main ()
{
	int flag = 0;
	while (scanf("%lld", &L) != EOF && L)
	{
		printf("Case %d: %lld\n", ++flag, number());
	}
	return 0 ;
}