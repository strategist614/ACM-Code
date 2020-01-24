/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<math.h>
#include<algorithm>

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
const int N = 5010, _M = 200010;
int ver[_M], edge[_M], cost[_M], Next[_M], head[N];
int d[N], incf[N], pre[N], v[N];
int n, m, tot, s, t, maxflow, ans;
char a[N][N];

std::vector<pair<int, int> > H, M;

void add(int x, int y, int z, int c) {
	ver[++tot] = y, edge[tot] = z, cost[tot] = c;
	Next[tot] = head[x], head[x] = tot;
	ver[++tot] = x, edge[tot] = 0, cost[tot] = -c;
	Next[tot] = head[y], head[y] = tot;
}

int dis(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}


bool spfa() {
	queue<int> q;
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	q.push(s); d[s] = 0; v[s] = 1;
	incf[s] = 1 << 30;
	while (q.size()) {
		int x = q.front(); v[x] = 0; q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			if (!edge[i]) continue;
			int y = ver[i];
			if (d[y] > d[x] + cost[i]) {
				d[y] = d[x] + cost[i];
				incf[y] = min(incf[x], edge[i]);
				pre[y] = i;
				if (!v[y]) v[y] = 1, q.push(y);
			}
		}
	}
	if (d[t] == 0x3f3f3f3f) return false;
	return true;
}


void update() {
	int x = t;
	while (x != s) {
		int i = pre[x];
		edge[i] -= incf[t];
		edge[i ^ 1] += incf[t];
		x = ver[i ^ 1];
	}
	maxflow += incf[t];
	ans += d[t] * incf[t];
}

int main ()
{
	while (~scanf("%d %d", &n, &m)) {
		if (n == 0 && m == 0) break;
		tot = 1;
		ans = 0;
		maxflow = 0;
		H.clear();
		M.clear();
		memset(head, 0, sizeof(head));
		memset(incf, 0, sizeof(incf));
		memset(pre, 0, sizeof(pre));
		memset(cost, 0, sizeof(cost));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i][j] == 'H') {H.push_back(make_pair(i, j));}
				if (a[i][j] == 'm') {M.push_back(make_pair(i, j));}
			}
		}
		int _ = H.size();
		s = 2 * _;
		t = 2 * _ + 1;
		for (int i = 0; i < _; i++) {
			add(s, i, 1, 0);
			add(i + _, t, 1, 0);
		}
		for (int i = 0; i < H.size(); i++) {
			for (int j = 0; j < M.size(); j++)
			{
				int c = dis(H[i].first, H[i].second, M[j].first, M[j].second);
				add(i, j + _, 1, c);
			}
		}
		while (spfa()) update();
		printf("%d\n", ans);
	}
	return 0 ;
}