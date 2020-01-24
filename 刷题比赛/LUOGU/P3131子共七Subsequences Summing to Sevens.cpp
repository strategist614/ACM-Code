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
const int N = 5e4 + 5;
int a[N];
ll sum[N];
std::vector<int> v[7];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	read(n);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) sum[i] %= 7;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (sum[i] == j) v[j].push_back(i);
		}
	}
	int ans = 0;
	for (int i = 0; i < 7; i++)
	{
		if (v[i].size() >= 2)
		{
			ans = max(ans, v[i][v[i].size() - 1] - v[i][0]);
		}
	}
	cout << ans << endl;
	return 0 ;
}