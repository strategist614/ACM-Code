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
const int M = 1e6 + 5;
int n, m, tot;
int head[N], Next[M], ver[M], visit[N];
int match[N];
int ans ;
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
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		read(x);
		read(y);
		add(i, x);
		add(i, y);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) ans++;
		else break;
	}
	cout << ans << endl;
	return 0;
}