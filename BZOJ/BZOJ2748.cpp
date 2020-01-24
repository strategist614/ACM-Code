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
const int N = 55;
int a[N];
int f[N][1005];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, bl, ml;
	read(n);
	read(bl);
	read(ml);
	for (int i = 1; i <= n; i++) read(a[i]);
	memset(f, 0, sizeof(f));
	f[0][bl] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= ml; j++)
		{
			if (j + a[i] <= ml && f[i - 1][j + a[i]])
				f[i][j] = 1;
			if (j - a[i] >= 0 && f[i - 1][j - a[i]])
				f[i][j] = 1;
		}
	}
	int ans = 0;
	for (int i = ml; i >= 0; i--)
		if (f[n][i]) {ans = i; break;}
	if (ans) cout << ans << endl;
	else cout << -1 << endl;
	return 0;
}