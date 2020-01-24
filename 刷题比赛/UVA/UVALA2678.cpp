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
ll sum[N];
int n, m;
int main ()
{
	while (scanf("%d %d", &n, &m) != EOF) {
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++)
		{
			read(a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		int ans = 1e9;
		for (int i = 1; i <= n; i++) {
			int l = i;
			int r = n + 1;
			while (l < r) {
				int mid = (l + r) >> 1;
				int ans = sum[mid] - sum[i - 1];
				if (ans >= m) r = mid;
				else l = mid + 1;
			}
			if (l == n + 1) continue;
			ans = min(ans, l - i + 1);
		}
		if (ans == 1e9) ans = 0;
		cout << ans << endl;
	}
	return 0 ;
}