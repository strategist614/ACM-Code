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
const int N = 3e4 + 5;
const int M = 3e5 + 5;
int ver[N], Next[M], head[N], deg[N];
int tot = 0, cnt = 0;
int a[N];
bitset<N> b[N];
int n, m;
int ans[N];
void add(int x, int y)
{
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
	deg[y]++;
}
void topsort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) q.push(i);
	while (q.size())
	{
		int x = q.front();
		q.pop();
		a[++cnt] = x;
		for (int i = head[x]; i; i = Next[i])
		{
			int y = ver[i];
			if (--deg[y] == 0) q.push(y);
		}
	}
}
int main ()
{
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) b[i].reset();
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		read(x);
		read(y);
		add(x, y);
		b[x][y] = 1;
	}
	for (int i = 1; i <= n; i++) b[i][i] = 1;
	topsort();
	for (int i = cnt; i >= 1; i--)
	{
		int x = a[i];
		for (int j = head[x]; j; j = Next[j])
			b[x] |= b[ver[j]];
        ans[x] = b[x].count();
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << endl;
	return 0 ;
}