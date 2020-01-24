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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 2505;
int deg[N];
struct node
{
	int x;
	int y;
};
std::vector<node> v;
int fa[N];
bool cmp(node a, node b)
{
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int get(int x) {
	if (x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}

void merge(int x, int y) {
	fa[get(x)] = get(y);
}

int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		read(u);
		read(v);
		deg[u]++;
		deg[v]++;
		merge(u, v);
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] >= 3)
		{
			puts("NO");
			return 0;
		}
	}
	// 不同联通块相连
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (deg[i] != 2 && deg[j] != 2 && get(i) != get(j))
			{
				merge(i, j);
				deg[i]++;
				deg[j]++;
				v.push_back(node{j, i});
			}
		}
	}
	//同一个联通块首尾相连
	for (int i = 2; i <= n; i++)
	{
		if (deg[i] == 2) continue;
		for (int j = 1; j < i; j++)
		{
			if (deg[j] <= 1)
			{
				merge(j, i);
				deg[i] ++;
				deg[j] ++;
				v.push_back(node{j, i});
			}
		}
	}
	// 一个点成自环
	for (int i = 1; i <= n; i++)
		if (!deg[i]) v.push_back(node{i, i});
	int r = get(1);
	for (int i = 1; i <= n; i++)
	{
		if (get(i) != r) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	cout << v.size() << endl;
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++)
		cout << v[i].x << ' ' << v[i].y << endl;
	return 0 ;
}