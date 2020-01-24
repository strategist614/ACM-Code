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
typedef pair<int,int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const int N = 1005;
int a[N][N];
ll sum[N][N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n,m,r,c;
	read(n);
	read(m);
	read(r);
	read(c);
	for(int i = 1;i <= n;i++)
		for(int j =1;j <= m;j++)
			read(a[i][j]);
	for(int i =1;i <= n;i++)
		for(int j =1;j <= m;j++)
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
	ll ans = 0;
	for(int i =1;i + r - 1<= n;i++)
	{
		for(int j =1;j + c - 1 <= m;j++)
		{
			int x2 = i + r - 1;
			int y2 = j + c - 1;
			ll _ = sum[x2][y2] - sum[x2][j - 1] - sum[i - 1][y2] + sum[i - 1][j - 1];
			ans = max(ans,_);
		}
	}
	cout << ans << endl;
	return 0 ;
}