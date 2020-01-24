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
const int N = 10005;
int n, b;
std::vector<int> g[N];
int ans[N];
void add(int x, int y) {
	g[x].push_back(y);
	g[y].push_back(x);
}
int top = 0;
int a[N];
int vis[N];
int tot = 0;
int root[N];
void dfs(int u, int fa) {
	int t = top;
	for (int i = 0; i < g[u].size(); i++) {
		int y = g[u][i];
		if (vis[y]) continue;
		vis[y] = 1;
		dfs(y, u);
		if (top - t >= b)
		{
			root[++tot] = u;
			while (top > t) {
				ans[a[top--]] = tot;
			}
		}
	}
	a[++top] = u;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	//int n,b;
	read(n);
	read(b);
	for (int i = 1; i <= n - 1; i++) {
		int u, v;
		read(u);
		read(v);
		add(u, v);
	}
	dfs(1, 0);
	while(top) {
		ans[a[--top]] = tot;
	}
	cout << tot << endl;
	for(int i= 1; i<= n;i++) 
		cout << ans[i] <<" ";
	cout << endl;
	for(int i =1;i <= tot;i++)
		cout << root[i] <<" ";
	cout << endl;
	return 0 ;
}