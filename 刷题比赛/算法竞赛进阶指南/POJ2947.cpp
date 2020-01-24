/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
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
const int mod = 7;
int a[305][305];
int n, m;
int b[305];
map<string, int> mp;

int exgcd(int p, int q, int &x, int &y) {
	if (!q) {
		x = 1;
		y = 0;
		return p;
	}
	int d = exgcd(q, p % q, x, y);
	int z = x;
	x = y;
	y = z - y * (p / q);
	return d;
}

void guess()
{
	int w = 0;
	for (int i = 1; i <= n; i++) {
		int t = 0;
		for (int j = w + 1; j <= m; j++)
			if (a[j][i] && (!t || a[j][i] > a[t][i])) t = j;
		if (!t) continue;
		swap(b[++w], b[t]);
		for (int j = 1; j <= n; j++) swap(a[w][j], a[t][j]);
		for (int j = 1; j <= m; j++) {
			if (w == j || !a[j][i]) continue;
			int z = a[j][i];
			for (int k = 1; k <= n; k++)
				a[j][k] = (a[j][k] * a[w][i] - a[w][k] * z) % 7;
			b[j] = (b[j] * a[w][i] - b[w] * z) % 7;
		}
	}
	for (int i = w + 1; i <= m; i++)
		if (b[i] %= 7) {
			puts("Inconsistent data.");
			return;
		}
	if (w < n) {
		puts("Multiple solutions.");
		return;
	}
	for (int i = 1; i <= n; i++) {
		int x, y;
		int d = exgcd(a[i][i], 7, x, y);
		if (b[i] % d) {
			puts("Inconsistent data.");
			return;
		}
		else if (i < n) printf("%d ", ((x * b[i] / d - 3) % 7 + 7) % 7 + 3);
		else printf("%d\n", ((x * b[i] / d - 3) % 7 + 7) % 7 + 3);
	}
}

int main ()
{
	mp["MON"] = 1;
	mp["TUE"] = 2;
	mp["WED"] = 3;
	mp["THU"] = 4;
	mp["FRI"] = 5;
	mp["SAT"] = 6;
	mp["SUN"] = 7;
	while (~scanf("%d %d", &n, &m))
	{
		memset(a, 0, sizeof(a));
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= m; i++) {
			int k;
			char s1[6], s2[6];
			scanf("%d %s %s", &k, s1, s2);
			b[i] = (mp[s2] - mp[s1] + 1) % 7;
			while (k--) {
				int x;
				scanf("%d", &x);
				(++a[i][x]) %= 7;
			}
		}
		guess();
	}
	return 0 ;
}