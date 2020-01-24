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
const int N = 100005;
std::vector<int> g[N];
int tot = 0;
int match[N],v[N];

bool dfs(int x) {
	for (int i = 0,y;i < g[x].size();i++)
		if (!v[y = g[x][i]]) {
			v[y] = 1;
			if (!match[y] || dfs(match[y])) {
				match[y] = x;
				return true;
			}
		}
	return false;
}

int main ()
{
	int t;
	read(t);
	while (t--) {
		int p, n;
		read(p);
		read(n);
		for (int i = 1 ; i <= p; i++) g[i].clear();
		for (int i = 1; i <= p; i ++) {
			int k;
			read(k);
			for (int j = 1; j <= k; j++) {
				int tmp;
				read(tmp);
				g[i].push_back(tmp);
			}
		}
		int ans = 0;
		memset(match, 0, sizeof(match));
		for (int i = 1; i <= p; i++) {
			memset(v, 0, sizeof(v));
			if (dfs(i)) ans++;
		}
		if (ans == p) {
			printf("YES\n");
		}
		else printf("NO\n");
	}
	return 0 ;
}