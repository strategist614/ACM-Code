/*
  独立思考
  一个题不会做，收获5%，写了代码10%，提交对了30%，总结吃透了这个题才是100%.
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
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
const int N = 1005;
int head[N], ver[N * 2], Next[N * 2];
int tot = 0;
int v[N], match[N];
void add(int x, int y) {
	ver[++tot] = y;
	Next[tot] = head[x];
	head[x] = tot;
}
int n, m, k;

bool dfs(int x) {
	for (int i = head[x]; i; i = Next[i]) {
		int y = ver[i];
		if (!v[y]) {
			v[y] = 1;
			if (!match[y] || dfs(match[y])) {
				match[y] = x; return true;
			}
		}
	}
	return false;
}

int main ()
{
	while (~scanf("%d %d %d", &n, &m, &k) && n) {
		memset(head, 0, sizeof(head));
		memset(match, 0, sizeof(match));
		tot = 0;
		for (int i = 1; i <= k; i++) {
			int id, a, b;
			read(id);
			read(a);
			read(b);
		    if(a == 0 || b == 0) continue;
		    b += n;
			add(a,b);
			add(b,a);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			memset(v, 0, sizeof(v));
			if (dfs(i)) ans++;
		}
		out(ans);
		puts("");
	}
	return 0 ;
}