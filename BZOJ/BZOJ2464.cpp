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
typedef pair<int, int> pii;
const int N = 505;
int n, m;
char a[N][N];
int dis[N][N];
int vis[N][N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void bfs(int sx, int sy, int ex, int ey)
{
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	queue<pii> q;
	vis[sx][sy] = 1;
	dis[sx][sy] = 0;
	q.push(make_pair(sx, sy));
	while (q.size())
	{
		pii tmp = q.front();
		q.pop();
		vis[tmp.first][tmp.second] = 0;
		for (int i = 0; i < 4; i++)
		{
			int x = tmp.first + dx[i];
			int y = tmp.second + dy[i];
			if (x < 0 || x > n - 1 || y < 0 || y > m - 1) continue;
			int s = (a[x][y] == a[tmp.first][tmp.second] ? 0 : 1);
			if (dis[x][y] > dis[tmp.first][tmp.second] + s)
			{
				dis[x][y] = dis[tmp.first][tmp.second] + s;
				if (!vis[x][y]) {
					vis[x][y] = 1;
					q.push(make_pair(x, y));
				}
			}
		}
	}
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while (~scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> a[i][j];
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		bfs(sx, sy, ex, ey);
		cout << dis[ex][ey] << endl;
	}
	return 0 ;
}