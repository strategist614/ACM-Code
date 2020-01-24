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
const int N = 1e6 + 5;
int n, m;
int head[N], ver[N * 2], Next[N * 2], edge[N * 2];
int dfn[N], low[N], tot, num;
bool bridge[N * 2];
int cnt = 0;
std::vector<int> v;

void init() {
	v.clear();
	memset(head, 0, sizeof(head));
	memset(bridge, 0, sizeof(bridge));
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(edge,0,sizeof(edge));
	tot = 1;
	num = 0;
	cnt = 0;
}

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void tarjan(int x, int in_edge) {
	dfn[x] = low[x] = ++num;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y, i);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x])
				bridge[i] = bridge[i ^ 1] = true;
		}
		else if (i != (in_edge ^ 1))
			low[x] = min(low[x], dfn[y]);
	}
}

int main ()
{
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0 && m == 0) break;
		init();
		for (int i = 1; i <= m; i++) {
			int x, y, z;
			read(x);
			read(y);
			read(z);
			add(x, y, z);
			add(y, x, z);
		}
		for (int i = 1; i <= n; i++) {
			if (!dfn[i]) cnt++,tarjan(i, 0);
		}
		for (int i = 2; i < tot; i += 2) {
            if(bridge[i])
            	v.push_back(edge[i]);
		}
		sort(v.begin(),v.end());
		if(cnt > 1){
			printf("0\n");
		}
		else 
		{
			if(v.size() == 0) printf("-1\n");
			else {
				if(v[0] == 0) printf("1\n");
				else printf("%d\n",v[0]);
			}
		}
	}
	return 0 ;
}