//  805E
#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<=b; ++i)
#define per(i,b,a) for (int i=b; i>=a; --i)
#define mes(a,b)  memset(a,b,sizeof(a))
#define INF 0x3f3f3f3f
#define MP make_pair
#define PB push_back
#define fi  first
#define se  second
typedef long long ll;
const int N = 300005;

int n, m, col[N], need[N];
vector<int > s[N], G[N];
set<int > used;
void dfs(int u, int fa)
{
	used.clear();
	for (auto ai : s[u]) if (col[ai])
			used.insert(col[ai]);
	int now = 1;
	for (auto ai : s[u]) if (col[ai] == 0)
		{
			while (used.find(now) != used.end()) ++now;
			col[ai] = now;
			++now;
		}
	for (auto to : G[u]) if (to != fa)
			dfs(to, u);
}
int main()
{
	scanf("%d%d", &n, &m);
	int si, ai, ans = 0;
	rep(i, 1, n)
	{
		scanf("%d", &si);
		ans = max(ans, si);
		rep(j, 1, si)
		{
			scanf("%d",	 &ai);
			s[i].PB(ai);
		}
	}
	int u, v;
	rep(i, 1, n - 1)
	{
		scanf("%d%d", &u, &v);
		G[u].PB(v);  G[v].PB(u);
	}
	dfs(1, 0);
	ans = max(ans, 1);
	printf("%d\n", ans);
	rep(i, 1, m)
	if (col[i]) printf("%d ", col[i]);
	else printf("1 ");
	puts("");

	return 0;
}
/*
2 6
3 1 2 3
3 2 5 6
1 2
*/