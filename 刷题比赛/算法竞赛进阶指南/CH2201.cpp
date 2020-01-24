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
int c[20];
bool cmp(int a, int b)
{
	return a > b;
}
int n, w;
int cab[20];
int ans = 1e9;
void dfs(int now, int cnt)
{
	if (cnt >= ans) return ;
	if (now == n + 1)
	{
		ans = min(ans, cnt);
		return ;
	}
	for (int i = 1; i <= cnt; i++)
	{
		if (cab[i] + c[now] <= w)
		{
			cab[i] += c[now];
			dfs(now + 1, cnt);
			cab[i] -= c[now];
		}
	}
	cab[cnt + 1] = c[now];
	dfs(now + 1, cnt + 1);
	cab[cnt + 1] = 0;
}
int main ()
{
	read(n);
	read(w);
	for (int i = 1; i <= n; i++) read(c[i]);
	sort(c + 1, c + n + 1, cmp);
    dfs(1,0);
    cout<<ans<<endl;
	return 0 ;
}