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
const int N = 205;
int a[N];
struct node
{
	int c;
	int q;
} b[N];
bool cmp(int a, int b)
{
	return a > b;
}
bool cmp2(node a, node b)
{
	return a.q < b.q;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, m;
	while (~scanf("%d %d", &n, &m))
	{
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) read(a[i]);
		for (int i = 1; i <= m; i++)
		{
			read(b[i].c);
			read(b[i].q);
		}
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + m + 1, cmp2);
		int ans = 0;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (b[j].c && b[j].q >= a[i])
				{
					ans ++;
					b[j].c --;
					sum += a[i];
					break;
				}
			}
		}
		cout << ans << " " << sum << endl;
	}
	return 0 ;
}