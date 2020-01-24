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
char s[1000];
int n;
struct BigInt
{
	int s[2000], ws;
	void init() {memset(s, 0, sizeof(s)); s[ws = 1] = 0;}
	void output() {for (int i = ws; i; --i)printf("%d", s[i]); puts("");}
	void eql(ll x) {init(); ws = 0; while (x)s[++ws] = x % 10, x /= 10;}
} ans, P;
BigInt operator+(BigInt a, BigInt b)
{
	int ws = max(a.ws, b.ws);
	for (int i = 1; i <= ws; ++i)a.s[i] += b.s[i];
	for (int i = 1; i <= ws; ++i)a.s[i + 1] += a.s[i] / 10, a.s[i] %= 10;
	while (a.s[ws + 1])++ws, a.s[ws + 1] += a.s[ws] / 10, a.s[ws] %= 10;
	a.ws = ws; return a;
}
BigInt operator*(BigInt a, BigInt b)
{
	BigInt ret; int ws = a.ws + b.ws; ret.init();
	for (int i = 1; i <= a.ws; ++i)
		for (int j = 1; j <= b.ws; ++j)
			ret.s[i + j - 1] += a.s[i] * b.s[j];
	for (int i = 1; i <= ws; ++i)ret.s[i + 1] += ret.s[i] / 10, ret.s[i] %= 10;
	while (!ret.s[ws])--ws;
	ret.ws = ws; return ret;
}
int now = 0;
void dfs(int k)
{
	now ++;
	if (s[now] == '0') P.eql(1ll << k), ans = ans + P * P;
	else if (s[now] == '1');
	else {
		dfs(k - 1);
		dfs(k - 1);
		dfs(k - 1);
		dfs(k - 1);
	}
}
int main ()
{
	//freopen("input.in", "r", stdin);
	//freopen("test.out", "w", stdout);
	int k;
	read(k);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	dfs(k);
	ans.output();
	return 0 ;
}