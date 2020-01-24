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
const int N = 2e5 + 5;
int L[N], R[N];
int a[N], to[N], cs[N], pos[N];
int n, m;
void solve(int i)
{
	to[i] = i + a[i];
	if (to[i] > R[pos[i]]) cs[i] = 1;
	else cs[i] = cs[to[i]] + 1, to[i] = to[to[i]];
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	cin >> n ;
	int t = sqrt(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= t; i++)
	{
		L[i] = (i - 1) * sqrt(n) + 1;
		R[i] = i * sqrt(n);
	}
	if (R[t] < n) t++, L[t] = R[t - 1] + 1, R[t] = n;
	for (int i =  1; i <= t; i++)
		for (int j = L[i]; j <= R[i]; j++)
		{
			pos[j] = i;
		}
	for (int i = t; i >= 1; i--)
	{
		for (int j = R[i]; j >= L[i]; j --) {
			solve(j);
		}
	}
	cin >> m;
	while (m--)
	{
		int op;
		read(op);
		if (op == 2)
		{
			int x, y;
			read(x);
			read(y);
			x++;
			a[x] = y;
			for (int i = R[pos[x]]; i >= L[pos[x]]; i--) solve(i);
		}
		else
		{
			int x;
			read(x);
			x++;
			int ans = 0;
			while (x <= n) {ans += cs[x]; x = to[x];}
			printf("%d\n",ans);
		}
	}
	return 0 ;
}