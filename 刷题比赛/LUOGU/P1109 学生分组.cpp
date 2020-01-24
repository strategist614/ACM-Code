/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
/*
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
int a[55];
int main ()
{
	int n, l, r;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> l >> r;
	sort(a + 1, a + n + 1);
	int up = 0;
	int down = 0;
	int _ = 0;
	int __ = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < l) {down += l - a[i]; _++;}
		if (a[i] > r) {up += a[i] - r; __++;}
	}
	if (down == up)
	{
		cout << up << endl;
	}
	else if (down > up)
	{
		int ans = up;
		down -= up;
		int sum = __ * (r - l);
		if (sum >= down) ans += down;
		else
		{
			ans += sum;
			down -= sum;
			int num = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] >= l && a[i] <= r) num += a[i] - l;
			}
			if (num >= down) ans += down;
			else ans = -1;
		}
		cout << ans << endl;
	}
	else
	{
		int ans = down ;
		up -= down;
		int sum = _ * (r - l);
		if (sum > up) ans += up;
		else
		{
			ans += sum;
			up -= sum;
			int num = 0;
			for (int i = 1; i <= n; i++)
			{
				if (a[i] >= l && a[i] <= r) num += r - a[i];
			}
			if (num >= up) ans += up;
			else ans = -1;
		}
		cout << ans << endl;
	}
	return 0 ;
}
*/
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
int a[55];
int main ()
{
	int n, l, r;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {cin >> a[i]; sum += a[i];}
	cin >> l >> r;
	if (sum < l * n || sum > r * n)
	{
		cout << -1 << endl;
		return 0;
	}
	int _ = 0, __ =  0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > r) _ += a[i] - r;
		if (a[i] < l) __ += l - a[i];
	}
	cout<<max(_,__)<<endl;
	return 0 ;
}