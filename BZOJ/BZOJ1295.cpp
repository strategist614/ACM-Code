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
#define pii pair<int,int>
const int N = 35;
char a[N][N];
int dis[N][N];
int vis[N][N];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int n, m, t;
void bfs(int x, int y)
{
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x3f, sizeof(dis));
	queue<pii> q;
	vis[x][y] = 1;
	dis[x][y] = a[x][y] - '0';
	q.push(make_pair(x, y));
	while (q.size())
	{
		pii tmp = q.front();
		q.pop();
		vis[tmp.first][tmp.second] = 0;
		for (int i = 0; i < 4; i++)
		{
			int x = tmp.first + dx[i];
			int y = tmp.second + dy[i];
			if (x < 1 || x > n || y < 1 || y > m) continue;
			if (dis[x][y] > dis[tmp.first][tmp.second] + (a[x][y] - '0'))
			{
				dis[x][y] = dis[tmp.first][tmp.second] + (a[x][y] - '0');
				if (!vis[x][y])
				{
					vis[x][y] = 1;
					q.push(make_pair(x, y));
				}
			}
		}
	}
}
inline double dist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main ()
{
	//freopen("6.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	read(t);
	for (int i = 1; i <= n; i++)
		scanf("%s", a[i] + 1);
	double ans = 0.0;
	int i, j, k, l;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			bfs(i, j);
			for (k = 1; k <= n; k++) {
				for (l = 1; l <= m; l++) {
					if (dis[k][l] <= t)
					{
						ans = max(ans, dist(i, j, k, l));
					}
				}
			}
		}
	}
	printf("%.6lf\n", ans);
	return 0 ;
}