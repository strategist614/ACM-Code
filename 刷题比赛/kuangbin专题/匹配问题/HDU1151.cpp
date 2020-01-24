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
const int N = 20000;
int head[N], ver[N], Next[N];
int tot = 0;
int v[N], match[N];

void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

bool dfs(int x) {
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!v[y]) {
			v[y] = 1;
			if (!match[y] || dfs(match[y]))
			{
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int main ()
{
	int t;
	read(t);
	while (t--) {
		memset(head, 0, sizeof(head));
		tot = 0 ;
		memset(match, 0, sizeof(match));
		int n, m;
		read(n);
		read(m);
		for (int i = 1; i <= m; i++) {
			int u, v;
			read(u);
			read(v);
			add(u, v + n);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			memset(v, 0, sizeof(v));
			if (dfs(i)) ans++;
		}
		cout << n - ans << endl;
	}
	return 0 ;
}