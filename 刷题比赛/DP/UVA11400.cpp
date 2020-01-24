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
int n;
struct node
{
	int v;
	int k;
	int c;
	int l;
} a[N];
int f[N];
bool cmp(node a, node b)
{
	return a.v < b.v;
}
int sum[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	while (~scanf("%d", &n))
	{
		if (n == 0) break;
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			read(a[i].v);
			read(a[i].k);
			read(a[i].c);
			read(a[i].l);
		}
		sort(a + 1, a + n + 1, cmp);
		memset(f, 0x3f, sizeof(f));
		for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i].l;
		for (int i = 1; i <= n; i++)
		{
			f[i] = a[i].k + a[i].c * sum[i];
			for (int j = 1; j < i; j++)
				f[i] = min(f[i], f[j] + (sum[i] - sum[j]) * a[i].c + a[i].k);
		}
		cout << f[n] << endl;
	}
	return 0 ;
}