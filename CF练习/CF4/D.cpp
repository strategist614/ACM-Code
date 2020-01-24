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
const int N = 5005;
struct node
{
	int w;
	int h;
	int id;
} a[N];
int dp[N];
bool cmp(node a, node b)
{
	if (a.w == b.w) return a.h < b.h;
	return a.w < b.w;
}
int fa[N];
int ansx[N];
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n, w, h;
	cin >> n >> w >> h;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].w >> a[i].h;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
	{
		if (a[i].w > w && a[i].h > h)
			dp[i]  = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (a[i].w < a[j].w && a[i].h < a[j].h && a[i].w > w && a[i].h > h) {
				if (dp[i] + 1 > dp[j])
				{
					fa[j] = i;
					dp[j] = dp[i] + 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	int ed = 0;
	for (int i = 1; i <= n; i++) {
		if (ans == dp[i])
		{
			ed = i;
			break;
		}
	}
	std::vector<int> v;
	while (ed)
	{
		v.push_back(ed);
		ed = fa[ed];
	}
	for (int i = 0; i < v.size(); i++)
		ansx[i + 1] = a[v[i]].id;
	cout << ans << endl;
	for (int i = 1; i <= ans; i++)
		cout << ansx[ans - i + 1] << " " ;
	return 0 ;
}