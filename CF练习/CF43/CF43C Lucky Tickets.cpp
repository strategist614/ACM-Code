/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
  去做难度超过自己平时比赛能过的题难度的题，独立思考2-3小时再看题解
  反正，div2 A/B都做不利索的，请多做点题。
  div2 C要求一点脑洞和洞察力，刻意让自己思考一下，还是能培养出来的。
  更后面的题，那就是靠算法知识的积累+自己的大量思考了。
  做题不补等于白做
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
typedef pair<int, int> pii;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
int a[10000];
int solve(int x)
{
	int ans = 0;
	while (x)
	{
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		a[i] = solve(a[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		a[i] = a[i] % 3;
	}
	int _ = 0, __ = 0, ___ = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0) _++;
		else if (a[i] == 1) __ ++;
		else if (a[i] == 2) ___ ++;
	}
	int ans = 0;
	ans += _ / 2;
	ans += min(__, ___);
	cout << ans << endl;
	return 0 ;
}