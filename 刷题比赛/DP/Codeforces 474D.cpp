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
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
ll sum[N];
ll f[N];
int a[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t, k;
	read(t);
	read(k);
	for (int i = 0; i < k; i++)
		f[i] = 1;
	for (int i = k; i <= N - 5; i++) {
		f[i] = (f[i - 1] + f[i - k]) % mod;
	}
	sum[0] = 0;
	for (int i = 1; i <= N - 5; i++)
		sum[i] = (sum[i - 1] + f[i]) % mod;
	while (t--) {
        int a,b;
        read(a);
        read(b);
        ll ans = (sum[b] - sum[a - 1] + mod) % mod;
        out(ans);
        puts("");
	}
	return 0 ;
}