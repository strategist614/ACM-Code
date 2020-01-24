
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
const int N = 10005;
std::vector<int> son[N];
int f[N][2], v[N], h[N], n;
void dp(int x)
{
	f[x][0] = 0;
	f[x][1] = h[x];
	for (int i = 0; i < son[x].size(); i++)
	{
		int y = son[x][i];
		dp(y);
		f[x][0] += max(f[y][0], f[y][1]);
		f[x][1] += f[y][0];
	}
}
int main ()
{
	read(n);
	for (int i = 1; i <= n; i++)  read(h[i]);
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		read(x);
		read(y);
		v[x] = 1;
		son[y].push_back(x);
	}
	int root = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!v[i])
		{
			root = i;
			break;
		}
	}
	dp(root);
	cout << max(f[root][1], f[root][0]) << endl;
	return 0 ;
}