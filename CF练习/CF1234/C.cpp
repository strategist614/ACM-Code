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
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int q;
	cin >> q;
	while (q--) {
		int n;
		string s[2];
		cin >> n >> s[0] >> s[1];
		int row = 0;
		int pos = 0;
		for (pos = 0; pos < n; pos ++) {
			if (s[row][pos] >= '3')
			{
				if (s[row ^ 1][pos] < '3')
					break;
				else row ^= 1;
			}
		}
		if (pos == n && row == 1)
			printf("YES\n");
		else printf("NO\n");
	}
	return 0 ;
}