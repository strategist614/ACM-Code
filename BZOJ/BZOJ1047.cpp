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
int a, b, n;
int maxv[1005][1005][12], minv[1005][1005][12];
int kk;
inline int Max(int a, int b, int c, int d)
{
	return max(max(max(a, b), c), d);
}
inline int Min(int a, int b, int c, int d)
{
	return min(min(min(a, b), c), d);
}
inline int query_max(int x, int y, int xx, int yy)
{
	int t1 = maxv[x][y][kk], t2 = maxv[xx - (1 << kk) + 1][y][kk], t3 = maxv[x][yy - (1 << kk) + 1][kk], t4 = maxv[xx - (1 << kk) + 1][yy - (1 << kk) + 1][kk];
	return max(max(max(t1, t2), t3), t4);
}
inline int query_min(int x, int y, int xx, int yy)
{
	int t1 = minv[x][y][kk], t2 = minv[xx - (1 << kk) + 1][y][kk], t3 = minv[x][yy - (1 << kk) + 1][kk], t4 = minv[xx - (1 << kk) + 1][yy - (1 << kk) + 1][kk];
	return min(min(min(t1, t2), t3), t4);
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	read(a);
	read(b);
	read(n);
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			int val;
			read(val);
			maxv[i][j][0] = val;
			minv[i][j][0] = val;
		}
	}
	for (int k = 1; k <= 11; ++k)
		for (int i = 1; i + (1 << k) - 1 <= a; ++i)
			for (int j = 1; j + (1 << k) - 1 <= b; ++j)
			{
				maxv[i][j][k] = Max(maxv[i][j][k - 1], maxv[i + (1 << k - 1)][j][k - 1], maxv[i][j + (1 << k - 1)][k - 1], maxv[i + (1 << k - 1)][j + (1 << k - 1)][k - 1]);
				minv[i][j][k] = Min(minv[i][j][k - 1], minv[i + (1 << k - 1)][j][k - 1], minv[i][j + (1 << k - 1)][k - 1], minv[i + (1 << k - 1)][j + (1 << k - 1)][k - 1]);
			}
	kk = (int)(log(n) / log(2));
	int ans = 1e9;
	for (int i = 1; i + n - 1 <= a; i++)
	{
		for (int j = 1; j + n - 1 <= b; j++)
		{
			ans = min(ans, query_max(i, j, i + n - 1, j + n - 1) - query_min(i, j, i + n - 1, j + n - 1));
		}
	}
	printf("%d\n", ans);
	return 0 ;
}