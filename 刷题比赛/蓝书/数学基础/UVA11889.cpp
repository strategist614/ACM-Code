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
const int N = 1000;
int p1[N], c1[N], tot = 0;
int p2[N], c2[N];
map<int, int> vis;
int ksm(int a, int b) {
	int ans = 1;
	while (b > 0) {
		if (b & 1) ans = ans * a;
		a = a * a;
		b >>= 1;
	}
	return ans;
}
void divid1(int n) {
	memset(p1, 0, sizeof(p1));
	memset(c1, 0, sizeof(c1));
	tot = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			p1[++tot] = i;
			c1[tot] = 0;
			while (n % i == 0) n /= i, c1[tot]++;
		}
	}
	if (n > 1) p1[++tot] = n, c1[tot]++;
}
void divid2(int n) {
	memset(p2, 0, sizeof(p2));
	memset(c2, 0, sizeof(c2));
	tot = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			p2[++tot] = i;
			c2[tot] = 0;
			while (n % i == 0) n /= i, c2[tot]++;
		}
	}
	if (n > 1) p2[++tot] = n, c2[tot]++;
}
int main ()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		vis.clear();
		int x, y;
		scanf("%d %d", &x, &y);
		if (x == 1)
		{
			if (y == 1) {
				printf("1\n");
			}
			else printf("%d\n", y);
			continue;
		}
		divid1(x);
		int __ = tot;
		for (int i = 1; i <= tot; i++) {
			vis[p1[i]] = c1[i];
		}
		divid2(y);
		int ans = 1;
		int _ = 0;
		for (int i = 1; i <= tot; i++)
		{
			if (!vis[p2[i]]) {
				ans *= ksm(p2[i], c2[i]);
				//_++;
			}
			else {
				_++;
				if (vis[p2[i]] < c2[i])
				{
					ans *= ksm(p2[i], c2[i]);
				}
			}
		}
		if (_ != __) {
			printf("NO SOLUTION\n");
			continue;
		}
		printf("%d\n", ans);
	}
	return 0 ;
}