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
const int N = 1e6 + 5;
ll a[N];
ll sum[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	ll sumx = 0;
	for (int i = 1; i <= n; i++) {read(a[i]);sumx += a[i];}
	for (int i = 1; i <= n; i++) a[i] -= sumx / n;
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	sort(sum + 1, sum + n + 1);
	ll mid = 0;
	if (n % 2 == 0) mid = (sum[n / 2] + sum[n / 2 + 1]) / 2;
	else
		mid = sum[n / 2 + 1];
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = ans + (ll)abs(sum[i] - mid);
	cout << ans << endl;
	return 0 ;
}