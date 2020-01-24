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
const int N = 105;
const int inf = 0x3f3f3f3f;
int n;
int a[N];
int ans[N];
bool vis[N];
int s[N];
int maxlen, m;

void solve(int cnt) {
	for (int i = 1; i <= cnt; i++) {
		int tmp = ans[cnt] - ans[i];
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && a[j] == tmp)
				vis[j] = 1;
		}
	}
}

bool judge()
{
	for (int i = 1; i <= n; i++) if (!vis[i]) return 0;
	return 1;
}

void dfs(int cnt)
{
	bool vis2[N];
	if (ans[cnt - 1] > maxlen || cnt > m) return; // 减枝
	if (judge()) { // 判断是否全部选中
		if ((cnt < m) || (cnt == m && ans[cnt - 1] < maxlen))
		{
			maxlen = ans[cnt - 1];
			m = cnt;
			memcpy(s, ans, sizeof(ans));
			return ;
		}
	}
	memcpy(vis2, vis, sizeof(vis)); // 保存当前vis的状态，回溯用
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			for (int j = 1; j <= cnt; j++) {
				if (ans[j] + a[i] > ans[cnt - 1])
				{
					ans[cnt] = ans[j] + a[i];
					solve(cnt);
					dfs(cnt + 1);
					memcpy(vis, vis2, sizeof(vis));
				}
			}
		}
	}
}

void init() {
	memset(vis, 0, sizeof(vis));
	memset(ans, 0, sizeof(ans));
	memset(s, 0, sizeof(s));
}

int main ()
{
	//int n;
	int flag = 0;
	while (~scanf("%d", &n) && n) {
		init();
		for (int i = 1; i <= n; i++) read(a[i]);
		sort(a + 1, a + n + 1);
		maxlen = a[n];
		m = inf;
		ans[1] = 0;
		ans[2] = a[1];
		solve(2);
		dfs(3);
		printf("Case %d:\n", ++flag);
		printf("%d\n", m - 1);
		for (int i = 1; i < m; i++)
			printf("%d ", s[i]);
		puts("");
	}
	return 0 ;
}

