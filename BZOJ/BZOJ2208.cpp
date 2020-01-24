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
const int N = 2005;
char s[N][N];
int g[N][N];
int vis[N * N];
int ans = 0;
std::vector<int> v[N];
void dfs(int x)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (vis[y]) continue;
		vis[y] = 1;
		dfs(y);
	}
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cin >> s[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (s[i][j] == '1')
				v[i].push_back(j);
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++) vis[j] = 0;
		vis[i] = 1;
		dfs(i);
		int num = 0;
		for (int j = 1; j <= n; j++)
		{
			if (vis[j]) num++;
		}
		ans += num;
	}
	printf("%d\n", ans);
	return 0 ;
}
/*
5
01100
00101
00011
00000
00000
*/