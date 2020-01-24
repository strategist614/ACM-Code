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
const int SIZE = 100010;
int head[SIZE], ver[SIZE * 2], Next[SIZE * 2];
int dfn[SIZE], low[SIZE], Stack[SIZE];
int n, m, tot, num, root, top, cnt;
bool cut[SIZE];
vector<int> dcc[SIZE];

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}


void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	Stack[++top] = x;
	/*if (x == root && head[x] == 0) {
		dcc[++cnt].push_back(x);
		return;
	}*/
	int flag = 0;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) {
				flag++;
				if (x != root || flag > 1) cut[x] = true;
				cnt++;
				int z;
				do {
					z = Stack[top--];
					dcc[cnt].push_back(z);
				} while (z != y);
				dcc[cnt].push_back(x);
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}

void init()
{
	memset(head, 0, sizeof(head));
	memset(cut, 0, sizeof(cut));
	memset(Stack, 0, sizeof(Stack));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	//memset(vx,0,sizeof(vx));
	tot = 1;
	cnt = 0;
	top = 0;
	root = 0;
	num = 0;
}

int main ()
{
	int flag = 0;
	while (~scanf("%d", &n) && n)
	{
		init();
		for (int i = 1; i <= n; i++) dcc[i].clear();
		for (int i = 1; i <= n; i++)
		{
			int u, v;
			read(u);
			read(v);
			add(u, v);
			add(v, u);
		}
		for (int i = 1; i <= n; i++)
		{
			if (!dfn[i]) root = i, tarjan(i);
		}
		ll ans1 = 0;
		ll ans2 = 1;
		for (int i = 1; i <= cnt; i++) {
			int _ = 0;
			for (int j = 0; j < dcc[i].size(); j++)
			{
				if (cut[dcc[i][j]]) _++;
			}
			if (_ == 1)
			{
				ans1++;
				ans2 *= (ll)(dcc[i].size() - 1);
			}
		}
		if (cnt == 1)
		{
			ans1 = 2;
			ans2 = (ll)(dcc[1].size() - 1) * dcc[1].size() / 2;
		}
		printf("Case %d: %lld %lld\n", ++flag, ans1, ans2);
	}
	return 0 ;
}