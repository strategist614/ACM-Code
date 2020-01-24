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
struct node
{
	int s;
	int d;
} a[1005];
int main ()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].s >> a[i].d;
	ll s = a[1].s;
	for (int i = 2; i <= n; i++)
	{
		if(a[i].s > s)
		{
			s = a[i].s;
			continue;
		}
		ll x = 1;
		while (a[i].s + (ll)x * a[i].d <= s)
		{
			x++;
		}
		s = a[i].s + x * a[i].d;
	    //cout<<s<<endl;
	}
	cout << s << endl;
	return 0 ;
}