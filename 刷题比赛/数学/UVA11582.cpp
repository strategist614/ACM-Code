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
const int N = 1005;
ull a, b;
int n;
int f[N][6 * N];
ll p[N];
ll ksm(ull a, ull b, int mod)
{
	ll ans = 1;
	while (b > 0)
	{
		if (b & 1) ans = ans * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ans % mod;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out",  	"w", stdout);
	for (int i = 2; i <= 1000; i++) {
		f[i][0] = 0; f[i][1] = 1;
		for (int j = 2;; j++) {
			f[i][j] = (f[i][j - 2] + f[i][j - 1]) % i;
			if (f[i][j - 1] == 0 && f[i][j] == 1) {
				p[i] = j - 1;
				break;
			}
		}
	}
	int t;
	read(t);
	while (t--) {
		cin >> a >> b >> n;
		if (a == 0 || n == 1)
		{
			cout << 0 << endl;
			continue;
		}
		int ans = ksm(a % p[n], b, p[n]);
		cout << f[n][ans] << endl;
	}
	return 0 ;
}