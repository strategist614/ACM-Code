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
const int N = (1 << 18) + 5;
std::vector<ll> v;
bool a[N];
int main ()
{
	ll	 n, x;
	cin >> n >> x;
	a[0] = 1;
	v.push_back(0);
	for (int i = 1; i <= (1 << n) - 1; i++) {
		if (a[i ^ x]) continue;
		v.push_back(i);
		a[i] = 1;
	}
	cout << v.size() - 1<< endl;
	for (int i = 0; i < v.size() - 1; i++) {
		cout << (v[i] ^ v[i + 1] ) << " ";
	}
	return 0 ;
}