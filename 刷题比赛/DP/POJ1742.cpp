/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>

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
bool f[N];
int used[N];
int a[N], c[N];
int n, m;
void init() {
	memset(f, 0, sizeof(f));
	memset(used, 0, sizeof(used));
	memset(a, 0, sizeof(a));
	memset(c, 0, sizeof(c));
}
void solve() {
	f[0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) used[j] = 0;
		for (int j = a[i]; j <= m; j++)
			if (!f[j] && f[j - a[i]] && used[j - a[i]] < c[i])
				f[j] = true, used[j] = used[j - a[i]] + 1;
	}
	int ans = 0;
	for (int i = 1; i <= m; i++)
		ans += f[i];
	cout << ans << endl;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	//int n,m;
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		init();
		for (int i = 1; i <= n; i++)
			read(a[i]);
		for (int i = 1; i <= n; i++)
			read(c[i]);
		solve();
	}
	return 0 ;
}