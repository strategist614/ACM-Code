#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
typedef pair<int, int> P;
const int MAXN = 300010;
vector<P> mp[MAXN];
P fa[MAXN];
int d[MAXN];
bool book[MAXN], select[MAXN];
void dfs(int u, int pre)
{
	int v, id;
	for (int i = 0; i < mp[u].size(); i++)
	{
		v = mp[u][i].first;
		id = mp[u][i].second;
		if (v == pre || book[v]) continue;
		book[v] = 1;
		fa[v] = P(u, id);
		dfs(v, u);
		if (d[v] == 1)
		{
			d[v] = 0;
			select[id] ^= 1;
			if (d[u] != -1)
				d[u] ^= 1;
		}
	}
}
int main()
{
	int n, m, u, v;
	int node = 0, ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", d + i);
		if (d[i] == -1) node = i;
	}
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d", &u, &v);
		mp[u].push_back(P(v, i));
		mp[v].push_back(P(u, i));
	}
	dfs(1, -1);
	if (d[1] == 1)
	{
		if (node == 0)
		{
			cout << -1;
			return 0;
		}
		while (node != 1)
		{
			select[fa[node].second] ^= 1;
			node = fa[node].first;
		}
	}
	for (int i = 1; i <= m; i++)
		if (select[i])
			ans++;
	cout << ans << endl;
	for (int i = 1; i <= m; i++)
		if (select[i])
			printf("%d ", i);
	return 0;
}