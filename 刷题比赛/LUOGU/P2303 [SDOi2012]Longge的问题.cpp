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
ll n;
std::vector<ll> v;
ll phi(ll n) {
	ll ans = n;
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ans = ans / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) ans = ans / n * (n - 1);
	return ans;
}
int main ()
{
	cin >> n;
	ll ans = 0;
	v.push_back(1);
	v.push_back(n);
	for (ll i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			v.push_back(i);
			if (n / i != i) v.push_back(n / i);
		}
	}
	for (int i = 0; i < v.size(); i++) {
         ans += phi(n / v[i]) * v[i];
	}
	cout<<ans<<endl;
	return 0 ;
}