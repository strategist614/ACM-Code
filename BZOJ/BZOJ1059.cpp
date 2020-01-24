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
const int N = 205;
const int M = 40005;
int head[N], Next[M], ver[M], visit[N], match[N];
int n;
int a[N][N];
int tot;
int cnt = 0;
void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

bool dfs(int x) {
	for (int i = head[x], y; i; i = Next[i])
		if (!visit[y = ver[i]]) {
			visit[y] = 1;
			if (!match[y] || dfs(match[y])) {
				match[y] = x;
				return true;
			}
		}
	return false;
}

bool solve()
{
	for (int i = 1; i <= n; i++)
	{
		memset(visit,0,sizeof(visit));
		if (!dfs(i)) return 0;
	}
	return 1;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--)
	{
		cnt = 0;
		tot = 0;
		read(n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				read(a[i][j]);
		}
		memset(head, 0, sizeof(head));
		memset(match, 0, sizeof(match));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] == 1)
					add(i, j);
			}
		}
		if (solve()) puts("Yes");
		else puts("No");
	}
	return 0 ;
}