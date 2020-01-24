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
const int mod = 10056;

ll f[20005];
ll yh[2005][2005];


int main ()
{
	int flag = 0;
	ll t;
	read(t);
	for (int i = 0; i < 2000; i++)
	{
		yh[i][0] = 1;
		yh[i][i] = 1;
	}
	for (int i = 2; i < 2000; i++)
	{
		for (int j = 1; j < i; j++)
			yh[i][j] = (yh[i - 1][j] % mod + yh[i - 1][j - 1] % mod) % mod;
	}
	int top = 4;
	while (t--) {
		ll n;
		read(n);
		f[0] = 1;
		f[1] = 1;
		f[2] = 3;
		f[3] = 13;
		f[4] = 75;
		if(f[n]){
			printf("Case %d: %lld\n",++flag,f[n]);
			continue;
		}
		for (int i = top + 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++) {
				f[i] = (f[i] % mod + yh[i][j] % mod * f[i - j] % mod) % mod;
				f[i] %= mod;
			}
		}
		top = n;
		printf("Case %d: %lld\n", ++flag, f[n]);
	}
	return 0 ;
}