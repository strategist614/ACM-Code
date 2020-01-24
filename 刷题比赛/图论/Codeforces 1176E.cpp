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
const int N = 2e5 + 5;
std::vector<int> g[N];
int vis[N];
void dfs(int x) {
	for (int i = 0; i < g[x].size(); i++) {
		if (vis[g[x][i]]) continue;
		int y = g[x][i];
		vis[y] = (vis[x] == 1) ? 2 : 1;
		dfs(y);
	}
}
int main ()
{
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		read(n);
		read(m);
		for (int i = 1; i <= n; i++) g[i].clear();
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= m; i++) {
			int u, v;
			read(u);
			read(v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vis[1] = 1;
		dfs(1);
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 1) ans1++;
			else ans2++;
		}
		if (ans1 <= n / 2) {
			cout << ans1 << endl;
			for (int i = 1; i <= n; i++) {
				if (vis[i] == 1)
					cout << i << " ";
			}
			cout << endl;
			continue;
		}
		if (ans2 <= n / 2) {
			cout << ans2 << endl;
			for (int i = 1; i <= n; i++) {
				if (vis[i] == 2)
					cout << i << " ";
			}
			cout << endl;
			continue;
		}
	}
	return 0 ;
}