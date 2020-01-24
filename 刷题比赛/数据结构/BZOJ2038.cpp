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
const int N = 5e5 + 5;
int a[N];
int block[N];
struct Mo
{
	int l;
	int r;
	int pos;
	ll zi;
	ll mu;
} b[N];
bool cmp1(Mo a, Mo b) {
	if (block[a.l] == block[b.l]) return a.r < b.r;
	else return a.l < b.l;
}
bool cmp2(Mo a, Mo b) {
	return a.pos < b.pos;
}
int sum[N];
ll num = 0;
void del(int x) {
	num -= (--sum[a[x]]);
}
void add(int x) {
	num += (sum[a[x]]++);
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	int size = sqrt(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	for (int i = 1; i <= m; i++) {
		read(b[i].l);
		read(b[i].r);
		block[i] = i / size;
		b[i].pos = i;
	}
	int l = 1;
	int r = 0;
	sort(b + 1, b + m + 1, cmp1);
	for (int i = 1; i <= m; i++) {
		while (l < b[i].l) {
			del(l++);
		}
		while (l > b[i].l) {
			add(--l);
		}
		while (r > b[i].r)
		{
			del(r--);
		}
		while (r < b[i].r)
		{
			add(++r);
		}
		ll mu = (ll)(b[i].r - b[i].l + 1) * (b[i].r - b[i].l) / 2;
		if (b[i].l == b[i].r)
		{
			b[i].zi = 0;
			b[i].mu = 1;
		}
		else
		{
			ll x = gcd(mu, num);
			b[i].zi = num / x;
			b[i].mu = mu / x;
		}
	}
	sort(b + 1, b + m + 1, cmp2);
	for (int i = 1; i <= m; i++) {
		printf("%lld/%lld\n", b[i].zi, b[i].mu);
	}
	return 0 ;
}