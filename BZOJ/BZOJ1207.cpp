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
const int N = 10005;
int f[N];
struct node
{
	int x;
	int y;
	int time;
} a[N];
int dis(int x, int y, int a, int b)
{
	return abs(x - a) + abs(y - b);
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(a[i].time);
		read(a[i].x);
		read(a[i].y);
	}
	for (int i = 1; i <= m; i++)
	{
		f[i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (a[j].time == a[i].time) break;
			if (dis(a[i].x, a[i].y, a[j].x, a[j].y) <= (a[i].time - a[j].time))
				f[i] = max(f[i], f[j] + 1);
		}
	}
	int ans = 0;
	for (int i  = 1; i <= m; i++)
		ans = max(ans, f[i]);
	cout << ans << endl;
	return 0 ;
}
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
const int N = 10005;
int f[N];
struct node
{
	int x;
	int y;
	int time;
} a[N];
int dis(int x, int y, int ans, int b)
{
	return abs(x - a) + abs(y - b);
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	read(n);
	read(m);
	for (int i = 1; i <= m; i++)
	{
		read(a[i].time);
		read(a[i].x);
		read(a[i].y);
	}
	for (int i = 1; i <= m; i++) f[i] = 1;
	for (int i = 1; i <= m; i++)
	{
		//f[i] = 1;
		for (int j = i + 1; j <= m; j++)
			if (dis(a[i].x, a[i].y, a[j].x, a[j].y) <= (a[j].time - a[i].time))
				f[j] = max(f[j], f[i] + 1);
	}
	int ans = 0;
	for (int i  = 1; i <= m; i++)
		ans = max(ans, f[i]);
	cout << ans << endl;
	return 0 ;
}
*/