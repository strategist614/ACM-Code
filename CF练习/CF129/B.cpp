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
const int N = 10005;
int deg[N];
std::vector<int> g[N];
int n, m;

void add(int x, int y)
{
	g[x].push_back(y);
	g[y].push_back(x);
	deg[x] ++;
	deg[y] ++;
}
queue<int> q;
int ans;
void bfs()
{
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 1) q.push(i);
	}
	while (q.size())
	{
		int cnt =  0;
		int b[105];
		while (q.size())
		{
			b[cnt++] = q.front();
			q.pop();
		}
		if (cnt > 0) ans++;
		for (int i = 0; i < cnt; i++)
		{
			int y = b[i];
			deg[y]--;
			for (int j = 0; j < g[y].size(); j++)
			{
				int _ = g[y][j];
				if (deg[_] >= 1) deg[_] --;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] == 1) q.push(i);
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	bfs();
	cout << ans << endl;
	return 0;
}