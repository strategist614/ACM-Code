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
std::vector<ll> v;
std::vector<ll> ans;
int main ()
{
	int t;
	read(t);
	int flag = 0;
	while (t--)
	{
		v.clear();
		ans.clear();
		ll a, b, l;
		cin >> a >> b >> l;
		ll g = gcd(a, b);
		ll x = a / gcd(a, b) * b;
		printf("Case %d: ", ++flag);
		v.push_back(1);
		v.push_back(x);
		for (int i = 2; i <= sqrt(x); i++)
		{
			if (x % i == 0)
			{
				v.push_back(i);
				if (x / i != i) v.push_back(x / i);
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			ll _ = l * v[i];
			ll __ = x;
			if (_ % __ == 0) 
			{
				if(gcd(x,_/__) == v[i]) ans.push_back(_/__);
			}
		}
		sort(ans.begin(), ans.end());
		if (ans.size() == 0) cout << "impossible" << endl;
		else cout << ans[0] << endl;
	}
	return 0 ;
}