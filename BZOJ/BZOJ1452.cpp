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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
#define lowbit(x) x & -x
const int N = 305;
int c[105][N][N];
int a[N][N];
int n, m;
void update(int rt, int x, int y, int val)
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		for (int j = y; j <= m; j += lowbit(j))
			c[rt][i][j] += val;
	}
}
int ask(int rt, int x, int y)
{
	int ans = 0;
	for (int i = x; i; i -= lowbit(i))
	{
		for (int j = y; j; j -= lowbit(j))
		{
			ans += c[rt][i][j];
		}
	}
	return ans;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			read(a[i][j]);
			update(a[i][j], i, j, 1);
		}
	}
	int q;
	read(q);
	while (q--)
	{
		int op;
		read(op);
		if (op == 1)
		{
			int x, y, c;
			read(x);
			read(y);
			read(c);
			update(a[x][y], x, y, -1);
			a[x][y] = c;
			update(c, x, y, 1);
		}
		else
		{
			int x1, y1, x2, y2, c;
			read(x1);
			read(x2);
			read(y1);
			read(y2);
			read(c);
			int ans = ask(c, x2, y2) - ask(c, x2, y1 - 1) - ask(c, x1 - 1, y2) + ask(c, x1 - 1, y1 - 1);
			printf("%d\n", ans);
		}
	}
	return 0 ;
}