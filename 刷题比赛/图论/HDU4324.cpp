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
const int N = 2005, M = 4000005;
int head[N], ver[M], Next[M];
int deg[N];
int cnt, tot;
int n;
char b[N][N];
int a[N][N];
void init()
{
	memset(deg, 0, sizeof(deg));
	memset(head, 0, sizeof(head));
	tot = 0;
	cnt = 0;
}
void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
	deg[y]++;
}
void topsort() {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0) q.push(i);
	while (q.size()) {
		int x = q.front(); q.pop();
		++cnt;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (--deg[y] == 0) q.push(y);
		}
	}
}
int main() {
	int t;
	read(t);
	int flag = 0;
	while (t--) {
		init();
		read(n);
		for (int i = 1; i <= n; i++)
			scanf("%s", b[i] + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = b[i][j] - '0';
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (a[i][j]) add(i, j);
			}
		topsort();
        if(cnt != n)
        	printf("Case #%d: Yes\n",++flag);
        else printf("Case #%d: No\n",++flag);
	}
	return 0 ;
}