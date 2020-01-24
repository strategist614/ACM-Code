//Author:XuHt
/*
#include <iostream>
#define ll long long
using namespace std;

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, x, y);
	ll z = x;
	x = y;
	y = z - y * (a / b);
	return d;
}

int main() {
	int n;
	while (cin >> n) {
		ll a, b, x, y, k;
		cin >> a >> b;
		ll lcm = a, ans = b;
		bool flag = 1;
		--n;
		while (n--) {
			cin >> a >> b;
			b = (b - ans % a + a) % a;
			ll d = exgcd(lcm, a, x, y);
			if (b % d) flag = 0;
			else k = x * (b / d) % a;
			ans += k * lcm;
			lcm = lcm / d * a;
			ans = (ans % lcm + lcm) % lcm;
		}
		if (flag) cout << ans << endl;
		else cout << "-1" << endl;
	}
	return 0;
}
*/
/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstring>
#include<cstdio>
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

ll exgcd(ll a, ll b, ll &x, ll &y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, x, y);
	ll z = x;
	x = y;
	y = z - y * (a / b);
	return d;
}

int main ()
{
	int n;
	while (scanf("%d", &n) != EOF)
	{
		int a, b;
		read(a);
		read(b);
		int flag = 0;
		ll ans = b;
		ll lcm = a;
		ll x = 0, y = 0, k = 0;
		for (int i = 1; i < n; i++)
		{
			read(a);
			read(b);
			b = (b - ans % a + a) % a;
			ll d = exgcd(lcm, a, x, y);
			if (b % d) flag = 1;
			else k = x * (b / d) % a;
			ans += k * lcm;
			lcm = lcm / d * a;
			ans = (ans % lcm + lcm) % lcm;
		}
		if (!flag)
			cout << ans  << endl;
		else cout << "-1" << endl;
	}
	return 0 ;
}