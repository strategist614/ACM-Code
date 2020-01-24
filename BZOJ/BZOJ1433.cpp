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
const int N = 1005;
int ver[N << 1], Next[N << 1], head[N];
int a[55];
int b[55];
int match[55];
int visit[55];
int tot;
void init()
{
	memset(match, 0, sizeof(match));
	memset(head, 0, sizeof(head));
	tot = 0;

}
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

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int t;
	read(t);
	while (t--)
	{
		init();
		int n;
		read(n);
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= n; i++) read(b[i]);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 0 || (a[i] == 1 && b[i] == 0)) cnt++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] == 1 && b[i] == 0) add(i, i);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int x;
				read(x);
				if (a[i] == 0 || (a[i] == 1 && b[i] == 0))
				{
					if (x && a[j]) add(i, j);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			memset(visit, 0, sizeof(visit));
			if (a[i] == 0 || (a[i] == 1 && b[i] == 0))
			{
				if (dfs(i)) ans++;
			}
		}
		if (ans == cnt) printf("^_^\n");
		else printf("T_T\n");
	}
	return 0 ;
}