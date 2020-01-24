/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
  去做难度超过自己平时比赛能过的题难度的题，独立思考2-3小时再看题解
  反正，div2 A/B都做不利索的，请多做点题。
  div2 C要求一点脑洞和洞察力，刻意让自己思考一下，还是能培养出来的。
  更后面的题，那就是靠算法知识的积累+自己的大量思考了。
  做题不补等于白做
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
int cnt[55];
std::vector<int> g[55];
std::vector<int> v;
int p, q;
int vis[55];
int in[55];
void add(int u, int v)
{
	g[u].push_back(v);
}
int flag = 0;
void dfs(int x)
{
	vis[x] = 1;
	if (x == v[1]) {
		flag = 1;
		return ;
	}
	for (int i =  0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (vis[y]) continue;
		dfs(y);
	}
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	int _ = (n - 1) * n / 2;
	for (int i = 1; i <= _ - 1; i++) {
		int u, v;
		read(u);
		read(v);
		add(u, v);
		in[v]++;
		cnt[u]++;
		cnt[v]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i])
		{
			if (cnt[i] != n - 1) v.push_back(i);
		}
	}
	dfs(v[0]);
	if (flag == 1)
	{
		cout << v[0] << ' ' << v[1] << endl;
	}
	else
	{
		cout << v[1] << ' ' << v[0] << endl;
	}
	return 0 ;
}