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
const int N = 1e6 + 5;
bitset<N * 10> v, v1;
int a[N];
std::vector<int> ans;
int main ()
{
	int n;
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{
		mx = max(mx, a[i]);
		if (v[a[i]] == 1) v1[a[i]] = 1;
		v[a[i]] = 1;
	}
	ll res = 1e18;
	int pos1 = 0, pos2 = 0;
	int l = -1;
	int r = -1;
	for (int i = 1; i <= mx; i++)
	{
		ans.clear();
		for (int j = i; j <= mx; j += i)
		{
			if (v[j])
			{
				ans.push_back(j);
				if (v1[j]) ans.push_back(j);
				if (ans.size() >= 2) break;
			}
		}
		if (ans.size() < 2) continue;
		if (res > (ll) ans[0] * ans[1] / i)
		{
			res = (ll)ans[0] * ans[1] / i;
			pos1 = ans[0];
			pos2 = ans[1];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == pos1) {
			l = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == pos2 && l != i)
		{
			r = i;
			break;
		}
	}
	if (l > r) swap(l, r);
	cout << l << " " << r << endl;
	return 0 ;
}