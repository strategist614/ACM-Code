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
int n, m;
int a[55];
int solve(int mid)
{
	int _ = min(m, mid);
	for (int i = 1; i <= n; i++)
    {
        if(a[i] < mid)
        {
        	_ -= (mid - a[i]);
        	if(_ < 0) return 0;
        }  
    }
    return 1;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	int l = 0;
	int r = 0;
	for (int i = 1; i <= n; i++)
	{
		r = max(r, a[i]);
	}
	r += m + 1;
	while (l < r)
	{
		int mid = (l + r + 1) >> 1;
		if (solve(mid)) l = mid;
		else r = mid - 1;
	}
	cout << l << endl;
	return 0 ;
}