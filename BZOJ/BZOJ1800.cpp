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
int a[55];
int sum[55];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++)
		a[n + i] = a[i];
	for (int i = 1; i <= 2 * n; i++)
		sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int s = 1; s <= n; s++)
	{
		for (int i = s; i <= s + n - 1; i++)
		{
			for (int j = i + 1; j <= s + n - 1; j++)
				for (int k = j + 1; k <= s + n - 1; k ++) {
					if ((sum[i] - sum[s - 1] == sum[k] - sum[j]) && (sum[j] - sum[i] == sum[s + n - 1] - sum[k]))
					{
						ans++;
					}
				}
		}
	}
	cout << ans / 4 << endl;
	return 0 ;
}