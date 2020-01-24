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
std::vector<int> g[N];
int inv[N];
void add(int x, int y)
{
	inv[y]++;
	g[x].push_back(y);
}
double ans = 0.0;
void dfs(int x, int pre, double f, int d)
{
	for (int i = 0; i < g[x].size(); i++)
	{
		int y = g[x][i];
		if (y == pre) continue;
		dfs(y, x, f / inv[x], d + 1);
	}
	if (inv[x] == 0){
		ans += f * (double)d ;
	}
}
int main ()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		read(u);
		read(v);
		add(u, v);
		add(v, u);
	}
	for (int i = 2; i <= n; i++) inv[i]--;
	dfs(1, 0, 1, 0);
	printf("%.8f\n",ans);
	return 0 ;
}
/*
4
1 2
1 3
2 4
*/
