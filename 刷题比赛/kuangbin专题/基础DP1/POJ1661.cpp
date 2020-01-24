/*
独立思考
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
const int N = 1005;
const int INF = 1e9;
struct node
{
	int l;
	int r;
	int h;
} a[N];
int n, x, y, maxn, dp[N][3];
bool cmp(node a, node b)
{
	return a.h < b.h;
}
void left(int i)
{
	int k = i - 1;
	while (k > 0 && a[i].h - a[k].h <= maxn)
	{
		if (a[i].l <= a[k].r && a[i].l >= a[k].l)
		{
			dp[i][0] = a[i].h - a[k].h + min(dp[k][0] + a[i].l - a[k].l, dp[k][1] + a[k].r - a[i].l);
			return ;
		}
		else k--;
	}
	if (a[i].h - a[k].h > maxn)
	{
		dp[i][0] = INF;
	}
	else dp[i][0] = a[i].h;
}
void right(int i)
{
	int k = i - 1;
	while (k > 0 && a[i].h - a[k].h <= maxn)
	{
		if (a[i].r >= a[k].l && a[i].r <= a[k].r)
		{
			dp[i][1] = a[i].h - a[k].h + min(dp[k][0] + a[i].r - a[k].l, dp[k][1] + a[k].r - a[i].r);
			return ;
		}
		else k--;
	}
	if (a[i].h - a[k].h > maxn)
		dp[i][1] = INF;
	else dp[i][1] = a[i].h;
}
int main ()
{
	int t;
	cin >> t;
	while (t--)
	{
		read(n);
		read(x);
		read(y);
		read(maxn);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].l >> a[i].r >> a[i].h;
		}
		a[0].l = -20000;
		a[0].r = 20000;
		a[0].h = 0;
		a[n + 1].l = x;
		a[n + 1].r = x;
		a[n + 1].h = y;
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n + 1; i++)
		{
			left(i);
			right(i);
		}
		int ans = INF;
		ans = min(dp[n + 1][0], dp[n + 1][1]);
		cout << ans << endl;
	}
	return 0 ;
}