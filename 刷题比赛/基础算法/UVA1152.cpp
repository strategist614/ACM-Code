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
const int N = 4005;
int a[N][4];
unordered_map<ll, int> mp;
int main ()
{
	int t;
	read(t);
	while (t--)
	{
		mp.clear();
		int n;
		read(n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 4; j++) {
				read(a[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mp[a[i][1] + a[j][2]]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ll tmp = a[i][3] + a[j][4];
				if (mp[-tmp]) ans += mp[-tmp];
			}
		}
		out(ans);
		puts("");
		if (t != 0) puts("");
	}
	return 0 ;
}