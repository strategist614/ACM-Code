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
char a[2005][2005];
int b[2005][2005];
ll sum1[2005][2005];
ll sum2[2005][2005];
int main ()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	if(k == 1)
	{
		int ans = 0;
		for(int i =1;i <= n;i++){
			for(int j =1;j <= m;j++)
			if(a[i][j] == '.') ans ++; 
		}
		cout<<ans<<endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '*') b[i][j] = 0;
			else b[i][j] = 1;
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			sum1[i][j] = sum1[i][j - 1] + b[i][j];
		}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
		{
			sum2[i][j] = sum2[i][j - 1] + b[j][i];
		}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (sum1[i][j] - sum1[i][j - k] == k) ans ++;
		}
	for(int i = 1;i <= m;i++)
		for(int j =1;j <= n;j++)
		{
			if(sum2[i][j] - sum2[i][j- k] == k) ans++;
		}
	cout << ans << endl;
	return 0 ;
}