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
const int N = 105;
char s[N][N];
map<char , int> mp;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	char c;
	read(n);
	read(m);
	cin >> c;
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	int ans = 0;
	int flag = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] == c)
			{
				if (s[i + 1][j] != '.' && (i + 1) <= n && !mp[s[i + 1][j]] && s[i + 1][j] != c) {
					ans++;
					mp[s[i + 1][j]] = 1;
				}
				if (s[i - 1][j] != '.' && (i - 1) >= 1 && !mp[s[i - 1][j]] && s[i - 1][j] != c)
				{
					ans ++;
					mp[s[i - 1][j]] = 1;
				}
				if (s[i][j + 1] != '.' && (j + 1) <= m && !mp[s[i][j + 1]] && s[i][j + 1] != c)
				{
					ans ++;
					mp[s[i][j + 1]] = 1;
				}
				if (s[i][j - 1] != '.' && (j - 1) >= 1 && !mp[s[i][j - 1]] && s[i][j - 1] != c)
				{
					ans ++;
					mp[s[i][j - 1]] = 1;
				}
			}
		}
	}
	cout << ans << endl;
	return 0 ;
}