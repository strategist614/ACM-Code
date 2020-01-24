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
int a[N];
std::vector<int> v[N];
int vis[N * 10];
void solve(int n, int x)
{
	if (n == 1)
	{
		v[x].push_back(1);
		return ;
	}
	v[x].push_back(1);
	v[x].push_back(n);
	for (register int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			v[x].push_back(i);
			if (n / i != i) v[x].push_back(n / i);
		}
	}
}
int ans[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	for (register int i = 1; i <= n; i++) {read(a[i]); vis[a[i]]++;}
	for (register int i = 1; i <= n; i++)
	{
		solve(a[i], i);
	}
	for (register int i = 1; i <= n; i++) {
		int tmp = 0;
		for (register int j = 0; j < v[i].size(); j++) {
			if (vis[v[i][j]])
			{
				if (v[i][j] == a[i]) {
					if (vis[a[i]] >= 2)
						tmp += vis[a[i]] - 1;
				}
				else
				{
					tmp += vis[v[i][j]];
				}
			}
		}
		ans[i] = tmp;
	}
	for (register int i = 1; i <= n; i++)
	{
		out(ans[i]);
		puts("");
	}
	return 0 ;
}
