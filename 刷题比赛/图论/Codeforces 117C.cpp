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
const int N = 5005;
char b[N][N];
int a[N][N];
int n;
int vis[N * N];
bool dfs(int i, int fa) {
	vis[i] = 1;
	for (int j = 1; j <= n; j++) {
		if (a[i][j])
		{
			if (a[j][fa]) {
				printf("%d %d %d\n", fa, i, j);
				return true;
			}
			else if (!vis[j]) {
				if (dfs(j, i))
					return true;
			}
		}
	}
	return false;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	read(n);
	for (int i = 1; i <= n; i++)
		scanf("%s", b[i] + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			a[i][j] = b[i][j] - '0';
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			if (dfs(i, i)) return 0;
		}
	}
	printf("-1\n");
	return 0 ;
}