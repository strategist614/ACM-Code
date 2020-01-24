/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
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
int sg[N][N];
int SG(int x, int y) {
	bool f[N];
	memset(f, 0, sizeof(f));
	if (sg[x][y] != -1) return sg[x][y];
	for (int i = 2; i <= x - i; i++) f[SG(i, y)^SG(x - i, y)] = 1;
	for (int i = 2; i <= y - i; i++) f[SG(x, i)^SG(x, y - i)] = 1;
	int t = 0;
	while (f[t]) ++t;
	return sg[x][y] = t;
}
int main ()
{
	int n, m;
	memset(sg, -1, sizeof(sg));
	sg[2][2] = sg[2][3] = sg[3][2] = 0;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		puts(SG(n, m) ? "WIN" : "LOSE");
	}
	return 0 ;
}