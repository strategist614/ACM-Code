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
const int N = 205;
int n;
int a[105][105];
std::vector<int> g[N];
int L[N], R[N];
int v[N], match[N];

bool dfs(int x) {
	for (int  i = 0; i < g[x].size(); i++) {
		int y = g[x][i];
		if (!v[y]) {
			v[y] = 1;
			if (!match[y] || dfs(match[y]))
			{
				match[y] = x;
				return true;
			}
		}
	}
	return false;
}

int main ()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) g[i].clear();
		memset(match, 0, sizeof(match));
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				scanf("%d", &a[i][j]);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (a[i][j] == 1) g[i].push_back(j);
			}
		}
		int ans = 0 ;
		for (int i = 1; i <= n; i++)
		{
			memset(v, 0, sizeof(v));
			if (dfs(i)) ans++;
		}
		if (ans == n) {
			int tot = 0;
			for (int i = 1; i <= n; i++) {
				if (match[i] != i) {
					for (int j = 1; j <= n; j++) {
						if (match[j] == i)
						{
							L[tot] = i;
							R[tot] = j;
							tot++;
							swap(match[i], match[j]);
							break;
						}
					}
				}
			}
			printf("%d\n", tot);
			for (int i = 0; i < tot; i++)
				printf("C %d %d\n", L[i], R[i]);
		}
		else puts("-1");
	}
	return 0 ;
}