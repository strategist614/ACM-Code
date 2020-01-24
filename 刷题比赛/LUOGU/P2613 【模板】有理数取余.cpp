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
const int mod = 19260817;

inline void read(long long &x) {
	int f = 1; x = 0; char s = getchar();
	while (s > '9' || s < '0') {if (s == '-')f = -1; s = getchar();}
	while (s <= '9' && s >= '0') {x = x * 10 % mod + (s - '0') % mod; s = getchar();}
	x = x % mod * f;
}

inline ll ksm(ll a, ll b)
{
	ll ans = 1 % mod;
	while (b)
	{
		if (b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans % mod;
}
int main ()
{
	ll a, b;
	read(a);
	read(b);
	if (b == 0) printf("Angry!\n");
	else
	{
		printf("%lld\n", (a * ksm(b, mod - 2) % mod + mod) % mod);
	}
	return 0 ;
}