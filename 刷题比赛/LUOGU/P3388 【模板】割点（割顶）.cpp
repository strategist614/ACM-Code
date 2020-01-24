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

const int N = 1e5 + 5;
int head[N], ver[N * 2], Next[N * 2];
int dfn[N], low[N], n, m, tot, num, root;
bool cut[N];
std::vector<int> v;

void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}

void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	int flag = 0;
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!dfn[y]) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
			if (low[y] >= dfn[x]) {
				flag ++;
				if (x != root || flag > 1) cut[x] = true;
			}
		}
		else low[x] = min(low[x], dfn[y]);
	}
}

int main ()
{
	cin >> n >> m;
	tot = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		read(x);
		read(y);
		if (x == y) continue;
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) root = i, tarjan(i);
	}
	for (int i = 1; i <= n; i++) {
		if (cut[i]) v.push_back(i);
	}
	printf("%d\n",v.size());
	sort(v.begin(),v.end());
	for(int i = 0;i < v.size();i++)
		cout<<v[i]<<" ";
	return 0 ;
}