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
const int N = 1e4 + 5;
int a[N];
int vis[N];
std::vector<int> v;
int n, m;
int f[N];
int solve()
{
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] >= 2)
		{
			int flag = 1;
			vis[i] -= 2;
			for (int j = 1; j <= n + 2; j ++) f[j] = vis[j];
			for (int j = 1; j <= n + 2; j++)
			{
				if (f[j] < 0) {flag = 0; break;}
				f[j] %= 3;
				f[j + 1] -= f[j];
				f[j + 2] -= f[j];
			}
			vis[i] += 2;
			if (flag)
				return 1;
		}
	}
	return 0;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= 3 * m + 1; i++)
		read(a[i]);
	for (int i = 1; i <= 3 * m + 1; i++)
		vis[a[i]] ++;
	for (int i = 1; i <= n; i++)
	{
		vis[i]++;
		if (solve())
		{
			v.push_back(i);
		}
		vis[i]--;
	}
	if (v.size() == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0 ;
}