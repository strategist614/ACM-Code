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
ll a[1000];
map<ll, int> mp;
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	ll n;
	read(n);
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= 72; i++) {
		a[i] = a[i - 1] + a[i - 2];
		mp[a[i]] = 1;
	}
	ll ans = 0;
	if (n == 1)
	{
		printf("1\n");
		return 0;
	}
	if (n == 2)
	{
		printf("2\n");
		return 0;
	}
	for (int i = 1; i <= 72; i++)
	{
		if (a[i] > n)
		{
			if (mp[n])
			{
                ans = n - a[i - 2];  
			}
			else
				ans = n - a[i - 1];
			printf("%lld\n", ans);
			return 0;
		}
	}
	return 0 ;
}