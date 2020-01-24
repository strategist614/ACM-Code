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
const int N = 10005;
int prime[N];
bool is_prime[N];
int tot = 0 ;
int cnt = 0 ;
int p[N], c[N];
void divid(int n) {
	cnt = 0;
	memset(p, 0, sizeof(p));
	memset(c, 0, sizeof(c));
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			p[++cnt] = i;
			c[cnt] = 0;
			while (n % i == 0) n /= i , c[cnt]++;
		}
	}
	if (n > 1) p[++cnt] = n, c[cnt]++;
}
void sieve() {
	for (int i = 0; i <= N; i++) is_prime[i] = 1;
	is_prime[0] = is_prime[1] = 0;
	for (int i = 2; i <= N; i++) {
		if (is_prime[i]) {
			prime[++tot] = i;
			for (int j = i * 2; j <= N; j += i) is_prime[j] = 0;
		}
	}
}
int solve(int x, int y) {
	if (x < y) return 0;
	return x / y + solve(x / y, y);
}
map<int, int> mp;
int main ()
{
	sieve();
	int t;
	read(t);
	int flag = 0;
	while (t--) {
		mp.clear();
		int n, m;
		read(m);
		read(n);
		for (int i = 1; i <= tot && prime[i] <= n; i ++) {
			mp[prime[i]] = solve(n, prime[i]);
		}
		divid(m);
		int _ = 0;
		int ans = 1e9;
		for (int i = 1; i <= cnt; i++) {
			if (!mp[p[i]]) {
				_ = 1;
			}
			else
				ans = min(ans, mp[p[i]] / c[i]);
		}
		printf("Case %d:\n", ++flag);
		if (!_) printf("%d\n", ans);
		else printf("Impossible to divide\n");
	}
	return 0 ;
}