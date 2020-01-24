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
const int N = 1e6 + 6;
const int M = 2e6 + 6;
int head[N], Next[M], ver[M];
int visit[N];
int tot, n, m;
int ans;
int match[N];
int T;

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

bool dfs(int x) {
	for (int i = head[x], y; i; i = Next[i])
		if (visit[y = ver[i]] != T) {
			visit[y] = T;
			if (!match[y] || dfs(match[y])) {
				match[y] = x;
				return true;
			}
		}
	return false;
}

int main () {
	//freopen("1.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	for (int i = 1; i <= n; i++)
	{
		int u, v;
		read(u);
		read(v);
		add(u, i);
		add(v, i);
	}
	for (int i = 1; i <= 10000; i++) {
		T++;
		if (dfs(i)) ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}